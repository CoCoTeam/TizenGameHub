/*
 * GHAchievementCompletedListener.h
 *
 *  Created on: Apr 8, 2014
 *      Author: KICHUL
 */

#ifndef GHACHIEVEMENTCOMPLETEDLISTENER_H_
#define GHACHIEVEMENTCOMPLETEDLISTENER_H_

#include "GHAchievementListener.h"

class GHAchievementCompletedListener
	: public virtual GHAchievementListener {
public:
	GHAchievementCompletedListener();
	virtual ~GHAchievementCompletedListener();

	virtual void completeAchievementFinished(int statusCode) = 0;

private:
	virtual void loadAchievementFinished(Tizen::Base::Collection::ArrayList* attackhelperList){};
	virtual void setAchievementFinished(int statusCode){};
	virtual void revealAchievementFinished(int statusCode){};
};

#endif /* GHACHIEVEMENTCOMPLETEDLISTENER_H_ */
