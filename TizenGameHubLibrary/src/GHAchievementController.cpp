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
void GHAchievementController::loadAchievements(GHAchievementListener* listener) {

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
void GHAchievementController::revealAchievement(String ac_id, GHAchievementListener* listener) {
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
void GHAchievementController::completeAchievement(String ac_id, GHAchievementListener* listener) {
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
void GHAchievementController::increaseAchievement(String ac_id, GHAchievementListener* listener) {
	this->currentListener = listener;
	this->increaseAchievement(ac_id);
}



// 모든 통신의 콜백에서 호출하는 함수
void GHAchievementController::OnTransactionReadyToRead(String apiCode, String statusCode, IJsonValue* data){


	// reveal, complete, increase TEST /////////////////////////////////////////////////////////
	//AppLogDebug("status : %S", statusCode);
	////////////////////////////////////////////////////////////////////////////////////////////



//	// load TEST /////////////////////////////////////////////////////////
//	// 0번째 있는 배열의 값(JsonObject를 가지고 온다.)
	JsonArray* jsonArray = static_cast<JsonArray*>(data);

	IJsonValue* pValue = null;
	jsonArray->GetAt(0, pValue);
	JsonObject* pJsonObj = static_cast<JsonObject*>(pValue);

	// Key에 대한 값을 뽑는다.
	String* pStrFNKey      = new String(L"img_url");
	IJsonValue* pObjValue = null;
	pJsonObj->GetValue(pStrFNKey, pObjValue);

	String* pStrFNKey2      = new String(L"ac_id");
	IJsonValue* pObjValue2 = null;
	pJsonObj->GetValue(pStrFNKey2, pObjValue2);

	// 형변환 한다.
	JsonString* pJsonStr = static_cast<JsonString*>(pObjValue);
	JsonNumber* pJsonNum = static_cast<JsonNumber*>(pObjValue2);

	AppLogDebug("value : %S", pJsonStr->GetPointer());
	AppLogDebug("value : %d", pJsonNum->ToInt());
//	///////////////////////////////////////////////////////////////////


	//리스너 호출
	if(this->currentListener != null){
		//currentListener->doAchievementFinished(atoi(statusCode.GetPointer()));
	}
}
