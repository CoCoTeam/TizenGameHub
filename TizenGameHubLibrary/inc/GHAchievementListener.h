/*
 * GHAchievementListener.h
 *
 *  Created on: Mar 28, 2014
 *      Author: KICHUL
 */

#ifndef GHACHIEVEMENTLISTENER_H_
#define GHACHIEVEMENTLISTENER_H_

#include <GHAchievement.h>

class GHAchievementListener {
public:
	GHAchievementListener();
	virtual ~GHAchievementListener();

	virtual void doAchievementFinished(int statusCode) = 0;
	virtual void doAchievementFinished(Tizen::Base::Collection::ArrayList* achievementList) = 0;
};

#endif /* GHACHIEVEMENTLISTENER_H_ */
