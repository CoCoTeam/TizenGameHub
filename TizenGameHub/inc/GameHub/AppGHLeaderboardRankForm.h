/*
 * LeaderboardRankForm.h
 *
 *  Created on: Apr 11, 2014
 *      Author: Administrator
 */

#ifndef APPGHLEADERBOARDRANKFORM_H_
#define APPGHLEADERBOARDRANKFORM_H_

#include "GHTizen.h"
#include "GHLeaderboard/GHLeaderboard.h"
#include "GameHub/AppGHLeaderboardController.h"
#include "GameHub/AppGHLeaderboardRankProvider.h"
#include "GHLeaderboard/GHLeaderboardListLoadedListener.h"
#include "GHLeaderboard/GHLeaderboardMyRankLoadedListener.h"

class AppGHLeaderboardRankForm
	: public Tizen::Ui::Controls::Form
	, public Tizen::Ui::IActionEventListener
	, public Tizen::Ui::Controls::IFormBackEventListener
	, public Tizen::Ui::Scenes::ISceneEventListener
	, public Tizen::Ui::Controls::IScrollEventListener
	, public AppGHLeaderboardController
	, public GHLeaderboardListLoadedListener
	, public GHLeaderboardMyRankLoadedListener
{
public:
	AppGHLeaderboardRankForm();
	virtual ~AppGHLeaderboardRankForm();
	bool Initialize(void);

private:
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);
	//IActionEventListener
	virtual void OnActionPerformed(const Tizen::Ui::Control& source, int actionId);
	//IFormBackEventListener
	virtual void OnFormBackRequested(Tizen::Ui::Controls::Form& source);
	//ISceneEventListener
	virtual void OnSceneActivatedN(const Tizen::Ui::Scenes::SceneId& previousSceneId,
								   const Tizen::Ui::Scenes::SceneId& currentSceneId, Tizen::Base::Collection::IList* pArgs);
	virtual void OnSceneDeactivated(const Tizen::Ui::Scenes::SceneId& currentSceneId,
									const Tizen::Ui::Scenes::SceneId& nextSceneId);
	//IScrollEventListener
	virtual void OnScrollEndReached(Tizen::Ui::Control &source, Tizen::Ui::Controls::ScrollEndEvent type);

	//GHLeaderboardListLoadedListener
	virtual void loadLeaderboardRankFinished(GHLeaderboard* _leaderboard);
	//GHLeaderboardMyRankLoadedListener
	virtual void loadLeaderboardMyRankFinished(GHPlayerRank* pPlayerRank);


	GHLeaderboard* leaderboard;
	Tizen::Base::String gameId, leaderboardId;
	Tizen::Base::Collection::ArrayList* rank_list;
	Tizen::Ui::Controls::ListView *pRankListView;
	AppGHLeaderboardRankProvider *pRankProvider;
	GHPlayerRank *myRank;

	Tizen::Ui::Controls::Panel *pPanelMyrank;
	Tizen::Ui::Controls::Label *pLabelName, *pLabelScore, *pLabelRank;
	Tizen::Ui::Controls::Gallery *pGallery;

	Tizen::Base::String strUnit;
	int offset;
	void setMyRank();

};

#endif /* APPGHLEADERBOARDRANKFORM_H_ */
