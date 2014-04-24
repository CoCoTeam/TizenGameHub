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

/*
1. onMatchStart = 1;
2. onMatchTurnMy = 2;
3. onMatchTurnWait = 3;
4. onMatchFinish = 4;

5. READY = 10;
6. TURN FINISH =11 ;
*/




class GHTurnbasedMatchController
	: public GHSocket
{
public:
	GHTurnbasedMatchController();
	virtual ~GHTurnbasedMatchController();

	// Socket Listener Overloading
	virtual void OnSocketConnected(Tizen::Net::Sockets::Socket& socket);

	// class member function
	virtual result connectSocketServer(Tizen::Base::String ipAddress, int port, GHTurnbasedMatchListener* listener);
	virtual void ReceiveData(ListenerType::Type flag, Tizen::Base::String data);
	virtual void sendDataToPlayer(Tizen::Base::String data);

private:
	GHTurnbasedMatchListener* currentListener;
};

#endif /* GHTurnBasedMatchController_H_ */
