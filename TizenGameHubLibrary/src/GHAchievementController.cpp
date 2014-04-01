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

	GHhttpClient* httpPost = new GHhttpClient();

	//GET 함수 호출
	String game_id("key_aa");
	String player_id("pkeykichul");
	httpPost->RequestHttpGetTran(this, new String(L"/f_achievements/" + game_id + "/" + player_id));
}

// hidden -> reveal 상태로 바꾼다.
void GHAchievementController::revealAchievement(STRING* id) {

}
void GHAchievementController::revealAchievement(GHAchievementListener* listener, STRING* id) {
	this->currentListener = listener;
}

// normal achievement update
void GHAchievementController::completeAchievement(STRING* id) {

}
void GHAchievementController::completeAchievement(GHAchievementListener* listener, STRING* id) {
	this->currentListener = listener;
}

// incremental achievement update
void GHAchievementController::increaseAchievement(STRING* id) {

}
void GHAchievementController::increaseAchievement(GHAchievementListener* listener, STRING* id) {
	this->currentListener = listener;
}


void GHAchievementController::OnTransactionReadyToRead(IJsonValue* data){
	// IJsonValue를 JsonArray로 변환한다. (배열인 경우)
	JsonArray* pJsonArray = static_cast<JsonArray*>(data);

	// 0번째 있는 배열의 값(JsonObject를 가지고 온다.)
	IJsonValue* pValue = null;
	pJsonArray->GetAt(0, pValue);
	JsonObject* pJsonObj = static_cast<JsonObject*>(pValue);

	// Key에 대한 값을 뽑는다.
	String  *pStrFNKey      = new String(L"img_url");
	IJsonValue* pObjValue = null;
	pJsonObj->GetValue(pStrFNKey, pObjValue);

	String  *pStrFNKey2      = new String(L"ac_id");
	IJsonValue* pObjValue2 = null;
	pJsonObj->GetValue(pStrFNKey2, pObjValue2);

	// 형변환 한다.
	JsonString* pJsonStr = static_cast<JsonString*>(pObjValue);
	JsonNumber* pJsonNum = static_cast<JsonNumber*>(pObjValue2);


	AppLogDebug("value : %S", pJsonStr->GetPointer());
	AppLogDebug("value : %d", pJsonNum->ToInt());
}
