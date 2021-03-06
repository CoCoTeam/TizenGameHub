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
	pProgressPopup = new (std::nothrow) Tizen::Ui::Controls::ProgressPopup();
	pProgressPopup->Construct(true, false);
//	pProgressPopup->RemoveProgressPopupEventListener(*this);
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

	// progress Popup 생성
	pProgressPopup->SetTitleText(L"Multiplay");
	pProgressPopup->SetText(L"다른 사용자의 접속을 기다립니다.");
	pProgressPopup->SetShowState(true);
	pProgressPopup->Show();
}

//데이터 수신시 호출
void GHTurnbasedMatchController::ReceiveData(ListenerType::Type flag, Tizen::Base::String data){

	AppLogDebug("[Socket] respose flag: %d", flag);
	AppLogDebug("[Socket] respose data : %S", data.GetPointer());

	switch(flag) {
	case ListenerType::onMatchSetting:
		currentListener->onMatchSetting();
		break;
	case ListenerType::OnMatchStart:
		currentListener->onMatchStart(data);
		pProgressPopup->SetShowState(false);
		break;
	case ListenerType::OnMatchTurnMy:
		currentListener->onMatchMyturn(data);
		break;
	case ListenerType::OnMatchTurnWait:
		currentListener->onMatchTurnWait();
		break;
	case ListenerType::OnMatchFinish:

		this->OnCloseSocket();
		currentListener->onMatchFinish(data);
		break;
	default:
		break;
	}
}


//개발자에게 사용하라고 공개하는 함수 ///////////////////////////////////////////////////////////////////////////
void GHTurnbasedMatchController::sendDataToSetting(String data) {
	String jData = "{\"flag\":12, \"data\":\"" + data + "\"}";
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

void GHTurnbasedMatchController::connectSocketServer(GHTurnbasedMatchListener* listener){
	this->connectSocketServer("54.238.195.222", 8082, listener);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////


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
