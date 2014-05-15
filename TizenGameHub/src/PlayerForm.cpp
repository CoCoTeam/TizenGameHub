/*
 * PlayerForm.cpp
 *
 *  Created on: Mar 25, 2014
 *      Author: Administrator
 */

#include "PlayerForm.h"
#include "AppResourceId.h"
#include "TizenGameHubFrame.h"
#include "GHSharedAuthData.h"

using namespace Tizen::App;
using namespace Tizen::Ui::Scenes;
using namespace Tizen::Web::Json;

using namespace Tizen::Ui::Controls;
using namespace Tizen::Base;
using namespace Tizen::Base::Collection;

using namespace Tizen::App;
using namespace Tizen::Ui;
using namespace Tizen::Io;
using namespace Tizen::Graphics;
using namespace Tizen::Media;
using namespace Tizen::Base::Collection;
using namespace Tizen::Base::Utility;
using namespace Tizen::Content;
using namespace Tizen::System;


PlayerForm::PlayerForm()
: __pUserBmp(null), gameOffset(0), friendOffset(0), isLocalPlayer(true), isFriend(false)
{
	// TODO Auto-generated constructor stub
}

PlayerForm::~PlayerForm() {
	// TODO Auto-generated destructor stub

}

bool
PlayerForm::Initialize(void)
{
	result r = Construct(IDL_FORM_PLAYER);
	TryReturn(r == E_SUCCESS, false, "Failed to construct form");

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

	pLabelUserName = static_cast< Label* >(pPanelUser->GetControl(IDC_USER_LABEL_USERNAME));
	pLabelUserScore = static_cast< Label* >(pPanelUser->GetControl(IDC_USER_LABEL_USERSCORE));
	pButtonUserFriend = static_cast< Button* >(pPanelUser->GetControl(IDC_USER_BUTTON_USERFRIEND));
	pPanelScroll = static_cast< Panel* >(GetControl(IDC_USER_SCROLLPANEL));
	pPanelGame = static_cast< Panel* >(pPanelScroll->GetControl(IDC_USER_PANEL_GAME));
	pPanelFriend = static_cast< Panel* >(pPanelScroll->GetControl(IDC_USER_PANEL_FRIEND));
	pPanelFriend->SetShowState(false);

	pListViewGame = static_cast< ListView* >(pPanelGame->GetControl(IDC_USER_LISTVIEW_GAME));
	pListViewFriend = static_cast< ListView* >(pPanelFriend->GetControl(IDC_USER_LISTVIEW_FRIEND));

	pListViewGame->AddScrollEventListener(*this);
	pListViewFriend->AddScrollEventListener(*this);

	pButtonSearchFriend = static_cast< Button* >(pPanelFriend->GetControl(IDC_USER_BUTTON_SEARCHFRIEND));
	pButtonSearchFriend->SetActionId(IDA_BUTTON_SEARCHFRIEND);
	pButtonSearchFriend->AddActionEventListener(*this);

	pGameProvider = new GHGameProvider();
	pGameListItemEventListener = new GHGameListItemEventListener();

	AppLog("__pCroppedBmp EXIST");

	Gallery *pGalleryUserProfile;
	pGalleryUserProfile = static_cast< Gallery* >(pPanelUser->GetControl(IDC_USER_IMG_USERIMG));
	pGalleryUserProfile->SetItemProvider(*this);

	/*pGalleryUserProfile->SetItemProvider(*this);
	pGalleryUserProfile->AddTouchEventListener(*this);*/

	//User Image 설정
/*	String path = L"http://54.238.195.222:80/players/pkeykichul/image";
	this->RequestImage(path,400,400,5000);*/

	String user_image_path = Environment::GetMediaPath() + L"Downloads/profile.jpg";
	AppLogDebug("USER_IMAGE --> %S", user_image_path.GetPointer());

	Image img;
	img.Construct();
	__pUserBmp = img.DecodeN(user_image_path, BITMAP_PIXEL_FORMAT_ARGB8888);

	pGalleryUserProfile->RefreshGallery(0,GALLERY_REFRESH_TYPE_ITEM_ADD);

	return r;
}

