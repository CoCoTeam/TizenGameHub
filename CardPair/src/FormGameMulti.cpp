#include "FormGameMulti.h"
#include "AppResourceId.h"
#include "AppGameData.h"

using namespace Tizen::Base;
using namespace Tizen::App;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Ui::Scenes;
using namespace Tizen::Web::Json;


FormGameMulti::FormGameMulti(void)
{
	isMultiplay = true;
	onMyTurn = false;
	isGameFirst = true;
	isWin = false;
}

FormGameMulti::~FormGameMulti(void)
{
}
void FormGameMulti::setAdditionalInitialState()
{
	pLabelTimer->SetText("");
	multiController = new GHTurnbasedMatchController();
	multiController->connectSocketServer(this);


	pLabelScore2 = static_cast< Label* >(GetControl(IDC_GAME_LABEL_SCORE2));
	pLabelScore2->SetText("0");
}
/*
 * 전송받은 카드 정보에 따라 초기 카드 세팅을 완료한다.
 */
void FormGameMulti::shuffleCard(String data)
{
	JsonObject* pJsonObj = parseJson(data);
	// 카드 데이터 입력
	for(int i=0 ; i<MAX_CARD_SIZE ; i++) {
		String *key = new String(Integer::ToString(i));
		Tizen::Web::Json::IJsonValue *pObjValue = null;
		pJsonObj->GetValue(key, pObjValue);
		Tizen::Web::Json::JsonString *pJsonStr = static_cast<Tizen::Web::Json::JsonString*>(pObjValue);
		String ch(pJsonStr->GetPointer());
		if(pObjValue!= null) delete pObjValue;
		delete key;

		cardChar[i] = ch;
		pButtonCard[i]->SetText(cardChar[i]);
	}

	Draw();
}
void FormGameMulti::onReadyToStart()
{
	multiController->readyForPlay();
	isClickable = false;
}
/*
 * 게임 진행 시간 Timer Label 설정
 */
result FormGameMulti::SetGameTimer(Tizen::Base::TimeSpan ts)
{
	result r = E_SUCCESS;

	return r;
}
/*
 * 스테이지 클리어 시 호출되는 함수(게임 종료)
 */
void FormGameMulti::onStageComplete()
{
	AppLog("============================================ Complete Stage ============================================");
	// 게임 종료, 승리

	isWin = true;

	//	gameScore, maxCombo

	//win = saveMyGrade(true);	// 게임 전적 저장 -> cloudSave
	// [Achievement] 멀티플레이 10승 달성
	/*GHAchievementController* Achievementcontroller = new GHAchievementController();
	if(multiplay_winNum >= 3)
	{
		Achievementcontroller->completeAchievement("4",this);
		AppLog("totalMis complete !!");
	}*/

}
/*
 * 카드 선택 시 상대방에게 전송
 */
void FormGameMulti::onTurnFinished(int actionType, int cardNum, bool isCorrect)
{
	int finished = 0;
	if(isComplete) {
		finished = 1;
	}
	String data("{\'actionType\':"+Integer::ToString(actionType)+ ",\'cardNum\':"+Integer::ToString(cardNum) +",\'score\':"+Integer::ToString(gameScore)
				+ ",\'isCorrect\':\'"+Boolean::ToString(isCorrect)+ "\'}");
	multiController->sendDataToPlayer(data, finished);
	AppLogDebug("%S", data.GetPointer());
}

