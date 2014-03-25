/*
 * GameForm.cpp
 *
 *  Created on: Mar 25, 2014
 *      Author: Administrator
 */

#include "GameForm.h"
#include "AppResourceId.h"

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
//	SceneManager* pSceneManager = SceneManager::GetInstance();
//	AppAssert(pSceneManager);

	switch(actionId)
	{
//	case IDA_BUTTON_OK:
//		AppLog("OK Button is clicked!");
//		break;
//
//	default:
//		break;
	}
}

void
GameForm::OnFormBackRequested(Tizen::Ui::Controls::Form& source)
{
	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);
	pSceneManager->GoBackward(BackwardSceneTransition(SCENE_TRANSITION_ANIMATION_TYPE_LEFT));
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
			AppLog("[GameForm] Argument Received");

			Tizen::Base::Long *isLocalPlayer = static_cast<Tizen::Base::Long*>(pArgs->GetAt(0));
			mGame = getGameInstance( isLocalPlayer->ToLong() );
//			Panel* pPanelGame = static_cast< Panel* >(GetControl(IDC_GAME_PANEL_GAME));
//			Gallery* pGalleryGameImg = static_cast< Gallery* >(pPanelGame->GetControl(IDC_GAME_IMG_GAMEIMG));
//			Label* pLabelGameName = static_cast< Label* >(pPanelGame->GetControl(IDC_GAME_LABEL_GAMENAME));
//			Label* pLabelDeveloper = static_cast< Label* >(pPanelGame->GetControl(IDC_GAME_LABEL_DEVELOPER));
//			Button* pButtonGame = static_cast< Button* >(pPanelGame->GetControl(IDC_GAME_BUTTON_DOWNLOAD));
//
//		//	String *totalScoreStr = new String();
//		//	totalScoreStr->Append(localPlayer->getTotalScore());
//		//	pLabelUserScore->SetText( *totalScoreStr );
//			//!! 프로필 이미지 세팅, 버튼 속성 세팅
//			//pGalleryUserProfile->Set
//			//pButtonUserFriend->Set
//
//			Panel* pPanelScroll = static_cast< Panel* >(GetControl(IDC_GAME_SCROLLPANEL));
//			Panel* pPanelGameDetail = static_cast< Panel* >(pPanelScroll->GetControl(IDC_GAME_PANEL_GAMEDETAIL));
//			Label* pLabelGameDesc = static_cast< Label* >(pPanelGameDetail->GetControl(IDC_GAME_LABEL_DESC));
//			pLabelGameName->SetText( *(mGame->getTitle()) );
//			pLabelGameDesc->SetText( *(mGame->getDescription()) );
		}
//			pArgs->RemoveAll(true);
		delete pArgs;
	}
}

void
GameForm::OnSceneDeactivated(const Tizen::Ui::Scenes::SceneId& currentSceneId,
										   const Tizen::Ui::Scenes::SceneId& nextSceneId)
{
	// TODO: Deactivate your scene here.

}


GHGame* GameForm::getGameInstance(long id)
{
	AppLog("Id : %d", id);
	switch(id)
	{
	case 111:
		return new GHGame(111, 100, "FunnyGame", "This Game is really fun.", "default", 1, 1, 1, false, false);
		break;
	case 222:
		return new GHGame(222, 101, "MultiGame", "This Game provides Turn-Based Multiplay.", "default", 2, 2, 2, false, true);
		break;
	case 333:
		return new GHGame(333, 100, "CloudGame", "This Game provides Cloud Save.", "default", 1, 3, 2, true, false);
		break;
	default:
		return null;
		break;
	}
}

















