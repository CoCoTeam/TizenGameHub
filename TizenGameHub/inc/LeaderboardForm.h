/*
 * LeaderboardForm.h
 *
 *  Created on: Apr 1, 2014
 *      Author: Administrator
 */

#ifndef LEADERBOARDFORM_H_
#define LEADERBOARDFORM_H_

#include <GHTizen.h>
#include "GHLeaderboard/GHLeaderboard.h"
#include "GameHub/AppGHLeaderboardController.h"
#include "GHLeaderboard/GHLeaderboardDataLoadedListener.h"

class LeaderboardForm
	: public Tizen::Ui::Controls::Form
	, public Tizen::Ui::IActionEventListener
	, public Tizen::Ui::Controls::IFormBackEventListener
	, public Tizen::Ui::Scenes::ISceneEventListener
	, public AppGHLeaderboardController
	, public GHLeaderboardDataLoadedListener
{
public:
	LeaderboardForm();
	virtual ~LeaderboardForm();
	bool Initialize(void);

	Tizen::Base::Collection::ArrayList* lb_list;

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

	//GHLeaderboardDataLoadedListener
	virtual void loadLeaderboardFinished(Tizen::Base::Collection::ArrayList* leaderboardList);

	void setLeaderboardList();
	Tizen::Base::String gameId;

	Tizen::Ui::Controls::ScrollPanel* pLeaderboard_scrollpanel;
};

#endif /* LEADERBOARDFORM_H_ */