// GHTurnbasedMatchListener
void FormGameMulti::onMatchConnect(){
	AppLogDebug("[onMatchConnect]");
}
void FormGameMulti::onMatchSetting(){
	AppLogDebug("[onMatchSetting]callback success");
	setInitialState();

	Tizen::Base::String data = "";
	data.Append("{");
	for(int i=0 ; i<MAX_CARD_SIZE ; i++) {
		data.Append("\'"+Integer::ToString(i)+"\':\'"+cardChar[i]+"\'");
		if(i != MAX_CARD_SIZE-1) {
			data.Append(",");
		} else {
			data.Append("}");
		}
	}
	multiController->sendDataToSetting(data);
}
void FormGameMulti::onMatchStart(String data){
	AppLogDebug("[onMatchStart] data : %S", data.GetPointer());
	shuffleCard(data);
	startInitState();

	pLabelMyTurn->SetShowState(false);
	pLabelYourTurn->SetShowState(true);
}
void FormGameMulti::onMatchMyturn(String data){
	AppLogDebug("[onMatchMyturn] %S", data.GetPointer());

	bool isMyTurn = false;
	if(data == "") {	// (최초 시작 시, 내 턴 지속 시)
		isMyTurn = true;
		if(isGameFirst) {
			isGameFirst = false;
			startMyTurnThread();
		}
	}
	else {
		JsonObject* pObject = parseJson(data);
		IJsonValue* pValue = null;

		// Score Setting
		pObject->GetValue(new String("score"), pValue);
		JsonNumber *pjScore = static_cast<JsonNumber*>(pValue);
		int iScore = pjScore->ToInt();
		delete pjScore;
		pLabelScore2->SetText(Integer::ToString(iScore));
		pLabelScore2->Draw();

		// Get ActionType
		pObject->GetValue(new String("actionType"), pValue);
		JsonNumber *pjActionType = static_cast<JsonNumber*>(pValue);
		int actionType = pjActionType->ToInt();
		delete pjActionType;

		// Get CardNum
		pObject->GetValue(new String("cardNum"), pValue);
		JsonNumber *pjCardNum = static_cast<JsonNumber*>(pValue);
		int cardNum = pjCardNum->ToInt();
		delete pjCardNum;

		// isFirstFlip
		if(actionType == 1) {
			AppLogDebug("actionType : 1");
			firstSelected = cardNum;
			setCardVisible(cardNum);	// flip card
			multiController->sendDataToPlayer("", 0);
		}
		// isSecondFlip, isCorrect
		else if(actionType == 2) {
			AppLogDebug("actionType : 2");
			secondSelected = cardNum;
			setCardVisible(cardNum);	// flip card

			// 맞으면 카드 제거
			pButtonCard[firstSelected]->SetShowState(false);
			pButtonCard[secondSelected]->SetShowState(false);

			countRemoved++;

			multiController->sendDataToPlayer("", 0);
		}
		// turnExpired, 틀리면
		else if(actionType == 3) {
			AppLogDebug("actionType : 3");
			if(cardNum >= 0 && cardNum < MAX_CARD_SIZE) {
				setCardVisible(cardNum);
			}
			onMyTurn = false;

			// 5초 Thread 시작
			startMyTurnThread();
		}
	}
}
void FormGameMulti::onMatchTurnWait(){
	AppLogDebug("[onMatchTurnWait]");
	isClickable = false;
}
void FormGameMulti::onMatchFinish(String data){
	AppLogDebug("[onMatchFinish]");

	// 마지막 턴 처리 --------------------------------------------
	if(data == "") {

	}else {
		JsonObject* pObject = parseJson(data);
		IJsonValue* pValue = null;

		// Score Setting
		pObject->GetValue(new String("score"), pValue);
		JsonNumber *pjScore = static_cast<JsonNumber*>(pValue);
		int iScore = pjScore->ToInt();
		delete pjScore;
		pLabelScore2->SetText(Integer::ToString(iScore));
		pLabelScore2->Draw();

		// Get ActionType
		pObject->GetValue(new String("actionType"), pValue);
		JsonNumber *pjActionType = static_cast<JsonNumber*>(pValue);
		int actionType = pjActionType->ToInt();
		delete pjActionType;

		// Get CardNum
		pObject->GetValue(new String("cardNum"), pValue);
		JsonNumber *pjCardNum = static_cast<JsonNumber*>(pValue);
		int cardNum = pjCardNum->ToInt();
		delete pjCardNum;

		// isFirstFlip
		if(actionType == 1) {
			AppLogDebug("actionType : 1");
			firstSelected = cardNum;
			setCardVisible(cardNum);	// flip card
		}
		// isSecondFlip, isCorrect
		else if(actionType == 2) {
			AppLogDebug("actionType : 2");
			secondSelected = cardNum;
			setCardVisible(cardNum);	// flip card

			// 맞으면 카드 제거
			pButtonCard[firstSelected]->SetShowState(false);
			pButtonCard[secondSelected]->SetShowState(false);

			countRemoved++;
		}
		// turnExpired, 틀리면
		else if(actionType == 3) {
			AppLogDebug("actionType : 3");
			if(cardNum >= 0 && cardNum < MAX_CARD_SIZE) {
				setCardVisible(cardNum);
			}
			onMyTurn = false;
		}
	}


	// -----------------------------------------------------------

	// Cloud Save ------------------------------------------------
	// 게임 전적 저장
	csController = new GHCloudsaveController();

	if(isWin) {
		int winNum;
		Integer::Parse(multiplay_winNum, winNum);

		// 승 증가
		winNum = winNum + 1;

		multiplay_winNum =Integer::ToString(winNum);
		csController->saveCloudSlotData(multiplay_winNum, 1, this);
	}else {

		int loseNum;
		Integer::Parse(multiplay_loseNum, loseNum);

		// 승 증가
		loseNum = loseNum + 1;

		multiplay_loseNum =Integer::ToString(loseNum);
		csController->saveCloudSlotData(multiplay_loseNum, 2, this);


	}

	// -----------------------------------------------------------

	GHAchievementController* Achievementcontroller = new GHAchievementController();

	AppLog("multiplay_winNum : %S ", multiplay_winNum.GetPointer());

	if(multiplay_winNum.CompareTo("5") == 0)  // 5 번 이기면 complete
	{
<<<<<<< HEAD
		Achievementcontroller->completeAchievement("4", this);
		AppLog("totalMis complete !!");
=======
		Achievementcontroller->completeAchievement("4",this);
		AppLog("multiplay_winNum complete !!");
>>>>>>> a4d8df9121ae4f116e4b092e59fb934848540937
	}

	// ---------------------------------------------------------

}


