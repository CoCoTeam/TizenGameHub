/*
 * GHLeaderboardMyRankLoadedListener.h
 *
 *  Created on: May 14, 2014
 *      Author: Administrator
 */

#ifndef GHLEADERBOARDMYRANKLOADEDLISTENER_H_
#define GHLEADERBOARDMYRANKLOADEDLISTENER_H_

#include "GHLeaderboardListener.h"

class GHLeaderboardMyRankLoadedListener
	: public virtual GHLeaderboardListener
{
public:
	GHLeaderboardMyRankLoadedListener();
	virtual ~GHLeaderboardMyRankLoadedListener();

	virtual void loadLeaderboardMyRankFinished(GHPlayerRank* pPlayerRank)=0;
};

#endif /* GHLEADERBOARDMYRANKLOADEDLISTENER_H_ */
