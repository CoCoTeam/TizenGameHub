/*
 * GHAchievementController.cpp
 *
 *  Created on: Mar 26, 2014
 *      Author: JOHEEYEON
 */

#include "GHAchievement/GHAchievementController.h"

using namespace Tizen::Base::Collection;
using namespace Tizen::Net::Http;
using namespace Tizen::Web::Json;
using namespace Tizen::Base;

//game id: key_aa
//player id: pkeykichul

GHAchievementController::GHAchievementController() {
	// TODO Auto-generated constructor stub

}

GHAchievementController::~GHAchievementController() {
	// TODO Auto-generated destructor stub
}


// Achievement 목록을 가져온다.
void GHAchievementController::loadAchievements(GHAchievementLoadedListener* listener) {

	this->currentListener = listener;

	//GET 함수 호출
	String game_id("key_aa");
	String player_id("pkeykichul");
	String url(L"/f_achievements/" + game_id + "/" + player_id);
	httpPost.RequestHttpGetTran(this, url);
}

// hidden -> reveal 상태로 바꾼다.
void GHAchievementController::revealAchievement(String ac_id) {
	String game_id("key_aa");
	String player_id("pkeykichul");
	String url(L"/f_achievements/reveal");
	__pMap = new (std::nothrow) Tizen::Base::Collection::HashMap();
	__pMap->Construct();
	__pMap->Add(new String("game_id"), new String(game_id));
	__pMap->Add(new String("player_id"), new String(player_id));
	__pMap->Add(new String("ac_id"), new String(ac_id));

	httpPost.RequestHttpPutTran(this, url, __pMap);
}
void GHAchievementController::revealAchievement(String ac_id, GHAchievementRevealedListener* listener) {
	this->currentListener = listener;

	this->revealAchievement(ac_id);
}

// normal achievement update
void GHAchievementController::completeAchievement(String ac_id) {
	this->currentListener = null;

	String game_id("key_aa");
	String player_id("pkeykichul");
	String url(L"/f_achievements/complete");
	__pMap = new (std::nothrow) Tizen::Base::Collection::HashMap();
	__pMap->Construct();
	__pMap->Add(new String("game_id"), new String(game_id));
	__pMap->Add(new String("player_id"), new String(player_id));
	__pMap->Add(new String("ac_id"), new String(ac_id));

	httpPost.RequestHttpPutTran(this, url, __pMap);
}
void GHAchievementController::completeAchievement(String ac_id, GHAchievementCompletedListener* listener) {
	this->currentListener = listener;

	this->completeAchievement(ac_id);
}

// incremental achievement update
void GHAchievementController::setAchievement(String ac_id) {
	this->currentListener = null;

	String game_id("key_aa");
	String player_id("pkeykichul");


	String url(L"/f_achievements/set");
	__pMap = new (std::nothrow) Tizen::Base::Collection::HashMap();
	__pMap->Construct();
	__pMap->Add(new String("game_id"), new String(game_id));
	__pMap->Add(new String("player_id"), new String(player_id));
	__pMap->Add(new String("ac_id"), new String(ac_id));
	__pMap->Add(new String("point"), new String(Integer::ToString(10)));

	httpPost.RequestHttpPutTran(this, url, __pMap);
}
void GHAchievementController::setAchievement(String ac_id, GHAchievementSettedListener* listener) {
	this->currentListener = listener;
	this->setAchievement(ac_id);
}


// 모든 통신의 콜백에서 호출하는 함수
void GHAchievementController::OnTransactionReadyToRead(String apiCode, String statusCode, IJsonValue* data){

	AppLogDebug("[DEBUG] apiCode : %S", apiCode.GetPointer() );
	AppLogDebug("[DEBUG] statusCode : %S", statusCode.GetPointer() );


	if(apiCode.Equals(ACHIEVEMENT_LOAD)) {	// ACHIEVEMENT LOAD
		ArrayList* acArr;

		// 정상적으로 결과를 반환했을 때
		if(statusCode == "1") {
			JsonArray* 	pJsonArray 	= static_cast<JsonArray*>(data);
			int 		arrNum 		= pJsonArray->GetCount();
			acArr = new ArrayList();

			// KEY NAME
			String* pkeyId 			= new String(L"ac_id");
			String* pkeyTitle 		= new String(L"title");
			String* pkeyDesc 		= new String(L"description");
			String* pkeyImgUrl 		= new String(L"img_url");
			String* pkeyPrize 		= new String(L"prize");
			String* pkeyGoalPoint 	= new String(L"goal_point");
			String* pkeyIsComplete 	= new String(L"is_complete");
			String* pkeyIsHidden 	= new String(L"is_hidden");
			String* pkeyCurPoint 	= new String(L"cur_point");

			//AppLogDebug("[DEBUG] arrNum : %d", arrNum );

			for(int i=0; i<arrNum; i++) {
				JsonObject *pJsonOject 	= getJsonObjectByIndex(pJsonArray, i);

				// 데이터 파싱
				String  sId 			= getStringByKey(pJsonOject, pkeyId);
				String  sTitle 			= getStringByKey(pJsonOject, pkeyTitle);
				String  sDesc 			= getStringByKey(pJsonOject, pkeyDesc);
				String  sImgUrl 		= getStringByKey(pJsonOject, pkeyImgUrl);
				int iPrize 				= getIntByKey(pJsonOject, pkeyPrize);
				int iHidden 			= getIntByKey(pJsonOject, pkeyIsHidden);
				int iComplete 			= getIntByKey(pJsonOject, pkeyIsComplete);
				int iGoalPoint 			= getIntByKey(pJsonOject, pkeyGoalPoint);
				int iCurPoint 			= getIntByKey(pJsonOject, pkeyCurPoint);

				// 리스트에 추가
				acArr->Add(new GHAchievement(sId, sTitle, sDesc, sImgUrl, iPrize, iHidden, iComplete, iGoalPoint, iCurPoint));

			}

			// KEY NAME DELETE
			delete pkeyId; 			delete pkeyTitle;		delete pkeyDesc;	 delete pkeyImgUrl;		delete pkeyPrize;
			delete pkeyGoalPoint;	delete pkeyIsComplete;	delete pkeyIsHidden; delete pkeyCurPoint;

		}else { // 에러가 발생했을 때
			acArr = null;
		}

		if(this->currentListener != null) this->currentListener->loadAchievementFinished(acArr);

	} else if(apiCode.Equals(ACHIEVEMENT_REVEAL)) { // ACHIEVEMENT_REVEAL
		int stateCode;
		Integer::Parse(statusCode, stateCode);

		if(this->currentListener != null) this->currentListener->revealAchievementFinished(stateCode);

	} else if(apiCode.Equals(ACHIEVEMENT_COMPLETE)) { // ACHIEVEMENT_COMPLETE
		int stateCode;
		Integer::Parse(statusCode, stateCode);

		if(this->currentListener != null) this->currentListener->completeAchievementFinished(stateCode);

	} else if(apiCode.Equals(ACHIEVEMENT_SET)) { // ACHIEVEMENT_SET
		int stateCode;
		Integer::Parse(statusCode, stateCode);

		if(this->currentListener != null) this->currentListener->setAchievementFinished(stateCode);

	}



}
