/*
 * GHLeaderboardListLoadedListener.h
 *
 *  Created on: Apr 8, 2014
 *      Author: Administrator
 */

#ifndef GHLEADERBOARDLISTLOADEDLISTENER_H_
#define GHLEADERBOARDLISTLOADEDLISTENER_H_

#include "GHLeaderboard.h"
#include "GHLeaderboard/GHLeaderboardListener.h"

class GHLeaderboardListLoadedListener
	: public GHLeaderboardListener
{
public:
	GHLeaderboardListLoadedListener();
	virtual ~GHLeaderboardListLoadedListener();

	virtual void loadLeaderboardRankFinished(){};

private:
	virtual void loadLeaderboardFinished(Tizen::Base::Collection::ArrayList* leaderboardList) = 0;
	virtual void updateLeaderboardScoreFinished()=0;
};

#endif /* GHLEADERBOARDLISTLOADEDLISTENER_H_ */
