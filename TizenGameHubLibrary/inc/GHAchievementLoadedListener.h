/*
 * GHAchievementsLoadedListener.h
 *
 *  Created on: Mar 27, 2014
 *      Author: KICHUL
 */

#ifndef GHACHIEVEMENTLOADEDLISTENER_H_
#define GHACHIEVEMENTLOADEDLISTENER_H_

#include <GHAchievement.h>

class GHAchievementLoadedListener {
public:
	GHAchievementLoadedListener();
	virtual ~GHAchievementLoadedListener();

	virtual void loadAchievementsFinished(GHAchievement* achievementArray) = 0;

};

#endif /* GHACHIEVEMENTSLOADEDLISTENER_H_ */
