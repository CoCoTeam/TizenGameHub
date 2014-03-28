/*
 * GHLeaderboardController.cpp
 *
 *  Created on: Mar 28, 2014
 *      Author: Administrator
 */

#include "GHLeaderboardController.h"

using namespace Tizen::Net::Http;
using namespace Tizen::Base;

GHLeaderboardController::GHLeaderboardController() {
	// TODO Auto-generated constructor stub

}

GHLeaderboardController::~GHLeaderboardController() {
	// TODO Auto-generated destructor stub
}

void GHLeaderboardController::loadLeaderboards(GHLeaderboardListener * listener)
{
	this->currentListener = listener;

	GHhttpClient* httpPost = new GHhttpClient();

	//GET 함수 호출
	String game_id("key_aa");
	httpPost->RequestHttpGetTran(this, new String(L"/f_leaderboards/" + game_id));
}

// leaderboard의 랭킹 목록을 가져온다.
void GHLeaderboardController::loadLeaderboardRank(STRING* leaderboardId)
{
	GHhttpClient* httpPost = new GHhttpClient();

	//GET 함수 호출
	String game_id("key_aa");
	String lb_id("key_lb");
	String external = "?order=true&start_pos=0&max_length=10";
	httpPost->RequestHttpGetTran(this, new String(L"/f_leaderboards/rank/" + game_id +"/"+ lb_id));

}
void GHLeaderboardController::loadLeaderboardRank(STRING* leaderboardId, GHLeaderboardListener * listener)
{
	this->currentListener = listener;
	loadLeaderboardRank(leaderboardId);
}


// 해당 leaderboard에 점수를 업데이트한다.
void GHLeaderboardController::updateLeaderboardScore(STRING* leaderboardId, long score)
{

	GHhttpClient* httpPost = new GHhttpClient();

	String* game_id = new String("key_aa");
	String* lb_id = new String(*leaderboardId);
	Long* pScore = new Long(score);

	__pMap = new (std::nothrow) Tizen::Base::Collection::HashMap();
	__pMap->Construct();
	__pMap->Add(new String("game_id"), game_id);
	__pMap->Add(new String("lb_id"), lb_id);
	__pMap->Add(new String("score"), pScore);

	//Put 함수 호출
	httpPost->RequestHttpPutTran(this, new String(L"/f_leaderboards/update"), __pMap);
}
void GHLeaderboardController::updateLeaderboardScore(STRING* leaderboardId, long score, GHLeaderboardListener * listener)
{
	this->currentListener = listener;
	updateLeaderboardScore(leaderboardId, score);
}



// HTTP 통신 Listener -------------------------------------------------------------------------------------------------------

// Request 후 Response 를 받았을 때 처리
void GHLeaderboardController::OnTransactionReadyToRead(HttpSession& httpSession, HttpTransaction& httpTransaction, int availableBodyLen)
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
//			if(tmpeBody->header == "updateLeaderboardScore") {
//				currentListener->doLeaderboardScoreUpdateFineshed();
//			}
//			else if(tmpeBody->header == "loadLeaderboardRank") {
//				currentListener->fdfdf();
//			}
			//////////////////////////////////////////////////////////////////
			//////////////////////////////////////////////////////////////////

			delete tempHeaderString;
			delete pBuffer;
		}
	}
}

void GHLeaderboardController::OnTransactionAborted(HttpSession& httpSession, HttpTransaction& httpTransaction, result r)
{
	AppLog("OnTransactionAborted(%s)", GetErrorMessage(r));

	delete &httpTransaction;
}

void GHLeaderboardController::OnTransactionReadyToWrite(HttpSession& httpSession, HttpTransaction& httpTransaction, int recommendedChunkSize)
{
	AppLog("OnTransactionReadyToWrite");
}

void GHLeaderboardController::OnTransactionHeaderCompleted(HttpSession& httpSession, HttpTransaction& httpTransaction, int headerLen, bool authRequired)
{
	AppLog("OnTransactionHeaderCompleted");
}

void GHLeaderboardController::OnTransactionCompleted(HttpSession& httpSession, HttpTransaction& httpTransaction)
{
	AppLog("OnTransactionCompleted");

	delete &httpTransaction;
}

void GHLeaderboardController::OnTransactionCertVerificationRequiredN(HttpSession& httpSession, HttpTransaction& httpTransaction, Tizen::Base::String* pCert)
{
	AppLog("OnTransactionCertVerificationRequiredN");

	httpTransaction.Resume();

	delete pCert;
}
