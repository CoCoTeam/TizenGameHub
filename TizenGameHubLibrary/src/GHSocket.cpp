/*
 * GHSocket.cpp
 *
 *  Created on: Apr 16, 2014
 *      Author: KICHUL
 */

#include "GHSocket.h"

using namespace Tizen::Base;
using namespace Tizen::Net;
using namespace Tizen::Net::Sockets;
using namespace Tizen::Web::Json;

GHSocket::GHSocket() {
	// TODO Auto-generated constructor stub

}

GHSocket::~GHSocket() {
	// TODO Auto-generated destructor stub
}

result
GHSocket::CreateSocket()
{
    unsigned long arg = 1;
    result res = E_SUCCESS;

    // Create socket
    __pSocket = new (std::nothrow) Socket();
    TryReturn(__pSocket != null, E_OUT_OF_MEMORY, "Failed to allocate Socket");

    // Socket을 생성한다.
    // type : stream, datagram
    // Protocol : TCP, UDT
    AppLog("Constructing Socket");
    res = __pSocket->Construct(NET_SOCKET_AF_IPV4, NET_SOCKET_TYPE_STREAM, NET_SOCKET_PROTOCOL_TCP);
    TryReturn(res == E_SUCCESS, res, "Socket Construction failed %d", res);

    // Non-blocking mode = 1, blocking mode = 0
    // NET_SOCKET_FIONBIO 옵션은 소켓 Non-blocking, blocking mode 모드를 설정한다.
    // 기본값은 Non-blocking mode(1) 이다.
    res = __pSocket->Ioctl(NET_SOCKET_FIONBIO, arg);
    TryReturn(res == E_SUCCESS, res, "Socket Ioctl failed %d", res);

    // Add Socket Listener to listen to socket event
    // 소켈 이벤트 리스너를 등록한다.
    res = __pSocket->AddSocketListener(*this);
    TryReturn(res == E_SUCCESS, res, "Socket AddSocketListener failed %d", res);

    // 소켓의 설정을 변경한다.
    // NET_SOCKET_SO_REUSEADDR : 소켓이 이미 사용중인 주소에 바인딩 할 수 있다.
    res = __pSocket->SetSockOpt(NET_SOCKET_SOL_SOCKET, NET_SOCKET_SO_REUSEADDR, 1);
    TryReturn(res == E_SUCCESS, res, "Socket SetSockOpt failed %d", res);

    // Set the socket as select an interested event.
    // 특정한 메세지에의해 비동기적으로 호출될 핸들러를 지정한다.
    res = __pSocket->AsyncSelectByListener(NET_SOCKET_EVENT_CONNECT | NET_SOCKET_EVENT_WRITE | NET_SOCKET_EVENT_READ | NET_SOCKET_EVENT_CLOSE | NET_SOCKET_EVENT_ACCEPT);
    TryReturn(res == E_SUCCESS, res, "Socket AsyncSelectByListener failed %d", res);

    return res;
}

result
GHSocket::SocketClient(void)
{
    result res = E_SUCCESS;

	// Create server endpoint using serverip address and port
	// Endpoint 를 설정한다. __pClientIp: 입력받은 서버 IP주소, __port: 입력받은 port주소
	NetEndPoint* pPeerEndPoint = new (std::nothrow) NetEndPoint(*__pClientIp, __port);
	TryReturn(pPeerEndPoint != null, E_OUT_OF_MEMORY, "Failed to allocate NetEndPoint");

	// Connect to peer for tcp protocol
	// 서버쪽에 연결한다.
	res = __pSocket->Connect(*pPeerEndPoint);
	AppLog("Socket Return %ls", GetErrorMessage(res));
	delete pPeerEndPoint;
	return res;

    return res;
}

// 소켓 연결을 받아들었을 때 실행되는 리스너
void
GHSocket::OnSocketAccept(Socket& socket)
{
    result res = E_SUCCESS;
    AppLog("OnSocketAccept");

    if (__pTcpSocket != null)
    {
        socket.Close();
        AppLog("Already Connected with one Client");
        return;
    }

    __isConnected = true;

    Socket* pSocket = const_cast< Socket* >(&socket);
    __pTcpSocket = __pSocket;

    // Accept the connection attempt.
    // 들어오는 연결을 받아들인다.
    // AcceptN() : 보류중인 연결 큐에서 첫 번째의 연결을 꺼내고,
    //			    대기(서버)소켓과 같은 type, protocol, protocol family 를 생성한다.
    __pSocket = pSocket->AcceptN();
    if (__pSocket == null)
    {
        AppLog("Socket Accept Failed");
        return;
    }

    // Add Socket Listener to listen to socket event.
    // __pSocket 가 새로 생성되었기 때문에 이벤트 리스너를 다시 등록한다.
    res = __pSocket->AddSocketListener(*this);
    if (IsFailed(res))
    {
        AppLog("Socket AddSocketListener failed %d", res);
    }

    // Set the socket as select an interested event.
    // 마찬가지로 특정한 메세지에의해 비동기적으로 호출될 핸들러를 지정한다.
    res = __pSocket->AsyncSelectByListener(NET_SOCKET_EVENT_WRITE | NET_SOCKET_EVENT_READ | NET_SOCKET_EVENT_CLOSE);
    if (IsFailed(res))
    {
        AppLog("Socket AsyncSelectByListener failed %d", res);
    }
}

void
GHSocket::OnSocketClosed(Socket& socket, NetSocketClosedReason reason)
{
    AppLog("OnSocketClosed");
    AppLog(GetErrorMessage(GetLastResult()));
    AppLog("Reasoning %d", reason);

    OnCloseSocket();
    AppLog("Close Socket");

    //pSceneManager->GoBackward(BackwardSceneTransition(SCENE_MAIN_MENU));
}

