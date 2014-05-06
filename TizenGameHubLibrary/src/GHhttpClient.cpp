//
// Tizen Native SDK
// Copyright (c) 2012-2013 Samsung Electronics Co., Ltd.
//
// Licensed under the Flora License, Version 1.1 (the License);
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://floralicense.org/license/
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an AS IS BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#include <new>
#include "GHhttpClient.h"

using namespace Tizen::App;
using namespace Tizen::Base;
using namespace Tizen::Net::Http;
using namespace Tizen::Base::Collection;
using namespace Tizen::Base::Utility;
using namespace Tizen::System;

GHhttpClient::GHhttpClient(void)
	: __pHttpSession(null)
	, hostAddr(L"http://54.238.195.222:80")
{
}

GHhttpClient::~GHhttpClient(void)
{
	if (__pHttpSession != null)
	{
		delete __pHttpSession;
		__pHttpSession = null;
	}
}


// GET 방식의 요청 보내기.
result
GHhttpClient::RequestHttpGet(IHttpTransactionEventListener* listener)
{
	//----------------------------------------------------------------------
	// Construct an HTTP session
	result r = E_SUCCESS;
	HttpTransaction* pHttpTransaction = null;
	HttpRequest* pHttpRequest = null;

	// 주소
	String player_id = "hhhh";
	String hostAddr(L"http://211.189.127.187:80");
	String requestAddr(L"http://211.189.127.187:8081/players/" + player_id);

	if (__pHttpSession == null)
	{
		__pHttpSession = new (std::nothrow) HttpSession();

		r = __pHttpSession->Construct(NET_HTTP_SESSION_MODE_NORMAL, null, hostAddr, null);
		if (IsFailed(r))
		{
			delete __pHttpSession;
			__pHttpSession = null;
			AppLogException("Failed to create the HttpSession.");
			goto CATCH;
		}

		r = __pHttpSession->SetAutoRedirectionEnabled(true);
		TryCatch(r == E_SUCCESS, , "Failed to set the redirection automatically.");
	}
	//----------------------------------------------------------------------

	// Open a new transaction
	pHttpTransaction = __pHttpSession->OpenTransactionN();
	r = GetLastResult();
	TryCatch(pHttpTransaction != null, , "Failed to open the HttpTransaction.");

	// Add a listener
	r = pHttpTransaction->AddHttpTransactionListener(*listener);
	TryCatch(r == E_SUCCESS, , "Failed to add the HttpTransactionListener.");

	// Get an HTTP request
	pHttpRequest = const_cast< HttpRequest* >(pHttpTransaction->GetRequest());

	// Set the HTTP method and URI
	r = pHttpRequest->SetUri(requestAddr);
	TryCatch(r == E_SUCCESS, , "Failed to set the uri.");

	r = pHttpRequest->SetMethod(NET_HTTP_METHOD_GET);
	TryCatch(r == E_SUCCESS, , "Failed to set the method.");

	// Submit the request
	r = pHttpTransaction->Submit();
	TryCatch(r == E_SUCCESS, , "Failed to submit the HttpTransaction.");

	return r;

CATCH:

	delete pHttpTransaction;
	pHttpTransaction = null;

	AppLog("RequestHttpGet() failed. (%s)", GetErrorMessage(r));
	return r;
}


