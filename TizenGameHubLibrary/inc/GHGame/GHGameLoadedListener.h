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
	: public GHGameListener
{
public:
	GHGameLoadedListener();
	virtual ~GHGameLoadedListener();

	virtual void loadPlayerDataFinished(GHGame* game){};
};

#endif /* GHGAMELOADEDLISTENER_H_ */
