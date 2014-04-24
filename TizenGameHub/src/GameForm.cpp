/*
 * GameForm.cpp
 *
 *  Created on: Mar 25, 2014
 *      Author: Administrator
 */

#include "GameForm.h"
#include "AppResourceId.h"
#include "TizenGameHubFrame.h"

using namespace Tizen::Base;
using namespace Tizen::Ui::Scenes;
using namespace Tizen::Ui::Controls;

GameForm::GameForm() {
	// TODO Auto-generated constructor stub

}

GameForm::~GameForm() {
	// TODO Auto-generated destructor stub
}

bool
GameForm::Initialize(void)
{
	result r = Construct(IDL_FORM_GAME);
	TryReturn(r == E_SUCCESS, false, "Failed to construct form");

	return true;
}

result
GameForm::OnInitializing(void)
{
	result r = E_SUCCESS;

	// TODO: Add your initialization code here

	// Setup back event listener
	SetFormBackEventListener(this);

	// Get a button via resource ID
	AppLog("[GameForm] OnInitializing");

	pPanelGame = static_cast< Panel* >(GetControl(IDC_GAME_PANEL_GAME));
	pGalleryGameImg = static_cast< Gallery* >(pPanelGame->GetControl(IDC_GAME_IMG_GAMEIMG));
	pLabelGameName = static_cast< Label* >(pPanelGame->GetControl(IDC_GAME_LABEL_GAMENAME));
	pLabelDeveloper = static_cast< Label* >(pPanelGame->GetControl(IDC_GAME_LABEL_DEVELOPER));
	pButtonGame = static_cast< Button* >(pPanelGame->GetControl(IDC_GAME_BUTTON_DOWNLOAD));
	pPanelScroll = static_cast< Panel* >(GetControl(IDC_GAME_SCROLLPANEL));
	pPanelGameDetail = static_cast< Panel* >(pPanelScroll->GetControl(IDC_GAME_PANEL_GAMEDETAIL));
	pLabelGameDesc = static_cast< Label* >(pPanelGameDetail->GetControl(IDC_GAME_LABEL_DESC));
	pPanelFunction = static_cast< Panel* >(pPanelGameDetail->GetControl(IDC_GAME_PANEL_FUNCTION));
	pButtonLeaderboard = static_cast< Button* >(pPanelFunction->GetControl(IDC_GAME_BUTTON_LEADERBOARD));
	pButtonAchievement = static_cast< Button* >(pPanelFunction->GetControl(IDC_GAME_BUTTON_ACHIEVEMENT));

	pPanelFriend = static_cast< Panel* >(pPanelScroll->GetControl(IDC_GAME_PANEL_FRIEND));
	pPanelFriend->SetShowState(false);

	pButtonLeaderboard->SetActionId(ID_BUTTON_LEADERBOARD);
	pButtonLeaderboard->AddActionEventListener(*this);
	pButtonAchievement->SetActionId(ID_BUTTON_ACHIEVEMENT);
	pButtonAchievement->AddActionEventListener(*this);

	setFooterMenu();
	setPlayerList();

	return r;
}

result
GameForm::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here
	return r;
}

void
GameForm::OnActionPerformed(const Tizen::Ui::Control& source, int actionId)
{
	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);

	ArrayList* pList = new (std::nothrow)ArrayList;
	AppAssert(pList);
	pList->Construct();
	pList->Add( new String(mGame->getId()) );

	switch(actionId)
	{
	case ID_FOOTER_FIRST_TAB:
		changePanel(0);
		break;
	case ID_FOOTER_SECOND_TAB:
		changePanel(1);
		break;
	case ID_BUTTON_LEADERBOARD:
		pSceneManager->GoForward(ForwardSceneTransition(SCENE_LEADERBOARD, SCENE_TRANSITION_ANIMATION_TYPE_LEFT), pList);
		break;
	case ID_BUTTON_ACHIEVEMENT:
		pSceneManager->GoForward(ForwardSceneTransition(SCENE_ACHIEVEMENT, SCENE_TRANSITION_ANIMATION_TYPE_LEFT), pList);
		break;
	}
}

