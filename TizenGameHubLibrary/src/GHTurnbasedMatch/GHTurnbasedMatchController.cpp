/*
 * GHTurnBasedMatchController.cpp
 *
 *  Created on: Apr 17, 2014
 *      Author: KICHUL
 */

#include "GHTurnbasedMatch/GHTurnbasedMatchController.h"

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
	currentListener->onMatchConnect();
}

//데이터 수신시 호출
void GHTurnbasedMatchController::ReceiveData(ListenerType::Type flag, Tizen::Base::String data){

	switch(flag) {
	case ListenerType::onMatchSetting:
		currentListener->onMatchSetting();
		break;
	case ListenerType::OnMatchStart:
		currentListener->onMatchStart(data);
		break;
	case ListenerType::OnMatchTurnMy:
		currentListener->onMatchMyturn(data);
		break;
	case ListenerType::OnMatchTurnWait:
		currentListener->onMatchTurnWait();
		break;
	case ListenerType::OnMatchFinish:
		AppLogDebug("zzzzzzzzzzzzzzzzzzzzz");
		this->OnCloseSocket();
		AppLogDebug("zzzzzzzzzzzzzzzzzzzzz2");
		currentListener->onMatchFinish(data);
		break;
	default:
		break;
	}

	AppLogDebug("[Socket] respose flag: %d", flag);
	AppLogDebug("[Socket] respose data : %S", data.GetPointer());
}


//개발자에게 사용하라고 공개하는 함수 ///////////////////////////////////////////////////////////////////////////

void GHTurnbasedMatchController::sendDataToSetting(String data) {
	String jData = "{\"flag\":12, \"data\":\"" + data + "\"}";
	//String jData = '{"flag":11, "isFinish":' + Integer::ToString(isFinish) + ', "data":' + data + '"}';
	AppLogDebug("sendDataToSetting");
	AppLogDebug("sendDataToSetting : %S", jData.GetPointer() );

	this->SendData(jData);
}

void GHTurnbasedMatchController::sendDataToPlayer(String data, int isFinish) {
	String jData = "{\"flag\":11,\"isFinish\":" + Integer::ToString(isFinish) + ",\"data\":\"" + data + "\"}";
	//String jData = '{"flag":11, "isFinish":' + Integer::ToString(isFinish) + ', "data":' + data + '"}';
	AppLogDebug("sendDataToPlayer");
	AppLogDebug("sendDataToPlayer : %S", jData.GetPointer() );

	this->SendData(jData);
}

void GHTurnbasedMatchController::readyForPlay(){
	String jData = "{\"flag\":10}";
	AppLogDebug("sendDataToPlayer : %S", jData.GetPointer() );

	this->SendData(jData);
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
