/*
 * AchievementForm.cpp
 *
 *  Created on: Apr 1, 2014
 *      Author: Administrator
 */

#include "AchievementForm.h"
#include "AppResourceId.h"
#include "TizenGameHubFrame.h"
#include "ListPanel.h"

using namespace Tizen::Ui::Controls;
using namespace Tizen::Ui::Scenes;

AchievementForm::AchievementForm() {
	// TODO Auto-generated constructor stub
}
AchievementForm::~AchievementForm() {
	// TODO Auto-generated destructor stub
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

	// TODO: Add your initialization code here

	// Setup back event listener
	SetFormBackEventListener(this);

	// Get a button via resource ID
	pAchievement_scrollpanel = static_cast<ScrollPanel*>(GetControl(IDC_ACHIEVEMENT_SCROLLPANEL));

	return r;
}
result AchievementForm::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here
	return r;
}
//IActionEventListener
void AchievementForm::OnActionPerformed(const Tizen::Ui::Control& source, int actionId)
{

}
//IFormBackEventListener
void AchievementForm::OnFormBackRequested(Tizen::Ui::Controls::Form& source)
{
	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);

	pSceneManager->GoBackward(BackwardSceneTransition(SCENE_TRANSITION_ANIMATION_TYPE_RIGHT));
}
void AchievementForm::OnSceneActivatedN(const Tizen::Ui::Scenes::SceneId& previousSceneId,
										  const Tizen::Ui::Scenes::SceneId& currentSceneId, Tizen::Base::Collection::IList* pArgs)
{
	// TODO: Activate your scene here.
	if (pArgs != null)
	{
		if (pArgs->GetCount())
		{
			Tizen::Base::String *gameId = static_cast<Tizen::Base::String*>(pArgs->GetAt(0));
			AppLog("[AchievementForm] Argument Received %S", gameId->GetPointer());
			loadAchievements(this);
		}
		pArgs->RemoveAll(true);
		delete pArgs;
	}
}

void AchievementForm::OnSceneDeactivated(const Tizen::Ui::Scenes::SceneId& currentSceneId,
										   const Tizen::Ui::Scenes::SceneId& nextSceneId)
{
	// TODO: Deactivate your scene here.

}

void AchievementForm::loadAchievementFinished(Tizen::Base::Collection::ArrayList* achievementList)
{
	ac_list = achievementList;
	AppLogDebug("[AchievementForm] achievementArray Received. (arraySize : %d)", ac_list->GetCount() );
	setAchievementList();
}
void AchievementForm::setAchievementList()
{
	int initX = 20, initY = 10;
	int posX = 330, posY = 430;

	int completeCount = 0;
	for(int i=0 ; i<ac_list->GetCount()*5 ; i++)
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
//	AppLogDebug("[AchievementForm] %S", titleStr.GetPointer());

	Label* pLabelTitle = static_cast<Label*>(GetControl(IDC_ACHIEVEMENT_LABEL_TITLE));
	pLabelTitle->SetText(titleStr);
	Draw();
}
