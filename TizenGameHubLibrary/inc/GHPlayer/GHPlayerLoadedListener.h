/*
 * GHPlayerLoadedListener.h
 *
 *  Created on: Apr 3, 2014
 *      Author: Administrator
 */

#ifndef GHPLAYERLOADEDLISTENER_H_
#define GHPLAYERLOADEDLISTENER_H_

#include "GHPlayer.h"
#include "GHPlayer/GHPlayerListener.h"

class GHPlayerLoadedListener
	: public virtual GHPlayerListener
{
public:
	GHPlayerLoadedListener();
	virtual ~GHPlayerLoadedListener();
	virtual void loadPlayerDataFinished(GHPlayer* player)=0;

private:
	virtual void joinPlayerFinished(Tizen::Base::String statusCode){};
	virtual void loginPlayerFinished(Tizen::Base::String statusCode){};
	virtual void editPlayerFinished(Tizen::Base::String statusCode){};
	virtual void joinPlayerGameFinished(Tizen::Base::String statusCode){};
	virtual void logoutPlayerFinished(Tizen::Base::String statusCode){};

	virtual void loadPlayerGamesFinished(Tizen::Base::Collection::ArrayList* gameList){};
	virtual void loadPlayerFriendsFinished(Tizen::Base::Collection::ArrayList* friendsList){};
};

#endif /* GHPLAYERLOADEDLISTENER_H_ */
