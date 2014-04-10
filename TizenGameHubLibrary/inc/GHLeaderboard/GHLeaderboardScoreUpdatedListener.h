/*
 * GHLeaderboardScoreUpdatedListener.h
 *
 *  Created on: Apr 8, 2014
 *      Author: Administrator
 */

#ifndef GHLEADERBOARDSCOREUPDATEDLISTENER_H_
#define GHLEADERBOARDSCOREUPDATEDLISTENER_H_

/*#include "GHLeaderboard.h"*/
#include "GHLeaderboard/GHLeaderboardListener.h"

class GHLeaderboardScoreUpdatedListener
	: public GHLeaderboardListener
{
public:
	GHLeaderboardScoreUpdatedListener();
	virtual ~GHLeaderboardScoreUpdatedListener();
	virtual void updateLeaderboardScoreFinished(int statusCode)=0;
};

#endif /* GHLEADERBOARDSCOREUPDATEDLISTENER_H_ */
