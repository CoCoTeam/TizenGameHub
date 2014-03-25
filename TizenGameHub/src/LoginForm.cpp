/*
 * LoginForm.cpp
 *
 *  Created on: Mar 25, 2014
 *      Author: Administrator
 */

#include "LoginForm.h"
#include "AppResourceId.h"
#include "TizenGameHubFrame.h"

using namespace Tizen::App;
using namespace Tizen::Ui::Scenes;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Base::Collection;

LoginForm::LoginForm() {
	// TODO Auto-generated constructor stub

}

LoginForm::~LoginForm() {
	// TODO Auto-generated destructor stub
}

bool
LoginForm::Initialize(void)
{
	result r = Construct(IDL_FORM_LOGIN);
	TryReturn(r == E_SUCCESS, false, "Failed to construct form");

	return true;
}

result
LoginForm::OnInitializing(void)
{
	result r = E_SUCCESS;

	// TODO: Add your initialization code here

	// Setup back event listener
	SetFormBackEventListener(this);

	// Get a button via resource ID
	Button* pButtonLogin = static_cast< Button* >(GetControl(IDC_LOGIN_BUTTON_SIGN));
	if (pButtonLogin != null)
	{
		pButtonLogin->SetActionId(IDA_BUTTON_LOGIN);
		pButtonLogin->AddActionEventListener(*this);
	}
	Button* pButtonJoin = static_cast< Button* >(GetControl(IDC_LOGIN_BUTTON_JOIN));
	if (pButtonJoin != null)
	{
		pButtonJoin->SetActionId(IDA_BUTTON_JOIN);
		pButtonJoin->AddActionEventListener(*this);
	}

	EditField* pTextEmail = static_cast< EditField* >(GetControl(IDC_LOGIN_EDITTEXT_EMAIL));
	if(pTextEmail != null)
	{

	}
	EditField* pTextPw = static_cast< EditField* >(GetControl(IDC_LOGIN_EDITTEXT_PW));
	if(pTextPw != null)
	{

	}



	return r;
}

result
LoginForm::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here
	return r;
}

void
LoginForm::OnActionPerformed(const Tizen::Ui::Control& source, int actionId)
{
	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);

	switch(actionId)
	{
	case IDA_BUTTON_JOIN:
		pSceneManager->GoForward(ForwardSceneTransition(SCENE_JOIN, SCENE_TRANSITION_ANIMATION_TYPE_DEPTH_IN));
		break;
	case IDA_BUTTON_LOGIN:
		//!! do Login

		ArrayList* pList = new (std::nothrow)ArrayList;
		AppAssert(pList);
		pList->Construct();
		pList->Add( new Tizen::Base::Boolean(true) );	// isLocalPlayer
		pList->Add( new Tizen::Base::Boolean(false) );	// isFriend
		pSceneManager->GoForward(ForwardSceneTransition(SCENE_PLAYER, SCENE_TRANSITION_ANIMATION_TYPE_RIGHT, SCENE_HISTORY_OPTION_NO_HISTORY), pList);
		break;
	}
}

void
LoginForm::OnFormBackRequested(Tizen::Ui::Controls::Form& source)
{
	UiApp* pApp = UiApp::GetInstance();
	AppAssert(pApp);
	pApp->Terminate();
}
