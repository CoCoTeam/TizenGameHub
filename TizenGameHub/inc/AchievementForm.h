/*
 * AchievementForm.h
 *
 *  Created on: Apr 1, 2014
 *      Author: Administrator
 */

#ifndef ACHIEVEMENTFORM_H_
#define ACHIEVEMENTFORM_H_

#include <GHTizen.h>
#include "GHAchievement/GHAchievement.h"
#include "GameHub/AppGHAchievementController.h"
#include "GHAchievement/GHAchievementLoadedListener.h"

class AchievementForm
	: public Tizen::Ui::Controls::Form
	, public Tizen::Ui::IActionEventListener
	, public Tizen::Ui::Controls::IFormBackEventListener
	, public Tizen::Ui::Scenes::ISceneEventListener
	, public AppGHAchievementController
	, public GHAchievementLoadedListener
//	, public Tizen::Ui::Controls::IScrollEventListener
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
	virtual void OnFormBackRequested(Tizen::Ui::Controls::Form& source);
	//ISceneEventListener
	virtual void OnSceneActivatedN(const Tizen::Ui::Scenes::SceneId& previousSceneId,
								   const Tizen::Ui::Scenes::SceneId& currentSceneId, Tizen::Base::Collection::IList* pArgs);
	virtual void OnSceneDeactivated(const Tizen::Ui::Scenes::SceneId& currentSceneId,
									const Tizen::Ui::Scenes::SceneId& nextSceneId);
	//IScrollEventListener
//	virtual void OnScrollEndReached (Tizen::Ui::Control &source, Tizen::Ui::Controls::ScrollEndEvent type){};
	//GHAchievementLoadedListener
	virtual void loadAchievementFinished(Tizen::Base::Collection::ArrayList* achievementList);

	void setAchievementList();
	Tizen::Base::String *gameId;

	Tizen::Ui::Controls::ScrollPanel* pAchievement_scrollpanel;

};

#endif /* ACHIEVEMENTFORM_H_ */