// POST 방식의 요청 보내기.
result
GHhttpClient::RequestHttpPost(IHttpTransactionEventListener* listener)
{
	//----------------------------------------------------------------------
	// Construct an HTTP session
	result r = E_SUCCESS;
	HttpTransaction* pHttpTransaction = null;
	HttpRequest* pHttpRequest = null;
	HttpUrlEncodedEntity* pHttpUrlEncodedEntity = null;

	// 주소
	String player_id = "hhhh";
	String hostAddr(L"http://54.238.195.222:8081");
	String requestAddr(L"http://54.238.195.222:8081/developers");

	if (__pHttpSession == null)
	{
		__pHttpSession = new (std::nothrow) HttpSession();

		r = __pHttpSession->Construct(NET_HTTP_SESSION_MODE_NORMAL, null, hostAddr, null);
		if (IsFailed(r))
		{
			delete __pHttpSession;
			__pHttpSession = null;
			AppLogException("Failed to create the HttpSession.");
			goto CATCH;
		}

		r = __pHttpSession->SetAutoRedirectionEnabled(true);
		TryCatch(r == E_SUCCESS, , "Failed to set the redirection automatically.");
	}
	//----------------------------------------------------------------------

	// Open a new transaction
	pHttpTransaction = __pHttpSession->OpenTransactionN();
	r = GetLastResult();
	TryCatch(pHttpTransaction != null, , "Failed to open the HttpTransaction.");

	// Add a listener
	r = pHttpTransaction->AddHttpTransactionListener(*listener);
	TryCatch(r == E_SUCCESS, , "Failed to add the HttpTransactionListener.");

	// Get an HTTP request
	pHttpRequest = const_cast< HttpRequest* >(pHttpTransaction->GetRequest());

	//----------------------------------------------------------------------
	// Set the HTTP method and URI
	r = pHttpRequest->SetUri(requestAddr);
	TryCatch(r == E_SUCCESS, , "Failed to set the uri.");

	r = pHttpRequest->SetMethod(NET_HTTP_METHOD_POST);
	TryCatch(r == E_SUCCESS, , "Failed to set the method.");

	// POST 데이터 설정
	pHttpUrlEncodedEntity = new HttpUrlEncodedEntity();
	r = pHttpUrlEncodedEntity->Construct();

	r = pHttpUrlEncodedEntity->AddParameter(L"dev_email", L"asdf@asdf.com");
	r = pHttpUrlEncodedEntity->AddParameter(L"dev_pwd", L"1234");

	r = pHttpRequest->SetEntity(*pHttpUrlEncodedEntity);
	//----------------------------------------------------------------------

	// Submit the request
	r = pHttpTransaction->Submit();
	TryCatch(r == E_SUCCESS, , "Failed to submit the HttpTransaction.");

	return r;

CATCH:

	delete pHttpTransaction;
	pHttpTransaction = null;

	AppLog("RequestHttpGet() failed. (%s)", GetErrorMessage(r));
	return r;
}


// Request 후 Response를 받았을 때 처리
//void
//httpClient::OnTransactionReadyToRead(HttpSession& httpSession, HttpTransaction& httpTransaction, int availableBodyLen)
//{
//
//	// 모든 response가 이 함수로 오는 것으로 보임.
//	// 따라서, 각 API마다 특정 패킷항상 보내주어서
//	// 이 함수에서 패킷에 따라 처리하도록 switch case문 등을 써야 할 것 같음.
//	// if(P_PLAYER_JOIN) ~~
//	// else if(P_PLAYER_SELECT) ~~
//
//
//	// 아니면 해당 eventListner IHttpTransactionEventListener를 상속받은 클래스를 만들어서,
//	// 그 클래스를 리스너로 등록하는 것도 가능할것 같으나
//	// 그 클래스에서 해당 form의 ui를 컨트롤 하는 것이 힘들어보임.
//
//
//
//
//	// 현재는 response data를 받아서 화면에 뿌리도록 함.
//
//	AppLog("OnTransactionReadyToRead");
//
//	HttpResponse* pHttpResponse = httpTransaction.GetResponse();
//	if (pHttpResponse->GetHttpStatusCode() == HTTP_STATUS_OK)
//	{
//		HttpHeader* pHttpHeader = pHttpResponse->GetHeader();
//		if (pHttpHeader != null)
//		{
//
//			String* tempHeaderString = pHttpHeader->GetRawHeaderN();
//
//			// 응답받은 데이터를 버퍼에 가져온다.
//			ByteBuffer* pBuffer = pHttpResponse->ReadBodyN();
//
//			AppLogDebug("[HTTP] response body size : %d " , availableBodyLen );
//
//			// 버퍼의 데이터를 string으로 추출.
//			byte* tempBody = new byte[availableBodyLen+1];
//			pBuffer->GetArray(tempBody, 0, availableBodyLen);
//			tempBody[availableBodyLen] = '\0';
//
//			AppLogDebug("[HTTP] response data : %s", (char *)tempBody);
//
//			String text = (const char *)tempBody;
//
//			// text control에 가져온 데이터를 보여준다.
//			__pEditArea->SetText(text);
//
//			delete tempHeaderString;
//			delete pBuffer;
//		}
//	}
//}

