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

GameForm::GameForm()
:friendOffset(0)
{
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
	pImgGame = static_cast< Label* >(pPanelGame->GetControl(IDC_GAME_IMG_GAMEIMG));
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

	pListViewFriend = static_cast< ListView* >(pPanelFriend->GetControl(IDC_GAME_LISTVIEW_FRIEND));
	pListViewFriend->AddScrollEventListener(*this);
	pFriendProvider = new PlayerProvider();
	pFriendListItemEventListener = new GHPlayerListItemEventListener();

	setFooterMenu();

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
			getGameInstance( *gameId );
		}
//		pArgs->RemoveAll(true);
		delete pArgs;
	}
}

void
GameForm::OnSceneDeactivated(const Tizen::Ui::Scenes::SceneId& currentSceneId,
										   const Tizen::Ui::Scenes::SceneId& nextSceneId)
{
	// TODO: Deactivate your scene here.

}
void GameForm::OnScrollEndReached(Tizen::Ui::Control &source, Tizen::Ui::Controls::ScrollEndEvent type)
{
	if(type == SCROLL_END_EVENT_END_BOTTOM) {
		getGamePlayingFriends(mGame->getId(), this, friendOffset);
	}
}

void GameForm::getGameInstance(Tizen::Base::String id)
{
	AppLogDebug("gameId : %S", id.GetPointer());
	getGameData(id, this);

	pFriendList = new ArrayList();
	getGamePlayingFriends(id, this, friendOffset);
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
	//ImgUrl : %S", mGame->getImgUrl().GetPointer());
//	pImgGame->SetBackgroundFromUrl("a");
	RequestImage( mGame->getId(), pImgGame->GetWidth(), pImgGame->GetHeight());

	if(mGame->isPlaying()) {
		pButtonGame->SetText(L"Play");
	}
	else {
		pButtonGame->SetText(L"Install");
	}
	pButtonGame->SetEnabled(false);

	Draw();
}
void GameForm::RequestImage(const Tizen::Base::String& path,int width, int height, int timeout)
{
	Tizen::Media::Image* pImage = new Tizen::Media::Image();
	pImage->Construct();

	// Set a URL
	Tizen::Base::Utility::Uri uri;
	uri.SetUri(L"http://54.238.195.222:80/f_games/"+ path +"/image");

	RequestId reqId;

	//서버에 보내기
	pImage->DecodeUrl(uri, Tizen::Graphics::BITMAP_PIXEL_FORMAT_ARGB8888, width, height, reqId, *this, timeout);
}
// Receive the image and call the delete timer
void GameForm::OnImageDecodeUrlReceived(RequestId reqId, Tizen::Graphics::Bitmap *pBitmap, result r, const Tizen::Base::String errorCode, const Tizen::Base::String errorMessage)
{
	if(IsFailed(r)) {
		AppLog("Request failed: errorCode(%ls) errorMessage(%ls)", errorCode.GetPointer(), errorMessage.GetPointer());
	}
	else {
		pImgGame->SetBackgroundBitmap(*pBitmap);
		pImgGame->Draw();
	}
}

void GameForm::loadGamePlayingFriendFinished(Tizen::Base::Collection::ArrayList* friendsList)
{
	if(friendsList == null) {
		return;
	}
	pFriendList = friendsList;
	friendOffset += pFriendList->GetCount();
	setPlayerList();
}

void GameForm::setPlayerList()
{
	pFriendProvider->setItemList(pFriendList);
	pListViewFriend->SetItemProvider( *pFriendProvider );

	pFriendListItemEventListener->setItemList(pFriendList);
	pListViewFriend->AddListViewItemEventListener( *pFriendListItemEventListener );

	pListViewFriend->Draw();
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
















