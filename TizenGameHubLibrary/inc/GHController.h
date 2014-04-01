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
	virtual void OnTransactionReadyToRead(Tizen::Web::Json::IJsonValue* data) = 0;
};

#endif /* GHCONTROLLER_H_ */
