/*
 * ListPanel.cpp
 *
 *  Created on: Apr 9, 2014
 *      Author: Administrator
 */

#include "GameHub/AppListPanel.h"
#include "AppResourceId.h"
#include "TizenGameHubFrame.h"
#include <FMedia.h>

using namespace Tizen::Base;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Ui::Scenes;

AppListPanel::AppListPanel() {
	Construct(IDL_PANEL_LISTPANEL);
}
AppListPanel::~AppListPanel() {
}
AppListPanel::AppListPanel(GHLeaderboard leaderboard)
{
	id = leaderboard.getId();
	title = leaderboard.getTitle();
	imgUrl = leaderboard.getImgUrl();

	setLeaderboardConfig();
}

void AppListPanel::setGameId(Tizen::Base::String game_id)
{
	this->game_id = game_id;
}

void AppListPanel::OnTouchReleased (const Tizen::Ui::Control &source, const Tizen::Graphics::Point &currentPosition, const Tizen::Ui::TouchEventInfo &touchInfo)
{
	AppLogDebug("[ListPanel] OnTouchReleased. (id:%S)", getId().GetPointer());
	Tizen::Base::Collection::ArrayList* pList = new (std::nothrow)Tizen::Base::Collection::ArrayList;
	AppAssert(pList);
	pList->Construct();
	pList->Add( new String(game_id) );
	pList->Add( new String(getId()) );

	// Scene 이동
	SceneManager* pSceneManager = SceneManager::GetInstance();
	pSceneManager->GoForward(ForwardSceneTransition(SCENE_LEADERBOARDRANK, SCENE_TRANSITION_ANIMATION_TYPE_LEFT), pList);
}
