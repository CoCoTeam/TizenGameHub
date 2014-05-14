/*
 * AppGHLeaderboardController.h
 *
 *  Created on: May 9, 2014
 *      Author: Administrator
 */

#ifndef APPGHLEADERBOARDCONTROLLER_H_
#define APPGHLEADERBOARDCONTROLLER_H_

#include <GHLeaderboard/GHLeaderboardController.h>

class AppGHLeaderboardController
	: public GHLeaderboardController
{
public:
	AppGHLeaderboardController();
	virtual ~AppGHLeaderboardController();

	void loadLeaderboards(GHLeaderboardListener * listener, Tizen::Base::String game_id);
	void loadLeaderboardRank(Tizen::Base::String game_id, Tizen::Base::String leaderboard_id, int startPosition=0, int loadSize=10);
	void loadLeaderboardRank(Tizen::Base::String game_id, Tizen::Base::String leaderboard_id, GHLeaderboardListLoadedListener * listener, int startPosition=0, int loadSize=10);
	void loadLeaderboardMyRank(Tizen::Base::String game_id, Tizen::Base::String leaderboardId, GHLeaderboardListLoadedListener * listener);
};

#endif /* APPGHLEADERBOARDCONTROLLER_H_ */