//void
//httpClient::OnTransactionAborted(HttpSession& httpSession, HttpTransaction& httpTransaction, result r)
//{
//	AppLog("OnTransactionAborted(%s)", GetErrorMessage(r));
//
//	delete &httpTransaction;
//}
//
//void
//httpClient::OnTransactionReadyToWrite(HttpSession& httpSession, HttpTransaction& httpTransaction, int recommendedChunkSize)
//{
//	AppLog("OnTransactionReadyToWrite");
//}
//
//void
//httpClient::OnTransactionHeaderCompleted(HttpSession& httpSession, HttpTransaction& httpTransaction, int headerLen, bool authRequired)
//{
//	AppLog("OnTransactionHeaderCompleted");
//}
//
//void
//httpClient::OnTransactionCompleted(HttpSession& httpSession, HttpTransaction& httpTransaction)
//{
//	AppLog("OnTransactionCompleted");
//
//	delete &httpTransaction;
//}
//
//void
//httpClient::OnTransactionCertVerificationRequiredN(HttpSession& httpSession, HttpTransaction& httpTransaction, Tizen::Base::String* pCert)
//{
//	AppLog("OnTransactionCertVerificationRequiredN");
//
//	httpTransaction.Resume();
//
//	delete pCert;
//}


result
GHhttpClient::RequestHttpGetTran(IHttpTransactionEventListener* listener, String url)
{
	AppLog("------------------>Request<------------------------- ");

	// Construct an HTTP session
	result r = E_SUCCESS;
	HttpTransaction* pHttpTransaction = null;
	HttpRequest* pHttpRequest = null;

	// 주소
	String requestAddr(hostAddr + url);

	if (__pHttpSession == null)
	{
		__pHttpSession = new (std::nothrow) HttpSession();

		r = __pHttpSession->Construct(NET_HTTP_SESSION_MODE_PIPELINING , null, hostAddr, null);
		if (IsFailed(r))
		{
			delete __pHttpSession;
			__pHttpSession = null;
			AppLogException("Failed to create the HttpSession.");
			goto CATCH;
		}

		r = __pHttpSession->SetAutoRedirectionEnabled(true);
		TryCatch(r == E_SUCCESS, , "Failed to set the redirection automatically.");
	}
	//----------------------------------------------------------------------
	// Open a new transaction
	pHttpTransaction = __pHttpSession->OpenTransactionN();
	r = GetLastResult();
	TryCatch(pHttpTransaction != null, , "Failed to open the HttpTransaction.");

	// Add a listener
	r = pHttpTransaction->AddHttpTransactionListener(*listener);
	TryCatch(r == E_SUCCESS, , "Failed to add the HttpTransactionListener.");

	// Get an HTTP request
	pHttpRequest = const_cast< HttpRequest* >(pHttpTransaction->GetRequest());

	// Set the HTTP method and URI
	r = pHttpRequest->SetUri(requestAddr);
	TryCatch(r == E_SUCCESS, , "Failed to set the uri.");

	r = pHttpRequest->SetMethod(NET_HTTP_METHOD_GET);
	TryCatch(r == E_SUCCESS, , "Failed to set the method.");

	// Submit the request
	r = pHttpTransaction->Submit();
	TryCatch(r == E_SUCCESS, , "Failed to submit the HttpTransaction.");

	return r;

CATCH:

	delete pHttpTransaction;
	pHttpTransaction = null;

	AppLog("RequestHttpGet() failed. (%s)", GetErrorMessage(r));
	return r;
}


result
GHhttpClient::RequestHttpPostTran(IHttpTransactionEventListener* listener, String url, Tizen::Base::Collection::IMap *map)

