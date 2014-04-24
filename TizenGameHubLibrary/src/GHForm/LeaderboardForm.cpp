/*
 * LeaderboardForm.cpp
 *
 *  Created on: Apr 1, 2014
 *      Author: Administrator
 */

#include "GHForm/LeaderboardForm.h"
#include "AppResourceId.h"
//#include "TizenGameHubFrame.h"
#include "GHForm/ListPanel.h"

using namespace Tizen::Ui::Controls;
using namespace Tizen::Ui::Scenes;

LeaderboardForm::LeaderboardForm() {
	// TODO Auto-generated constructor stub
}

LeaderboardForm::~LeaderboardForm() {
	// TODO Auto-generated destructor stub
}
bool LeaderboardForm::Initialize(void)
{
	result r = Construct(IDL_FORM_LEADERBOARD);
	TryReturn(r == E_SUCCESS, false, "Failed to construct form");

	return true;
}
result LeaderboardForm::OnInitializing(void)
{
	result r = E_SUCCESS;
	AppLogDebug("[LeaderboardForm] OnInitializing()");

	// TODO: Add your initialization code here

	// Setup back event listener
	SetFormBackEventListener(this);

	pLeaderboard_scrollpanel = static_cast<ScrollPanel*>(GetControl(IDC_LEADERBOARD_SCROLLPANEL));
	loadLeaderboards(this);

	return r;
}
result LeaderboardForm::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here
	return r;
}
//IActionEventListener
void LeaderboardForm::OnActionPerformed(const Tizen::Ui::Control& source, int actionId)
{

}
//IFormBackEventListener
void LeaderboardForm::OnFormBackRequested(Tizen::Ui::Controls::Form& source)
{
	AppLogDebug("[GameHub] OnFormBackRequested()");
//	SceneManager* pSceneManager = SceneManager::GetInstance();
//	AppAssert(pSceneManager);
//
//	pSceneManager->GoBackward(BackwardSceneTransition(SCENE_TRANSITION_ANIMATION_TYPE_RIGHT));
	this->Destroy();
}
void LeaderboardForm::OnSceneActivatedN(const Tizen::Ui::Scenes::SceneId& previousSceneId,
										  const Tizen::Ui::Scenes::SceneId& currentSceneId, Tizen::Base::Collection::IList* pArgs)
{
	// TODO: Activate your scene here.
	if (pArgs != null)
	{
		if (pArgs->GetCount())
		{
			Tizen::Base::String *gameId = static_cast<Tizen::Base::String*>(pArgs->GetAt(0));
			AppLog("[LeaderboardForm] Argument Received %S", gameId->GetPointer());
			loadLeaderboards(this);
		}
		pArgs->RemoveAll(true);
		delete pArgs;
	}
}

void LeaderboardForm::OnSceneDeactivated(const Tizen::Ui::Scenes::SceneId& currentSceneId,
										   const Tizen::Ui::Scenes::SceneId& nextSceneId)
{
	// TODO: Deactivate your scene here.

}

void LeaderboardForm::loadLeaderboardFinished(Tizen::Base::Collection::ArrayList* leaderboardList)
{
	lb_list = leaderboardList;
	AppLogDebug("[LeaderboardForm] leaderboardList Received. (listSize : %d)", lb_list->GetCount() );
	setLeaderboardList();
}
void LeaderboardForm::setLeaderboardList()
{
	int initX = 20, initY = 10;
	int posX = 330, posY = 430;
	for(int i=0 ; i<lb_list->GetCount() ; i++)
	{
		GHLeaderboard *leaderboard = (GHLeaderboard*)(lb_list->GetAt(0));
		Panel* pPanelLeaderboard= new ListPanel(leaderboard->getId(), leaderboard->getTitle(), leaderboard->getImgUrl());
		pPanelLeaderboard->SetPosition(initX + posX*(i%2), initY + posY*(i/2));
		pLeaderboard_scrollpanel->AddControl(pPanelLeaderboard);
	}
}















