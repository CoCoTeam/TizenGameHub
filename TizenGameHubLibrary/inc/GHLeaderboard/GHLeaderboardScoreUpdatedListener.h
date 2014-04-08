/*
 * GHLeaderboardScoreUpdatedListener.h
 *
 *  Created on: Apr 8, 2014
 *      Author: Administrator
 */

#ifndef GHLEADERBOARDSCOREUPDATEDLISTENER_H_
#define GHLEADERBOARDSCOREUPDATEDLISTENER_H_

#include "GHLeaderboard.h"
#include "GHLeaderboard/GHLeaderboardListener.h"

class GHLeaderboardScoreUpdatedListener
	: public GHLeaderboardListener
{
public:
	GHLeaderboardScoreUpdatedListener();
	virtual ~GHLeaderboardScoreUpdatedListener();

	virtual void updateLeaderboardScoreFinished(){};

private:
	virtual void loadLeaderboardFinished(Tizen::Base::Collection::ArrayList* leaderboardList) = 0;
	virtual void loadLeaderboardRankFinished()=0;
};

#endif /* GHLEADERBOARDSCOREUPDATEDLISTENER_H_ */
