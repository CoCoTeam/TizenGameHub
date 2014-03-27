/*
 * JoinForm.cpp
 *
 *  Created on: Mar 25, 2014
 *      Author: Administrator
 */

#include "JoinForm.h"
#include "AppResourceId.h"
#include "TizenGameHubFrame.h"

using namespace Tizen::Ui::Controls;
using namespace Tizen::Ui::Scenes;

JoinForm::JoinForm() {
	// TODO Auto-generated constructor stub

}

JoinForm::~JoinForm() {
	// TODO Auto-generated destructor stub
}

bool
JoinForm::Initialize(void)
{
	result r = Construct(IDL_FORM_JOIN);
	TryReturn(r == E_SUCCESS, false, "Failed to construct form");

	return true;
}

result
JoinForm::OnInitializing(void)
{
	result r = E_SUCCESS;

	// TODO: Add your initialization code here

	// Setup back event listener
	SetFormBackEventListener(this);

	// Get a button via resource ID
	pButtonJoin = static_cast< Button* >(GetControl(IDC_JOIN_BUTTON_JOIN));
	pButtonJoin->SetActionId(IDA_BUTTON_JOIN);
	pButtonJoin->AddActionEventListener(*this);
	Button* pButtonCancel = static_cast< Button* >(GetControl(IDC_JOIN_BUTTON_CANCEL));
	pButtonCancel->SetActionId(IDA_BUTTON_CANCEL);
	pButtonCancel->AddActionEventListener(*this);

	pTextEmail = static_cast< EditField* >(GetControl(IDC_JOIN_EDITTEXT_EMAIL));
	pTextPw = static_cast< EditField* >(GetControl(IDC_JOIN_EDITTEXT_PW));
	pTextPwconfirm = static_cast< EditField* >(GetControl(IDC_JOIN_EDITTEXT_PWCONFIRM));
	pTextName = static_cast< EditField* >(GetControl(IDC_JOIN_EDITTEXT_NAME));



	return r;
}

result
JoinForm::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here
	return r;
}

void
JoinForm::OnActionPerformed(const Tizen::Ui::Control& source, int actionId)
{
	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);

	switch(actionId)
	{
	case IDA_BUTTON_JOIN:
		if( isPlayerJoin )	//!! do Join
		{

		}
		else	// do Edit
		{

		}

		pSceneManager->GoBackward(BackwardSceneTransition(SCENE_TRANSITION_ANIMATION_TYPE_DEPTH_OUT));
		break;
	case IDA_BUTTON_CANCEL:
		pSceneManager->GoBackward(BackwardSceneTransition(SCENE_TRANSITION_ANIMATION_TYPE_DEPTH_OUT));
		break;
	}
}

void
JoinForm::OnFormBackRequested(Tizen::Ui::Controls::Form& source)
{
	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);

	pSceneManager->GoBackward(BackwardSceneTransition(SCENE_TRANSITION_ANIMATION_TYPE_DEPTH_OUT));
}


void
JoinForm::OnSceneActivatedN(const Tizen::Ui::Scenes::SceneId& previousSceneId,
										  const Tizen::Ui::Scenes::SceneId& currentSceneId, Tizen::Base::Collection::IList* pArgs)
{
	// TODO: Activate your scene here.
	if (pArgs != null)
	{
		if (pArgs->GetCount())
		{
			AppLog("[JoinForm] Argument Received");
			isPlayerJoin = static_cast<Tizen::Base::Boolean*>(pArgs->GetAt(0));

			if( isPlayerJoin )	// (수정 시퀀스면) 프로필 편집 Panel 추가
			{
				pButtonJoin->SetText( "Edit" );
			}

		}
		pArgs->RemoveAll(true);
		delete pArgs;
	}
}

void
JoinForm::OnSceneDeactivated(const Tizen::Ui::Scenes::SceneId& currentSceneId,
										   const Tizen::Ui::Scenes::SceneId& nextSceneId)
{
	// TODO: Deactivate your scene here.

}
