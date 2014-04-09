/*
 * GHPlayerController.cpp
 *
 *  Created on: Apr 2, 2014
 *      Author: Administrator
 */

#include "GHPlayer/GHPlayerController.h"
#include "GHGame.h"

using namespace Tizen::Base;
using namespace Tizen::Base::Collection;
using namespace Tizen::Net::Http;
using namespace Tizen::Web::Json;

GHPlayerController::GHPlayerController() {
	// TODO Auto-generated constructor stub

}

GHPlayerController::~GHPlayerController() {
	// TODO Auto-generated destructor stub
}

// 사용자 로그인
void GHPlayerController::playerLogin(Tizen::Base::String email, Tizen::Base::String pwd)
{
	String url(L"/players/login");

	Tizen::Base::Collection::HashMap* __pMap = new (std::nothrow) Tizen::Base::Collection::HashMap();
	__pMap->Construct();
	__pMap->Add(new String("email"), new String(email));
	__pMap->Add(new String("pwd"), new String(pwd));

	//post 함수 호출
	httpPost.RequestHttpPostTran(this, url, __pMap);
}
void GHPlayerController::playerLogin(Tizen::Base::String email, Tizen::Base::String pwd, GHPlayerListener* listener)
{
	this->currentListener = listener;
	this->playerLogin(email, pwd);
}

// 사용자 정보 가져오기
void GHPlayerController::getPlayerData(Tizen::Base::String playerId)
{
	//GET 함수 호출
	String url(L"/players/" + playerId);
	httpPost.RequestHttpGetTran(this, url);
}
void GHPlayerController::getPlayerData(Tizen::Base::String playerId, GHPlayerListener* listener)
{
	this->currentListener = listener;
	this->getPlayerData(playerId);
}

// 사용자 로그아웃


// 특정 게임에 사용자 등록하기(게임가입)
void GHPlayerController::PlayerGameJoin(Tizen::Base::String playerId, Tizen::Base::String gameId)
{
	String url(L"/players/gamejoin");

	Tizen::Base::Collection::HashMap* __pMap = new (std::nothrow) Tizen::Base::Collection::HashMap();
	__pMap->Construct();
	__pMap->Add(new String("player_id"), new String(playerId));
	__pMap->Add(new String("game_id"), new String(gameId));

	//post 함수 호출
	httpPost.RequestHttpPostTran(this, url, __pMap);
}

//사용자가 플레이하는 게임 리스트 가져오기
void GHPlayerController::getPlayerGameList(Tizen::Base::String playerId)
{
	getPlayerGameList(playerId, 0, 5);
}
void GHPlayerController::getPlayerGameList(Tizen::Base::String playerId, int start_pos, int max_length)
{
	Integer tmpInteger;
	String start_pos_str = tmpInteger.ToString(start_pos);
	String max_length_str = tmpInteger.ToString(max_length);
	String url(L"/players/" + playerId + "/games?start_pos=" + start_pos_str +"&max_length="+ max_length_str);
//	AppLogDebug("URL : %S", (new String(url))->GetPointer() );

	httpPost.RequestHttpGetTran(this, url);
}
void GHPlayerController::getPlayerGameList(Tizen::Base::String playerId, GHPlayerListener* listener)
{
	this->getPlayerGameList(playerId, 0, 5, listener);
}
void GHPlayerController::getPlayerGameList(Tizen::Base::String playerId, int start_pos, int max_length, GHPlayerListener* listener)
{
	this->currentListener = listener;
	this->getPlayerGameList(playerId, start_pos, max_length);
}


void GHPlayerController::OnTransactionReadyToRead(Tizen::Base::String apiCode, Tizen::Base::String statusCode, Tizen::Web::Json::IJsonValue* data)
{
	AppLogDebug("[DEBUG] apiCode : %S", apiCode.GetPointer() );
	AppLogDebug("[DEBUG] statusCode : %S", statusCode.GetPointer());

	if(apiCode.Equals(PLAYER_LOGIN)) {
		// 정상적으로 결과를 반환했을 때
		if(statusCode != "0") {
			if(this->currentListener != null) this->currentListener->loginPlayerFinished(statusCode);
		}
		else { // 에러가 발생했을 때
		}


	}
	else if(apiCode.Equals(PLAYER_PLAYERDATA)) {	// PLAYER_PLAYERDATA
			GHPlayer *player;

			// 정상적으로 결과를 반환했을 때
			if(statusCode == "1") {

				JsonObject *pJsonOject 	= static_cast<JsonObject*>(data);

				AppLogDebug("---------------------------2-----------------------");

				String* pkeyId		= new String(L"player_id");
				String* pkeyEmail 	= new String(L"email");
				String* pkeyName 	= new String(L"name");
				String* pkeyImgUrl 	= new String(L"img_url");

				String  sId 		= getStringByKey(pJsonOject, pkeyId);
				String  sEmail 		= getStringByKey(pJsonOject, pkeyEmail);
				String  sName		= getStringByKey(pJsonOject, pkeyName);
				String  sImgUrl 	= getStringByKey(pJsonOject, pkeyImgUrl);

				AppLogDebug("--------------------------------------------------");

				player = new GHPlayer(sId, sEmail, sName, sImgUrl);

				// KEY NAME DELETE
				delete pkeyId;			delete pkeyEmail;
				delete pkeyName;	 delete pkeyImgUrl;

			}
			else { // 에러가 발생했을 때
				player = null;
			}

			if(this->currentListener != null) this->currentListener->loadPlayerDataFinished(player);
	}
	else if(apiCode.Equals(PLAYER_GAMELIST))
	{
		ArrayList *gameList;

		// 정상적으로 결과를 반환했을 때
		if(statusCode == "1") {
			JsonArray* 	pJsonArray 	= static_cast<JsonArray*>(data);
			int 		arrNum 		= pJsonArray->GetCount();
			gameList = new ArrayList();

			// KEY NAME
			String* pKeyGameId 		= new String(L"game_id");
			String* pKeyGameTitle	= new String(L"title");
			String* pkeyGameImgUrl	= new String(L"img_url");

			AppLogDebug("[DEBUG] arrNum : %d", arrNum );

			for(int i=0; i<arrNum; i++) {
				JsonObject *pJsonOject 	= getJsonObjectByIndex(pJsonArray, i);

				// 데이터 파싱
				String  sGameId			= getStringByKey(pJsonOject, pKeyGameId);
				String  sGameTitle		= getStringByKey(pJsonOject, pKeyGameTitle);
				String  sGameImgUrl 	= getStringByKey(pJsonOject, pkeyGameImgUrl);

				// 리스트에 추가
				gameList->Add( new GHGame(sGameId, "", sGameTitle, "", sGameImgUrl, 0, 0, 0, false, false) );
			}

			// KEY NAME DELETE
			delete pKeyGameId;		delete pKeyGameTitle;	 delete pkeyGameImgUrl;
		}
		else { // 에러가 발생했을 때
			gameList = null;
		}

		if(this->currentListener != null) this->currentListener->loadPlayerGamesFinished(gameList);


	}
	else //PLAYER_LOGIN ,PLAYER_GAMEJOIN
	{
//		if(this->currentListener != null) this->currentListener->doPlayerFinished(statusCode);
	}
}