{

	AppLog("------------------>Request<-------------------------");

	// Construct an HTTP session
	result r = E_SUCCESS;
	HttpTransaction* pHttpTransaction = null;
	HttpRequest* pHttpRequest = null;
	HttpUrlEncodedEntity* pHttpUrlEncodedEntity = null;

	// 주소
	String player_id = "hhhh";

	//map에서 사용 .. goto 뒤에 변수 선언이 있으면 안됨
	IMapEnumerator* pMapEnum;
	String* pKey = null;
	String* pValue = null;

	/*	String hostAddr(L"http://211.189.127.187:8081");
	String requestAddr(L"http://211.189.127.187:8081/players");*/


	//String hostAddr(L"http://54.238.195.222:8081");
	//String requestAddr(L"http://54.238.195.222:8081/players");
	String requestAddr( hostAddr + url);

	if (__pHttpSession == null)
	{
		__pHttpSession = new (std::nothrow) HttpSession();

		r = __pHttpSession->Construct(NET_HTTP_SESSION_MODE_PIPELINING , null, hostAddr, null);
		if (IsFailed(r))
		{
			delete __pHttpSession;
			__pHttpSession = null;
			AppLogException("Failed to create the HttpSession.");
			goto CATCH;
		}

		r = __pHttpSession->SetAutoRedirectionEnabled(true);
		TryCatch(r == E_SUCCESS, , "Failed to set the redirection automatically.");
	}
	//----------------------------------------------------------------------

	// Open a new transaction
	pHttpTransaction = __pHttpSession->OpenTransactionN();
	r = GetLastResult();
	TryCatch(pHttpTransaction != null, , "Failed to open the HttpTransaction.");

	// Add a listener
	r = pHttpTransaction->AddHttpTransactionListener(*listener);
	TryCatch(r == E_SUCCESS, , "Failed to add the HttpTransactionListener.");

	// Get an HTTP request
	pHttpRequest = const_cast< HttpRequest* >(pHttpTransaction->GetRequest());

	//----------------------------------------------------------------------
	// Set the HTTP method and URI
	r = pHttpRequest->SetUri(requestAddr);
	TryCatch(r == E_SUCCESS, , "Failed to set the uri.");

	r = pHttpRequest->SetMethod(NET_HTTP_METHOD_POST);
	TryCatch(r == E_SUCCESS, , "Failed to set the method.");

	// POST 데이터 설정
	pHttpUrlEncodedEntity = new HttpUrlEncodedEntity();
	r = pHttpUrlEncodedEntity->Construct();

	/*
	r = pHttpUrlEncodedEntity->AddParameter(L"email", L"kichul");
	r = pHttpUrlEncodedEntity->AddParameter(L"pwd", L"kichulbabo");
	r = pHttpUrlEncodedEntity->AddParameter(L"name", L"kichul");
	r = pHttpUrlEncodedEntity->AddParameter(L"img_url", L"kichul.jpg");

	r = pHttpRequest->SetEntity(*pHttpUrlEncodedEntity);*/
	//----------------------------------------------------------------------

	pMapEnum = map->GetMapEnumeratorN();
	while (pMapEnum->MoveNext() == E_SUCCESS)
	{
		pKey = static_cast< String* > (pMapEnum->GetKey());
		pValue = static_cast< String* > (pMapEnum->GetValue());
		r = pHttpUrlEncodedEntity->AddParameter(*pKey, *pValue);

	}
		delete pMapEnum;

	r = pHttpRequest->SetEntity(*pHttpUrlEncodedEntity);

	// Submit the request
	r = pHttpTransaction->Submit();
	TryCatch(r == E_SUCCESS, , "Failed to submit the HttpTransaction.");

	return r;

CATCH:

	delete pHttpTransaction;
	pHttpTransaction = null;

	AppLog("RequestHttpGet() failed. (%s)", GetErrorMessage(r));
	return r;
}


result
GHhttpClient::RequestHttpPutTran(IHttpTransactionEventListener* listener, String url, Tizen::Base::Collection::IMap *map)
{
	AppLog("------------------>Request<-------------------------");

	// Construct an HTTP session
	result r = E_SUCCESS;
	HttpTransaction* pHttpTransaction = null;
	HttpRequest* pHttpRequest = null;
	HttpUrlEncodedEntity* pHttpUrlEncodedEntity = null;

	// 주소
	String player_id = "hhhh";

	//map에서 사용 .. goto 뒤에 변수 선언이 있으면 안됨
	IMapEnumerator* pMapEnum;
	String* pKey = null;
	String* pValue = null;


	String requestAddr( hostAddr + url);

	if (__pHttpSession == null)
	{
		__pHttpSession = new (std::nothrow) HttpSession();

		r = __pHttpSession->Construct(NET_HTTP_SESSION_MODE_PIPELINING , null, hostAddr, null);
		if (IsFailed(r))
		{
			delete __pHttpSession;
			__pHttpSession = null;
			AppLogException("Failed to create the HttpSession.");
			goto CATCH;
		}

		r = __pHttpSession->SetAutoRedirectionEnabled(true);
		TryCatch(r == E_SUCCESS, , "Failed to set the redirection automatically.");
	}
	//----------------------------------------------------------------------

	// Open a new transaction
	pHttpTransaction = __pHttpSession->OpenTransactionN();
	r = GetLastResult();

	TryCatch(pHttpTransaction != null, , "Failed to open the HttpTransaction.");

	// Add a listener
	r = pHttpTransaction->AddHttpTransactionListener(*listener);
	TryCatch(r == E_SUCCESS, , "Failed to add the HttpTransactionListener.");

	// Get an HTTP request
	pHttpRequest = const_cast< HttpRequest* >(pHttpTransaction->GetRequest());

	//----------------------------------------------------------------------
	// Set the HTTP method and URI
	r = pHttpRequest->SetUri(requestAddr);
	TryCatch(r == E_SUCCESS, , "Failed to set the uri.");

	r = pHttpRequest->SetMethod(NET_HTTP_METHOD_PUT);
	TryCatch(r == E_SUCCESS, , "Failed to set the method.");

	// POST 데이터 설정
	pHttpUrlEncodedEntity = new HttpUrlEncodedEntity();
	r = pHttpUrlEncodedEntity->Construct();



	pMapEnum = map->GetMapEnumeratorN();
	while (pMapEnum->MoveNext() == E_SUCCESS)
	{
		pKey = static_cast< String* > (pMapEnum->GetKey());
		pValue = static_cast< String* > (pMapEnum->GetValue());
		r = pHttpUrlEncodedEntity->AddParameter(*pKey, *pValue);

	}
	delete pMapEnum;


	r = pHttpRequest->SetEntity(*pHttpUrlEncodedEntity);

	// Submit the request
	r = pHttpTransaction->Submit();
	TryCatch(r == E_SUCCESS, , "Failed to submit the HttpTransaction.");

	return r;

CATCH:

	delete pHttpTransaction;
	pHttpTransaction = null;

	AppLog("RequestHttpGet() failed. (%s)", GetErrorMessage(r));
	return r;
}

