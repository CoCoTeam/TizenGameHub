/*
 * GameSelectForm.cpp
 *
 *  Created on: Mar 17, 2014
 *      Author: hursujung
 */

#include "GameSelectForm.h"
#include "AppResourceId.h"
#include <FApp.h>
#include <FGraphics.h>


GameSelectForm::GameSelectForm() {
	// TODO Auto-generated constructor stub

}

GameSelectForm::~GameSelectForm() {
	// TODO Auto-generated destructor stub
}

bool
GameSelectForm::Initialize()
{
	// Construct an XML form
	Construct(L"GameSelect");

	return true;
}

result
GameSelectForm::OnInitializing(void)
{
	result r = E_SUCCESS;

	// Setup back event listener
	SetFormBackEventListener(this);

	__pButtonMODE1 = static_cast<Button *>(GetControl(L"IDC_BUTTON_MODE1"));
	__pButtonMODE2 = static_cast<Button *>(GetControl(L"IDC_BUTTON_MODE2"));

	if (__pButtonMODE1 != null)
	{
		__pButtonMODE1->SetActionId(ID_BUTTON_MODE1);
		__pButtonMODE1->AddActionEventListener(*this);
	}
	if (__pButtonMODE2 != null)
	{
		__pButtonMODE2->SetActionId(ID_BUTTON_MODE2);
		__pButtonMODE2->AddActionEventListener(*this);
	}

	playerLogin();

	//SetFormBackEventListener(this);

	return r;
}

void
GameSelectForm::OnActionPerformed(const Tizen::Ui::Control& source, int actionId)
{
	switch(actionId)
	{
	case ID_BUTTON_MODE1:
		{
			SceneManager* pSceneManager = SceneManager::GetInstance();
			AppAssert(pSceneManager);

			pSceneManager->GoForward(ForwardSceneTransition(SCENE_MAIN_MENU));
		}
		break;
	case ID_BUTTON_MODE2:
		{
			SceneManager* pSceneManager = SceneManager::GetInstance();
			AppAssert(pSceneManager);

			pSceneManager->GoForward(ForwardSceneTransition(SCENE_MAIN_MENU2));
		}
		break;
	}
}

result
GameSelectForm::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here
	return r;
}
void GameSelectForm::OnFormBackRequested(Tizen::Ui::Controls::Form& source)
{
	UiApp* pApp = UiApp::GetInstance();
	AppAssert(pApp);
	pApp->Terminate();
}
