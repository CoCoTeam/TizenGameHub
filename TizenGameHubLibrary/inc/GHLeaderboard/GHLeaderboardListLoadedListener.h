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
	: public GHLeaderboardListener
{
public:
	GHLeaderboardListLoadedListener();
	virtual ~GHLeaderboardListLoadedListener();
<<<<<<< HEAD
	virtual void loadLeaderboardRankFinished(Tizen::Base::Collection::ArrayList* Ranklist)=0;
=======
	virtual void loadLeaderboardRankFinished()=0;
>>>>>>> 31aa9f59fed02dd9d1fdb09822ecec66c5245d38
};

#endif /* GHLEADERBOARDLISTLOADEDLISTENER_H_ */
