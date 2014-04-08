/*
 * GHPlayerListener.h
 *
 *  Created on: Apr 3, 2014
 *      Author: Administrator
 */

#ifndef GHPLAYERLISTENER_H_
#define GHPLAYERLISTENER_H_

#include "GHPlayer.h"

class GHPlayerListener {
public:
	GHPlayerListener();
	virtual ~GHPlayerListener();

	virtual void joinPlayerFinished(Tizen::Base::String statusCode)=0;
	virtual void loginPlayerFinished(Tizen::Base::String statusCode)=0;
	virtual void editPlayerFinished(Tizen::Base::String statusCode)=0;
	virtual void joinPlayerGameFinished(Tizen::Base::String statusCode)=0;
	virtual void logoutPlayerFinished(Tizen::Base::String statusCode)=0;

	virtual void loadPlayerDataFinished(GHPlayer* player)=0;
	virtual void loadPlayerGamesFinished(Tizen::Base::Collection::ArrayList* gameList)=0;
	virtual void loadPlayerFriendsFinished(Tizen::Base::Collection::ArrayList* friendsList)=0;
};

#endif /* GHPLAYERLISTENER_H_ */
