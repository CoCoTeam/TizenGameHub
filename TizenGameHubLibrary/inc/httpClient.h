/*
 * httpClient.h
 *
 *  Created on: Mar 27, 2014
 *      Author: KICHUL
 */

#ifndef HTTPCLIENT_H_
#define HTTPCLIENT_H_

#include <FApp.h>
#include <FBase.h>
#include <FNet.h>
#include <FUi.h>
#include <FText.h>

class httpClient
	: public Tizen::Net::Http::IHttpTransactionEventListener
{
public:
	httpClient();
	virtual ~httpClient();

	// IHttpTransactionEventListener
	virtual void OnTransactionReadyToRead(Tizen::Net::Http::HttpSession& httpSession, Tizen::Net::Http::HttpTransaction& httpTransaction, int availableBodyLen);
	virtual void OnTransactionAborted(Tizen::Net::Http::HttpSession& httpSession, Tizen::Net::Http::HttpTransaction& httpTransaction, result r);
	virtual void OnTransactionReadyToWrite(Tizen::Net::Http::HttpSession& httpSession, Tizen::Net::Http::HttpTransaction& httpTransaction, int recommendedChunkSize);
	virtual void OnTransactionHeaderCompleted(Tizen::Net::Http::HttpSession& httpSession, Tizen::Net::Http::HttpTransaction& httpTransaction, int headerLen, bool authRequired);
	virtual void OnTransactionCompleted(Tizen::Net::Http::HttpSession& httpSession, Tizen::Net::Http::HttpTransaction& httpTransaction);
	virtual void OnTransactionCertVerificationRequiredN(Tizen::Net::Http::HttpSession& httpSession, Tizen::Net::Http::HttpTransaction& httpTransaction, Tizen::Base::String* pCert);

private:
	result RequestHttpGet(void);
	result RequestHttpPost(void);

private:
	Tizen::Net::Http::HttpSession* __pHttpSession;

	Tizen::Ui::Controls::Button* __pButton;
	Tizen::Ui::Controls::EditArea* __pEditArea;
};

#endif /* HTTPCLIENT_H_ */
