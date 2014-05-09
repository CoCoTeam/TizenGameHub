/*
 * LeaderboardRankForm.cpp
 *
 *  Created on: Apr 11, 2014
 *      Author: Administrator
 */

#include "LeaderboardRankForm.h"
#include "AppResourceId.h"
#include "TizenGameHubFrame.h"

using namespace Tizen::Base;
using namespace Tizen::Ui::Scenes;
using namespace Tizen::Ui::Controls;

LeaderboardRankForm::LeaderboardRankForm() {
	// TODO Auto-generated constructor stub

}
LeaderboardRankForm::~LeaderboardRankForm() {
	// TODO Auto-generated destructor stub
}
bool LeaderboardRankForm::Initialize(void)
{
	result r = Construct(IDL_FORM_LEADERBOARDRANK);
	TryReturn(r == E_SUCCESS, false, "Failed to construct form");

	return true;
}
result LeaderboardRankForm::OnInitializing(void)
{
	result r = E_SUCCESS;

	// TODO: Add your initialization code here

	// Setup back event listener
	SetFormBackEventListener(this);

	// Get a button via resource ID
	pRankListView = static_cast<ListView*>(GetControl(IDC_LEADERBOARDRANK_LIST_RANK));

	return r;
}
result LeaderboardRankForm::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here
	return r;
}
//IActionEventListener
void LeaderboardRankForm::OnActionPerformed(const Tizen::Ui::Control& source, int actionId)
{

}
//IFormBackEventListener
void LeaderboardRankForm::OnFormBackRequested(Tizen::Ui::Controls::Form& source)
{
	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);

	pSceneManager->GoBackward(BackwardSceneTransition(SCENE_TRANSITION_ANIMATION_TYPE_RIGHT));
}
void LeaderboardRankForm::OnSceneActivatedN(const Tizen::Ui::Scenes::SceneId& previousSceneId,
										  const Tizen::Ui::Scenes::SceneId& currentSceneId, Tizen::Base::Collection::IList* pArgs)
{
	// TODO: Activate your scene here.
	if (pArgs != null)
	{
		if (pArgs->GetCount())
		{
			Tizen::Base::String *gameId = static_cast<Tizen::Base::String*>(pArgs->GetAt(0));
			Tizen::Base::String *leaderboardId = static_cast<Tizen::Base::String*>(pArgs->GetAt(1));
//			AppLogDebug("[LeaderboardRankForm] Argument Received (%S)", leaderboardId->GetPointer());
			loadLeaderboardRank(*gameId, *leaderboardId, this);
		}
		pArgs->RemoveAll(true);
		delete pArgs;
	}
}

void LeaderboardRankForm::OnSceneDeactivated(const Tizen::Ui::Scenes::SceneId& currentSceneId,
										   const Tizen::Ui::Scenes::SceneId& nextSceneId)
{
	// TODO: Deactivate your scene here.

}

void LeaderboardRankForm::loadLeaderboardRankFinished(GHLeaderboard* _leaderboard)
{
	if(_leaderboard == null) {
		return;
	}
	leaderboard = _leaderboard;
	rank_list = leaderboard->getRankList();
	AppLogDebug("[LeaderboardRankForm] leaderboardRankList Received. (listSize : %d)", rank_list->GetCount() );

	pRankProvider = new LeaderboardRankProvider();
	pRankProvider->setItemList(rank_list);
	pRankListView->SetItemProvider( *pRankProvider );
	Draw();
}

