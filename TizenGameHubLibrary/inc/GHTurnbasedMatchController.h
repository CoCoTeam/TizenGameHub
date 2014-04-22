/*
 * GHTurnBasedMatch.h
 *
 *  Created on: Apr 17, 2014
 *      Author: KICHUL
 */

#ifndef GHTURNBASEDMATCHCONTROLLER_H_
#define GHTURNBASEDMATCHCONTROLLER_H_

#include "GHSocket.h"
#include "GHTurnbasedMatchListener.h"

class GHTurnbasedMatchController
	: public GHSocket
{
public:
	GHTurnbasedMatchController();
	virtual ~GHTurnbasedMatchController();

	// Socket Listener Overloading
	virtual void OnSocketConnected(Tizen::Net::Sockets::Socket& socket);

	// class member function
	virtual void sendDataToPlayer(Tizen::Base::String data);
	virtual result connectSocketServer(Tizen::Base::String ipAddress, int port, GHTurnbasedMatchListener* listener);


private:
	GHTurnbasedMatchListener* currentListener;
};

#endif /* GHTurnBasedMatchController_H_ */
