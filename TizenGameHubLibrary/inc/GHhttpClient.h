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


class GHhttpClient {
public:
	GHhttpClient();
	virtual ~GHhttpClient();

public:
	result RequestHttpGet(Tizen::Net::Http::IHttpTransactionEventListener* listener);
	result RequestHttpPost(Tizen::Net::Http::IHttpTransactionEventListener* listener);
	result RequestHttpGetTran(Tizen::Net::Http::IHttpTransactionEventListener* listener, Tizen::Base::String url);
	result RequestHttpPostTran(Tizen::Net::Http::IHttpTransactionEventListener* listener, Tizen::Base::String url, Tizen::Base::Collection::IMap *map);
	result RequestHttpPutTran(Tizen::Net::Http::IHttpTransactionEventListener* listener, Tizen::Base::String url, Tizen::Base::Collection::IMap *map);
	result RequestHttpDelTran(Tizen::Net::Http::IHttpTransactionEventListener* listener, Tizen::Base::String url);
	result RequestImageUpload();	// [file], filename(formatting -> pkeykichul_20140417153111.png)
	result RequestImageDownload();	// url+[filename] ->download    ==> device 폴더를 만들고 거기에 저장	"pkeykichul_20140417153111.png"

private:
	Tizen::Net::Http::HttpSession* __pHttpSession;
	Tizen::Base::String hostAddr;
};

#endif /* HTTPCLIENT_H_ */
