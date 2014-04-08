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

};

#endif /* GHACHIEVEMENTREVEALEDLISTENER_H_ */
