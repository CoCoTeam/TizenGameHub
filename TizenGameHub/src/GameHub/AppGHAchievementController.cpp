/*
 * AppGHAchievementController.cpp
 *
 *  Created on: May 9, 2014
 *      Author: Administrator
 */

#include "GameHub/AppGHAchievementController.h"

using namespace Tizen::Base;

AppGHAchievementController::AppGHAchievementController() {
	// TODO Auto-generated constructor stub

}

AppGHAchievementController::~AppGHAchievementController() {
	// TODO Auto-generated destructor stub
}

// Achievement 목록을 가져온다.
void AppGHAchievementController::loadAchievements(GHAchievementLoadedListener* listener, String game_id, String player_id)
{
	this->currentListener = listener;

	//GET 함수 호출
	String url(L"/f_achievements/" + game_id + "/" + player_id);
	httpPost.RequestHttpGetTran(this, url);
}
