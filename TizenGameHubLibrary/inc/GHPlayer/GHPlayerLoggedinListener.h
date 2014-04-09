/*
 * GHPlayerLoggedinListener.h
 *
 *  Created on: Apr 8, 2014
 *      Author: Administrator
 */

#ifndef GHPLAYERLOGGEDINLISTENER_H_
#define GHPLAYERLOGGEDINLISTENER_H_

#include "GHPlayer.h"
#include "GHPlayer/GHPlayerListener.h"

class GHPlayerLoggedinListener
	: public virtual GHPlayerListener
{
public:
	GHPlayerLoggedinListener();
	virtual ~GHPlayerLoggedinListener();
	virtual void loginPlayerFinished(Tizen::Base::String statusCode)=0;
};

#endif /* GHPLAYERLOGGEDINLISTENER_H_ */
