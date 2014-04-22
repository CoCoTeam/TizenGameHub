/*
 * GHTurnBasedMatchController.cpp
 *
 *  Created on: Apr 17, 2014
 *      Author: KICHUL
 */

#include "GHTurnbasedMatchController.h"

using namespace Tizen::Base;
using namespace Tizen::Net;
using namespace Tizen::Net::Sockets;

GHTurnbasedMatchController::GHTurnbasedMatchController() {
	// TODO Auto-generated constructor stub

}

GHTurnbasedMatchController::~GHTurnbasedMatchController() {
	// TODO Auto-generated destructor stub
}

//연결 성공시 호출
void
GHTurnbasedMatchController::OnSocketConnected(Socket& socket)
{
	GHSocket::OnSocketConnected(socket);
    this->currentListener->onMatchConnect();
}

void GHTurnbasedMatchController::sendDataToPlayer(Tizen::Base::String data) {
	this->SendData(data);
}

result
GHTurnbasedMatchController::connectSocketServer(String ipAddress, int port, GHTurnbasedMatchListener* listener)
{
	this->currentListener = listener;

    result res = E_SUCCESS;

    //전달받은 값으로 IP 및 Port를 설정한다.
    __pClientIp = new (std::nothrow) Ip4Address(ipAddress);
    __port = port;

    // TCP 혹은 UDP에 따른 설정값으로 Socket을 생성한다. (:TCP)
    res = CreateSocket();
    TryReturn(res == E_SUCCESS, res, "Error in creating Socket %d", res);

    __isConstructed = true;

    // Client에 따른 설정값으로 서버에 연결한다.
    res = SocketClient();

    return res;
}
