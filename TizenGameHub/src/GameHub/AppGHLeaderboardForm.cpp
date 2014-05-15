/*
 * LeaderboardForm.cpp
 *
 *  Created on: Apr 1, 2014
 *      Author: Administrator
 */

#include "GameHub/AppGHLeaderboardForm.h"
#include "AppResourceId.h"
#include "TizenGameHubFrame.h"
#include "GameHub/AppListPanel.h"
#include "GameHub/AppGHLeaderboardController.h"

using namespace Tizen::Ui::Controls;
using namespace Tizen::Ui::Scenes;

AppGHLeaderboardForm::AppGHLeaderboardForm() {
	// TODO Auto-generated constructor stub
}

AppGHLeaderboardForm::~AppGHLeaderboardForm() {
	// TODO Auto-generated destructor stub
}
//IFormBackEventListener
void AppGHLeaderboardForm::OnFormBackRequested(Tizen::Ui::Controls::Form& source)
{
	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);

	pSceneManager->GoBackward(BackwardSceneTransition(SCENE_TRANSITION_ANIMATION_TYPE_RIGHT));
}
void AppGHLeaderboardForm::OnSceneActivatedN(const Tizen::Ui::Scenes::SceneId& previousSceneId,
										  const Tizen::Ui::Scenes::SceneId& currentSceneId, Tizen::Base::Collection::IList* pArgs)
{
	// TODO: Activate your scene here.
	if (pArgs != null)
	{
		if (pArgs->GetCount())
		{
			Tizen::Base::String *pGameId = static_cast<Tizen::Base::String*>(pArgs->GetAt(0));
			gameId = *pGameId;
			AppLog("[LeaderboardForm] Argument Received %S", gameId.GetPointer());
			AppGHLeaderboardController *lbController = new AppGHLeaderboardController();
			lbController->loadLeaderboards(this, gameId);
		}
		pArgs->RemoveAll(true);
		delete pArgs;
	}
}

void AppGHLeaderboardForm::OnSceneDeactivated(const Tizen::Ui::Scenes::SceneId& currentSceneId,
										   const Tizen::Ui::Scenes::SceneId& nextSceneId)
{
}
void AppGHLeaderboardForm::setLeaderboardList()
{
	int initX = 20, initY = 10;
	int posX = 340, posY = 430;

	for(int i=0 ; i<lb_list->GetCount() ; i++)
	{
		GHLeaderboard *leaderboard = (GHLeaderboard*)(lb_list->GetAt(i));
		AppListPanel *pPanelLeaderboard= new AppListPanel(*leaderboard);
		pPanelLeaderboard->setGameId(gameId);
		pPanelLeaderboard->SetPosition(initX + posX*(i%2), initY + posY*(i/2));
		pLeaderboard_scrollpanel->AddControl(pPanelLeaderboard);
	}
}















