/*
 * GHPlayerLoggedoutListener.h
 *
 *  Created on: Apr 8, 2014
 *      Author: Administrator
 */

#ifndef GHPLAYERLOGGEDOUTLISTENER_H_
#define GHPLAYERLOGGEDOUTLISTENER_H_

#include "GHPlayer.h"
#include "GHPlayer/GHPlayerListener.h"

class GHPlayerLoggedoutListener
	: public virtual GHPlayerListener
{
public:
	GHPlayerLoggedoutListener();
	virtual ~GHPlayerLoggedoutListener();
	virtual void logoutPlayerFinished(Tizen::Base::String statusCode)=0;
};

#endif /* GHPLAYERLOGGEDOUTLISTENER_H_ */
