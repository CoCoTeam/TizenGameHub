/*
 * LeaderboardRankForm.h
 *
 *  Created on: Apr 11, 2014
 *      Author: Administrator
 */

#ifndef LEADERBOARDRANKFORM_H_
#define LEADERBOARDRANKFORM_H_

#include "GHTizen.h"
#include "GHLeaderboard.h"
//#include "GHLeaderboard/GHLeaderboard"
#include "GHLeaderboard/GHLeaderboardController.h"
#include "GHLeaderboard/GHLeaderboardListLoadedListener.h"

class LeaderboardRankForm
	: public Tizen::Ui::Controls::Form
	, public Tizen::Ui::IActionEventListener
	, public Tizen::Ui::Controls::IFormBackEventListener
	, public Tizen::Ui::Scenes::ISceneEventListener
	, public GHLeaderboardController
	, public GHLeaderboardListLoadedListener
{
public:
	LeaderboardRankForm();
	virtual ~LeaderboardRankForm();
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
	//GHLeaderboardListLoadedListener
	virtual void loadLeaderboardRankFinished(Tizen::Base::Collection::ArrayList* Ranklist);

	GHLeaderboard leaderboard;


};

#endif /* LEADERBOARDRANKFORM_H_ */
