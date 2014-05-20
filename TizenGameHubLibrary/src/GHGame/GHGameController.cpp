/*
 * GHGameController.cpp
 *
 *  Created on: Apr 9, 2014
 *      Author: Administrator
 */

#include "GHGame/GHGame.h"
#include "GHGame/GHGameController.h"
#include "GHSharedAuthData.h"

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
void GHGameController::getGameData(Tizen::Base::String gameId, GHGameLoadedListener* listener)
{
	this->currentListener = listener;

	String player_id(GHSharedAuthData::getSharedInstance().getPlayerId());

	//GET 함수 호출
	String url(L"/f_games/" + gameId + "?player_id="+player_id);
	httpPost.RequestHttpGetTran(this, url);
}

// 게임을 플레이하는 친구 정보 가져오기
void GHGameController::getGamePlayingFriends(Tizen::Base::String gameId, int start_pos, int max_length)
{
	String player_id(GHSharedAuthData::getSharedInstance().getPlayerId());

	//GET 함수 호출
	String url(L"/f_games/" + gameId +"/"+ player_id +"/friends?start_pos="+Integer::ToString(start_pos) +"&max_length="+Integer::ToString(max_length));
	httpPost.RequestHttpGetTran(this, url);
}
void GHGameController::getGamePlayingFriends(Tizen::Base::String gameId, GHGamePlayingFriendListener* listener, int start_pos, int max_length)
{
	this->currentListener = listener;

	getGamePlayingFriends(gameId, start_pos, max_length);
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
				String* pkeyIsPlaying	= new String(L"is_playing");

				String  sGameId		= getStringByKey(pJsonOject, pkeyId);
				String  sGameTitle	= getStringByKey(pJsonOject, pkeyTitle);
				String  sImgUrl 	= getStringByKey(pJsonOject, pkeyImgUrl);
				String  sDesc		= getStringByKey(pJsonOject, pkeyDesc);

				int  iLbCount		= getIntByKey(pJsonOject, pkeyLbCount);
				int  iAcCount 		= getIntByKey(pJsonOject, pkeyAcCount);
				int  iAhCount 		= getIntByKey(pJsonOject, pkeyAhCount);
				bool isCloudSave	= getBoolByKey(pJsonOject, pkeyIsCloudsave);
				bool iMultiEnable	= getBoolByKey(pJsonOject, pkeyMultiEnable);
				bool iPlaying		= getBoolByKey(pJsonOject, pkeyIsPlaying);


				AppLogDebug("--------------------------------------------------");

				game = new GHGame(sGameId, "", sGameTitle, sDesc, sImgUrl, iLbCount, iAcCount, iAhCount, isCloudSave, iMultiEnable);
				game->setIsPlaying(iPlaying);

				// KEY NAME DELETE
				delete pkeyId;			delete pkeyTitle;
				delete pkeyImgUrl;	 	delete pkeyDesc;
				delete pkeyIsCloudsave;	delete pkeyMultiEnable;
				delete pkeyLbCount;	 	delete pkeyAcCount;
				delete pkeyAhCount;		delete pkeyIsPlaying;

			}
			else { // 에러가 발생했을 때
				game = null;
			}

			if(this->currentListener != null) this->currentListener->loadPlayerDataFinished(game);
	}
	else if(apiCode.Equals(GAME_GAMEFRIEND)) {	// GAME_GAMEFRIEND
		ArrayList *friendList;

		if(statusCode == "1") {
			JsonArray* 	pJsonArray 	= static_cast<JsonArray*>(data);
			int 		arrNum 		= pJsonArray->GetCount();
			friendList = new ArrayList();

			// KEY NAME
				String* pKeyPlayer		= new String(L"player_id");
				String* pKeyPlayerName	= new String(L"name");
				String* pkeyPlayerImgUrl= new String(L"img_url");

				AppLogDebug("[DEBUG] arrNum : %d", arrNum );

				for(int i=0; i<arrNum; i++) {
					JsonObject *pJsonOject 	= getJsonObjectByIndex(pJsonArray, i);

					// 데이터 파싱
					String  sPlayerId		= getStringByKey(pJsonOject, pKeyPlayer);
					String  sPlayerName		= getStringByKey(pJsonOject, pKeyPlayerName);
					String  sPlayerImgUrl 	= getStringByKey(pJsonOject, pkeyPlayerImgUrl);

					// 리스트에 추가
					friendList->Add( new GHPlayer(sPlayerId, sPlayerName, sPlayerImgUrl) );
				}

				// KEY NAME DELETE
				delete pKeyPlayer;		delete pKeyPlayerName;	 delete pkeyPlayerImgUrl;
		}
		else { // 에러가 발생했을 때
			friendList = null;
		}

		if(this->currentListener != null) this->currentListener->loadGamePlayingFriendFinished(friendList);
	}
}
