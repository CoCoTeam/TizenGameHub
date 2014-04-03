/*
 * GHPlayerUpdatedListener.h
 *
 *  Created on: Apr 3, 2014
 *      Author: Administrator
 */

#ifndef GHPLAYERUPDATEDLISTENER_H_
#define GHPLAYERUPDATEDLISTENER_H_

#include <GHPlayer.h>
#include <GHPlayerListener.h>

class GHPlayerUpdatedListener
	: public virtual GHPlayerListener
{
public:
	GHPlayerUpdatedListener();
	virtual ~GHPlayerUpdatedListener();
	virtual void doPlayerFinished(int statusCode) = 0;

private:
	void doPlayerFinished(GHPlayer* playerArray);
};

#endif /* GHPLAYERUPDATEDLISTENER_H_ */
