/*
 * GHAchievementListener.h
 *
 *  Created on: Mar 28, 2014
 *      Author: KICHUL
 */

#ifndef GHACHIEVEMENTLISTENER_H_
#define GHACHIEVEMENTLISTENER_H_

#include "GHAchievement.h"

class GHAchievementListener {
public:
	GHAchievementListener();
	virtual ~GHAchievementListener();

	virtual void loadAchievementFinished(Tizen::Base::Collection::ArrayList* attackhelperList) {};
	virtual void setAchievementFinished(int statusCode) {};
	virtual void revealAchievementFinished(int statusCode) {};
	virtual void completeAchievementFinished(int statusCode) { AppLogDebug("[DEBUG]ACHIEVEMENT"); };
};

#endif /* GHACHIEVEMENTLISTENER_H_ */
