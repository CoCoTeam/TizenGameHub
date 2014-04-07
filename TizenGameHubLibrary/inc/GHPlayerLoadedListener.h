/*
 * GHPlayerLoadedListener.h
 *
 *  Created on: Apr 3, 2014
 *      Author: Administrator
 */

#ifndef GHPLAYERLOADEDLISTENER_H_
#define GHPLAYERLOADEDLISTENER_H_

#include <GHPlayer.h>
#include <GHPlayerListener.h>

class GHPlayerLoadedListener
	: public virtual GHPlayerListener
{
public:
	GHPlayerLoadedListener();
	virtual ~GHPlayerLoadedListener();
	virtual void doPlayerFinished(GHPlayer* playerArray) = 0;

private:
	void doPlayerFinished(Tizen::Base::String statusCode);
};

#endif /* GHPLAYERLOADEDLISTENER_H_ */
