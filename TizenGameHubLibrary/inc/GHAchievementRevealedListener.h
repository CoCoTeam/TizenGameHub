/*
 * GHAchievementRevealedListener.h
 *
 *  Created on: Apr 8, 2014
 *      Author: KICHUL
 */

#ifndef GHACHIEVEMENTREVEALEDLISTENER_H_
#define GHACHIEVEMENTREVEALEDLISTENER_H_

#include "GHAchievementListener.h"

class GHAchievementRevealedListener
	: public virtual GHAchievementListener {
public:
	GHAchievementRevealedListener();
	virtual ~GHAchievementRevealedListener();

	virtual void revealAchievementFinished(int statusCode) = 0;
private:
	virtual void loadAchievementFinished(Tizen::Base::Collection::ArrayList* attackhelperList){};
	virtual void setAchievementFinished(int statusCode){};
	virtual void completeAchievementFinished(int statusCode){};
};

#endif /* GHACHIEVEMENTREVEALEDLISTENER_H_ */
