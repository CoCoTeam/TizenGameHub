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


class GHhttpClient
{
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
	result RequestImageUpload(Tizen::Net::Http::IHttpTransactionEventListener* listener, Tizen::Net::Http::IHttpProgressEventListener* listener2, Tizen::Base::String url, Tizen::Base::ByteBuffer* pBuffer);	// [file], filename(formatting -> pkeykichul_20140417153111.png)	// 갤러리 -> 파일 선택 -> 그 파일 경로를 가져오고, filename을 설정해서 서버로 전송
	result RequestImageDownload(Tizen::Net::Http::IHttpTransactionEventListener* listener, Tizen::Base::String url);	// url+[filename] ->download    ==>  byte array -> file로 만들고 <device 폴더>를 만들고 거기에 저장	"pkeykichul_20140417153111.png"


private:
	Tizen::Net::Http::HttpSession* __pHttpSession;
	Tizen::Base::String hostAddr;
};

#endif /* HTTPCLIENT_H_ */
