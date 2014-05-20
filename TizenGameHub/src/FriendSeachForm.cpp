/*
 * FriendSeachForm.cpp
 *
 *  Created on: May 12, 2014
 *      Author: Administrator
 */

#include "FriendSeachForm.h"
#include "AppResourceId.h"
#include "TizenGameHubFrame.h"
#include "GHForm/PlayerProvider.h"
#include "GHPlayerListItemEventListener.h"
#include "GHSharedAuthData.h"

using namespace Tizen::Base;
using namespace Tizen::Ui::Scenes;
using namespace Tizen::Ui::Controls;

FriendSeachForm::FriendSeachForm() {
	// TODO Auto-generated constructor stub

}

FriendSeachForm::~FriendSeachForm() {
	// TODO Auto-generated destructor stub
}

bool FriendSeachForm::Initialize(void)
{
	result r = Construct(IDL_FORM_SEARCHFRIEND);
	TryReturn(r == E_SUCCESS, false, "Failed to construct form");

	return true;
}

result FriendSeachForm::OnInitializing(void)
{
	result r = E_SUCCESS;

	// TODO: Add your initialization code here
	AppLog("[FriendSeachForm] OnInitializing");

	// Setup back event listener
	SetFormBackEventListener(this);

	// Get a button via resource ID
	pTextEmail = static_cast< EditField* >(GetControl(IDC_SEARCHFRIEND_TEXTBOX_FRIEND));
	pListViewFriend = static_cast< ListView* >(GetControl(IDC_SEARCHFRIEND_LIST_FRIEND));
	pButtonSearch = static_cast< Button* >(GetControl(IDC_SEARCHFRIEND_BUTTON_SEARCH));
	pButtonSearch->SetActionId(IDA_BUTTON_SEARCH);
	pButtonSearch->AddActionEventListener(*this);

	return r;
}

result FriendSeachForm::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here
	return r;
}



//IActionEventListener
void FriendSeachForm::OnActionPerformed(const Tizen::Ui::Control& source, int actionId)
{
	switch(actionId)
	{
	case IDA_BUTTON_SEARCH:
		searchFriend(pTextEmail->GetText(), this);
		break;
	}

}
//IFormBackEventListener
void FriendSeachForm::OnFormBackRequested(Tizen::Ui::Controls::Form& source)
{
	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);
	pSceneManager->GoBackward(BackwardSceneTransition(SCENE_TRANSITION_ANIMATION_TYPE_RIGHT));
}

void FriendSeachForm::searchFriendFinished(Tizen::Base::Collection::ArrayList* friendsList)
{
	if(friendsList == null) {
		return;
	}
	for(int i=0 ; i<friendsList->GetCount() ; i++) {
		GHPlayer *p = (GHPlayer*)(friendsList->GetAt(i));
		if(p->getId() == GHSharedAuthData::getSharedInstance().getPlayerId()) {
			friendsList->RemoveAt(i);
			break;
		}
	}

	PlayerProvider *pFriendProvider = new PlayerProvider();
	pFriendProvider->setItemList(friendsList);
	pListViewFriend->SetItemProvider( *pFriendProvider );

	GHPlayerListItemEventListener *pFriendListItemEventListener = new GHPlayerListItemEventListener();
	pFriendListItemEventListener->setItemList(friendsList);
	pListViewFriend->AddListViewItemEventListener( *pFriendListItemEventListener );

	pListViewFriend->Draw();
}
