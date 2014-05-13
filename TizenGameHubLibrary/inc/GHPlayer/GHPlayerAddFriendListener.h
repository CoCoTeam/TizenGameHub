/*
 * GHPlayerAddFriendListener.h
 *
 *  Created on: May 12, 2014
 *      Author: Administrator
 */

#ifndef GHPLAYERADDFRIENDLISTENER_H_
#define GHPLAYERADDFRIENDLISTENER_H_

#include "GHPlayer.h"
#include "GHPlayer/GHPlayerListener.h"

class GHPlayerAddFriendListener {
public:
	GHPlayerAddFriendListener();
	virtual ~GHPlayerAddFriendListener();
	virtual void addFriendFinished(Tizen::Base::String statusCode)=0;
};

#endif /* GHPLAYERADDFRIENDLISTENER_H_ */
