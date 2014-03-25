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
	Button* pButtonJoin = static_cast< Button* >(GetControl(IDC_JOIN_BUTTON_JOIN));
	if (pButtonJoin != null)
	{
		pButtonJoin->SetActionId(IDA_BUTTON_JOIN);
		pButtonJoin->AddActionEventListener(*this);
	}
	Button* pButtonCancel = static_cast< Button* >(GetControl(IDC_JOIN_BUTTON_CANCEL));
	if (pButtonCancel != null)
	{
		pButtonCancel->SetActionId(IDA_BUTTON_CANCEL);
		pButtonCancel->AddActionEventListener(*this);
	}

	EditField* pTextEmail = static_cast< EditField* >(GetControl(IDC_JOIN_EDITTEXT_EMAIL));
	if(pTextEmail != null)
	{

	}
	EditField* pTextPw = static_cast< EditField* >(GetControl(IDC_JOIN_EDITTEXT_PW));
	if(pTextPw != null)
	{

	}
	EditField* pTextPwconfirm = static_cast< EditField* >(GetControl(IDC_JOIN_EDITTEXT_PWCONFIRM));
	if(pTextPwconfirm != null)
	{

	}
	EditField* pTextName = static_cast< EditField* >(GetControl(IDC_JOIN_EDITTEXT_NAME));
	if(pTextName != null)
	{

	}



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
		//!! do Join

		pSceneManager->GoForward(ForwardSceneTransition(SCENE_LOGIN));
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

