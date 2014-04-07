/*
 * GHAchievementsUpdatedListener.h
 *
 *  Created on: Mar 27, 2014
 *      Author: KICHUL
 */

#ifndef GHACHIEVEMENTUPDATEDLISTENER_H_
#define GHACHIEVEMENTUPDATEDLISTENER_H_

#include <GHAchievement.h>

class GHAchievementUpdatedListener
	:  public virtual GHAchievementListener
{
public:
	GHAchievementUpdatedListener();
	virtual ~GHAchievementUpdatedListener();
	virtual void doAchievementFinished(int statusCode) = 0;
private:
};

#endif /* GHACHIEVEMENTUPDATEDLISTENER_H_ */
