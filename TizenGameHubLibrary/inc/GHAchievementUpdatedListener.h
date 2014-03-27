/*
 * GHAchievementsUpdatedListener.h
 *
 *  Created on: Mar 27, 2014
 *      Author: KICHUL
 */

#ifndef GHACHIEVEMENTUPDATEDLISTENER_H_
#define GHACHIEVEMENTUPDATEDLISTENER_H_

#include <GHAchievement.h>

class GHAchievementUpdatedListener {
public:
	GHAchievementUpdatedListener();
	virtual ~GHAchievementUpdatedListener();

	virtual void updateAchievementsFinished() = 0;

};

#endif /* GHACHIEVEMENTSUPDATEDLISTENER_H_ */
