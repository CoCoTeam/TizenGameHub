/*
 * GHPlayerController.cpp
 *
 *  Created on: Apr 2, 2014
 *      Author: Administrator
 */

#include "GHGame/GHGame.h"
#include "GHSharedAuthData.h"
#include "GHPlayer/GHPlayerController.h"

using namespace Tizen::Base;
using namespace Tizen::Base::Collection;
using namespace Tizen::Net::Http;
using namespace Tizen::Web::Json;

GHPlayerController::GHPlayerController()
{
	// TODO Auto-generated constructor stub
	pProgressPopup = new (std::nothrow) Tizen::Ui::Controls::ProgressPopup();
	pProgressPopup->Construct(true, false);
//	pProgressPopup->AddProgressPopupEventListener(*this);
}

GHPlayerController::~GHPlayerController() {
	// TODO Auto-generated destructor stub
	if(pProgressPopup != null) {
		delete pProgressPopup;
	}
}
void GHPlayerController::OnProgressPopupCanceled()
{
	pProgressPopup->SetShowState(false);
}

bool GHPlayerController::isLogin(){
	String player_id(GHSharedAuthData::getSharedInstance().getPlayerId());
	if(player_id == "") {
		return false;
	}
	return true;
}

// 사용자 로그인 팝업 생성
void GHPlayerController::getLoginPopup(GHPlayerLoggedinListener* listener)
{
	Tizen::Ui::Controls::MessageBox msgBox;
	int modalResult;
	msgBox.Construct(L"Login", L"", Tizen::Ui::Controls::MSGBOX_STYLE_OKCANCEL);
	msgBox.SetSize(600, 800);

    Tizen::Ui::Controls::EditField* pTextEmail = new Tizen::Ui::Controls::EditField();
    pTextEmail->Construct(Tizen::Graphics::Rectangle(60, 110, 550, 65), Tizen::Ui::Controls::EDIT_FIELD_STYLE_EMAIL_SMALL);
    pTextEmail->SetGuideText(String("Email"));
	msgBox.AddControl(pTextEmail);

    Tizen::Ui::Controls::EditField* pTextPwd = new Tizen::Ui::Controls::EditField();
    pTextPwd->Construct(Tizen::Graphics::Rectangle(60, 185, 550, 65), Tizen::Ui::Controls::EDIT_FIELD_STYLE_PASSWORD);
    pTextPwd->SetGuideText(String("Password"));
	msgBox.AddControl(pTextPwd);

	msgBox.ShowAndWait(modalResult);

	switch (modalResult)
	{
	case Tizen::Ui::Controls::MSGBOX_RESULT_OK:
		{
			// login
			String email = pTextEmail->GetText();
			String pwd = pTextPwd->GetText();
			playerLogin(email, pwd, listener);
		}
		break;
	default:
		break;
	}
}
// 사용자 로그인
void GHPlayerController::playerLogin(GHPlayerLoggedinListener* listener)
{
	String email;
	String pwd;
	appReg.get(appReg.email, email);
	appReg.get(appReg.pwd, pwd);

	if(email != NULL && pwd != NULL) {
		AppLogDebug("%S", email.GetPointer());
		if(email != "") {
			playerLogin(email, pwd, listener);
			return ;
		}
	}

	getLoginPopup(listener);
	return ;
}
// 사용자 로그인
void GHPlayerController::playerLogin(Tizen::Base::String email, Tizen::Base::String pwd, GHPlayerLoggedinListener* listener)
{
	// Set current Listener
	this->currentListener = listener;

	// Do playerLogin--------------------------------------------------
	String url(L"/players/login");

	Tizen::Base::Collection::HashMap* __pMap = new (std::nothrow) Tizen::Base::Collection::HashMap();
	__pMap->Construct();
	__pMap->Add(new String("email"), new String(email));
	__pMap->Add(new String("pwd"), new String(pwd));
	if(String(GHSharedAuthData::getSharedInstance().getGameId()) != null) {
		__pMap->Add(new String("game_id"), new String(GHSharedAuthData::getSharedInstance().getGameId()));
	}

	playerEmail = email; playerPwd = pwd;

	//post 함수 호출
	httpPost.RequestHttpPostTran(this, url, __pMap);
	//----------------------------------------------------------------

	pProgressPopup->SetTitleText(L"Login...");
	pProgressPopup->SetText(L"Hello " + email);
	pProgressPopup->SetShowState(true);
	pProgressPopup->Show();
}

