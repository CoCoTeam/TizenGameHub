/*
 * GHAchievementsLoadedListener.h
 *
 *  Created on: Mar 27, 2014
 *      Author: KICHUL
 */

#ifndef GHACHIEVEMENTLOADEDLISTENER_H_
#define GHACHIEVEMENTLOADEDLISTENER_H_

#include <GHAchievement.h>

class GHAchievementLoadedListener
	:  public virtual GHAchievementListener
{
public:
	GHAchievementLoadedListener();
	virtual ~GHAchievementLoadedListener();
	virtual void doAchievementFinished(Tizen::Base::Collection::ArrayList* achievementList) = 0;
private:
};

#endif /* GHACHIEVEMENTLOADEDLISTENER_H_ */
