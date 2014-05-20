/*
 * LeaderboardForm.h
 *
 *  Created on: Apr 1, 2014
 *      Author: Administrator
 */

#ifndef APPGHLEADERBOARDFORM_H_
#define APPGHLEADERBOARDFORM_H_

#include <GHTizen.h>
#include "GHForm/LeaderboardForm.h"

class AppGHLeaderboardForm
	: public LeaderboardForm
	, public Tizen::Ui::Scenes::ISceneEventListener
{
public:
	AppGHLeaderboardForm();
	virtual ~AppGHLeaderboardForm();

private:
	//IFormBackEventListener
	virtual void OnFormBackRequested(Tizen::Ui::Controls::Form& source);
	//ISceneEventListener
	virtual void OnSceneActivatedN(const Tizen::Ui::Scenes::SceneId& previousSceneId,
								   const Tizen::Ui::Scenes::SceneId& currentSceneId, Tizen::Base::Collection::IList* pArgs);
	virtual void OnSceneDeactivated(const Tizen::Ui::Scenes::SceneId& currentSceneId,
									const Tizen::Ui::Scenes::SceneId& nextSceneId);

	virtual void OnInitialized(){};
	virtual void setLeaderboardList();

	Tizen::Base::String gameId;
};

#endif /* APPGHLEADERBOARDFORM_H_ */
