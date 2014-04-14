/*
 * GHLeaderboardListLoadedListener.h
 *
 *  Created on: Apr 8, 2014
 *      Author: Administrator
 */

#ifndef GHLEADERBOARDLISTLOADEDLISTENER_H_
#define GHLEADERBOARDLISTLOADEDLISTENER_H_

/*#include "GHLeaderboard.h"*/
#include "GHLeaderboard/GHLeaderboardListener.h"

class GHLeaderboardListLoadedListener
	: public virtual GHLeaderboardListener
{
public:
	GHLeaderboardListLoadedListener();
	virtual ~GHLeaderboardListLoadedListener();

	virtual void loadLeaderboardRankFinished(GHLeaderboard* _leaderboard)=0;

};

#endif /* GHLEADERBOARDLISTLOADEDLISTENER_H_ */