result
GHhttpClient::RequestHttpDelTran(IHttpTransactionEventListener* listener, String url)
{
	AppLog("------------------>Request<------------------------- ");

	// Construct an HTTP session
	result r = E_SUCCESS;
	HttpTransaction* pHttpTransaction = null;
	HttpRequest* pHttpRequest = null;

	// 주소
	String requestAddr(hostAddr + url);

	if (__pHttpSession == null)
	{
		__pHttpSession = new (std::nothrow) HttpSession();

		r = __pHttpSession->Construct(NET_HTTP_SESSION_MODE_PIPELINING , null, hostAddr, null);
		if (IsFailed(r))
		{
			delete __pHttpSession;
			__pHttpSession = null;
			AppLogException("Failed to create the HttpSession.");
			goto CATCH;
		}

		r = __pHttpSession->SetAutoRedirectionEnabled(true);
		TryCatch(r == E_SUCCESS, , "Failed to set the redirection automatically.");
	}
	//----------------------------------------------------------------------
	// Open a new transaction
	pHttpTransaction = __pHttpSession->OpenTransactionN();
	r = GetLastResult();
	TryCatch(pHttpTransaction != null, , "Failed to open the HttpTransaction.");

	// Add a listener
	r = pHttpTransaction->AddHttpTransactionListener(*listener);
	TryCatch(r == E_SUCCESS, , "Failed to add the HttpTransactionListener.");

	// Get an HTTP request
	pHttpRequest = const_cast< HttpRequest* >(pHttpTransaction->GetRequest());

	// Set the HTTP method and URI
	r = pHttpRequest->SetUri(requestAddr);
	TryCatch(r == E_SUCCESS, , "Failed to set the uri.");

	r = pHttpRequest->SetMethod(NET_HTTP_METHOD_DELETE);
	TryCatch(r == E_SUCCESS, , "Failed to set the method.");

	// Submit the request
	r = pHttpTransaction->Submit();
	TryCatch(r == E_SUCCESS, , "Failed to submit the HttpTransaction.");

	return r;

CATCH:

	delete pHttpTransaction;
	pHttpTransaction = null;

	AppLog("RequestHttpDelTran() failed. (%s)", GetErrorMessage(r));
	return r;
}

