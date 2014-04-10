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
<<<<<<< HEAD
	virtual void updateLeaderboardScoreFinished(int statusCode)=0;
=======
	virtual void updateLeaderboardScoreFinished()=0;
>>>>>>> 31aa9f59fed02dd9d1fdb09822ecec66c5245d38
};

#endif /* GHLEADERBOARDSCOREUPDATEDLISTENER_H_ */
