/*
 * AppGHLeaderboardController.cpp
 *
 *  Created on: May 9, 2014
 *      Author: Administrator
 */

#include "AppGHLeaderboardController.h"
using namespace Tizen::Base;

AppGHLeaderboardController::AppGHLeaderboardController() {
	// TODO Auto-generated constructor stub

}

AppGHLeaderboardController::~AppGHLeaderboardController() {
	// TODO Auto-generated destructor stub
}

void AppGHLeaderboardController::loadLeaderboards(GHLeaderboardListener * listener, String game_id)
{
	this->currentListener = listener;

	//GET 함수 호출
	String url(L"/f_leaderboards/" + game_id);
	httpPost.RequestHttpGetTran(this, url);
}

void AppGHLeaderboardController::loadLeaderboardRank(String game_id, String leaderboard_id, int startPosition, int loadSize)
{
	this->currentListener = null;

	//GET 함수 호출
	String external(L"?start_pos="+Integer::ToString(startPosition)+"&max_length="+Integer::ToString(loadSize));
	String url(L"/f_leaderboards/rank/" + game_id +"/"+ leaderboard_id + external);
	AppLogDebug("%S", url.GetPointer());

	httpPost.RequestHttpGetTran(this, url);
}
void AppGHLeaderboardController::loadLeaderboardRank(String game_id, String leaderboard_id, GHLeaderboardListLoadedListener * listener, int startPosition, int loadSize)
{
	this->loadLeaderboardRank(game_id, leaderboard_id, startPosition, loadSize);
	this->currentListener = listener;
}
