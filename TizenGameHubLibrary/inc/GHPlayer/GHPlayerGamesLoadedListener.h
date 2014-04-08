/*
 * GHPlayerGamesLoadedListener.h
 *
 *  Created on: Apr 8, 2014
 *      Author: Administrator
 */

#ifndef GHPLAYERGAMESLOADEDLISTENER_H_
#define GHPLAYERGAMESLOADEDLISTENER_H_

#include "GHPlayer.h"
#include "GHPlayer/GHPlayerListener.h"

class GHPlayerGamesLoadedListener
	: public virtual GHPlayerListener
{
public:
	GHPlayerGamesLoadedListener();
	virtual ~GHPlayerGamesLoadedListener();

	virtual void loadPlayerGamesFinished(Tizen::Base::Collection::ArrayList* gameList)=0;

private:
	virtual void joinPlayerFinished(Tizen::Base::String statusCode){};
	virtual void loginPlayerFinished(Tizen::Base::String statusCode){};
	virtual void editPlayerFinished(Tizen::Base::String statusCode){};
	virtual void joinPlayerGameFinished(Tizen::Base::String statusCode){};
	virtual void logoutPlayerFinished(Tizen::Base::String statusCode){};

	virtual void loadPlayerDataFinished(GHPlayer* player){};
	virtual void loadPlayerFriendsFinished(Tizen::Base::Collection::ArrayList* friendsList){};
};

#endif /* GHPLAYERGAMESLOADEDLISTENER_H_ */
