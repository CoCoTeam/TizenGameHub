/*
 * LeaderboardRankForm.h
 *
 *  Created on: Apr 11, 2014
 *      Author: Administrator
 */

#ifndef APPGHLEADERBOARDRANKFORM_H_
#define APPGHLEADERBOARDRANKFORM_H_

#include "GHTizen.h"
#include "GHForm/LeaderboardRankForm.h"
#include "GameHub/AppGHLeaderboardController.h"

class AppGHLeaderboardRankForm
	: public LeaderboardRankForm
	, public Tizen::Ui::Scenes::ISceneEventListener
{
public:
	AppGHLeaderboardRankForm();
	virtual ~AppGHLeaderboardRankForm();

private:
	// IFormBackEventListener
	virtual void OnFormBackRequested(Tizen::Ui::Controls::Form& source);
	// ISceneEventListener
	virtual void OnSceneActivatedN(const Tizen::Ui::Scenes::SceneId& previousSceneId,
								   const Tizen::Ui::Scenes::SceneId& currentSceneId, Tizen::Base::Collection::IList* pArgs);
	virtual void OnSceneDeactivated(const Tizen::Ui::Scenes::SceneId& currentSceneId,
									const Tizen::Ui::Scenes::SceneId& nextSceneId);
	// IScrollEventListener
	virtual void OnScrollEndReached(Tizen::Ui::Control &source, Tizen::Ui::Controls::ScrollEndEvent type);

	virtual void OnInitialized();

	Tizen::Base::String gameId;
	AppGHLeaderboardController *lbController;
};

#endif /* APPGHLEADERBOARDRANKFORM_H_ */
