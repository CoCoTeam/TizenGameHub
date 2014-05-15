/*
 * AchievementForm.cpp
 *
 *  Created on: Apr 1, 2014
 *      Author: Administrator
 */

#include "GHForm/AchievementForm.h"
#include "LibResourceId.h"
#include "GHForm/ListPanel.h"
#include "GHAchievement/GHAchievementController.h"

using namespace Tizen::Ui::Controls;
using namespace Tizen::Ui::Scenes;

AchievementForm::AchievementForm() {
}
AchievementForm::~AchievementForm() {
}
bool AchievementForm::Initialize(void)
{
	result r = Construct(IDL_FORM_ACHIEVEMENT);
	TryReturn(r == E_SUCCESS, false, "Failed to construct form");

	return true;
}
result AchievementForm::OnInitializing(void)
{
	result r = E_SUCCESS;

	// Setup back event listener
	SetFormBackEventListener(this);

	// Get a panel via resource ID
	pAchievement_scrollpanel = static_cast<ScrollPanel*>(GetControl(IDC_ACHIEVEMENT_SCROLLPANEL));
	OnInitialized();

	return r;
}
void AchievementForm::OnInitialized()
{
	GHAchievementController* acController = new GHAchievementController();
	acController->loadAchievements(this);
}
result AchievementForm::OnTerminating(void)
{
	result r = E_SUCCESS;

//	ac_list->RemoveAll();	delete ac_list;
//	pAchievement_scrollpanel->RemoveAllControls();

	return r;
}
//IFormBackEventListener
void AchievementForm::OnFormBackRequested(Tizen::Ui::Controls::Form& source)
{
	source.GetParent()->RemoveControl(source);
}
void AchievementForm::loadAchievementFinished(Tizen::Base::Collection::ArrayList* achievementList)
{
	if(achievementList == null) {
		return;
	}
	ac_list = achievementList;
	AppLogDebug("[AchievementForm] achievementArray Received. (arraySize : %d)", ac_list->GetCount() );
	setAchievementList();
}
void AchievementForm::setAchievementList()
{
	int initX = 20, initY = 10;
	int posX = 330, posY = 430;

	int completeCount = 0;
	for(int i=0 ; i<ac_list->GetCount() ; i++)
	{
		GHAchievement *achievement = (GHAchievement*)(ac_list->GetAt(0));
		Panel* pPanelAchievement = new ListPanel(*achievement);
		pPanelAchievement->SetPosition(initX + posX*(i%2), initY + posY*(i/2));
		pAchievement_scrollpanel->AddControl(pPanelAchievement);

		if(achievement->getIsComplete() == true) {
			completeCount++;
		}
	}

	Tizen::Base::String titleStr = Tizen::Base::String("업적 ");
	titleStr.Append(ac_list->GetCount());
	titleStr.Append("개 중 ");
	titleStr.Append(completeCount);
	titleStr.Append("개 달성");

	Label* pLabelTitle = static_cast<Label*>(GetControl(IDC_ACHIEVEMENT_LABEL_TITLE));
	pLabelTitle->SetText(titleStr);
	Draw();
}
