/*
 * GHLeaderboardController.h
 *
 *  Created on: Mar 28, 2014
 *      Author: Administrator
 */

#ifndef GHLEADERBOARDCONTROLLER_H_
#define GHLEADERBOARDCONTROLLER_H_

#include <GHTizen.h>
#include <GHLeaderboard.h>
#include <GHLeaderboardListener.h>
#include <GHhttpClient.h>
#include <GHController.h>

class GHLeaderboardController
	: public GHController {
public:
	GHLeaderboardController();
	virtual ~GHLeaderboardController();

	// leaderboard 목록을 가져운다.
	void loadLeaderboards(GHLeaderboardListener * listener);	//(static Player)
	//!! Hub App에서 범용적으로 사용하기 위해 Method를 한번 더 감싸준다.
//	private void loadLeaderboards(GHLeaderboardListener * listener, STRING* playerId);

	// leaderboard의 랭킹 목록을 가져온다.
	void loadLeaderboardRank(STRING* leaderboardId);
	void loadLeaderboardRank(STRING* leaderboardId, GHLeaderboardListener * listener);
	//!! View 관점에서 로드할 때 필요한 요소를 parameter로 집어 넣어줄 수 있다.
//	void loadLeaderboardRank(STRING* leaderboardId, bool isOrderAsc = true);
//	void loadLeaderboardRank(STRING* leaderboardId, bool isOrderAsc = true, int startPoint = 0, int maxSize = 10);
//	void loadLeaderboardRank(STRING* leaderboardId, int startPoint = 0, int maxSize = 10);


	// 해당 leaderboard에 점수를 업데이트한다.
	void updateLeaderboardScore(STRING* leaderboardId, long score);		//(static Player)
	void updateLeaderboardScore(STRING* leaderboardId, long score, GHLeaderboardListener * listener);

	// IHttpTransactionEventListener (부모에서 구현함)
//	virtual void OnTransactionReadyToRead(Tizen::Net::Http::HttpSession& httpSession, Tizen::Net::Http::HttpTransaction& httpTransaction, int availableBodyLen);
//	virtual void OnTransactionAborted(Tizen::Net::Http::HttpSession& httpSession, Tizen::Net::Http::HttpTransaction& httpTransaction, result r);
//	virtual void OnTransactionReadyToWrite(Tizen::Net::Http::HttpSession& httpSession, Tizen::Net::Http::HttpTransaction& httpTransaction, int recommendedChunkSize);
//	virtual void OnTransactionHeaderCompleted(Tizen::Net::Http::HttpSession& httpSession, Tizen::Net::Http::HttpTransaction& httpTransaction, int headerLen, bool authRequired);
//	virtual void OnTransactionCompleted(Tizen::Net::Http::HttpSession& httpSession, Tizen::Net::Http::HttpTransaction& httpTransaction);
//	virtual void OnTransactionCertVerificationRequiredN(Tizen::Net::Http::HttpSession& httpSession, Tizen::Net::Http::HttpTransaction& httpTransaction, Tizen::Base::String* pCert);

private:
	virtual void OnTransactionReadyToRead(Tizen::Web::Json::IJsonValue* data);
	Tizen::Base::Collection::HashMap* __pMap;
	GHLeaderboardListener* currentListener;

//	// 현재 리더보드의 View 호출
//	//(Default view)
//	void getLeaderboardList(int start = 0, int max = 10);
//	void getLeaderboardList(long leaderboardId, int start = 0, int max = 10);
//	void getLeaderboardList(long leaderboardId, bool order, int start = 0, int max = 10);
//	//(for Custom view)
////	Tizen::Web::Json::JsonObject* getLeaderboardListData(int start = 0, int max = 10);
////	Tizen::Web::Json::JsonObject* getLeaderboardListData(long leaderboardId, int start = 0, int max = 10);
////	Tizen::Web::Json::JsonObject* getLeaderboardListData(long leaderboardId, bool order, int start = 0, int max = 10);
//
//
//	// 해당 player의 랭킹 호출(API)
//	long getLeaderboardRanking();
////	long getLeaderboardRanking(long playerId);
////	long getLeaderboardRanking(long playerId, long leaderboardId);
//
//	// 해당 player의 점수 호출(API)
//	long getLeaderboardScore();
////	long getLeaderboardScore(long playerId);
////	long getLeaderboardScore(long playerId, long leaderboardId);
//
////	// 해당 player의 GameTotal 점수 호출(API)
////	long getTotalLeaderboardGAMETotalScore();
////	long getTotalLeaderboardGameTotalScore(long playerId);
////	long getTotalLeaderboardGameTotalScore(long playerId, long gameId);
////
////	// 해당 player의 총 점수 호출(API)	//!!GHPlayer로?
////	long getTotalLeaderboardTotalScore();
////	long getTotalLeaderboardTotalScore(long playerId);

};

#endif /* GHLEADERBOARDCONTROLLER_H_ */