//result
//GHhttpClient::RequestHttpDelTran(IHttpTransactionEventListener* listener, String url, Tizen::Base::Collection::IMap *map)
//{
//
//	AppLog("------------------>Request<-------------------------");
//
//		// Construct an HTTP session
//		result r = E_SUCCESS;
//		HttpTransaction* pHttpTransaction = null;
//		HttpRequest* pHttpRequest = null;
//		HttpUrlEncodedEntity* pHttpUrlEncodedEntity = null;
//
//		// 주소
//		String player_id = "hhhh";
//
//		//map에서 사용 .. goto 뒤에 변수 선언이 있으면 안됨
//		IMapEnumerator* pMapEnum;
//		String* pKey = null;
//		String* pValue = null;
//
//		/*	String hostAddr(L"http://211.189.127.187:8081");
//		String requestAddr(L"http://211.189.127.187:8081/players");*/
//
//
//		//String hostAddr(L"http://54.238.195.222:8081");
//		//String requestAddr(L"http://54.238.195.222:8081/players");
//		String requestAddr( hostAddr + url);
//
//		if (__pHttpSession == null)
//		{
//			__pHttpSession = new (std::nothrow) HttpSession();
//
//			r = __pHttpSession->Construct(NET_HTTP_SESSION_MODE_NORMAL, null, hostAddr, null);
//			if (IsFailed(r))
//			{
//				delete __pHttpSession;
//				__pHttpSession = null;
//				AppLogException("Failed to create the HttpSession.");
//				goto CATCH;
//			}
//
//			r = __pHttpSession->SetAutoRedirectionEnabled(true);
//			TryCatch(r == E_SUCCESS, , "Failed to set the redirection automatically.");
//		}
//		//----------------------------------------------------------------------
//
//		// Open a new transaction
//		pHttpTransaction = __pHttpSession->OpenTransactionN();
//		r = GetLastResult();
//		TryCatch(pHttpTransaction != null, , "Failed to open the HttpTransaction.");
//
//		// Add a listener
//		r = pHttpTransaction->AddHttpTransactionListener(*listener);
//		TryCatch(r == E_SUCCESS, , "Failed to add the HttpTransactionListener.");
//
//		// Get an HTTP request
//		pHttpRequest = const_cast< HttpRequest* >(pHttpTransaction->GetRequest());
//
//		//----------------------------------------------------------------------
//		// Set the HTTP method and URI
//		r = pHttpRequest->SetUri(requestAddr);
//		TryCatch(r == E_SUCCESS, , "Failed to set the uri.");
//
//		r = pHttpRequest->SetMethod(NET_HTTP_METHOD_POST);
//		TryCatch(r == E_SUCCESS, , "Failed to set the method.");
//
//		// POST 데이터 설정
//		pHttpUrlEncodedEntity = new HttpUrlEncodedEntity();
//		r = pHttpUrlEncodedEntity->Construct();
//
//		/*
//		r = pHttpUrlEncodedEntity->AddParameter(L"email", L"kichul");
//		r = pHttpUrlEncodedEntity->AddParameter(L"pwd", L"kichulbabo");
//		r = pHttpUrlEncodedEntity->AddParameter(L"name", L"kichul");
//		r = pHttpUrlEncodedEntity->AddParameter(L"img_url", L"kichul.jpg");
//
//		r = pHttpRequest->SetEntity(*pHttpUrlEncodedEntity);*/
//		//----------------------------------------------------------------------
//
//		pMapEnum = map->GetMapEnumeratorN();
//		while (pMapEnum->MoveNext() == E_SUCCESS)
//		{
//			pKey = static_cast< String* > (pMapEnum->GetKey());
//			pValue = static_cast< String* > (pMapEnum->GetValue());
//			r = pHttpUrlEncodedEntity->AddParameter(*pKey, *pValue);
//
//		}
//			delete pMapEnum;
//
//		r = pHttpRequest->SetEntity(*pHttpUrlEncodedEntity);
//
//		// Submit the request
//		r = pHttpTransaction->Submit();
//		TryCatch(r == E_SUCCESS, , "Failed to submit the HttpTransaction.");
//
//		return r;
//
//CATCH:
//
//	delete pHttpTransaction;
//	pHttpTransaction = null;
//
//	AppLog("RequestHttpGet() failed. (%s)", GetErrorMessage(r));
//	return r;
//	/*AppLog("------------------>Request<-------------------------");
//
//		// Construct an HTTP session
//		result r = E_SUCCESS;
//		HttpTransaction* pHttpTransaction = null;
//		HttpRequest* pHttpRequest = null;
//
//		// 주소
//		String requestAddr(hostAddr + url);
//
//		if (__pHttpSession == null)
//		{
//			__pHttpSession = new (std::nothrow) HttpSession();
//
//			r = __pHttpSession->Construct(NET_HTTP_SESSION_MODE_NORMAL, null, hostAddr, null);
//			if (IsFailed(r))
//			{
//				delete __pHttpSession;
//				__pHttpSession = null;
//				AppLogException("Failed to create the HttpSession.");
//				goto CATCH;
//			}
//
//			r = __pHttpSession->SetAutoRedirectionEnabled(true);
//			TryCatch(r == E_SUCCESS, , "Failed to set the redirection automatically.");
//		}
//		//----------------------------------------------------------------------
//
//		// Open a new transaction
//		pHttpTransaction = __pHttpSession->OpenTransactionN();
//		r = GetLastResult();
//		TryCatch(pHttpTransaction != null, , "Failed to open the HttpTransaction.");
//
//		// Add a listener
//		r = pHttpTransaction->AddHttpTransactionListener(*listener);
//		TryCatch(r == E_SUCCESS, , "Failed to add the HttpTransactionListener.");
//
//		// Get an HTTP request
//		pHttpRequest = const_cast< HttpRequest* >(pHttpTransaction->GetRequest());
//
//		// Set the HTTP method and URI
//		r = pHttpRequest->SetUri(requestAddr);
//		TryCatch(r == E_SUCCESS, , "Failed to set the uri.");
//
//		r = pHttpRequest->SetMethod(NET_HTTP_METHOD_DELETE);
//		TryCatch(r == E_SUCCESS, , "Failed to set the method.");
//
//		// Submit the request
//		r = pHttpTransaction->Submit();
//		TryCatch(r == E_SUCCESS, , "Failed to submit the HttpTransaction.");
//
//		return r;
//
//	CATCH:
//
//		delete pHttpTransaction;
//		pHttpTransaction = null;
//
//		AppLog("RequestHttpGet() failed. (%s)", GetErrorMessage(r));
//		return r;*/
//}

