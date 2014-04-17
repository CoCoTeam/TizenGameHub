/*
 * GHSocket.h
 *
 *  Created on: Apr 16, 2014
 *      Author: KICHUL
 */

#ifndef GHSOCKET_H_
#define GHSOCKET_H_

#include "GHTizen.h"

#include <FNet.h>
#include <FNetSockSocketTypes.h>

class GHSocket
	: public Tizen::Net::Sockets::ISocketEventListener
{
public:
	GHSocket();
	virtual ~GHSocket();

	virtual void OnSocketAccept(Tizen::Net::Sockets::Socket& socket);
    virtual void OnSocketClosed(Tizen::Net::Sockets::Socket& socket1, Tizen::Net::Sockets::NetSocketClosedReason reason);
    virtual void OnSocketConnected(Tizen::Net::Sockets::Socket& socket1);
    virtual void OnSocketReadyToReceive(Tizen::Net::Sockets::Socket& socket);
    virtual void OnSocketReadyToSend(Tizen::Net::Sockets::Socket& socket1);

protected:
    result CreateSocket(void);
    result SocketClient(void);

    result SendData(Tizen::Base::String data);
    result ReceiveData(void);

    void OnClose(void);

    Tizen::Net::Ip4Address* __pClientIp;
    int __port;
    bool __isServer;
    bool __isConnected;
    bool __isConstructed;
    Tizen::Net::Sockets::Socket* __pSocket;
    Tizen::Net::Sockets::Socket* __pTcpSocket;
};

#endif /* GHSOCKET_H_ */
