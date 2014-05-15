/*
 * AchievementForm.h
 *
 *  Created on: Apr 1, 2014
 *      Author: Administrator
 */

#ifndef APPGHACHIEVEMENTFORM_H_
#define APPGHACHIEVEMENTFORM_H_

#include <GHTizen.h>
#include "GHForm/AchievementForm.h"

class AppGHAchievementForm
	: public AchievementForm
	, public Tizen::Ui::Scenes::ISceneEventListener
{
public:
	AppGHAchievementForm();
	virtual ~AppGHAchievementForm();

private:
	//IFormBackEventListener
	virtual void OnFormBackRequested(Tizen::Ui::Controls::Form& source);
	//ISceneEventListener
	virtual void OnSceneActivatedN(const Tizen::Ui::Scenes::SceneId& previousSceneId,
								   const Tizen::Ui::Scenes::SceneId& currentSceneId, Tizen::Base::Collection::IList* pArgs);
	virtual void OnSceneDeactivated(const Tizen::Ui::Scenes::SceneId& currentSceneId,
									const Tizen::Ui::Scenes::SceneId& nextSceneId);

	virtual void OnInitialized(){};
	Tizen::Base::String *gameId;
};

#endif /* APPGHACHIEVEMENTFORM_H_ */
