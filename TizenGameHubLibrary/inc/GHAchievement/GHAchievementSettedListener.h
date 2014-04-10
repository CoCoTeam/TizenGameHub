/*
 * GHAchievementSettedListener.h
 *
 *  Created on: Apr 8, 2014
 *      Author: KICHUL
 */

#ifndef GHACHIEVEMENTSETTEDLISTENER_H_
#define GHACHIEVEMENTSETTEDLISTENER_H_

#include "GHAchievementListener.h"

class GHAchievementSettedListener
	: public virtual GHAchievementListener {
public:
	GHAchievementSettedListener();
	virtual ~GHAchievementSettedListener();

	virtual void setAchievementFinished(int statusCode) = 0;

};

#endif /* GHACHIEVEMENTSETTEDLISTENER_H_ */