// 소켓이 연결되었을 때 실행되는 리스너 (클라이언트, 서버??)  (CALLBACK: onConnect 호출해야함)
void
GHSocket::OnSocketConnected(Socket& socket)
{
    AppLog("OnSocketConnected");
    //EnableControl(true);
    __isConnected = true;

}

// 소켓이 연결된 후에 메세지를 받을 준비가 되었을 때 실행되는 리스너 (클라이언트 && 서버??)
// 데이터를 받은 직후에도 실행된다.
void
GHSocket::OnSocketReadyToReceive(Socket& socket)
{
    AppLog("OnSocketReadyToReceive");
    ReceiveData();
}

// 소켓이 연결된 후에 메세지를 보낼 준비가 되었을 때 실행되는 리스너 (클라이언트 && 서버??)
void
GHSocket::OnSocketReadyToSend(Socket& socket)
{
    AppLog("OnSocketReadyToSend");
}


// 메세지 보내기 (클라이언트, 서버)
result
GHSocket::SendData(String data)
{
    //String data;
    ByteBuffer* pTxBuffer = null;
    ByteBuffer buffer;
    result res = E_SUCCESS;

    AppLog("String length is %d", data.GetCapacity());
    if (data.IsEmpty())
    {
        AppLog("There is no data to send");
        return E_SUCCESS;
    }

    // 스트링을 byteBuffer로 변환한다.
    pTxBuffer = Tizen::Base::Utility::StringUtil::StringToUtf8N(data);
    TryReturn(pTxBuffer != null, E_OUT_OF_MEMORY, "Failed to allocate ByteBuffer");

    AppLog("Text Length %d", pTxBuffer->GetLimit());

    // buffer를 생성한다.
    buffer.Construct(pTxBuffer->GetLimit());
    buffer.CopyFrom(*pTxBuffer);
    buffer.Flip();
    delete pTxBuffer;

    // TCP인 경우 Send로 메세지를 전송한다.
    res = __pSocket->Send(buffer);

    // 보내는게 성공하면 내 화면에도 뿌려준다.
    if (res == E_SUCCESS || res == E_WOULD_BLOCK)
    {
        //data.Append(L"\n");
        //pEditAreaData->AppendText(data);
        //pEditAreaData->RequestRedraw();
        //pEditFieldtext->SetText(L"");
        //pEditFieldtext->RequestRedraw();
    }
    else
    {
        AppLog("Error sending data");
    }

    // 버퍼를 비운다.
    buffer.Clear();

    return res;
}

// TCP 프로토콜로 데이터를 받은 경우 (CALLBACK: onStart, onMyturn, onWait, onFinish 호출해야함)
result
GHSocket::ReceiveData(void)
{
    result res = E_SUCCESS;
    ByteBuffer txBuffer;
    char* pBuffer = null;
    String data;
    unsigned long buflen = 0;

    // Get the size of data received
    __pSocket->Ioctl(NET_SOCKET_FIONREAD, buflen);

    // Socket에서 데이터를 받아온다.
    txBuffer.Construct(buflen + 1);
    res = __pSocket->Receive(txBuffer);
    TryReturn(res == E_SUCCESS, res, "Receive Failed");

    // buffer의 데이터를 String으로 추출
	txBuffer.Flip();
	pBuffer = (char*) (txBuffer.GetPointer());
	data.SetCapacity(buflen + 2);
	res = data.Append(pBuffer);
	TryReturn(res == E_SUCCESS, res, "Append Failed");

	// String 출력
	AppLogDebug("[Socket] response data : %S", data.GetPointer());


    //버퍼의 데이터를 JsonObject로 변경
    IJsonValue* pValue = JsonParser::ParseN(txBuffer);
    JsonObject* pJsonObj = static_cast<JsonObject*>(pValue);

    //키(여기서는 FLAG)에 해당하는 값 가지고 오기
    String key = "flag";
    IJsonValue * pObjValue = null;
    pJsonObj->GetValue(&key, pObjValue);
    JsonNumber * pJsonNum = static_cast<JsonNumber*>(pObjValue);
    int retFlag = pJsonNum->ToInt();
	if(pObjValue!= null) delete pObjValue;

    //키(여기서는 DATA)에 해당하는 값 가지고 오기
    key = "data";
    pObjValue = null;
    pJsonObj->GetValue(&key, pObjValue);
    JsonString * pJsonStr = static_cast<JsonString*>(pObjValue);
    String retData(pJsonStr->GetPointer());
    if(pObjValue!= null) delete pObjValue;

	// 자식 객체에게 FALG value를 넘겨줘서 거기서 리스너 호출하도록 만들어야 한다.
	this->ReceiveData((ListenerType::Type)retFlag, retData);

    // clear txBuffer
    txBuffer.Clear();

    return res;
}

void
GHSocket::OnCloseSocket(void)
{
    result res = E_SUCCESS;
    AppLog("Socket Close Received");

    if (__isConstructed)
    {
        if (__pSocket != null)
        {
            res = __pSocket->RemoveSocketListener(*this);
            if (IsFailed(res))
            {
                AppLog("RemoveSocketListener failed %d", res);
            }

            __pSocket->Close();
        }

//
//        if (__pTcpSocket != null)
//        {
//            __pTcpSocket->Close();
//        }
    }

    delete __pSocket;
//    delete __pTcpSocket;

    __pSocket = null;
    __pTcpSocket = null;
    __isConnected = false;
    __isConstructed = false;
    AppLog("Socket Close Received2");
}
