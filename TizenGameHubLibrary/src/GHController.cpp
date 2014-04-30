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



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// JSON FUNCTION  /////////////////////////////////////////////////////////////////////////////////////////////////
JsonArray* GHController::getJsonArrayByKey(JsonObject *pJsonObj, const String *key)
{

	IJsonValue * pObjValue = null;
	pJsonObj->GetValue(key, pObjValue);

	JsonArray * pRet = static_cast<JsonArray*>(pObjValue);

//	if(pObjValue != null) delete pObjValue;

	return pRet;
}

JsonObject* GHController::getJsonObjectByKey(JsonObject* pJsonObj, const String *key)
{
	IJsonValue * pObjValue = null;
	pJsonObj->GetValue(key, pObjValue);

	JsonObject * pRet = static_cast<JsonObject*>(pObjValue);

//	if(pObjValue != null) delete pObjValue;

	return pRet;
}
String GHController::getStringByKey(JsonObject* pJsonObj, const String *key)
{
	IJsonValue * pObjValue = null;

	pJsonObj->GetValue(key, pObjValue);
	JsonString * pJsonStr = static_cast<JsonString*>(pObjValue);

	String ret(pJsonStr->GetPointer());
	if(pObjValue!= null) delete pObjValue;

	return ret;

}
int	GHController::getIntByKey(JsonObject* pJsonObj, const String *key)
{

	IJsonValue * pObjValue = null;
	pJsonObj->GetValue(key, pObjValue);

	JsonNumber * pJsonNum = static_cast<JsonNumber*>(pObjValue);
	int ret = pJsonNum->ToInt();

	if(pObjValue!= null) delete pObjValue;

	return ret;

}
bool GHController::getBoolByKey(Tizen::Web::Json::JsonObject* pJsonObj, const Tizen::Base::String* key)
{

	IJsonValue * pObjValue = null;
	pJsonObj->GetValue(key, pObjValue);

	JsonNumber * pJsonNum = static_cast<JsonNumber*>(pObjValue);
	bool ret = ( pJsonNum->ToInt() == 1 ? true : false);

	if(pObjValue!= null) delete pObjValue;

	return ret;

}

JsonArray* GHController::getJsonArrayByIndex(JsonArray* pJsonArr, const int index)
{
	IJsonValue* pObjValue = null;
	pJsonArr->GetAt(index, pObjValue);

	JsonArray * pRet = static_cast<JsonArray*>(pObjValue);

//	if(pObjValue != null) delete pObjValue;

	return pRet;

}
JsonObject*	GHController::getJsonObjectByIndex(JsonArray* pJsonArr,  const int index)
{
	IJsonValue* pObjValue = null;
	pJsonArr->GetAt(index, pObjValue);

	JsonObject * pRet = static_cast<JsonObject*>(pObjValue);

//	if(pObjValue != null) delete pObjValue;

	return pRet;

}
String GHController::getStringByIndex(JsonArray* pJsonArr,  const int index)
{
	IJsonValue* pObjValue = null;
	pJsonArr->GetAt(index, pObjValue);

	JsonString * pJsonStr = static_cast<JsonString*>(pObjValue);
	String ret(pJsonStr->GetPointer());

	if(pObjValue!= null) delete pObjValue;

	return ret;

}
int GHController::getIntByIndex(JsonArray* pJsonArr, const int index)
{
	IJsonValue* pObjValue = null;
	pJsonArr->GetAt(index, pObjValue);

	JsonNumber * pJsonNum = static_cast<JsonNumber*>(pObjValue);
	int ret = pJsonNum->ToInt();

	if(pObjValue != null) delete pObjValue;
	return ret;

}
bool GHController::getBoolByIndex(JsonArray* pJsonArr, const int index)
{
	IJsonValue* pObjValue = null;
	pJsonArr->GetAt(index, pObjValue);

	JsonNumber * pJsonNum = static_cast<JsonNumber*>(pObjValue);
	bool ret = ( pJsonNum->ToInt() == 1 ? true : false);

	if(pObjValue != null) delete pObjValue;
	return ret;

}

//
//// reveal, complete, increase TEST /////////////////////////////////////////////////////////
//JsonArray* pJsonArray = static_cast<JsonArray*>(data);
//String* pStrFNKey      = new String(L"statusCode");
//IJsonValue* pObjValue = null;
//pJsonObj->GetValue(pStrFNKey, pObjValue);
//JsonString* pJsonStr = static_cast<JsonString*>(pObjValue);
//AppLogDebug("value : %S", pJsonStr->GetPointer());
/////////////////////////////////////////////////////////////////////



//	// load TEST /////////////////////////////////////////////////////////
//	// 0번째 있는 배열의 값(JsonObject를 가지고 온다.)
//	IJsonValue* pValue = null;
//	pJsonArray->GetAt(0, pValue);
//	JsonObject* pJsonObj = static_cast<JsonObject*>(pValue);
//
//	// Key에 대한 값을 뽑는다.
//	String* pStrFNKey      = new String(L"img_url");
//	IJsonValue* pObjValue = null;
//	pJsonObj->GetValue(pStrFNKey, pObjValue);
//
//	String* pStrFNKey2      = new String(L"ac_id");
//	IJsonValue* pObjValue2 = null;
//	pJsonObj->GetValue(pStrFNKey2, pObjValue2);
//
//	// 형변환 한다.
//	JsonString* pJsonStr = static_cast<JsonString*>(pObjValue);
//	JsonNumber* pJsonNum = static_cast<JsonNumber*>(pObjValue2);
//
//	// JsonString*을 String으로 변환한다.
//	//String zString(pJsonStr->GetPointer());
//
//	AppLogDebug("value : %S", pJsonStr->GetPointer());
//	AppLogDebug("value : %d", pJsonNum->ToInt());
//	///////////////////////////////////////////////////////////////////
