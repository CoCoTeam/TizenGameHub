/*
 * AchievementForm.cpp
 *
 *  Created on: Apr 1, 2014
 *      Author: Administrator
 */

#include "GameHub/AppGHAchievementForm.h"
#include "LibResourceId.h"
#include "GHSharedAuthData.h"
#include "GHForm/ListPanel.h"
#include "TizenGameHubFrame.h"
#include "GameHub/AppGHAchievementController.h"

using namespace Tizen::Ui::Controls;
using namespace Tizen::Ui::Scenes;

AppGHAchievementForm::AppGHAchievementForm() {}
AppGHAchievementForm::~AppGHAchievementForm() {}
//IFormBackEventListener
void AppGHAchievementForm::OnFormBackRequested(Tizen::Ui::Controls::Form& source)
{
	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);

	pSceneManager->GoBackward(BackwardSceneTransition(SCENE_TRANSITION_ANIMATION_TYPE_RIGHT));
}
void AppGHAchievementForm::OnSceneActivatedN(const SceneId& previousSceneId, const SceneId& currentSceneId,
												Tizen::Base::Collection::IList* pArgs)
{
	if (pArgs != null)
	{
		if (pArgs->GetCount())
		{
			gameId = static_cast<Tizen::Base::String*>(pArgs->GetAt(0));
			AppLog("[AchievementForm] Argument Received %S", gameId->GetPointer());

			GHSharedAuthData & sharedInstance = GHSharedAuthData::getSharedInstance();
			AppGHAchievementController *acController = new AppGHAchievementController();
			acController->loadAchievements(this, *gameId, sharedInstance.getPlayerId());
		}
		pArgs->RemoveAll(true);
		delete pArgs;
	}
}

void AppGHAchievementForm::OnSceneDeactivated(const SceneId& currentSceneId,
												const SceneId& nextSceneId)
{}
