/*
 * GHPlayerController.h
 *
 *  Created on: Apr 2, 2014
 *      Author: Administrator
 */

#ifndef GHPLAYERCONTROLLER_H_
#define GHPLAYERCONTROLLER_H_

#include "GHTizen.h"
#include "GHAppRegistry.h"
#include "GHhttpClient.h"
#include "GHController.h"
#include "GHPlayer.h"
#include "GHPlayer/GHPlayerListener.h"
#include "GHPlayer/GHPlayerLoadedListener.h"
#include "GHPlayer/GHPlayerLoggedinListener.h"
#include "GHPlayer/GHPlayerGamesLoadedListener.h"
#include "GHPlayer/GHPlayerFriendsLoadedListener.h"
#include "GHPlayer/GHPlayerAddFriendListener.h"
#include "GHPlayer/GHPlayerSearchFriendListener.h"


const Tizen::Base::String PLAYER_LOGIN = "02";
const Tizen::Base::String PLAYER_PLAYERDATA = "04";
const Tizen::Base::String PLAYER_GAMEJOIN = "05";
const Tizen::Base::String PLAYER_GAMELIST = "07";
const Tizen::Base::String PLAYER_LOADFRIENDS = "08";
const Tizen::Base::String PLAYER_SEARCHFRIEND = "010";
const Tizen::Base::String PLAYER_ADDFRIEND = "011";

class GHPlayerController
	: public GHController
//	, public Tizen::Ui::IProgressPopupEventListener
{
public:
	GHPlayerController();
	virtual ~GHPlayerController();

	// 사용자 로그인 상태 리턴
	bool isLogin();

	// 사용자 로그인
	void playerLogin(GHPlayerLoggedinListener* listener = null);
	void playerLogin(Tizen::Base::String email, Tizen::Base::String pwd, GHPlayerLoggedinListener* listener = null);
	// 사용자 로그인 팝업 생성
	void getLoginPopup(GHPlayerLoggedinListener* listener = null);

	// 사용자 정보 가져오기
	void getPlayerData(Tizen::Base::String playerId, GHPlayerLoadedListener* listener = null);

	// 사용자 로그아웃
	void playerLogout();

	// 특정 게임에 사용자 등록하기(게임가입)
	void playerJoinToGame(Tizen::Base::String playerId, Tizen::Base::String gameId);

	//사용자가 플레이하는 게임 리스트 가져오기
	void getPlayerGameList(Tizen::Base::String playerId, int start_pos=0, int max_length=15);
	void getPlayerGameList(Tizen::Base::String playerId, GHPlayerGamesLoadedListener* listener, int start_pos=0, int max_length=15);

	// 친구 검색
	void searchFriend(Tizen::Base::String searchKey, GHPlayerSearchFriendListener* listener = null);
	// 친구 추가
	void addFriend(Tizen::Base::String playerId, Tizen::Base::String friendEmail, GHPlayerAddFriendListener* listener = null);
	// 사용자의 친구 리스트 불러오기
	void getFriendsList(Tizen::Base::String player_id, int start_pos=0, int max_length=15);
	void getFriendsList(Tizen::Base::String playerId, GHPlayerFriendsLoadedListener* listener, int start_pos=0, int max_length=15);

	//IProgressPopupEventListener
	virtual void OnProgressPopupCanceled();


private:
	virtual void OnTransactionReadyToRead(Tizen::Base::String apiCode, Tizen::Base::String statusCode, Tizen::Web::Json::IJsonValue* data);
	Tizen::Base::Collection::HashMap* __pMap;
	GHPlayerListener* currentListener;

	GHAppRegistry appReg;
	Tizen::Base::String playerEmail, playerPwd;
	Tizen::Ui::Controls::ProgressPopup* pProgressPopup;
};

#endif /* GHPLAYERCONTROLLER_H_ */
