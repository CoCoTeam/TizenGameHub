/*
 * GHPlayerLoadedListener.h
 *
 *  Created on: Apr 3, 2014
 *      Author: Administrator
 */

#ifndef GHPLAYERLOADEDLISTENER_H_
#define GHPLAYERLOADEDLISTENER_H_

#include "GHPlayer.h"
#include "GHPlayer/GHPlayerListener.h"

class GHPlayerLoadedListener
	: public virtual GHPlayerListener
{
public:
	GHPlayerLoadedListener();
	virtual ~GHPlayerLoadedListener();
	virtual void loadPlayerDataFinished(GHPlayer* player)=0;
};

#endif /* GHPLAYERLOADEDLISTENER_H_ */
