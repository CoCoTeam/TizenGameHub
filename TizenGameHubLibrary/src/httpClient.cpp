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
#include "httpClient.h"

using namespace Tizen::App;
using namespace Tizen::Base;
using namespace Tizen::Net::Http;

using namespace Tizen::Base::Utility;


httpClient::httpClient(void)
	: __pHttpSession(null)
{
}

httpClient::~httpClient(void)
{
	if (__pHttpSession != null)
	{
		delete __pHttpSession;
		__pHttpSession = null;
	}
}


// GET 방식의 요청 보내기.
result
httpClient::RequestHttpGet(IHttpTransactionEventListener* listener)
{
	//----------------------------------------------------------------------
	// Construct an HTTP session
	result r = E_SUCCESS;
	HttpTransaction* pHttpTransaction = null;
	HttpRequest* pHttpRequest = null;

	// 주소
	String player_id = "hhhh";
	String hostAddr(L"http://211.189.127.187:8081");
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
httpClient::RequestHttpPost(IHttpTransactionEventListener* listener)
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