// 사용자 정보 가져오기
void GHPlayerController::getPlayerData(Tizen::Base::String playerId, GHPlayerLoadedListener* listener)
{
	// Set current Listener
	this->currentListener = listener;

	//GET 함수 호출
	String url(L"/players/" + playerId +"?req_id="+ GHSharedAuthData::getSharedInstance().getPlayerId());
	httpPost.RequestHttpGetTran(this, url);
}

// 사용자 로그아웃
void GHPlayerController::playerLogout()
{
	// Save AppRegistry Data(Email, Password)----------
	appReg.put(appReg.email, "");
	appReg.put(appReg.pwd, "");

	GHSharedAuthData::getSharedInstance().setPlayerId("");
}

// 특정 게임에 사용자 등록하기(게임가입)
void GHPlayerController::playerJoinToGame(Tizen::Base::String playerId, Tizen::Base::String gameId)
{
	String url(L"/players/gamejoin");

	Tizen::Base::Collection::HashMap* __pMap = new (std::nothrow) Tizen::Base::Collection::HashMap();
	__pMap->Construct();
	__pMap->Add(new String("player_id"), new String(playerId));
	__pMap->Add(new String("game_id"), new String(gameId));

	//post 함수 호출
	httpPost.RequestHttpPostTran(this, url, __pMap);
}

// 사용자가 플레이하는 게임 리스트 가져오기
void GHPlayerController::getPlayerGameList(Tizen::Base::String playerId, int start_pos, int max_length)
{
	String start_pos_str = Integer::ToString(start_pos);
	String max_length_str = Integer::ToString(max_length);
	String url(L"/players/" + playerId + "/games?start_pos=" + start_pos_str +"&max_length="+ max_length_str);

	httpPost.RequestHttpGetTran(this, url);
}
void GHPlayerController::getPlayerGameList(Tizen::Base::String playerId, GHPlayerGamesLoadedListener* listener, int start_pos, int max_length)
{
	this->currentListener = listener;
	this->getPlayerGameList(playerId, start_pos, max_length);
}

void GHPlayerController::searchFriend(Tizen::Base::String searchKey, GHPlayerSearchFriendListener* listener)
{
	// Set current Listener
	this->currentListener = listener;

	//GET 함수 호출
	String url(L"/players/search/" + searchKey);
	httpPost.RequestHttpGetTran(this, url);
}
void GHPlayerController::addFriend(Tizen::Base::String playerId, Tizen::Base::String friendEmail, GHPlayerAddFriendListener* listener)
{
	// Set current Listener
	this->currentListener = listener;

	__pMap = new (std::nothrow) Tizen::Base::Collection::HashMap();
	__pMap->Construct();
	__pMap->Add(new String("friend_email"), new String(friendEmail));

	//POST 함수 호출
	String url(L"/players/" + playerId + "/addfriend");
	httpPost.RequestHttpPostTran(this, url, __pMap);
}
// 사용자의 친구 리스트 불러오기
void GHPlayerController::getFriendsList(Tizen::Base::String player_id, int start_pos, int max_length)
{
	String url(L"/players/" + player_id + "/friends?start_pos=" + Integer::ToString(start_pos) +"&max_length="+ Integer::ToString(max_length));
	httpPost.RequestHttpGetTran(this, url);
}
void GHPlayerController::getFriendsList(Tizen::Base::String playerId, GHPlayerFriendsLoadedListener* listener, int start_pos, int max_length)
{
	this->currentListener = listener;
	this->getFriendsList(playerId, start_pos, max_length);
}

