/*
 * GHAchievementController.cpp
 *
 *  Created on: Mar 26, 2014
 *      Author: JOHEEYEON
 */

#include "GHAchievementController.h"

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
void GHAchievementController::revealAchievement(String ac_id, GHAchievementUpdatedListener* listener) {
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
void GHAchievementController::completeAchievement(String ac_id, GHAchievementUpdatedListener* listener) {
	this->currentListener = listener;
	this->completeAchievement(ac_id);
}

// incremental achievement update
void GHAchievementController::increaseAchievement(String ac_id) {
	this->currentListener = null;
	String game_id("key_aa");
	String player_id("pkeykichul");
	String url(L"/f_achievements/set");
	__pMap = new (std::nothrow) Tizen::Base::Collection::HashMap();
	__pMap->Construct();
	__pMap->Add(new String("game_id"), new String(game_id));
	__pMap->Add(new String("player_id"), new String(player_id));
	__pMap->Add(new String("ac_id"), new String(ac_id));
	__pMap->Add(new String("point"), new Long(10));

	httpPost.RequestHttpPutTran(this, url, __pMap);
}
void GHAchievementController::increaseAchievement(String ac_id, GHAchievementUpdatedListener* listener) {
	this->currentListener = listener;
	this->increaseAchievement(ac_id);
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

		if(this->currentListener != null) this->currentListener->doAchievementFinished(acArr);

	} else { // ACHIEVEMENT_REVEAL, ACHIEVEMENT_COMPLETE, ACHIEVEMENT_SET
		int stateCode;
		Integer::Parse(statusCode, stateCode);

		if(this->currentListener != null) this->currentListener->doAchievementFinished(stateCode);
	}


	// reveal, complete, increase TEST /////////////////////////////////////////////////////////
//	String* pStrFNKey      = new String(L"statusCode");
//	IJsonValue* pObjValue = null;
//	data->GetValue(pStrFNKey, pObjValue);
//	JsonString* pJsonStr = static_cast<JsonString*>(pObjValue);
//	AppLogDebug("value : %S", pJsonStr->GetPointer());
	////////////////////////////////////////////////////////////////////////////////////////////



//	// load TEST /////////////////////////////////////////////////////////
//	// 0번째 있는 배열의 값(JsonObject를 가지고 온다.)
//
//	String* pStrDataKey     = new String(L"data");
//	IJsonValue* pDataValue = null;
//	data->GetValue(pStrDataKey, pDataValue);

//	JsonArray* jsonArray = static_cast<JsonArray*>(data);
//
//	IJsonValue* pValue = null;
//	jsonArray->GetAt(0, pValue);
//	JsonObject* pJsonObj = static_cast<JsonObject*>(pValue);
//
//	// Key에 대한 값을 뽑는다.
//	String* pStrFNKey      = new String(L"img_url");
//	IJsonValue* pObjValue = null;
//	pJsonObj->GetValue(pStrFNKey, pObjValue);
//
//	String* pStrFNKey2      = new String(L"ac_id");
//	IJsonValue* pObjValue2 = null;
//	pJsonObj->GetValue(pStrFNKey2, pObjValue2);
//
//	// 형변환 한다.
//	JsonString* pJsonStr = static_cast<JsonString*>(pObjValue);
//	JsonNumber* pJsonNum = static_cast<JsonNumber*>(pObjValue2);
//
//	// JsonString*을 String으로 변환한다.
//	//String zString(pJsonStr->GetPointer());
//
//	AppLogDebug("value : %S", pJsonStr->GetPointer());
//	AppLogDebug("value : %d", pJsonNum->ToInt());
//	///////////////////////////////////////////////////////////////////
}
