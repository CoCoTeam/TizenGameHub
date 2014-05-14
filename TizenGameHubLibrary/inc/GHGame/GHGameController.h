/*
 * GHGameController.h
 *
 *  Created on: Apr 9, 2014
 *      Author: Administrator
 */

#ifndef GHGAMECONTROLLER_H_
#define GHGAMECONTROLLER_H_

#include "GHTizen.h"
#include "GHPlayer/GHPlayer.h"
#include "GHGame/GHGameListener.h"
#include "GHController.h"

const Tizen::Base::String GAME_GAMEDATA = "41";
const Tizen::Base::String GAME_GAMEFRIEND = "42";

class GHGameController
	: public GHController
{
public:
	GHGameController();
	virtual ~GHGameController();

	// 게임 정보 가져오기
	void getGameData(Tizen::Base::String gameId, GHGameListener* listener = null);

	// 게임을 플레이하는 친구 정보 가져오기
	void getGamePlayingFriends(Tizen::Base::String gameId, int start_pos=0, int max_length=8);
	void getGamePlayingFriends(Tizen::Base::String gameId, GHGameListener* listener, int start_pos=0, int max_length=8);

private:
	virtual void OnTransactionReadyToRead(Tizen::Base::String apiCode, Tizen::Base::String statusCode, Tizen::Web::Json::IJsonValue* data);
	Tizen::Base::Collection::HashMap* __pMap;
	GHGameListener* currentListener;
};

#endif /* GHGAMECONTROLLER_H_ */
