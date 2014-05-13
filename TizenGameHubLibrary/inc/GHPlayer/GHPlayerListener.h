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

	virtual void joinPlayerFinished(Tizen::Base::String statusCode){};
	virtual void loginPlayerFinished(Tizen::Base::String statusCode){};
	virtual void editPlayerFinished(Tizen::Base::String statusCode){};
	virtual void joinPlayerGameFinished(Tizen::Base::String statusCode){};
	virtual void logoutPlayerFinished(Tizen::Base::String statusCode){};

	virtual void loadPlayerDataFinished(GHPlayer* player){};
	virtual void loadPlayerGamesFinished(Tizen::Base::Collection::ArrayList* gameList){};
	virtual void loadPlayerFriendsFinished(Tizen::Base::Collection::ArrayList* friendsList){};

	virtual void searchFriendFinished(Tizen::Base::Collection::ArrayList* friendsList){};
	virtual void addFriendFinished(Tizen::Base::String statusCode){};
};

#endif /* GHPLAYERLISTENER_H_ */
