#include "FormGame.h"

using namespace Tizen::Base;
using namespace Tizen::App;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Ui::Scenes;

const Tizen::Base::String CARD_SET_A[FormGame::MAX_CARD_SIZE/2] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J"};

FormGame::FormGame(void)
:gameTick(0),initTick(0),isClickable(false),isComplete(false),prevSelected(-1),countRemoved(0),isMultiplay(false),gameScore(0),combo(0), initialTime(0), initialScore(0), maxCombo(0)
{
}

FormGame::~FormGame(void)
{
}

bool
FormGame::Initialize(void)
{
	result r = Construct(IDL_FORM_GAME);
	TryReturn(r == E_SUCCESS, false, "Failed to construct form");

	return true;
}

result
FormGame::OnInitializing(void)
{
	result r = E_SUCCESS;

	// TODO: Add your initialization code here

	// Setup back event listener
	SetFormBackEventListener(this);

	// Get a button via resource ID
	for(int i=0 ; i<MAX_CARD_SIZE ; i++) {
		pButtonCard[i] = static_cast< Button* >(GetControl(i));
		if(pButtonCard[i] != null) {
			pButtonCard[i]->SetActionId(IDA_CARD_BASE+i);
			pButtonCard[i]->AddActionEventListener(*this);
		}
	}
	pLabelTimer = static_cast< Label* >(GetControl(IDC_GAME_LABEL_TIMER));
	pLabelCount = static_cast< Label* >(GetControl(IDC_GAME_LABEL_COUNT));
	pLabelScore = static_cast< Label* >(GetControl(IDC_GAME_LABEL_SCORE));

	pLabelMyTurn = static_cast< Label* >(GetControl(IDC_GAME_LABEL_MYTURN));
	pLabelYourTurn = static_cast< Label* >(GetControl(IDC_GAME_LABEL_OTHERTURN));
	pLabelMyTurn->SetShowState(false);
	pLabelYourTurn->SetShowState(false);

	setTimer();

	if(!isMultiplay) {
		setInitialState();
	}
	// 멀티 플레이 전용 추가 초기 세팅
	setAdditionalInitialState();

	return r;
}

result
FormGame::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here
	if(pTimerGame != null) {
		delete pTimerGame;
	}
	if(pTimerInit != null) {
		delete pTimerInit;
	}
	if(pTimerCompare != null) {
		delete pTimerCompare;
	}
	if(pTimerFlip != null) {
		delete pTimerFlip;
	}
	if(isMultiplay && pTimerMulti != null) {
		delete pTimerMulti;
	}

	return r;
}

void
FormGame::OnActionPerformed(const Tizen::Ui::Control& source, int actionId)
{
	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);

	switch(actionId)
	{
	default:
		if(actionId >= IDA_CARD_BASE && isClickable) {
			int cardNum = actionId - IDA_CARD_BASE;
			setCardVisible(cardNum);

			if(prevSelected == -1) {	// (첫번째 카드 선택 시)
				prevSelected = cardNum;
				onTurnFinished(1, cardNum, false);

				// Flip Thread start (3초 내 미 선택 시 턴 종료, prevSelected -1로 세팅)
				Tizen::Base::TimeSpan uptime(0);
				flipTick = uptime.GetTicks();
				if(!isMultiplay) {
					pTimerFlip->Start(3000);
				}
			}
			else {	// (두번째 카드 선택 시) 카드 비교

				// 이전카드와 동일한 카드 선택 막기
				if(cardNum == prevSelected) {
					break;
				}

				nowSelected = cardNum;

				isClickable = false;
				onMyTurn = false;

				// FlipTimer 정지
				if(!isMultiplay) {
					pTimerFlip->Cancel();
				} else {
					pTimerMulti->Cancel();
				}
				pLabelCount->SetText("");
				pLabelCount->Draw();

				// 1초간 wait
				Tizen::Base::TimeSpan uptime(0);
				compareTick = uptime.GetTicks();
				pTimerCompare->Start(1000);
			}
		}
		break;
	}
}

void
FormGame::OnFormBackRequested(Tizen::Ui::Controls::Form& source)
{
	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);
	pSceneManager->GoBackward(BackwardSceneTransition(SCENE_TRANSITION_ANIMATION_TYPE_DEPTH_OUT));
}

/*
 * Timer 변수를 초기화한다.
 */
