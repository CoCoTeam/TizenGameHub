/*
 * GHLeaderboardListener.h
 *
 *  Created on: Mar 28, 2014
 *      Author: Administrator
 */

#ifndef GHLEADERBOARDLISTENER_H_
#define GHLEADERBOARDLISTENER_H_

#include "GHLeaderboard.h"

class GHLeaderboardListener {
public:
	GHLeaderboardListener();
	virtual ~GHLeaderboardListener();

	virtual void loadLeaderboardFinished(Tizen::Base::Collection::ArrayList* leaderboardList){};
	virtual void loadLeaderboardRankFinished(GHLeaderboard* _leaderboard){};
	virtual void updateLeaderboardScoreFinished(int statusCode){};

};

#endif /* GHLEADERBOARDLISTENER_H_ */