void
PlayerForm::RequestImage(const String& path,int width, int height,int timeout)
{
	Image* pImage = new Image();
	pImage->Construct();

	// Set a URL
	Uri uri;
	RequestId reqId;

	uri.SetUri(path);

	//서버에 보내기
	pImage->DecodeUrl(uri, BITMAP_PIXEL_FORMAT_RGB565, width, height, reqId, *this, timeout);

	//pGalleryUserProfile->SetItemProvider(*this);

}

// Receive the image and call the delete timer
void
PlayerForm::OnImageDecodeUrlReceived (RequestId reqId, Tizen::Graphics::Bitmap *pBitmap, result r, const Tizen::Base::String errorCode, const Tizen::Base::String errorMessage)
{
	AppLog("OnImageDecodeUrlReceived");
	AppLog("reqId : %d",reqId);
	if(IsFailed(r))
	{
		AppLog("Request failed: errorCode(%ls) errorMessage(%ls)", errorCode.GetPointer(), errorMessage.GetPointer());
	}
	else
	{
		AppLog("========================test1 ");

		// Create a label and set the background bitmap
/*
		Label* pLabel = new Label();
		pLabel->Construct(Rectangle(0,50, pBitmap->GetWidth(),pBitmap->GetHeight()),L"");
		AddControl(*pLabel);
		pLabel->SetBackgroundBitmap(*pBitmap);

		Draw();Show();
*/

/*		Gallery* pGalleryProfile = static_cast< Gallery* >(GetControl(IDC_GAME_IMG_GAMEIMG));
		pGalleryProfile->SetItemProvider(*this);*/

		__pUserBmp = pBitmap;

/*		Gallery *pGalleryUserProfile;
		pGalleryUserProfile = static_cast< Gallery* >(pPanelUser->GetControl(IDC_USER_IMG_USERIMG));
		pGalleryUserProfile->SetItemProvider(*this);*/

		AppLog("========================test2 ");

/*		//서버에서 image 다운로드
		DownloadStart();*/
	}
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
			pList->Add( new Tizen::Base::Integer(0) );	// isJoin -> isEdit
			pSceneManager->GoForward(ForwardSceneTransition(SCENE_JOIN, SCENE_TRANSITION_ANIMATION_TYPE_DEPTH_IN), pList);
		}
		else {		// (나 자신이 아니면)
			if( isFriend ) {	//!! (친구이면) 친구 해제

			}
			else {	//!! (친구가 아니면) 친구 요청
				addFriend(GHSharedAuthData::getSharedInstance().getPlayerId(), mPlayer->getEmail(), this);
			}

		}
		break;
	case IDA_BUTTON_SEARCHFRIEND:
		pSceneManager->GoForward(ForwardSceneTransition(SCENE_SEARCHFRIEND, SCENE_TRANSITION_ANIMATION_TYPE_LEFT));
		break;

	case ID_FOOTER_FIRST_TAB:
		changePanel(0);
		break;

	case ID_FOOTER_SECOND_TAB:
		if( isLocalPlayer ) {	// (나 자신이면) 친구 리스트 Panel 보이기
			changePanel(1);
		}
		else {		// (아니면) 내 정보 페이지로 이동하기
			pSceneManager->ClearSceneHistory();
			pSceneManager->GoForward(ForwardSceneTransition(SCENE_PLAYER, SCENE_TRANSITION_ANIMATION_TYPE_DEPTH_OUT, SCENE_HISTORY_OPTION_NO_HISTORY, SCENE_DESTROY_OPTION_DESTROY));
		}
		break;
	}
}
void
PlayerForm::OnFormBackRequested(Tizen::Ui::Controls::Form& source)
{
	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);

	// (SceneHistory가 있으면) 이전 Scene으로 이동
	if(pSceneManager->GetSceneHistoryN()->GetCount() != 0) {
		pSceneManager->GoBackward(BackwardSceneTransition(SCENE_TRANSITION_ANIMATION_TYPE_DEPTH_OUT));
	}
	else {	// (없으면) 앱 종료
		Tizen::Ui::Controls::MessageBox msgBox;
		int modalResult;
		msgBox.Construct(L"Exit", L"TizenGameHub를 종료하시겠습니까?", Tizen::Ui::Controls::MSGBOX_STYLE_OKCANCEL);
		msgBox.ShowAndWait(modalResult);

		switch (modalResult)
		{
		case Tizen::Ui::Controls::MSGBOX_RESULT_OK:
			{
				// 앱 종료
				UiApp* pApp = UiApp::GetInstance();
				AppAssert(pApp);
				pApp->Terminate();
			}
			break;
		default:
			break;
		}
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
			AppLogDebug("[PlayerForm] Argument Received");
			mPlayerId = static_cast<Tizen::Base::String*>(pArgs->GetAt(0));
			isLocalPlayer = (*mPlayerId == GHSharedAuthData::getSharedInstance().getPlayerId() ? true : false);
			setFooterMenu();

			// 사용자 데이터 수신
			getCurrentPlayerData( *mPlayerId );
		}
