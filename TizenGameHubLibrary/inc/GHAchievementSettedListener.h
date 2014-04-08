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
private:
	virtual void loadAchievementFinished(Tizen::Base::Collection::ArrayList* attackhelperList){};
	virtual void revealAchievementFinished(int statusCode){};
	virtual void completeAchievementFinished(int statusCode){};
};

#endif /* GHACHIEVEMENTSETTEDLISTENER_H_ */
