/*
 * AchievementForm.h
 *
 *  Created on: Apr 1, 2014
 *      Author: Administrator
 */

#ifndef ACHIEVEMENTFORM_H_
#define ACHIEVEMENTFORM_H_

#include <GHTizen.h>
#include "GHAchievement.h"
#include "GHAchievementController.h"
#include "GHAchievementLoadedListener.h"

class AchievementForm
	: public Tizen::Ui::Controls::Form
	, public Tizen::Ui::IActionEventListener
	, public Tizen::Ui::Controls::IFormBackEventListener
	, public Tizen::Ui::Scenes::ISceneEventListener
	, public GHAchievementController
	, public GHAchievementLoadedListener
{
public:
	AchievementForm();
	virtual ~AchievementForm();
	bool Initialize(void);

	Tizen::Base::Collection::ArrayList* ac_list;

private:
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);
	//IActionEventListener
	virtual void OnActionPerformed(const Tizen::Ui::Control& source, int actionId);
	//IFormBackEventListener
	//ISceneEventListener
	virtual void OnSceneActivatedN(const Tizen::Ui::Scenes::SceneId& previousSceneId,
								   const Tizen::Ui::Scenes::SceneId& currentSceneId, Tizen::Base::Collection::IList* pArgs);
	virtual void OnSceneDeactivated(const Tizen::Ui::Scenes::SceneId& currentSceneId,
									const Tizen::Ui::Scenes::SceneId& nextSceneId);
	virtual void OnFormBackRequested(Tizen::Ui::Controls::Form& source);

	//GHAchievementLoadedListener
	virtual void loadAchievementFinished(Tizen::Base::Collection::ArrayList* achievementList);
};

#endif /* ACHIEVEMENTFORM_H_ */
