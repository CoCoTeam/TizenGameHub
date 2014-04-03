/*
 * GHPlayerListener.h
 *
 *  Created on: Apr 3, 2014
 *      Author: Administrator
 */

#ifndef GHPLAYERLISTENER_H_
#define GHPLAYERLISTENER_H_

class GHPlayerListener {
public:
	GHPlayerListener();
	virtual ~GHPlayerListener();

	virtual void doPlayerFinished(int statusCode) = 0;
	virtual void doPlayerFinished(GHPlayer* playerArray) = 0;
};
};

#endif /* GHPLAYERLISTENER_H_ */
