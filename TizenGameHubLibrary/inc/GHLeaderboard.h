/*
 * GHLeaderboard.h
 *
 *  Created on: Mar 24, 2014
 *      Author: Administrator
 */

#ifndef GHLEADERBOARD_H_
#define GHLEADERBOARD_H_

#include <GHTizen.h>
/*
lb_id		리더보드 고유키
title		leaderboard 제목
//format		numeric/time
img_url		leaderboard 대표 이미지 url
unit		단위
order		오름차순/내림차순 순서
is_time		자신의 점수 데이터를 시간형태로 표현하는 것을 설정하는 여부

player_id		사용자 고유키
score			해당 leaderboard에서 비교되는 점수
update_time		기록 업데이트 시간
 */
class GHLeaderboard {
private:
	long id;
	long gameId;	//!!
	STRING* title;
	STRING* imgUrl;
	STRING* unit;
	bool misAscendingOrder;
	bool misTimeFormat;

public:
	GHLeaderboard();
//	GHLeaderboard(Tizen::Web::Json::JsonObject *jsonData);
	virtual ~GHLeaderboard();

	/// Get Instance
//	static GHLeaderboard* getLeaderboardInstance(long leaderboardId)
//	{
//		Tizen::Web::Json::JsonObject *jsonData;
//		jsonData->Construct();
//		return new GHLeaderboard(jsonData);
//	}
	//////////

	/// Get Functions
	long getId();
//	long getGameId();
	STRING* getTitle();
	STRING* getImgUrl();
	STRING* getUnit();
	bool isAscendingOrder();
	bool isTimeFormat();
	//////////

	// 현재 게임의 리더보드 리스트 호출  //!!GHGame으로?


	// 현재 리더보드의 View 호출
	//(Default view)
	void getLeaderboardList(int start = 0, int max = 10);
	void getLeaderboardList(long leaderboardId, int start = 0, int max = 10);
	void getLeaderboardList(long leaderboardId, bool order, int start = 0, int max = 10);
	//(for Custom view)
//	Tizen::Web::Json::JsonObject* getLeaderboardListData(int start = 0, int max = 10);
//	Tizen::Web::Json::JsonObject* getLeaderboardListData(long leaderboardId, int start = 0, int max = 10);
//	Tizen::Web::Json::JsonObject* getLeaderboardListData(long leaderboardId, bool order, int start = 0, int max = 10);


	// 해당 player의 랭킹 호출(API)
	long getLeaderboardRanking();
	long getLeaderboardRanking(long playerId);
	long getLeaderboardRanking(long playerId, long leaderboardId);

	// 해당 player의 점수 호출(API)
	long getLeaderboardScore();
	long getLeaderboardScore(long playerId);
	long getLeaderboardScore(long playerId, long leaderboardId);

	// 해당 player의 GameTotal 점수 호출(API)
	long getTotalLeaderboardGAMETotalScore();
	long getTotalLeaderboardGameTotalScore(long playerId);
	long getTotalLeaderboardGameTotalScore(long playerId, long gameId);

	// 해당 player의 총 점수 호출(API)	//!!GHPlayer로?
	long getTotalLeaderboardTotalScore();
	long getTotalLeaderboardTotalScore(long playerId);


};

#endif /* GHLEADERBOARD_H_ */
