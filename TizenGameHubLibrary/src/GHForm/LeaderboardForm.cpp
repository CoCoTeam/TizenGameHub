/*
 * LeaderboardForm.cpp
 *
 *  Created on: Apr 1, 2014
 *      Author: Administrator
 */

#include "GHForm/LeaderboardForm.h"
#include "AppResourceId.h"
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

	lb_list->RemoveAll();	delete lb_list;

	return r;
}
//IFormBackEventListener
void LeaderboardForm::OnFormBackRequested(Tizen::Ui::Controls::Form& source)
{
	source.GetParent()->RemoveControl(source);
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















