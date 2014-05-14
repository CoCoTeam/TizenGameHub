/*
 * GHGameLoadedListener.h
 *
 *  Created on: Apr 9, 2014
 *      Author: Administrator
 */

#ifndef GHGAMELOADEDLISTENER_H_
#define GHGAMELOADEDLISTENER_H_

#include "GHGame.h"
#include "GHGame/GHGameListener.h"

class GHGameLoadedListener
	: public virtual GHGameListener
{
public:
	GHGameLoadedListener();
	virtual ~GHGameLoadedListener();

	virtual void loadPlayerDataFinished(GHGame* game)=0;
};

#endif /* GHGAMELOADEDLISTENER_H_ */