void FormGameMulti::completeAchievementFinished(int statusCode)
{
	AppLogDebug("[DEBUG] completeAchievementFinished statusCode ===> : %d", statusCode);
}

JsonObject* FormGameMulti::parseJson(String data)
{
	//포맷 변환 : String -> ByteBuffer
	ByteBuffer *pBuffer = new ByteBuffer();
	pBuffer->Construct(data.GetLength()+sizeof(wchar_t));
	for(int i=0 ; i<data.GetLength() ; i++) {
		wchar_t ch = null;
		data.GetCharAt(i, ch);
		if(ch == '\'') {
			ch = '\"';
		}
		pBuffer->SetWchar(i, ch);
	}
	pBuffer->SetWchar(data.GetLength(), '\n');

	// 포맷 변환 : ByteBuffer -> JsonObject
	IJsonValue *pValue = JsonParser::ParseN(*pBuffer);
	JsonObject* pJsonObj = static_cast<JsonObject*>(pValue);

	delete pBuffer;

	return pJsonObj;
}

void FormGameMulti::startMyTurnThread()
{
	// 카드 하나 선택 후 두번째 카드 선택 시 새로운 턴 시작을 방지
	if(onMyTurn) {
		return;
	}
	onMyTurn = true;
	pLabelMyTurn->SetShowState(true);
	pLabelYourTurn->SetShowState(false);

	Tizen::Base::TimeSpan uptime(0);
	Tizen::System::SystemTime::GetUptime(uptime);
	multiTick = uptime.GetTicks();
	pTimerMulti->Start(1000);
}

// cloud save
void FormGameMulti::saveCloudsaveFinished(int statusCode)
{
	AppLogDebug("saveCloudsaveFinished");
	if(statusCode != 0) {

		SceneManager* pSceneManager = SceneManager::GetInstance();
		AppAssert(pSceneManager);
		pSceneManager->GoBackward(BackwardSceneTransition(SCENE_TRANSITION_ANIMATION_TYPE_RIGHT));



	}
}

/*void FormGameMulti::completeAchievementFinished(int statusCode)
{
	AppLogDebug("[DEBUG] completeAchievementFinished statusCode : %d", statusCode);
}


void FormGameMulti::updateLeaderboardScoreFinished(int statusCode)
{
	AppLogDebug("[DEBUG] updateLeaderboardScoreFinished statusCode : %d", statusCode);

	if(statusCode == 1)
	{
		AppLogDebug("--------------> Update <-----------------");

	}
	else if(statusCode == 2)
	{
		AppLogDebug("--------------> No Update <-----------------");
	}
}*/
