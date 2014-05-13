/*
 * GHGameListener.h
 *
 *  Created on: Apr 9, 2014
 *      Author: Administrator
 */

#ifndef GHGAMELISTENER_H_
#define GHGAMELISTENER_H_

#include "GHGame.h"

class GHGameListener {
public:
	GHGameListener();
	virtual ~GHGameListener();

	virtual void loadPlayerDataFinished(GHGame* game){};
	virtual void loadGamePlayingFriendFinished(Tizen::Base::Collection::ArrayList* friendsList){};
};

#endif /* GHGAMELISTENER_H_ */
