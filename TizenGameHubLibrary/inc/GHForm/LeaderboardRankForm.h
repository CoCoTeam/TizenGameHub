/*
 * LeaderboardRankForm.h
 *
 *  Created on: Apr 11, 2014
 *      Author: Administrator
 */

#ifndef LEADERBOARDRANKFORM_H_
#define LEADERBOARDRANKFORM_H_

#include "GHTizen.h"
#include "GHLeaderboard/GHLeaderboard.h"
#include "GHLeaderboard/GHLeaderboardController.h"
#include "GHLeaderboard/GHLeaderboardListLoadedListener.h"
#include "LeaderboardRankProvider.h"

class LeaderboardRankForm
	: public Tizen::Ui::Controls::Form
	, public Tizen::Ui::Controls::IFormBackEventListener
	, public GHLeaderboardController
	, public GHLeaderboardListLoadedListener
{
public:
	LeaderboardRankForm();
	LeaderboardRankForm(Tizen::Base::String leaderboardId);
	virtual ~LeaderboardRankForm();
	bool Initialize(void);

private:
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);
	//IFormBackEventListener
	virtual void OnFormBackRequested(Tizen::Ui::Controls::Form& source);
	//GHLeaderboardListLoadedListener
	virtual void loadLeaderboardRankFinished(GHLeaderboard* _leaderboard);

	GHLeaderboard* leaderboard;						// 해당 리더보드의 정보
	Tizen::Base::String leaderboardId;				// 이전 Form에서 전달받은 리더보드의 Id값
	Tizen::Base::Collection::ArrayList* rank_list;	// ranking 정보를 포함한 ArrayList
	Tizen::Ui::Controls::ListView *pRankListView;	// ranking 정보를 뿌려주는 ListView
	LeaderboardRankProvider *pRankProvider;			// ranking 정보를 지니고 있는 Provider
};

#endif /* LEADERBOARDRANKFORM_H_ */