result GHhttpClient::RequestImageUpload(Tizen::Net::Http::IHttpTransactionEventListener* listener, Tizen::Net::Http::IHttpProgressEventListener* listener2, Tizen::Base::String url, Tizen::Base::ByteBuffer* pBuffer)
/*result GHhttpClient::RequestImageUpload(Tizen::Base::Runtime::IEventListener* listener, Tizen::Net::Http::IHttpProgressEventListener* listener2, Tizen::Base::String url, Tizen::Base::ByteBuffer* pBuffer)
undefined reference to `GHhttpClient::RequestImageUpload(Tizen::Net::Http::IHttpTransactionEventListener*, Tizen::Base::String, Tizen::Base::ByteBuffer*)*/
{
	AppLog("------------------>Request<------------------------- ");

	//String hostAddr(L"http://54.238.195.222:3000");

	// Construct an HTTP session
	result r = E_SUCCESS;
	HttpTransaction* pHttpTransaction = null;
	HttpRequest* pHttpRequest = null;
	HttpMultipartEntity* pMultipartEntity = null;

	// 주소
	String requestAddr(hostAddr + url);

	if (__pHttpSession == null)
	{
		__pHttpSession = new (std::nothrow) HttpSession();

		r = __pHttpSession->Construct(NET_HTTP_SESSION_MODE_PIPELINING , null, hostAddr, null);
		if (IsFailed(r))
		{
			delete __pHttpSession;
			__pHttpSession = null;
			AppLogException("Failed to create the HttpSession.");
			goto CATCH;
		}

		r = __pHttpSession->SetAutoRedirectionEnabled(true);
		TryCatch(r == E_SUCCESS, , "Failed to set the redirection automatically.");
	}

	AppLog("-------------------------3-------------------------- ");
	//----------------------------------------------------------------------
	// Open a new transaction
	pHttpTransaction = __pHttpSession->OpenTransactionN();
	r = GetLastResult();
	TryCatch(pHttpTransaction != null, , "Failed to open the HttpTransaction.");

	// Add a listener
	//pHttpTransaction->AddHttpTransactionListener(* (reinterpret_cast<Tizen::Net::Http::IHttpTransactionEventListener *> (listener)));
	//pHttpTransaction->SetHttpProgressListener(* (reinterpret_cast<Tizen::Net::Http::IHttpProgressEventListener *> (listener)));
	//TryCatch(r == E_SUCCESS, , "Failed to add the HttpTransactionListener.");
	pHttpTransaction->AddHttpTransactionListener(*listener);
	pHttpTransaction->SetHttpProgressListener(*listener2);

	// Get an HTTP request
	pHttpRequest = const_cast< HttpRequest* >(pHttpTransaction->GetRequest());

	// Set the HTTP method and URI
	r = pHttpRequest->SetUri(requestAddr);
	TryCatch(r == E_SUCCESS, , "Failed to set the uri.");

	r = pHttpRequest->SetMethod(NET_HTTP_METHOD_POST);
	TryCatch(r == E_SUCCESS, , "Failed to set the method.");

/*	HttpHeader* pHeader = null;
	pHeader = pHttpRequest->GetHeader();*/

	///////////// header와 body에 포함시켜서 보냄 /////////////////////
/*
	r = pHeader->AddField(L"Content-Length",L"100000");
		//TryCatch(r == E_SUCCESS, , "Failed to set Length.");
	//r = pHeader->AddField(L"Content-Type",L"image/jpg");
	r = pHeader->AddField(L"Content-Type",L"multipart");
		//TryCatch(r == E_SUCCESS, , "Failed to set Type.");
	r = pHeader->AddField(L"Content-Disposition",L"form-data");
	r = pHeader->AddField(L"name",L"uploadedfile");
	r = pHeader->AddField(L"filename",L"hello.o");

	r = pHttpRequest->WriteBody(*pBuffer);*/
	//TryCatch(r == E_SUCCESS, , "Failed to write body buffer.");
	//////////////////////////////////////////////////////////

	pMultipartEntity = new HttpMultipartEntity();
    pMultipartEntity->Construct();
    //pMultipartEntity->AddFilePart(L"photoFile", Tizen::App::App::GetInstance()->GetAppDataPath() + L"Images/20140430003645.jpg");
    pMultipartEntity->AddFilePart(L"photoFile",	Tizen::App::App::GetInstance()->GetAppDataPath() + L"UserCropped.jpg");
    //pMultipartEntity->AddFilePart(L"photoFile", Tizen::System::Environment::GetMediaPath() + L"Images/image1.jpg");

    pHttpRequest->SetEntity(*pMultipartEntity);

    pHttpTransaction->SetUserObject(pMultipartEntity);

	AppLog("-------------------------2-------------------------- ");

	// Submit the request
	r = pHttpTransaction->Submit();
	TryCatch(r == E_SUCCESS, , "Failed to submit the HttpTransaction.");

	//로그
/*	for(int i = 0; i < pHeader->GetFieldNamesN()->GetCount(); i++)
	{
		AppLog("%s", static_cast< String* > ( pHeader->GetFieldNamesN()->GetAt(i))->GetPointer());
		String *s =  static_cast< String* > (pHeader->GetFieldNamesN()->GetAt(i));

		IEnumerator *irator = pHeader->GetFieldValuesN(*s);
		while(irator->MoveNext() == E_SUCCESS)
		{
			AppLog("%s", static_cast< String* > (irator->GetCurrent())->GetPointer());
		}
	}*/
	return r;

CATCH:

	delete pHttpTransaction;
	pHttpTransaction = null;

	AppLog("RequestHttpDelTran() failed. (%s)", GetErrorMessage(r));
	return r;
}

