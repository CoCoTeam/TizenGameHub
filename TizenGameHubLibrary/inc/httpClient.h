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


class httpClient {
public:
	httpClient();
	virtual ~httpClient();

public:
	result RequestHttpGet(Tizen::Net::Http::IHttpTransactionEventListener* listener);
	result RequestHttpPost(Tizen::Net::Http::IHttpTransactionEventListener* listener);
	result RequestHttpGetTran(Tizen::Net::Http::IHttpTransactionEventListener* listener, Tizen::Base::String *url);
	result RequestHttpPostTran(Tizen::Net::Http::IHttpTransactionEventListener* listener, Tizen::Base::String *url, Tizen::Base::Collection::IMap *map);
	result RequestHttpPutTran(Tizen::Net::Http::IHttpTransactionEventListener* listener, Tizen::Base::String *url, Tizen::Base::Collection::IMap *map);
	result RequestHttpDelTran(Tizen::Net::Http::IHttpTransactionEventListener* listener, Tizen::Base::String *url);

private:
	Tizen::Net::Http::HttpSession* __pHttpSession;
	Tizen::Base::String hostAddr;
};

#endif /* HTTPCLIENT_H_ */