//		pArgs->RemoveAll(true);
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
void PlayerForm::getCurrentPlayerData(String playerId)
{
	AppLogDebug("playerId : %S", playerId.GetPointer());
	getPlayerData(playerId, this);
}
void PlayerForm::loadPlayerDataFinished(GHPlayer* player)
{
	if(player != null)
	{
		mPlayer = player;
		isFriend = mPlayer->isFriend();
		setPlayerData();

		getGames( mPlayer->getId() );
	}
}
void PlayerForm::setPlayerData()
{
	pLabelUserName->SetText( (mPlayer->getName()) );

	//!! 프로필 이미지 세팅
	//	pGalleryUserProfile->Set


	if( isLocalPlayer ) {
		// 버튼 정보 변경
		pButtonUserFriend->SetText( "정보 수정" );

		// 친구 리스트 설정
		getFriends( mPlayer->getId() );
	}
	else {
		// 버튼 정보 변경
		if( isFriend ) {
			pButtonUserFriend->SetText( "친구 해제" );
			pButtonUserFriend->SetEnabled(false);
		}
		else {
			pButtonUserFriend->SetText( "친구 요청" );
		}
	}

	pButtonUserFriend->SetActionId(IDA_BUTTON_USER);
	pButtonUserFriend->AddActionEventListener(*this);

	Draw();
}

void PlayerForm::getGames(String playerId)
{
	pGameList = new ArrayList();
	getPlayerGameList(playerId, this, gameOffset);
}
void PlayerForm::loadPlayerGamesFinished(Tizen::Base::Collection::ArrayList* gameList)
{
	if(gameList == null) {
		return;
	}
	pGameList = gameList;
	gameOffset += pGameList->GetCount();
	setGameList();
}
void PlayerForm::setGameList()
{
	pGameProvider->setItemList(pGameList);
	pListViewGame->SetItemProvider( *pGameProvider );

	pGameListItemEventListener->setItemList(pGameList);
	pListViewGame->AddListViewItemEventListener( *pGameListItemEventListener );

	pListViewGame->Draw();
}

