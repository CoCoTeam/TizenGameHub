/*
 * GHPlayerGamesLoadedListener.h
 *
 *  Created on: Apr 8, 2014
 *      Author: Administrator
 */

#ifndef GHPLAYERGAMESLOADEDLISTENER_H_
#define GHPLAYERGAMESLOADEDLISTENER_H_

#include "GHPlayer.h"
#include "GHPlayer/GHPlayerListener.h"

class GHPlayerGamesLoadedListener
	: public virtual GHPlayerListener
{
public:
	GHPlayerGamesLoadedListener();
	virtual ~GHPlayerGamesLoadedListener();
	virtual void loadPlayerGamesFinished(Tizen::Base::Collection::ArrayList* gameList)=0;
};

#endif /* GHPLAYERGAMESLOADEDLISTENER_H_ */
