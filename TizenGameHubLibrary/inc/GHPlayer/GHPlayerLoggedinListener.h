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

private:
	virtual void joinPlayerFinished(Tizen::Base::String statusCode){};
	virtual void editPlayerFinished(Tizen::Base::String statusCode){};
	virtual void joinPlayerGameFinished(Tizen::Base::String statusCode){};
	virtual void logoutPlayerFinished(Tizen::Base::String statusCode){};

	virtual void loadPlayerDataFinished(GHPlayer* player){};
	virtual void loadPlayerGamesFinished(Tizen::Base::Collection::ArrayList* gameList){};
	virtual void loadPlayerFriendsFinished(Tizen::Base::Collection::ArrayList* friendsList){};
};

#endif /* GHPLAYERLOGGEDINLISTENER_H_ */
