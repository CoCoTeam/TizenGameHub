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

	virtual void loadAchievementFinished(Tizen::Base::Collection::ArrayList* attackhelperList) = 0;
	virtual void setAchievementFinished(int statusCode) = 0;
	virtual void revealAchievementFinished(int statusCode) = 0;
	virtual void completeAchievementFinished(int statusCode) = 0;
};

#endif /* GHACHIEVEMENTLISTENER_H_ */
