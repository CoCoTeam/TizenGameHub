/*
 * GHController.cpp
 *
 *  Created on: Apr 1, 2014
 *      Author: KICHUL
 */

#include "GHController.h"

using namespace Tizen::Base::Collection;
using namespace Tizen::Base;

using namespace Tizen::Net::Http;
using namespace Tizen::Web::Json;

GHController::GHController() {
	// TODO Auto-generated constructor stub

}

GHController::~GHController() {
	// TODO Auto-generated destructor stub
}


void GHController::OnTransactionReadyToRead(HttpSession& httpSession, HttpTransaction& httpTransaction, int availableBodyLen)
{
	// 현재는 response data를 받아서 화면에 뿌리도록 함.
	AppLog("OnTransactionReadyToRead");

	HttpResponse* pHttpResponse = httpTransaction.GetResponse();
	if (pHttpResponse->GetHttpStatusCode() == HTTP_STATUS_OK)
	{
		HttpHeader* pHttpHeader = pHttpResponse->GetHeader();
		if (pHttpHeader != null)
		{

			String* tempHeaderString = pHttpHeader->GetRawHeaderN();

			// 응답받은 데이터를 버퍼에 가져온다.
			ByteBuffer* pBuffer = pHttpResponse->ReadBodyN();


			// 받아온 buffer를  JsonValue로 파싱한다.
			IJsonValue* pValue = JsonParser::ParseN(*pBuffer);

			JsonObject* pJsonObj = static_cast<JsonObject*>(pValue);

			String* pStrApiKey     = new String(L"apiCode");
			IJsonValue* pApiValue = null;
			pJsonObj->GetValue(pStrApiKey, pApiValue);
			JsonString* pApiStr = static_cast<JsonString*>(pApiValue);

			String* pStrFNKey     = new String(L"statusCode");
			IJsonValue* pStatusValue = null;
			pJsonObj->GetValue(pStrFNKey, pStatusValue);
			JsonString* pStatusStr = static_cast<JsonString*>(pStatusValue);

			String* pStrDataKey     = new String(L"data");
			IJsonValue* pDataValue = null;
			pJsonObj->GetValue(pStrDataKey, pDataValue);

			//AppLogDebug("api : %S, status : %S", pApiStr->GetPointer(), pStatusStr->GetPointer());

			// 자식 객체의 함수를 호출한다.
			String apiCode(pApiStr->GetPointer());
			String statusCode(pStatusStr->GetPointer());

			this->OnTransactionReadyToRead(apiCode, statusCode, pDataValue);

			delete pApiStr;
			delete pStatusStr;
			delete pStrFNKey;
			delete pStrApiKey;
			delete tempHeaderString;
			delete pBuffer;
		}
	}
}

void GHController::OnTransactionAborted(HttpSession& httpSession, HttpTransaction& httpTransaction, result r)
{
	AppLog("OnTransactionAborted(%s)", GetErrorMessage(r));

	delete &httpTransaction;
}

void GHController::OnTransactionReadyToWrite(HttpSession& httpSession, HttpTransaction& httpTransaction, int recommendedChunkSize)
{
	AppLog("OnTransactionReadyToWrite");
}

void GHController::OnTransactionHeaderCompleted(HttpSession& httpSession, HttpTransaction& httpTransaction, int headerLen, bool authRequired)
{
	AppLog("OnTransactionHeaderCompleted");
}

void GHController::OnTransactionCompleted(HttpSession& httpSession, HttpTransaction& httpTransaction)
{
	AppLog("OnTransactionCompleted");

	delete &httpTransaction;
}

void GHController::OnTransactionCertVerificationRequiredN(HttpSession& httpSession, HttpTransaction& httpTransaction, Tizen::Base::String* pCert)
{
	AppLog("OnTransactionCertVerificationRequiredN");

	httpTransaction.Resume();

	delete pCert;
}
