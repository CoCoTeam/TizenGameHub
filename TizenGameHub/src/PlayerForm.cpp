/*
 * PlayerForm.cpp
 *
 *  Created on: Mar 25, 2014
 *      Author: Administrator
 */

#include "PlayerForm.h"
#include "AppResourceId.h"
#include "TizenGameHubFrame.h"

using namespace Tizen::App;
using namespace Tizen::Ui::Scenes;

PlayerForm::PlayerForm() {
	// TODO Auto-generated constructor stub
	isLocalPlayer = new Boolean(true);
	isFriend = new Boolean(false);
}

PlayerForm::~PlayerForm() {
	// TODO Auto-generated destructor stub
}

bool
PlayerForm::Initialize(void)
{
	result r = Construct(IDL_FORM_PLAYER);
	TryReturn(r == E_SUCCESS, false, "Failed to construct form");

	//!! 임시 더미 데이터
	setCurrentPlayerData(1001);

	return true;
}

result
PlayerForm::OnInitializing(void)
{
	result r = E_SUCCESS;

	// TODO: Add your initialization code here
	AppLog("[PlayerForm] OnInitializing");

	// Setup back event listener
	SetFormBackEventListener(this);

	// Get a button via resource ID
	pPanelUser = static_cast< Panel* >(GetControl(IDC_USER_PANEL_USER));
	pGalleryUserProfile = static_cast< Gallery* >(pPanelUser->GetControl(IDC_USER_IMG_USERIMG));
	pLabelUserName = static_cast< Label* >(pPanelUser->GetControl(IDC_USER_LABEL_USERNAME));
	pLabelUserScore = static_cast< Label* >(pPanelUser->GetControl(IDC_USER_LABEL_USERSCORE));
	pButtonUserFriend = static_cast< Button* >(pPanelUser->GetControl(IDC_USER_BUTTON_USERFRIEND));
	pPanelScroll = static_cast< Panel* >(GetControl(IDC_USER_SCROLLPANEL));
	pPanelGame = static_cast< Panel* >(pPanelScroll->GetControl(IDC_USER_PANEL_GAME));
	pPanelFriend = static_cast< Panel* >(pPanelScroll->GetControl(IDC_USER_PANEL_FRIEND));
	pPanelFriend->SetShowState(false);

	pLabelUserName->SetText( *(mPlayer->getName()) );
	String *totalScoreStr = new String();
	totalScoreStr->Append(mPlayer->getTotalScore());
	pLabelUserScore->SetText( *totalScoreStr );
	//!! 프로필 이미지 세팅, 버튼 속성 세팅
	//	pGalleryUserProfile->Set
	//	pButtonUserFriend->Set

	pButtonUserFriend->SetActionId(IDA_BUTTON_USER);
	pButtonUserFriend->AddActionEventListener(*this);

	setGameList();
	setFooterMenu();

	return r;
}

result
PlayerForm::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here
	return r;
}

void
PlayerForm::OnActionPerformed(const Tizen::Ui::Control& source, int actionId)
{
	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);

	AppLog("[PlayerForm] OnActionPerformed(%d)", actionId);
	switch(actionId)
	{
	case IDA_BUTTON_USER:
		if( isLocalPlayer ) {	// (나 자신이면) 정보 수정 페이지로 이동
			ArrayList* pList = new (std::nothrow)ArrayList;
			AppAssert(pList);
			pList->Construct();
			pList->Add( new Tizen::Base::Boolean(false) );	// isJoin -> isEdit
			pSceneManager->GoForward(ForwardSceneTransition(SCENE_JOIN, SCENE_TRANSITION_ANIMATION_TYPE_DEPTH_IN), pList);
		}
		else {		// (나 자신이 아니면)
			if( isFriend ) {	//!! (친구이면) 친구 해제

			}
			else {	//!! (친구가 아니면) 친구 요청

			}

		}
		break;

	case ID_FOOTER_FIRST_TAB:
		changePanel(0);
		break;

	case ID_FOOTER_SECOND_TAB:
		if( isLocalPlayer ) {	// (나 자신이면) 친구 리스트 Panel 보이기
			changePanel(1);
		}
		else {		//!! (아니면) 내 정보 페이지로 이동하기

		}
		break;
	}
}

void
PlayerForm::OnFormBackRequested(Tizen::Ui::Controls::Form& source)
{
	//!! SceneHistory가 있으면
	if(false) {
		SceneManager* pSceneManager = SceneManager::GetInstance();
		AppAssert(pSceneManager);
		pSceneManager->GoBackward(BackwardSceneTransition(SCENE_TRANSITION_ANIMATION_TYPE_DEPTH_OUT));
	}
	else {	// 없으면
		UiApp* pApp = UiApp::GetInstance();
		AppAssert(pApp);
		pApp->Terminate();
	}
}

