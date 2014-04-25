/*
 * GHGameController.h
 *
 *  Created on: Apr 9, 2014
 *      Author: Administrator
 */

#ifndef GHGAMECONTROLLER_H_
#define GHGAMECONTROLLER_H_

#include "GHTizen.h"
#include "GHGame/GHGameListener.h"
#include "GHController.h"

const Tizen::Base::String GAME_GAMEDATA = "41";

class GHGameController
	: public GHController
{
public:
	GHGameController();
	virtual ~GHGameController();

	// 게임 정보 가져오기
	void getGameData(Tizen::Base::String gameId);
	void getGameData(Tizen::Base::String gameId, GHGameListener* listener = null);

private:
	virtual void OnTransactionReadyToRead(Tizen::Base::String apiCode, Tizen::Base::String statusCode, Tizen::Web::Json::IJsonValue* data);
	Tizen::Base::Collection::HashMap* __pMap;
	GHGameListener* currentListener;
};

#endif /* GHGAMECONTROLLER_H_ */