void GHPlayerController::OnTransactionReadyToRead(Tizen::Base::String apiCode, Tizen::Base::String statusCode, Tizen::Web::Json::IJsonValue* data)
{
	AppLogDebug("[DEBUG] apiCode : %S", apiCode.GetPointer() );
	AppLogDebug("[DEBUG] statusCode : %S", statusCode.GetPointer());

	if(pProgressPopup->IsVisible()) {
		pProgressPopup->SetShowState(false);
	}
	if(apiCode.Equals(PLAYER_LOGIN)) {
		// 정상적으로 결과를 반환했을 때
		if(statusCode != "0") {

			// Save AppRegistry Data(Email, Password)----------
			appReg.put(appReg.email, playerEmail);
			appReg.put(appReg.pwd, playerPwd);
			//------------------------------------------------

			GHSharedAuthData & sharedInstance = GHSharedAuthData::getSharedInstance();
			sharedInstance.setPlayerId(statusCode);

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
				String* pkeyIsFriend= new String(L"is_friend");

				String  sId 		= getStringByKey(pJsonOject, pkeyId);
				String  sEmail 		= getStringByKey(pJsonOject, pkeyEmail);
				String  sName		= getStringByKey(pJsonOject, pkeyName);
				String  sImgUrl 	= getStringByKey(pJsonOject, pkeyImgUrl);
				bool  	bIsFriend 	= getBoolByKey(pJsonOject, pkeyIsFriend);

				AppLogDebug("--------------------------------------------------");

				player = new GHPlayer(sId, sEmail, sName, sImgUrl);
				player->setIsFriend(bIsFriend);

				// KEY NAME DELETE
				delete pkeyId;		delete pkeyEmail;
				delete pkeyName;	delete pkeyImgUrl;
				delete pkeyIsFriend;

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
			String* pKeyGameDesc	= new String(L"description");

			AppLogDebug("[DEBUG] arrNum : %d", arrNum );

			for(int i=0; i<arrNum; i++) {
				JsonObject *pJsonOject 	= getJsonObjectByIndex(pJsonArray, i);

				// 데이터 파싱
				String  sGameId			= getStringByKey(pJsonOject, pKeyGameId);
				String  sGameTitle		= getStringByKey(pJsonOject, pKeyGameTitle);
				String  sGameImgUrl 	= getStringByKey(pJsonOject, pkeyGameImgUrl);
				String  sGameDesc	 	= getStringByKey(pJsonOject, pKeyGameDesc);

				// 리스트에 추가
				gameList->Add( new GHGame(sGameId, "", sGameTitle, sGameDesc, sGameImgUrl, 0, 0, 0, false, false) );
			}

			// KEY NAME DELETE
			delete pKeyGameId;		delete pKeyGameTitle;	 delete pkeyGameImgUrl;
		}
		else { // 에러가 발생했을 때
			gameList = null;
		}

		if(this->currentListener != null) this->currentListener->loadPlayerGamesFinished(gameList);


	}
	else if(apiCode.Equals(PLAYER_SEARCHFRIEND))
	{
		ArrayList *friendList;

		if(statusCode == "1") {
			JsonObject *pJsonOject 	= static_cast<JsonObject*>(data);
			friendList = new ArrayList();

			// KEY NAME
			String* pKeyPlayerId	= new String(L"player_id");
			String* pKeyPlayerEmail	= new String(L"email");
			String* pkeyPlayerName	= new String(L"name");
			String* pkeyPlayerImgUrl= new String(L"img_url");

			// 데이터 파싱
			String  sPlayerId		= getStringByKey(pJsonOject, pKeyPlayerId);
			String  sPlayerEmail	= getStringByKey(pJsonOject, pKeyPlayerEmail);
			String  sPlayerName		= getStringByKey(pJsonOject, pkeyPlayerName);
			String  sPlayerImgUrl 	= getStringByKey(pJsonOject, pkeyPlayerImgUrl);

			// 리스트에 추가
			friendList->Add( new GHPlayer(sPlayerId, sPlayerEmail, sPlayerName, sPlayerImgUrl) );

			// KEY NAME DELETE
			delete pKeyPlayerId;		delete pKeyPlayerEmail;
			delete pkeyPlayerName;		delete pkeyPlayerImgUrl;
		}
		else { // 에러가 발생했을 때
			friendList = null;
		}

		if(this->currentListener != null) this->currentListener->searchFriendFinished(friendList);
	}
	else if(apiCode.Equals(PLAYER_ADDFRIEND))
	{
		if(this->currentListener != null) this->currentListener->addFriendFinished(statusCode);
	}
	else if(apiCode.Equals(PLAYER_LOADFRIENDS))	// 친구 목록 불러오기
	{
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

		if(this->currentListener != null) this->currentListener->loadPlayerFriendsFinished(friendList);

	}
	else //PLAYER_LOGIN ,PLAYER_GAMEJOIN
	{
//		if(this->currentListener != null) this->currentListener->doPlayerFinished(statusCode);
	}
}
