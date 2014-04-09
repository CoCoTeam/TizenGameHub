/*
 * GHPlayerEdittedListener.h
 *
 *  Created on: Apr 8, 2014
 *      Author: Administrator
 */

#ifndef GHPLAYEREDITTEDLISTENER_H_
#define GHPLAYEREDITTEDLISTENER_H_

#include "GHPlayer.h"
#include "GHPlayer/GHPlayerListener.h"

class GHPlayerEdittedListener
	: public virtual GHPlayerListener
{
public:
	GHPlayerEdittedListener();
	virtual ~GHPlayerEdittedListener();
	virtual void editPlayerFinished(Tizen::Base::String statusCode)=0;
};

#endif /* GHPLAYEREDITTEDLISTENER_H_ */
