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
void GHAchievementController::loadAchievements(GHAchievementListener* listener) {

	this->currentListener = listener;

	GHhttpClient* httpPost = new GHhttpClient();


	//GET 함수 호출
	String game_id("key_aa");
	String player_id("pkeykichul");
	httpPost->RequestHttpGetTran(this, new String(L"/f_achievements/" + game_id + "/" + player_id));
}

// hidden -> reveal 상태로 바꾼다.
void GHAchievementController::revealAchievement(STRING* id) {

}
void GHAchievementController::revealAchievement(GHAchievementListener* listener, STRING* id) {
	this->currentListener = listener;
}

// normal achievement update
void GHAchievementController::completeAchievement(STRING* id) {

}
void GHAchievementController::completeAchievement(GHAchievementListener* listener, STRING* id) {
	this->currentListener = listener;
}

// incremental achievement update
void GHAchievementController::increaseAchievement(STRING* id) {

}
void GHAchievementController::increaseAchievement(GHAchievementListener* listener, STRING* id) {
	this->currentListener = listener;
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

			//////////////////////////////////////////////////////////////////
			// 실제로는 리턴값을 상황에 따라 가공해서 넘겨준다.//////////////////////
			GHAchievement* array = new GHAchievement[3];
			currentListener->doAchievementFinished(array);
			//////////////////////////////////////////////////////////////////
			//////////////////////////////////////////////////////////////////

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
