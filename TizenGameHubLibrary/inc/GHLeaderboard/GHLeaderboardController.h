/*
 * GHLeaderboardController.h
 *
 *  Created on: Mar 28, 2014
 *      Author: Administrator
 */

#ifndef GHLEADERBOARDCONTROLLER_H_
#define GHLEADERBOARDCONTROLLER_H_

#include "GHTizen.h"
#include "GHLeaderboard.h"
#include "GHLeaderboard/GHLeaderboardListener.h"
#include "GHLeaderboard/GHLeaderboardDataLoadedListener.h"
#include "GHLeaderboard/GHLeaderboardScoreUpdatedListener.h"
#include "GHLeaderboard/GHLeaderboardListLoadedListener.h"
#include "GHhttpClient.h"
#include "GHController.h"
#include "GHPlayerRank.h"

const Tizen::Base::String LEADERBOARD_LEADERBOARDS		= "21";
const Tizen::Base::String LEADERBOARD_RANK 				= "22";
const Tizen::Base::String LEADERBOARD_SCORE 			= "23";


class GHLeaderboardController
	: public GHController {
public:
	GHLeaderboardController();
	virtual ~GHLeaderboardController();

	// leaderboard 목록을 가져운다.
	void loadLeaderboards(GHLeaderboardDataLoadedListener * listener);	//(static Player)
	//!! Hub App에서 범용적으로 사용하기 위해 Method를 한번 더 감싸준다.
//	private void loadLeaderboards(GHLeaderboardListener * listener, STRING* playerId);

	// leaderboard의 랭킹 목록을 가져온다.
//	void loadLeaderboardRank(Tizen::Base::String leaderboardId);
//	void loadLeaderboardRank(Tizen::Base::String leaderboardId, GHLeaderboardListLoadedListener * listener);
	void loadLeaderboardRank(Tizen::Base::String leaderboardId, int startPosition = 0, int loadSize = 10);
	void loadLeaderboardRank(Tizen::Base::String leaderboardId, GHLeaderboardListLoadedListener * listener, int startPosition = 0, int loadSize = 10);

	// 해당 leaderboard에 점수를 업데이트한다.
	void updateLeaderboardScore(Tizen::Base::String leaderboardId, long score);
	void updateLeaderboardScore(Tizen::Base::String leaderboardId, long score, GHLeaderboardScoreUpdatedListener * listener);

private:
	virtual void OnTransactionReadyToRead(Tizen::Base::String apiCode, Tizen::Base::String statusCode, Tizen::Web::Json::IJsonValue* data);
	Tizen::Base::Collection::HashMap* __pMap;
	GHLeaderboardListener* currentListener;
};

#endif /* GHLEADERBOARDCONTROLLER_H_ */
