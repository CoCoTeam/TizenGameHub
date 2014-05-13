/*
 * GHPlayerSearchFriendListener.h
 *
 *  Created on: May 12, 2014
 *      Author: Administrator
 */

#ifndef GHPLAYERSEARCHFRIENDLISTENER_H_
#define GHPLAYERSEARCHFRIENDLISTENER_H_

#include "GHPlayer.h"
#include "GHPlayer/GHPlayerListener.h"

class GHPlayerSearchFriendListener
	: public virtual GHPlayerListener
{
public:
	GHPlayerSearchFriendListener();
	virtual ~GHPlayerSearchFriendListener();

	virtual void searchFriendFinished(Tizen::Base::Collection::ArrayList* friendsList)=0;
};

#endif /* GHPLAYERSEARCHFRIENDLISTENER_H_ */
