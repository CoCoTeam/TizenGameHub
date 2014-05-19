/*
 * LeaderboardForm.cpp
 *
 *  Created on: Apr 1, 2014
 *      Author: Administrator
 */

#include "GHForm/LeaderboardForm.h"
#include "LibResourceId.h"
#include "GHForm/ListPanel.h"
#include "GHLeaderboard/GHLeaderboardController.h"

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
	result r = Construct(IDL_GHFORM_LEADERBOARD);
	TryReturn(r == E_SUCCESS, false, "Failed to construct form");

	return true;
}
result LeaderboardForm::OnInitializing(void)
{
	result r = E_SUCCESS;
	AppLogDebug("[LeaderboardForm] OnInitializing()");

	// Setup back event listener
	SetFormBackEventListener(this);

	pLeaderboard_scrollpanel = static_cast<ScrollPanel*>(GetControl(IDC_LEADERBOARD_SCROLLPANEL));
	OnInitialized();

	return r;
}
void LeaderboardForm::OnInitialized()
{
	GHLeaderboardController* lbController = new GHLeaderboardController();
	lbController->loadLeaderboards(this);
}
result LeaderboardForm::OnTerminating(void)
{
	result r = E_SUCCESS;
//	lb_list->RemoveAll();	delete lb_list;
//	pLeaderboard_scrollpanel->RemoveAllControls();

	return r;
}
//IFormBackEventListener
void LeaderboardForm::OnFormBackRequested(Tizen::Ui::Controls::Form& source)
{
	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);
	pSceneManager->GoBackward(BackwardSceneTransition(SCENE_TRANSITION_ANIMATION_TYPE_RIGHT));
}
void LeaderboardForm::loadLeaderboardFinished(Tizen::Base::Collection::ArrayList* leaderboardList)
{
	if(leaderboardList == null) {
		return;
	}
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
		GHLeaderboard *leaderboard = (GHLeaderboard*)(lb_list->GetAt(i));
		Panel* pPanelLeaderboard = new ListPanel(*leaderboard);
		pPanelLeaderboard->SetPosition(initX + posX*(i%2), initY + posY*(i/2));
		pLeaderboard_scrollpanel->AddControl(pPanelLeaderboard);
	}
}















