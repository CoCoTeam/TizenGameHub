/*
 * GHGamePlayingFriendListener.h
 *
 *  Created on: May 13, 2014
 *      Author: Administrator
 */

#ifndef GHGAMEPLAYINGFRIENDLISTENER_H_
#define GHGAMEPLAYINGFRIENDLISTENER_H_

#include "GHGameListener.h"

class GHGamePlayingFriendListener
	: public virtual GHGameListener
{
public:
	GHGamePlayingFriendListener();
	virtual ~GHGamePlayingFriendListener();

	virtual void loadGamePlayingFriendFinished(Tizen::Base::Collection::ArrayList* friendsList)=0;
};

#endif /* GHGAMEPLAYINGFRIENDLISTENER_H_ */
