/*
 * LeaderboardRankForm.cpp
 *
 *  Created on: Apr 11, 2014
 *      Author: Administrator
 */

#include "GHForm/LeaderboardRankForm.h"
#include "AppResourceId.h"

using namespace Tizen::Base;
using namespace Tizen::Ui::Scenes;
using namespace Tizen::Ui::Controls;

LeaderboardRankForm::LeaderboardRankForm() {
}
LeaderboardRankForm::LeaderboardRankForm(Tizen::Base::String leaderboardId) {
	this->leaderboardId = leaderboardId;
}
LeaderboardRankForm::~LeaderboardRankForm() {
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

	// Setup back event listener
	SetFormBackEventListener(this);

	// Get a button via resource ID
	pRankListView = static_cast<ListView*>(GetControl(IDC_LEADERBOARDRANK_LIST_RANK));
	if(leaderboardId != null) {
		loadLeaderboardRank(leaderboardId, this);
	}

	return r;
}
result LeaderboardRankForm::OnTerminating(void)
{
	result r = E_SUCCESS;

	rank_list->RemoveAll();	delete rank_list;

	return r;
}
//IFormBackEventListener
void LeaderboardRankForm::OnFormBackRequested(Tizen::Ui::Controls::Form& source)
{
	source.GetParent()->RemoveControl(source);
}
//GHLeaderboardListLoadedListener
void LeaderboardRankForm::loadLeaderboardRankFinished(GHLeaderboard* _leaderboard)
{
	leaderboard = _leaderboard;
	rank_list = leaderboard->getRankList();
	AppLogDebug("[LeaderboardRankForm] leaderboardRankList Received. (listSize : %d)", rank_list->GetCount() );

	pRankProvider = new LeaderboardRankProvider();
	pRankProvider->setItemList(rank_list);
	pRankListView->SetItemProvider( *pRankProvider );
	Draw();
}

