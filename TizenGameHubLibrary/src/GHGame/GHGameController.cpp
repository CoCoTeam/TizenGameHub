/*
 * GHGameController.cpp
 *
 *  Created on: Apr 9, 2014
 *      Author: Administrator
 */

#include "GHGame.h"
#include "GHGame/GHGameController.h"

using namespace Tizen::Base;
using namespace Tizen::Base::Collection;
using namespace Tizen::Net::Http;
using namespace Tizen::Web::Json;

GHGameController::GHGameController() {
	// TODO Auto-generated constructor stub

}

GHGameController::~GHGameController() {
	// TODO Auto-generated destructor stub
}

// 게임 정보 가져오기
void GHGameController::getGameData(Tizen::Base::String gameId)
{
	//GET 함수 호출
	String url(L"/f_games/" + gameId);
	httpPost.RequestHttpGetTran(this, url);
}
void GHGameController::getGameData(Tizen::Base::String gameId, GHGameListener* listener)
{
	this->currentListener = listener;
	getGameData(gameId);
}

void GHGameController::OnTransactionReadyToRead(Tizen::Base::String apiCode, Tizen::Base::String statusCode, Tizen::Web::Json::IJsonValue* data)
{
	AppLogDebug("[DEBUG] apiCode : %S", apiCode.GetPointer() );
	AppLogDebug("[DEBUG] statusCode : %S", statusCode.GetPointer());

	if(apiCode.Equals(GAME_GAMEDATA)) {	// GAME_GAMEDATA
			GHGame *game;

			// 정상적으로 결과를 반환했을 때
			if(statusCode == "1") {

				JsonObject *pJsonOject 	= static_cast<JsonObject*>(data);

				AppLogDebug("---------------------------2-----------------------");
				String* pkeyId			= new String(L"game_id");
				String* pkeyTitle		= new String(L"title");
				String* pkeyImgUrl 		= new String(L"img_url");
				String* pkeyDesc		= new String(L"description");

				String* pkeyIsCloudsave	= new String(L"is_cloudsave");
				String* pkeyMultiEnable	= new String(L"is_multienable");
				String* pkeyLbCount		= new String(L"lb_count");
				String* pkeyAcCount		= new String(L"ac_count");
				String* pkeyAhCount		= new String(L"ah_count");

				String  sGameId		= getStringByKey(pJsonOject, pkeyId);
				String  sGameTitle	= getStringByKey(pJsonOject, pkeyTitle);
				String  sImgUrl 	= getStringByKey(pJsonOject, pkeyImgUrl);
				String  sDesc		= getStringByKey(pJsonOject, pkeyDesc);

				int  iLbCount		= getIntByKey(pJsonOject, pkeyLbCount);
				int  iAcCount 		= getIntByKey(pJsonOject, pkeyAcCount);
				int  iAhCount 		= getIntByKey(pJsonOject, pkeyAhCount);
				bool isCloudSave	= ( getIntByKey(pJsonOject, pkeyIsCloudsave) == 1 ? true : false );
				bool iMultiEnable	= ( getIntByKey(pJsonOject, pkeyMultiEnable) == 1 ? true : false );


				AppLogDebug("--------------------------------------------------");

				game = new GHGame(sGameId, "", sGameTitle, sDesc, sImgUrl, iLbCount, iAcCount, iAhCount, isCloudSave, iMultiEnable);

				// KEY NAME DELETE
				delete pkeyId;			delete pkeyTitle;
				delete pkeyImgUrl;	 	delete pkeyDesc;
				delete pkeyIsCloudsave;	delete pkeyMultiEnable;
				delete pkeyLbCount;	 	delete pkeyAcCount;
				delete pkeyAhCount;

			}
			else { // 에러가 발생했을 때
				game = null;
			}

			if(this->currentListener != null) this->currentListener->loadPlayerDataFinished(game);
	}
}