void
PlayerForm::OnSceneActivatedN(const Tizen::Ui::Scenes::SceneId& previousSceneId,
										  const Tizen::Ui::Scenes::SceneId& currentSceneId, Tizen::Base::Collection::IList* pArgs)
{
	// TODO: Activate your scene here.
	if (pArgs != null)
	{
		if (pArgs->GetCount())
		{
			AppLog("[PlayerForm] Argument Received");
			Tizen::Base::String *pPlayerIdStr = static_cast<Tizen::Base::String*>(pArgs->GetAt(0));
			isLocalPlayer = static_cast<Tizen::Base::Boolean*>(pArgs->GetAt(1));
			isFriend = static_cast<Tizen::Base::Boolean*>(pArgs->GetAt(2));

			if( isLocalPlayer ) {
				//!! Footer 정보 변경
//				setFooterMenu();

				// 버튼 정보 변경
				pButtonUserFriend->SetText( "정보 수정" );

				// 친구 리스트 설정
				setPlayerList();
			}
			else {

				//!! Footer 정보 변경

				// 버튼 정보 변경
				if( isFriend ) {
					pButtonUserFriend->SetText( "친구 해제" );
				}
				else {
					pButtonUserFriend->SetText( "친구 요청" );
				}
			}
		}
		pArgs->RemoveAll(true);
		delete pArgs;
	}
}

void
PlayerForm::OnSceneDeactivated(const Tizen::Ui::Scenes::SceneId& currentSceneId,
										   const Tizen::Ui::Scenes::SceneId& nextSceneId)
{
	// TODO: Deactivate your scene here.

}

//
void PlayerForm::setCurrentPlayerData(long playerId)
{
	mPlayer = new GHPlayer(1001, "aaa@aaa.com", "홍길동", "profile_user_333");
}

void PlayerForm::setGameList()
{
	pGameList = new ArrayList();

	pGameList->Add( (Object*)new GHGame(111, 100, "FunnyGame", "This Game is really fun.", "default", 1, 1, 1, false, false) );
	pGameList->Add( (Object*)new GHGame(222, 101, "MultiGame", "This Game provides Turn-Based Multiplay.", "default", 2, 2, 2, false, true) );
	pGameList->Add( (Object*)new GHGame(333, 100, "CloudGame", "This Game provides Cloud Save.", "default", 1, 3, 2, true, false) );

	pGameProvider = new GHGameProvider();
	pGameProvider->setItemList(pGameList);
	pGameListItemEventListener = new GHGameListItemEventListener();
	pGameListItemEventListener->setItemList(pGameList);

	pListViewGame = static_cast< ListView* >(pPanelGame->GetControl(IDC_USER_LISTVIEW_GAME));
	pListViewGame->SetItemProvider( *pGameProvider );
	pListViewGame->AddListViewItemEventListener( *pGameListItemEventListener );

}
void PlayerForm::setPlayerList()
{
	pFriendList = new ArrayList();

	pFriendList->Add( (Object*)new GHPlayer(1, "aaa@aaa.com", "전경호", "default") );
	pFriendList->Add( (Object*)new GHPlayer(2, "bbb@aaa.com", "김기철", "default") );
	pFriendList->Add( (Object*)new GHPlayer(3, "ccc@aaa.com", "노동완", "default") );

	pFriendProvider = new GHPlayerProvider();
	pFriendProvider->setItemList(pFriendList);
	pFriendListItemEventListener = new GHPlayerListItemEventListener();
	pFriendListItemEventListener->setItemList(pFriendList);

	pListViewFriend = static_cast< ListView* >(pPanelFriend->GetControl(IDC_USER_LISTVIEW_FRIEND));
	pListViewFriend->SetItemProvider( *pFriendProvider );
	pListViewFriend->AddListViewItemEventListener( *pFriendListItemEventListener );
}

void PlayerForm::setFooterMenu()
{
	// Set-up footer
	Footer* pFooter = GetFooter();
	AppAssert(pFooter)
	pFooter->SetStyle(FOOTER_STYLE_BUTTON_TEXT);
	pFooter->SetBackButton();

	FooterItem footerItem1;
	footerItem1.Construct(ID_FOOTER_FIRST_TAB);
	footerItem1.SetText(L"사용자 정보");
	pFooter->AddItem(footerItem1);

	FooterItem footerItem2;
	footerItem2.Construct(ID_FOOTER_SECOND_TAB);
	footerItem2.SetText(L"친구 정보");
	pFooter->AddItem(footerItem2);
//	pFooter->SetItemSelected(0);
	pFooter->AddActionEventListener(*this);
}

void PlayerForm::changePanel(int selected)
{
	AppLog("[GameForm] changePanel(%d)", selected);
	switch(selected)
	{
	case 0:
		pPanelFriend->SetShowState(false);
		pPanelGame->SetShowState(true);
		break;
	case 1:
		pPanelGame->SetShowState(false);
		pPanelFriend->SetShowState(true);
		break;
	}
}