void
GameForm::OnFormBackRequested(Tizen::Ui::Controls::Form& source)
{
	AppLog("[GameForm] OnFormBackRequested");
	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);
	pSceneManager->GoBackward(BackwardSceneTransition(SCENE_TRANSITION_ANIMATION_TYPE_RIGHT));
}

void
GameForm::OnSceneActivatedN(const Tizen::Ui::Scenes::SceneId& previousSceneId,
										  const Tizen::Ui::Scenes::SceneId& currentSceneId, Tizen::Base::Collection::IList* pArgs)
{
	// TODO: Activate your scene here.
	if (pArgs != null)
	{
		if (pArgs->GetCount())
		{
			String *gameId = static_cast<String*>(pArgs->GetAt(0));
			AppLog("[GameForm] Argument Received (%S)", gameId->GetPointer());
			getGameInstance( *gameId );
		}
//		pArgs->RemoveAll(true);
		delete pArgs;
		AppLog("[GameForm] Argument Received" );
	}
}

void
GameForm::OnSceneDeactivated(const Tizen::Ui::Scenes::SceneId& currentSceneId,
										   const Tizen::Ui::Scenes::SceneId& nextSceneId)
{
	// TODO: Deactivate your scene here.

}

void GameForm::getGameInstance(Tizen::Base::String id)
{
	AppLogDebug("gameId : %S", id.GetPointer());
	getGameData(id, this);

//	mGame = new GHGame("111", "100", "FunnyGame", "This Game is really fun.", "default", 1, 1, 1, false, false);
//	setGameData();
}
void GameForm::loadPlayerDataFinished(GHGame* game)
{
	mGame = game;
	setGameData();
}
void GameForm::setGameData()
{
	pLabelGameName->SetText( mGame->getTitle() );
	pLabelGameDesc->SetText( mGame->getDescription() );
	Draw();
}

void GameForm::setPlayerList()
{
	pFriendList = new ArrayList();

	pFriendList->Add( (Object*)new GHPlayer("1", "aaa@aaa.com", "전경호", "default") );
	pFriendList->Add( (Object*)new GHPlayer("2", "bbb@aaa.com", "김기철", "default") );
	pFriendList->Add( (Object*)new GHPlayer("3", "ccc@aaa.com", "노동완", "default") );

	pFriendProvider = new GHPlayerProvider();
	pFriendProvider->setItemList(pFriendList);
	pFriendListItemEventListener = new GHPlayerListItemEventListener();
	pFriendListItemEventListener->setItemList(pFriendList);

	pListViewFriend = static_cast< ListView* >(pPanelFriend->GetControl(IDC_GAME_LISTVIEW_FRIEND));
	pListViewFriend->SetItemProvider( *pFriendProvider );
	pListViewFriend->AddListViewItemEventListener( *pFriendListItemEventListener );
}

void GameForm::setFooterMenu()
{
	// Set-up footer
	Footer* pFooter = GetFooter();
	AppAssert(pFooter)
	pFooter->SetStyle(FOOTER_STYLE_BUTTON_TEXT);
	pFooter->SetBackButton();

	FooterItem footerItem1;
	footerItem1.Construct(ID_FOOTER_FIRST_TAB);
	footerItem1.SetText(L"게임 정보");
	pFooter->AddItem(footerItem1);

	FooterItem footerItem2;
	footerItem2.Construct(ID_FOOTER_SECOND_TAB);
	footerItem2.SetText(L"친구 정보");
	pFooter->AddItem(footerItem2);
//	pFooter->SetItemSelected(0);
	pFooter->AddActionEventListener(*this);
}

void GameForm::changePanel(int selected)
{
	AppLog("[GameForm] changePanel(%d)", selected);
	switch(selected)
	{
	case 0:
		pPanelFriend->SetShowState(false);
		pPanelGameDetail->SetShowState(true);
		break;
	case 1:
		pPanelGameDetail->SetShowState(false);
		pPanelFriend->SetShowState(true);
		break;
	}
}
