void FormGame::setTimer()
{
	// Set Game Timer
	pTimerGame = new (std::nothrow) Tizen::Base::Runtime::Timer();
	pTimerGame->Construct(*this);

	// Set Init state Timer
	pTimerInit = new (std::nothrow) Tizen::Base::Runtime::Timer();
	pTimerInit->Construct(*this);

	// Set Card Compare Timer
	pTimerCompare = new (std::nothrow) Tizen::Base::Runtime::Timer();
	pTimerCompare->Construct(*this);

	// Set Card Flip Timer
	pTimerFlip = new (std::nothrow) Tizen::Base::Runtime::Timer();
	pTimerFlip->Construct(*this);

	if(isMultiplay) {
		pTimerMulti = new (std::nothrow) Tizen::Base::Runtime::Timer();
		pTimerMulti->Construct(*this);
	}
}
/*
 * Timer 동작 시 호출되는 함수
 */
void FormGame::OnTimerExpired(Tizen::Base::Runtime::Timer& timer)
{
	TimeSpan span = null;
	if( timer.Equals(*pTimerGame) ) {
		if(!isMultiplay) {
			span = getCurrentTimeSpan(gameTick);
			SetGameTimer(span);
		}
	}
	else if( timer.Equals(*pTimerInit) ) {
		span = getCurrentTimeSpan(initTick);

		if( span.GetSeconds() < 3 ) {

			String __watchText;
			__watchText.Clear();
			__watchText.Append(3-span.GetSeconds());
			pLabelCount->SetText(__watchText);
			pLabelCount->Draw();

			pTimerInit->Start(1000);
		}
		if( span.GetSeconds() == 3 ) {
			pLabelCount->SetText("");
			pLabelCount->Draw();

			startGame();
		}
	}
	else if( timer.Equals(*pTimerCompare) ) {
		compareCard();
	}
	else if( timer.Equals(*pTimerFlip) ) {
		if(isClickable) {
			// 다시 뒤집기
			setCardVisible(prevSelected, false);

			// 턴 종료
			onTurnExpired();
		}
	}
	else if( timer.Equals(*pTimerMulti) ) {
		span = getCurrentTimeSpan(multiTick);

		if( span.GetSeconds() == 1) {

			// 틀리면 카드 다시 뒤집기
			for(int i=0 ; i<MAX_CARD_SIZE ; i++) {
				if(pButtonCard[i]->GetShowState()) {
					setCardVisible(i, false);
				}
			}
		}
		if( span.GetSeconds() < 4 ) {
			isClickable = true;

			String __watchText;
			__watchText.Clear();
			__watchText.Append(4-span.GetSeconds());
			pLabelCount->SetText(__watchText);
			pLabelCount->Draw();

			pTimerMulti->Start(1000);
		}
		else if( span.GetSeconds() == 4 ) {
			pLabelCount->SetText("");
			pLabelCount->Draw();

			// 틀리면 카드 다시 뒤집기
			for(int i=0 ; i<MAX_CARD_SIZE ; i++) {
				if(pButtonCard[i]->GetShowState()) {
					setCardVisible(i, false);
				}
			}
			onMyTurn = false;

			onTurnExpired();
		}
	}
}
/*
 * 각 Timer에 해당하는 경과 시간(TimeSpan)을 리턴한다.
 * prevTick : 최초 기준 시간(tick)
 */
TimeSpan FormGame::getCurrentTimeSpan(long long prevTick) {
	// Get current tick value
	Tizen::Base::TimeSpan uptime(0);
	result r = Tizen::System::SystemTime::GetUptime(uptime);
	if (IsFailed(r))
	{
		AppLog("System uptime not available\n");
	}
	long long tick = uptime.GetTicks();
	tick -= prevTick;
	TimeSpan span = static_cast<long>(tick);

	return span;
}
void FormGame::setTimeLabel(Tizen::Base::TimeSpan span)
{
	String __watchText;
	__watchText.Clear();
	if(span.GetMinutes() < 10) {
		__watchText.Append("0");
	}
	__watchText.Append(span.GetMinutes()); __watchText.Append(":");
	if(span.GetSeconds() < 10) {
		__watchText.Append("0");
	}
	__watchText.Append(span.GetSeconds()); __watchText.Append(":");
	if(span.GetMilliseconds() / 10 < 10) {
		__watchText.Append("0");
	}
	__watchText.Append(span.GetMilliseconds() / 10);

	pLabelTimer->SetText(__watchText);
	pLabelTimer->Invalidate(false);
	pLabelTimer->Show();
}
/*
 * 초기 상태(카드 보여주기) 설정
 */
