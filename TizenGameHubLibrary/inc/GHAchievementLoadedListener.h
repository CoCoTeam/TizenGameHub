/*
 * GHAchievementsLoadedListener.h
 *
 *  Created on: Mar 27, 2014
 *      Author: KICHUL
 */

#ifndef GHACHIEVEMENTLOADEDLISTENER_H_
#define GHACHIEVEMENTLOADEDLISTENER_H_

#include "GHAchievementListener.h"

class GHAchievementLoadedListener
	:  public virtual GHAchievementListener {
public:
	GHAchievementLoadedListener();
	virtual ~GHAchievementLoadedListener();

	virtual void loadAchievementFinished(Tizen::Base::Collection::ArrayList* achievementList) = 0;
private:
	virtual void setAchievementFinished(int statusCode){};
	virtual void revealAchievementFinished(int statusCode){};
	virtual void completeAchievementFinished(int statusCode){};
};

#endif /* GHACHIEVEMENTLOADEDLISTENER_H_ */
