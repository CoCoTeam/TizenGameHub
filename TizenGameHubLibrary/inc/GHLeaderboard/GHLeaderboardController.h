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
const Tizen::Base::String LEADERBOARD_MYRANK 			= "24";


class GHLeaderboardController
	: public GHController {
public:
	GHLeaderboardController();
	virtual ~GHLeaderboardController();

	// LeaderboardForm(Page)을 로드한다.
	void loadLeaderboardForm();

	// leaderboard 목록을 가져운다.
	void loadLeaderboards(GHLeaderboardDataLoadedListener * listener);

	// 각 Leaderboard에 해당하는 랭킹 목록을 가져온다.
	void loadLeaderboardRank(Tizen::Base::String leaderboardId, int start_position = 0, int max_length = 15);
	void loadLeaderboardRank(Tizen::Base::String leaderboardId, GHLeaderboardListLoadedListener * listener, int start_position = 0, int max_length = 15);

	// 해당 Leaderboard에 대한 해당 player의 랭킹 정보를 가져온다.
	void loadLeaderboardMyRank(Tizen::Base::String leaderboardId, GHLeaderboardListLoadedListener * listener);

	// 해당 Leaderboard에 점수를 업데이트한다.
	void updateLeaderboardScore(Tizen::Base::String leaderboardId, long score, GHLeaderboardScoreUpdatedListener * listener = null);

protected:
	GHLeaderboardListener* currentListener;

private:
	virtual void OnTransactionReadyToRead(Tizen::Base::String apiCode, Tizen::Base::String statusCode, Tizen::Web::Json::IJsonValue* data);
	Tizen::Base::Collection::HashMap* __pMap;
};

#endif /* GHLEADERBOARDCONTROLLER_H_ */