result FormGame::setInitialState()
{
	result r = E_SUCCESS;

	isClickable = false;
	isComplete = false;
	countRemoved = 0;

	pLabelCount->SetText("3");
	pLabelCount->Draw();

	shuffleCard();

	if(!isMultiplay) {
		setTimeLabel(initialTime);
		startInitState();
	}

	return r;
}
/*
 * 카드를 섞어 랜덤으로 배치한다.
 */
void FormGame::shuffleCard()
{
	int setCount = 0;
	bool isSet[MAX_CARD_SIZE] = {false,};
	int settingNum = 0;

	// 전부 다 세팅 될 동안
	while(setCount < 20) {
		// 랜덤 돌려서 세팅할 카드 선택
		int selectedCardNum = (rand() % 20);

		// 세팅 안된 카드면
		if( !isSet[selectedCardNum] ) {
			// 카드 세팅
			cardChar[selectedCardNum] = CARD_SET_A[(settingNum++)/2];
			pButtonCard[selectedCardNum]->SetText(cardChar[selectedCardNum]);
			isSet[selectedCardNum] = true;

			// 세팅 카운트 증가
			setCount++;
		}
	}
	Draw();
}
void FormGame::startInitState()
{
	Tizen::Base::TimeSpan uptime(0);
	Tizen::System::SystemTime::GetUptime(uptime);
	initTick = uptime.GetTicks();
	pTimerInit->Start(1000);
}

/*
 * 초기 상태 이후 게임을 시작한다.
 */
result FormGame::startGame()
{
	//!!! 카드 전체 뒤집어서 안보이게
	for(int i=0 ; i<MAX_CARD_SIZE ; i++) {
//		setCardVisible(i, false);
	}

	// 카드 선택 가능하게(게임 시작)
	if(!isMultiplay) {
		isClickable = true;
	} else {
		onReadyToStart();
	}

	Tizen::Base::TimeSpan uptime(0);
	result r = Tizen::System::SystemTime::GetUptime(uptime);
	if (IsFailed(r))
	{
		AppLog("System uptime not available\n");
		return r;
	}

	gameTick = uptime.GetTicks();
	pTimerGame->Start(10);
	return r;
}
void FormGame::setCardVisible(int cardNum, bool visibility)
{
	if(visibility) {
		pButtonCard[cardNum]->SetText(cardChar[cardNum]);
	}
	else {
		pButtonCard[cardNum]->SetText("");
	}
	pButtonCard[cardNum]->Draw();
}

void FormGame::removeCard()
{
	pButtonCard[prevSelected]->SetShowState(false);
	pButtonCard[nowSelected]->SetShowState(false);
	Draw();
}
void FormGame::compareCard()
{
	if(cardChar[prevSelected] == cardChar[nowSelected]) {
		removeCard();

		// 점수 증가
		gameScore += (200 + 10 * (combo*combo));
		setGameScore();
		if(maxCombo <= ++combo) {
			maxCombo = combo;
		}

		// 스테이지 클리어 조건 체크
		if(++countRemoved >= (MAX_CARD_SIZE/2)) {
			if(isMultiplay) {
				pTimerMulti->Cancel();
			} else {
				pTimerGame->Cancel();
			}
			isComplete = true;

			// 스테이지 클리어 점수 증가
			gameScore += 1000;

			// 스테이지 클리어 시 호출
			onStageComplete();
		}

		onTurnFinished(2, nowSelected, true);
		nowSelected = -1;

		if(!isComplete) {
			startMyTurnThread();
		}
	}
	else {
		// 다시 뒤집기
		setCardVisible(prevSelected, false);
		setCardVisible(nowSelected, false);

		onTurnExpired();
		nowSelected = -1;
	}
	prevSelected = -1;
	isClickable = true;


}
void FormGame::onTurnExpired()
{
	// 점수 감소
	gameScore -= 30;
	if(gameScore < 0) {
		gameScore = 0;
	}
	setGameScore();
	combo = 0;

	// (멀티 플레이 시) 사용자 턴 종료
	if(isMultiplay) {
		onTurnFinished(3, nowSelected, false);

		pLabelMyTurn->SetShowState(false);
		pLabelYourTurn->SetShowState(true);
	}

	prevSelected = -1;
	isClickable = true;
}
void FormGame::setGameScore()
{
	String textScore;
	textScore.Clear();
	textScore.Append(gameScore);
	pLabelScore->SetText(textScore);
	pLabelScore->Draw();
}














