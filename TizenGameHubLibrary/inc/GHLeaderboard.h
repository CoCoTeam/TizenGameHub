/*
 * GHLeaderboard.h
 *
 *  Created on: Mar 24, 2014
 *      Author: Administrator
 */

#ifndef GHLEADERBOARD_H_
#define GHLEADERBOARD_H_

#include "GHTizen.h"

class GHLeaderboard
: public Tizen::Base::Object {

private:

	//----------------------------------------------------------------
	// variables
	Tizen::Base::String id;					// leaderboard 고유키
	Tizen::Base::String title;				// leaderboard 제목
	Tizen::Base::String imgUrl;				// leaderboard 대표 이미지
	Tizen::Base::String unit;				// leaderboard 표시 단위

	bool isAscendingOrder;		// 정렬 순서 ()
	bool isTimeFormat;			// 데이터 타입 시간 ()

	Tizen::Base::Collection::ArrayList* learderboardRankList;

public:
	GHLeaderboard();

	GHLeaderboard(Tizen::Base::String _id, Tizen::Base::String _title, Tizen::Base::String _imgUrl, Tizen::Base::String _unit, bool _isAscendingOrder, bool _isTimeFormat);
	GHLeaderboard(Tizen::Base::String _id, Tizen::Base::String _title, Tizen::Base::String _imgUrl);
	GHLeaderboard(Tizen::Base::String _id, Tizen::Base::String _unit, bool _isAscendingOrder, bool _isTimeFormat, Tizen::Base::Collection::ArrayList* learderboardRankList);

	virtual ~GHLeaderboard();

	//----------------------------------------------------------------
	// GET Functions
	Tizen::Base::String getId();
	Tizen::Base::String getTitle();
	Tizen::Base::String getImgUrl();
	Tizen::Base::String getUnit();

	bool getIsAscendingOrder();
	bool getIsTimeFormat();
	//----------------------------------------------------------------
};

#endif /* GHLEADERBOARD_H_ */

/*

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

*/