void PlayerForm::getFriends(String playerId)
{
	pFriendList = new ArrayList();
	getFriendsList(playerId, this, friendOffset);
}
void PlayerForm::loadPlayerFriendsFinished(Tizen::Base::Collection::ArrayList* friendsList)
{
	if(friendsList == null) {
		return;
	}
	pFriendList = friendsList;
	friendOffset += pFriendList->GetCount();
	setPlayerList();
}
void PlayerForm::setPlayerList()
{
	PlayerProvider *pFriendProvider = new PlayerProvider();
	pFriendProvider->setItemList(pFriendList);
	pListViewFriend->SetItemProvider( *pFriendProvider );

	GHPlayerListItemEventListener *pFriendListItemEventListener = new GHPlayerListItemEventListener();
	pFriendListItemEventListener->setItemList(pFriendList);
	pListViewFriend->AddListViewItemEventListener( *pFriendListItemEventListener );

	pListViewFriend->Draw();
}
void PlayerForm::addFriendFinished(Tizen::Base::String statusCode)
{
	if(statusCode == "1") {
		Tizen::Ui::Controls::MessageBox msgBox;
		int modalResult;
		msgBox.Construct(L"친구추가", L"친구가 추가되었습니다.", Tizen::Ui::Controls::MSGBOX_STYLE_OK);
		msgBox.ShowAndWait(modalResult);

		pButtonUserFriend->SetText( "친구 해제" );
		pButtonUserFriend->SetEnabled(false);
	}
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
	if(isLocalPlayer) {
		footerItem2.SetText(L"친구 정보");
	}
	else {
		footerItem2.SetText(L"내 정보로");
	}
	pFooter->AddItem(footerItem2);

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

void PlayerForm::OnScrollEndReached(Tizen::Ui::Control &source, Tizen::Ui::Controls::ScrollEndEvent type)
{
	if(type == SCROLL_END_EVENT_END_BOTTOM) {
		if(source.Equals(*pListViewFriend)) {
			getFriendsList(mPlayer->getId(), this, friendOffset, 8);
		}
		else if(source.Equals(*pListViewGame)) {
			getPlayerGameList(mPlayer->getId(), this, gameOffset, 8);
		}
	}
}

// IGalleryItemProvider implementation  ( 이걸 해야 Galley 에 추가할 수 있음 ... !! )

GalleryItem*
PlayerForm::CreateItem(int index)
{
    // Gets an instance of Bitmap
   // AppResource* pAppResource = Application::GetInstance()->GetAppResource();
   // Bitmap* pImageTemp = pAppResource->GetBitmapN(L"Image.jpg");

    // Creates an instance of GalleryItem and registers the bitmap to the gallery item

	AppLog("__pCroppedBmp NULL");

	GalleryItem* pGallery = new GalleryItem();
	pGallery->Construct(*__pUserBmp);


	/*if(__pUserBmp != null)
	{
		delete __pUserBmp;
		__pUserBmp = null;
		AppLog("__pUserBmp NotNull");
	}
	else
	{
		AppLog("__pUserBmp Null");
	}
*/

	return pGallery;

    // Deallocates the bitmap
   // delete pImageTemp;
}

bool
PlayerForm::DeleteItem(int index, GalleryItem *pItem)
{
    delete pItem;
    return true;
}

int
PlayerForm::GetItemCount(void)
{
    return 1;
}


//////////////////////////////////////////////////////////////////////////////////////////////////

/*void PlayerForm::DownloadStart() {

             String url =L"http://54.238.195.222:80/players/pkeykichul/image";

            // DownloadRequest request(url);
             DownloadRequest* requestpath = new DownloadRequest();
             requestpath->DownloadRequest(url, Environment::GetMediaPath());


             //파일에 있는 목록 삭제하고 저장!! profile_1, profile_2 이런식으로 저장되기 때문..
             File file;
             file.Remove(Environment::GetDefaultDownloadPath() + "profile.jpg");


             DownloadRequest request(url);
             request.SetFileName("profile");

             DownloadManager* pManager =DownloadManager::GetInstance();

             pManager->SetDownloadListener(this);
             pManager->Start(request,__requestId);
}

void
PlayerForm::OnDownloadInProgress (RequestId reqId, unsigned long long receivedSize, unsigned long long totalSize) {

             String strMessage =L"";
             strMessage.Append((long)receivedSize);
             strMessage.Append("/ ");
             strMessage.Append((long)totalSize);
}

void
PlayerForm::OnDownloadCompleted (RequestId reqId, const Tizen::Base::String &path) {

			AppLogDebug("path -----------------------> %S", path.GetPointer());

}*/
/*
void PlayerForm::OnTransactionReadyToRead(String apiCode, String statusCode,IJsonValue* data)
{
	 AppLog("return data");
}

void
PlayerForm::OnTransactionCompleted(Tizen::Net::Http::HttpSession& httpSession, Tizen::Net::Http::HttpTransaction& httpTransaction)
{

	 AppLog("success");

	 Tizen::Net::Http::HttpMultipartEntity* pMultipartEntity = static_cast< Tizen::Net::Http::HttpMultipartEntity* >(httpTransaction.GetUserObject());

	 if (pMultipartEntity)
	      delete pMultipartEntity;

	 delete &httpTransaction;

}
*/
