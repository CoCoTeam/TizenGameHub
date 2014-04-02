<<<<<<< HEAD
/*
 * GHController.h
 *
 *  Created on: Apr 1, 2014
 *      Author: KICHUL
 */

#ifndef GHCONTROLLER_H_
#define GHCONTROLLER_H_

#include <GHTizen.h>
#include <GHhttpClient.h>

class GHController
	: public Tizen::Net::Http::IHttpTransactionEventListener {
public:
	GHController();
	virtual ~GHController();

public:
	// IHttpTransactionEventListener
	virtual void OnTransactionReadyToRead(Tizen::Net::Http::HttpSession& httpSession, Tizen::Net::Http::HttpTransaction& httpTransaction, int availableBodyLen);
	virtual void OnTransactionAborted(Tizen::Net::Http::HttpSession& httpSession, Tizen::Net::Http::HttpTransaction& httpTransaction, result r);
	virtual void OnTransactionReadyToWrite(Tizen::Net::Http::HttpSession& httpSession, Tizen::Net::Http::HttpTransaction& httpTransaction, int recommendedChunkSize);
	virtual void OnTransactionHeaderCompleted(Tizen::Net::Http::HttpSession& httpSession, Tizen::Net::Http::HttpTransaction& httpTransaction, int headerLen, bool authRequired);
	virtual void OnTransactionCompleted(Tizen::Net::Http::HttpSession& httpSession, Tizen::Net::Http::HttpTransaction& httpTransaction);
	virtual void OnTransactionCertVerificationRequiredN(Tizen::Net::Http::HttpSession& httpSession, Tizen::Net::Http::HttpTransaction& httpTransaction, Tizen::Base::String* pCert);

protected:
	GHhttpClient httpPost;
	virtual void OnTransactionReadyToRead(Tizen::Base::String apiCode, Tizen::Base::String statusCode, Tizen::Web::Json::IJsonValue* data) = 0;
};

#endif /* GHCONTROLLER_H_ */
=======
/*
 * GHController.h
 *
 *  Created on: Apr 1, 2014
 *      Author: KICHUL
 */

#ifndef GHCONTROLLER_H_
#define GHCONTROLLER_H_

#include <GHTizen.h>
#include <GHhttpClient.h>

class GHController
	: public Tizen::Net::Http::IHttpTransactionEventListener {
public:
	GHController();
	virtual ~GHController();

public:
	// IHttpTransactionEventListener
	virtual void OnTransactionReadyToRead(Tizen::Net::Http::HttpSession& httpSession, Tizen::Net::Http::HttpTransaction& httpTransaction, int availableBodyLen);
	virtual void OnTransactionAborted(Tizen::Net::Http::HttpSession& httpSession, Tizen::Net::Http::HttpTransaction& httpTransaction, result r);
	virtual void OnTransactionReadyToWrite(Tizen::Net::Http::HttpSession& httpSession, Tizen::Net::Http::HttpTransaction& httpTransaction, int recommendedChunkSize);
	virtual void OnTransactionHeaderCompleted(Tizen::Net::Http::HttpSession& httpSession, Tizen::Net::Http::HttpTransaction& httpTransaction, int headerLen, bool authRequired);
	virtual void OnTransactionCompleted(Tizen::Net::Http::HttpSession& httpSession, Tizen::Net::Http::HttpTransaction& httpTransaction);
	virtual void OnTransactionCertVerificationRequiredN(Tizen::Net::Http::HttpSession& httpSession, Tizen::Net::Http::HttpTransaction& httpTransaction, Tizen::Base::String* pCert);

protected:
	GHhttpClient httpPost;
	virtual void OnTransactionReadyToRead(Tizen::Web::Json::IJsonValue* data) = 0;

	// JSON FUNCTION - JSON Object
	Tizen::Web::Json::JsonArray	  getJsonArrayByKey(Tizen::Web::Json::JsonObject jsonObj, String key);
	Tizen::Web::Json::JsonObject  getJsonObjectByKey(Tizen::Web::Json::JsonObject jsonObj, String key);
	Tizen::Base::String			  getStringByKey(Tizen::Web::Json::JsonObject jsonObj, String key);
	int							  getIntByKey(Tizen::Web::Json::JsonObject jsonObj, String key);
	bool						  getBoolByKey(Tizen::Web::Json::JsonObject jsonObj, String key);

	// JSON FUNCTION - JSON Array
	Tizen::Web::Json::JsonArray	  getJsonArrayByIndex(Tizen::Web::Json::JsonArray jsonArr, String key);
	Tizen::Web::Json::JsonObject  getJsonObjectByIndex(Tizen::Web::Json::JsonArray jsonArr, String key);
	Tizen::Base::String	  		  getStringByIndex(Tizen::Web::Json::JsonArray jsonArr, String key);
	int	  						  getIntByIndex(Tizen::Web::Json::JsonArray jsonArr, String key);
	bool	  					  getBoolByIndex(Tizen::Web::Json::JsonArray jsonArr, String key);

};

#endif /* GHCONTROLLER_H_ */
>>>>>>> 7544b60ef4349d0f629f2703bf4aa265f9df5ea2
