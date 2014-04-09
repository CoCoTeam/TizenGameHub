/*
 * GHPlayerFriendsLoadedListener.h
 *
 *  Created on: Apr 8, 2014
 *      Author: Administrator
 */

#ifndef GHPLAYERFRIENDSLOADEDLISTENER_H_
#define GHPLAYERFRIENDSLOADEDLISTENER_H_

#include "GHPlayer.h"
#include "GHPlayer/GHPlayerListener.h"

class GHPlayerFriendsLoadedListener
	: public virtual GHPlayerListener
{
public:
	GHPlayerFriendsLoadedListener();
	virtual ~GHPlayerFriendsLoadedListener();
	virtual void loadPlayerFriendsFinished(Tizen::Base::Collection::ArrayList* friendsList)=0;
};

#endif /* GHPLAYERFRIENDSLOADEDLISTENER_H_ */
