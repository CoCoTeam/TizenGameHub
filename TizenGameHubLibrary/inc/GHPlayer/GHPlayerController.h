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


const Tizen::Base::String PLAYER_LOGIN = "02";
const Tizen::Base::String PLAYER_PLAYERDATA = "04";
const Tizen::Base::String PLAYER_GAMEJOIN = "05";
const Tizen::Base::String PLAYER_GAMELIST = "07";

class GHPlayerController
	: public GHController
{
public:
	GHPlayerController();
	virtual ~GHPlayerController();

	// 사용자 로그인
	void getLoginPopup(GHPlayerListener* listener = null);	// 사용자 로그인 팝업 생성
	void playerLogin(GHPlayerListener* listener = null);
	void playerLogin(Tizen::Base::String email, Tizen::Base::String pwd, GHPlayerListener* listener = null);

	// 사용자 정보 가져오기
//	void getPlayerData(Tizen::Base::String playerId);
	void getPlayerData(Tizen::Base::String playerId, GHPlayerListener* listener = null);

	// 사용자 로그아웃


	// 특정 게임에 사용자 등록하기(게임가입)
	void PlayerGameJoin(Tizen::Base::String playerId, Tizen::Base::String gameId);

	//사용자가 플레이하는 게임 리스트 가져오기
	void getPlayerGameList(Tizen::Base::String playerId);
	void getPlayerGameList(Tizen::Base::String playerId, int start_pos, int max_length);
	void getPlayerGameList(Tizen::Base::String playerId, GHPlayerListener* listener);
	void getPlayerGameList(Tizen::Base::String playerId, int start_pos, int max_length, GHPlayerListener* listener);
	/*
	 GET
	 /players/{player_id}/games	player_id {?start_pos=0 & max_length=5}
	 { apiCode:XX, statusCode:1, data[{game_id:"", title:"", img_url:""}, {}, ...] }
	*/


private:
	virtual void OnTransactionReadyToRead(Tizen::Base::String apiCode, Tizen::Base::String statusCode, Tizen::Web::Json::IJsonValue* data);
	Tizen::Base::Collection::HashMap* __pMap;
	GHPlayerListener* currentListener;

	GHAppRegistry appReg;
	Tizen::Base::String playerEmail, playerPwd;
	Tizen::Ui::Controls::ProgressPopup* pProgressPopup;
};

#endif /* GHPLAYERCONTROLLER_H_ */
