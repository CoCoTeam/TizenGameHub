/*
 * GHLeaderboardDataLoadedListener.h
 *
 *  Created on: Apr 8, 2014
 *      Author: Administrator
 */

#ifndef GHLEADERBOARDDATALOADEDLISTENER_H_
#define GHLEADERBOARDDATALOADEDLISTENER_H_

#include "GHLeaderboard.h"
#include "GHLeaderboard/GHLeaderboardListener.h"

class GHLeaderboardDataLoadedListener
	: public GHLeaderboardListener
{
public:
	GHLeaderboardDataLoadedListener();
	virtual ~GHLeaderboardDataLoadedListener();

	virtual void loadLeaderboardFinished(Tizen::Base::Collection::ArrayList* leaderboardList){};

private:
	virtual void loadLeaderboardRankFinished()=0;
	virtual void updateLeaderboardScoreFinished()=0;
};

#endif /* GHLEADERBOARDDATALOADEDLISTENER_H_ */
