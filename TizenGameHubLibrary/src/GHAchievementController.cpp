/*
 * GHAchievementController.cpp
 *
 *  Created on: Mar 26, 2014
 *      Author: JOHEEYEON
 */

#include "GHAchievementController.h"

using namespace Tizen::Net::Http;
using namespace Tizen::Base;

//game id: key_aa
//player id: pkeykichul

//GHListener* Plistener;

GHAchievementController::GHAchievementController() {
	// TODO Auto-generated constructor stub

}

GHAchievementController::~GHAchievementController() {
	// TODO Auto-generated destructor stub
}


// Achievement 목록을 가져온다.
void GHAchievementController::loadAchievements(GHAchievementsLoadedListener* listener) {
	GHhttpClient* httpPost = new GHhttpClient();
	//httpPost->RequestHttpPost(this);

	//GET 함수 호출
/*	String game_id("key_aa");
	httpPost->RequestHttpGetTran(this, new String(L"/achievements/" + game_id));*/


	//post 함수 호출
/*	__pMap = new (std::nothrow) HashMap();
	__pMap->Construct();

	__pMap->Add(new String(L"email"), new String(L"kichulee"));
	__pMap->Add(new String(L"pwd"), new String(L"kichulbabo"));
	__pMap->Add(new String(L"name"), new String(L"kichul"));
	__pMap->Add(new String(L"img_url"), new String(L"kichul.jpg"));

	httpPost->RequestHttpPostTran(this, new String(L"/players"), __pMap);*/


	////put함수 호출
/*	String game_id("key_aa");
	String ac_id("3");

	__pMap = new (std::nothrow) HashMap();
	__pMap->Construct();

	__pMap->Add(new String(L"title"), new String(L"kichul"));
	__pMap->Add(new String(L"description"), new String(L"kichul"));
	__pMap->Add(new String(L"img_url"), new String(L"kichul"));
	__pMap->Add(new String(L"list_order"), new String(L"1"));

	httpPost->RequestHttpPutTran(this, new String(L"/achievements/" + game_id + "/" + ac_id), __pMap);*/

	//DELETE함수 호출
	String game_id("key_aa");
	String ac_id("3");
	httpPost->RequestHttpDelTran(this, new String(L"/achievements/" + game_id + "/" + ac_id));


	// 통신끝난 후 호출하면서 데이터를 전달해야 한다. // 개발자는 GHAchievementLoadedListener를 상속받아서 아래 함수를 구현해놔야 한다.
	//GHAchievement* array = new GHAchievement[3];
	//listener->loadAchievementsFinished(array, this);
}

// hidden -> reveal 상태로 바꾼다.
void GHAchievementController::revealAchievement(STRING* id) {

}
void GHAchievementController::revealAchievement(GHAchievementsUpdatedListener* listener, STRING* id) {
	listener->updateAchievementsFinished();
}

// normal achievement update
void GHAchievementController::completeAchievement(STRING* id) {

}
void GHAchievementController::completeAchievement(GHAchievementsUpdatedListener* listener, STRING* id) {
	listener->updateAchievementsFinished();
}

// incremental achievement update
void GHAchievementController::increaseAchievement(STRING* id) {

}
void GHAchievementController::increaseAchievement(GHAchievementsUpdatedListener* listener, STRING* id) {
	listener->updateAchievementsFinished();
}


// HTTP 통신 Listener -------------------------------------------------------------------------------------------------------

// Request 후 Response 를 받았을 때 처리
void GHAchievementController::OnTransactionReadyToRead(HttpSession& httpSession, HttpTransaction& httpTransaction, int availableBodyLen)
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

			AppLogDebug("[HTTP] response body size : %d " , availableBodyLen );

			// 버퍼의 데이터를 string으로 추출.
			byte* tempBody = new byte[availableBodyLen+1];
			pBuffer->GetArray(tempBody, 0, availableBodyLen);
			tempBody[availableBodyLen] = '\0';

			AppLogDebug("[HTTP] response data : %s", (char *)tempBody);



			//Plistener->function();

			//String text = (const char *)tempBody;
			// text control에 가져온 데이터를 보여준다.
			//_pEditArea->SetText(text);

			delete tempHeaderString;
			delete pBuffer;
		}
	}
}

void GHAchievementController::OnTransactionAborted(HttpSession& httpSession, HttpTransaction& httpTransaction, result r)
{
	AppLog("OnTransactionAborted(%s)", GetErrorMessage(r));

	delete &httpTransaction;
}

void GHAchievementController::OnTransactionReadyToWrite(HttpSession& httpSession, HttpTransaction& httpTransaction, int recommendedChunkSize)
{
	AppLog("OnTransactionReadyToWrite");
}

void GHAchievementController::OnTransactionHeaderCompleted(HttpSession& httpSession, HttpTransaction& httpTransaction, int headerLen, bool authRequired)
{
	AppLog("OnTransactionHeaderCompleted");
}

void GHAchievementController::OnTransactionCompleted(HttpSession& httpSession, HttpTransaction& httpTransaction)
{
	AppLog("OnTransactionCompleted");

	delete &httpTransaction;
}

void GHAchievementController::OnTransactionCertVerificationRequiredN(HttpSession& httpSession, HttpTransaction& httpTransaction, Tizen::Base::String* pCert)
{
	AppLog("OnTransactionCertVerificationRequiredN");

	httpTransaction.Resume();

	delete pCert;
}
