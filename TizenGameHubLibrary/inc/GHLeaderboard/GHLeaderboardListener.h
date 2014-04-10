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
<<<<<<< HEAD
	virtual void loadLeaderboardRankFinished(Tizen::Base::Collection::ArrayList* Ranklist){};
	virtual void updateLeaderboardScoreFinished(int statusCode){};
=======
	virtual void loadLeaderboardRankFinished(){};
	virtual void updateLeaderboardScoreFinished(){};
>>>>>>> 31aa9f59fed02dd9d1fdb09822ecec66c5245d38

};

#endif /* GHLEADERBOARDLISTENER_H_ */
