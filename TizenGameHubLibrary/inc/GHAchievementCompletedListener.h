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


};

#endif /* GHACHIEVEMENTCOMPLETEDLISTENER_H_ */
