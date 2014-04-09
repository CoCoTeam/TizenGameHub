/*
 * GHPlayerJoinedListener.h
 *
 *  Created on: Apr 8, 2014
 *      Author: Administrator
 */

#ifndef GHPLAYERJOINEDLISTENER_H_
#define GHPLAYERJOINEDLISTENER_H_

#include "GHPlayer.h"
#include "GHPlayer/GHPlayerListener.h"

class GHPlayerJoinedListener
	: public virtual GHPlayerListener
{
public:
	GHPlayerJoinedListener();
	virtual ~GHPlayerJoinedListener();
	virtual void joinPlayerFinished(Tizen::Base::String statusCode)=0;
};

#endif /* GHPLAYERJOINEDLISTENER_H_ */
