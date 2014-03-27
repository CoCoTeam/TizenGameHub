/*
 * GHAchievementsLoadedListener.h
 *
 *  Created on: Mar 27, 2014
 *      Author: KICHUL
 */

#ifndef GHACHIEVEMENTSLOADEDLISTENER_H_
#define GHACHIEVEMENTSLOADEDLISTENER_H_

#include <GHAchievement.h>

class GHAchievementsLoadedListener {
public:
	GHAchievementsLoadedListener();
	virtual ~GHAchievementsLoadedListener();

	virtual void loadAchievementsFinished(GHAchievement* achievementArray) = 0;

};

#endif /* GHACHIEVEMENTSLOADEDLISTENER_H_ */
