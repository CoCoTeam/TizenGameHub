/*
 * LeaderboardRankForm.cpp
 *
 *  Created on: Apr 11, 2014
 *      Author: Administrator
 */

#include "GameHub/AppGHLeaderboardRankForm.h"
#include "LibResourceId.h"
#include "TizenGameHubFrame.h"

using namespace Tizen::Base;
using namespace Tizen::Ui::Scenes;
using namespace Tizen::Ui::Controls;

AppGHLeaderboardRankForm::AppGHLeaderboardRankForm()
:LeaderboardRankForm()
{
	// TODO Auto-generated constructor stub

}
AppGHLeaderboardRankForm::~AppGHLeaderboardRankForm() {
	// TODO Auto-generated destructor stub
}
void AppGHLeaderboardRankForm::OnInitialized()
{
	lbController = new AppGHLeaderboardController();
}
// IFormBackEventListener
void AppGHLeaderboardRankForm::OnFormBackRequested(Tizen::Ui::Controls::Form& source)
{
	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);

	pSceneManager->GoBackward(BackwardSceneTransition(SCENE_TRANSITION_ANIMATION_TYPE_RIGHT));
}
// ISceneEventListener
void AppGHLeaderboardRankForm::OnSceneActivatedN(const Tizen::Ui::Scenes::SceneId& previousSceneId,
										  const Tizen::Ui::Scenes::SceneId& currentSceneId, Tizen::Base::Collection::IList* pArgs)
{
	// TODO: Activate your scene here.
	if (pArgs != null)
	{
		if (pArgs->GetCount())
		{
			Tizen::Base::String *pGameId = static_cast<Tizen::Base::String*>(pArgs->GetAt(0));
			Tizen::Base::String *pLeaderboardId = static_cast<Tizen::Base::String*>(pArgs->GetAt(1));
//			AppLogDebug("[LeaderboardRankForm] Argument Received (%S)", leaderboardId->GetPointer());
			gameId = *pGameId;
			leaderboardId = *pLeaderboardId;

			lbController->loadLeaderboardRank(gameId, leaderboardId, this, offset, 15);
			lbController->loadLeaderboardMyRank(gameId, leaderboardId, this);
		}
		pArgs->RemoveAll(true);
		delete pArgs;
	}
}
void AppGHLeaderboardRankForm::OnSceneDeactivated(const Tizen::Ui::Scenes::SceneId& currentSceneId,
										   const Tizen::Ui::Scenes::SceneId& nextSceneId)
{
	// TODO: Deactivate your scene here.

}
// IScrollEventListener
void AppGHLeaderboardRankForm::OnScrollEndReached(Tizen::Ui::Control &source, Tizen::Ui::Controls::ScrollEndEvent type)
{
	if(type == SCROLL_END_EVENT_END_BOTTOM) {
		AppLogDebug("[LeaderboardRankForm] OnScrollEndReached()");
		lbController->loadLeaderboardRank(gameId, leaderboardId, this, offset, 15);
	}
}
