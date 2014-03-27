/*
 * GHAchievementsLoadedListener.h
 *
 *  Created on: Mar 27, 2014
 *      Author: KICHUL
 */

#ifndef GHACHIEVEMENTLOADEDLISTENER_H_
#define GHACHIEVEMENTLOADEDLISTENER_H_

#include <GHAchievement.h>
#include <GHAchievementListener.h>

class GHAchievementLoadedListener
	: public GHAchievementListener
{
public:
	GHAchievementLoadedListener();
	virtual ~GHAchievementLoadedListener();
	virtual void doAchievementFinished(GHAchievement* achievementArray) = 0;

private:
	void doAchievementFinished(int statusCode);
};

#endif /* GHACHIEVEMENTLOADEDLISTENER_H_ */
