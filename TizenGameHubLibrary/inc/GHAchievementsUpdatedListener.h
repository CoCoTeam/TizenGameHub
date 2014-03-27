/*
 * GHAchievementsUpdatedListener.h
 *
 *  Created on: Mar 27, 2014
 *      Author: KICHUL
 */

#ifndef GHACHIEVEMENTSUPDATEDLISTENER_H_
#define GHACHIEVEMENTSUPDATEDLISTENER_H_

#include <GHAchievement.h>

class GHAchievementsUpdatedListener {
public:
	GHAchievementsUpdatedListener();
	virtual ~GHAchievementsUpdatedListener();

	virtual void updateAchievementsFinished() = 0;

};

#endif /* GHACHIEVEMENTSUPDATEDLISTENER_H_ */