/*
result GHhttpClient::RequestImageDownload(Tizen::Net::Http::IHttpTransactionEventListener* listener,Tizen::Net::Http::IHttpProgressEventListener* listener2,  Tizen::Base::String url)
{
	AppLog("------------------>Request<------------------------- ");

	// Construct an HTTP session
	result r = E_SUCCESS;
	HttpTransaction* pHttpTransaction = null;
	HttpRequest* pHttpRequest = null;
	HttpMultipartEntity* pMultipartEntity = null;

	// 주소
	String requestAddr(hostAddr + "/players/pkeykichul/image");

	AppLog("url --> %S", requestAddr.GetPointer());

	if (__pHttpSession == null)
	{
		__pHttpSession = new (std::nothrow) HttpSession();

		r = __pHttpSession->Construct(NET_HTTP_SESSION_MODE_PIPELINING , null, hostAddr, null);
		if (IsFailed(r))
		{
			delete __pHttpSession;
			__pHttpSession = null;
			AppLogException("Failed to create the HttpSession.");
			goto CATCH;
		}

		r = __pHttpSession->SetAutoRedirectionEnabled(true);
		TryCatch(r == E_SUCCESS, , "Failed to set the redirection automatically.");
	}
	//----------------------------------------------------------------------
	// Open a new transaction
	pHttpTransaction = __pHttpSession->OpenTransactionN();
	r = GetLastResult();
	TryCatch(pHttpTransaction != null, , "Failed to open the HttpTransaction.");

	// Add a listener
	r = pHttpTransaction->AddHttpTransactionListener(*listener);
	TryCatch(r == E_SUCCESS, , "Failed to add the HttpTransactionListener.");

	pHttpTransaction->AddHttpTransactionListener(*listener);
	pHttpTransaction->SetHttpProgressListener(*listener2);

	// Get an HTTP request
	pHttpRequest = const_cast< HttpRequest* >(pHttpTransaction->GetRequest());

	// Set the HTTP method and URI
	r = pHttpRequest->SetUri(requestAddr);
	TryCatch(r == E_SUCCESS, , "Failed to set the uri.");

	r = pHttpRequest->SetMethod(NET_HTTP_METHOD_GET);
	TryCatch(r == E_SUCCESS, , "Failed to set the method.");

	// Submit the request
	r = pHttpTransaction->Submit();
	TryCatch(r == E_SUCCESS, , "Failed to submit the HttpTransaction.");

	return r;

CATCH:

	delete pHttpTransaction;
	pHttpTransaction = null;

	AppLog("RequestHttpDelTran() failed. (%s)", GetErrorMessage(r));
	return r;
}
*/


