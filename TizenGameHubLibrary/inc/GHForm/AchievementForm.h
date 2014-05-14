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
#include "GHAchievement/GHAchievementController.h"
#include "GHAchievement/GHAchievementLoadedListener.h"

class AchievementForm
	: public Tizen::Ui::Controls::Form
	, public Tizen::Ui::Controls::IFormBackEventListener
	, public GHAchievementController
	, public GHAchievementLoadedListener
{
public:
	AchievementForm();
	virtual ~AchievementForm();
	bool Initialize(void);


private:
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);
	//IFormBackEventListener
	virtual void OnFormBackRequested(Tizen::Ui::Controls::Form& source);
	//GHAchievementLoadedListener
	virtual void loadAchievementFinished(Tizen::Base::Collection::ArrayList* achievementList);

	void setAchievementList();
	Tizen::Base::Collection::ArrayList* ac_list;
	Tizen::Ui::Controls::ScrollPanel* pAchievement_scrollpanel;

};

#endif /* ACHIEVEMENTFORM_H_ */
