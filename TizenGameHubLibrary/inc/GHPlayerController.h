/*
 * GHPlayerController.h
 *
 *  Created on: Apr 2, 2014
 *      Author: Administrator
 */

#ifndef GHPLAYERCONTROLLER_H_
#define GHPLAYERCONTROLLER_H_

#include <GHTizen.h>
#include <GHhttpClient.h>
#include <GHController.h>
#include <GHPlayer.h>

class GHPlayerController
	: public GHController
{
public:
	GHPlayerController();
	virtual ~GHPlayerController();

	// 사용자 로그인
	Tizen::Base::String playerLogin(Tizen::Base::String email, Tizen::Base::String pwd);
//	Tizen::Base::String playerLogin(Tizen::Base::String email, Tizen::Base::String pwd, GHPlayerListener* listener);

	// 사용자 정보 가져오기
	GHPlayer getPlayerData(Tizen::Base::String playerId);
//	GHPlayer getPlayerData(Tizen::Base::String playerId, GHPlayerListener* listener);

	// 사용자 로그아웃


	// 특정 게임에 사용자 등록하기(게임가입)


private:
	virtual void OnTransactionReadyToRead(Tizen::Web::Json::IJsonValue* data);
	Tizen::Base::Collection::HashMap* __pMap;
	GHLeaderboardListener* currentListener;
};

#endif /* GHPLAYERCONTROLLER_H_ */
