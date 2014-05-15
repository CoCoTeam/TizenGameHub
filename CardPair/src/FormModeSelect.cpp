#include "FormModeSelect.h"
#include "AppResourceId.h"
#include "AppGameData.h"
#include "CardPairFrame.h"
#include "GHPlayer/GHPlayerController.h"

using namespace Tizen::Base;
using namespace Tizen::App;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Ui::Scenes;


FormModeSelect::FormModeSelect(void)
{
}

FormModeSelect::~FormModeSelect(void)
{
}

bool
FormModeSelect::Initialize(void)
{
	result r = Construct(IDL_FORM);
	TryReturn(r == E_SUCCESS, false, "Failed to construct form");

	return true;
}

result
FormModeSelect::OnInitializing(void)
{
	result r = E_SUCCESS;

	// TODO: Add your initialization code here

	// Setup back event listener
	SetFormBackEventListener(this);

	// Get a button via resource ID
	Tizen::Ui::Controls::Button* pButtonTmp = static_cast< Button* >(GetControl(IDC_MAIN_BUTTON_LOGIN));
	pButtonTmp->SetShowState(false);
	Tizen::Ui::Controls::Button* pButtonTime = static_cast< Button* >(GetControl(IDC_MAIN_BUTTON_PLAY));
	if (pButtonTime != null)
	{
		pButtonTime->SetText("Time Attck");
		pButtonTime->SetActionId(IDA_BUTTON_TIME);
		pButtonTime->AddActionEventListener(*this);
	}
	Tizen::Ui::Controls::Button* pButtonSeconds = static_cast< Button* >(GetControl(IDC_MAIN_BUTTON_LEADERBOARD));
	if (pButtonSeconds != null)
	{
		pButtonSeconds->SetText("60 Seconds");
		pButtonSeconds->SetActionId(IDA_BUTTON_SECONDS);
		pButtonSeconds->AddActionEventListener(*this);
	}
	Tizen::Ui::Controls::Button* pButtonMulti = static_cast< Button* >(GetControl(IDC_MAIN_BUTTON_ACHIEVEMENT));
	if (pButtonMulti != null)
	{
		pButtonMulti->SetText("Multi Play");
		pButtonMulti->SetActionId(IDA_BUTTON_MULTI);
		pButtonMulti->AddActionEventListener(*this);
	}

	// cloud save
	Tizen::Ui::Controls::Label * pLabelRecord = static_cast < Label* >(GetControl(IDC_LABEL_RECORD));
	pLabelRecord->SetShowState(false);

	Tizen::Ui::Controls::Label * pLabelRecordImg = static_cast < Label* >(GetControl(IDC_LABEL_RECORDIMG));
	pLabelRecordImg->SetShowState(false);


	return r;
}

result
FormModeSelect::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here
	return r;
}

void
FormModeSelect::OnActionPerformed(const Tizen::Ui::Control& source, int actionId)
{
	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);

	switch(actionId)
	{
	case IDA_BUTTON_TIME:
		if(checkHeart()) {
			pSceneManager->GoForward(ForwardSceneTransition(SCENE_GAME_TIMETRIAL, SCENE_TRANSITION_ANIMATION_TYPE_FADE_IN_OUT));
		}
		break;
	case IDA_BUTTON_SECONDS:
		if(checkHeart()) {
			pSceneManager->GoForward(ForwardSceneTransition(SCENE_GAME_SECONDS, SCENE_TRANSITION_ANIMATION_TYPE_FADE_IN_OUT));
		}
		break;
	case IDA_BUTTON_MULTI:
		GHPlayerController *playerController = new GHPlayerController();
		bool isLogin = playerController->isLogin();
		if(isLogin) {
			if(checkHeart()) {
				pSceneManager->GoForward(ForwardSceneTransition(SCENE_GAME_MULTI, SCENE_TRANSITION_ANIMATION_TYPE_FADE_IN_OUT));
			}
		} else {
			playerController->playerLogin(this);
		}
		break;
	}
}

void
FormModeSelect::OnFormBackRequested(Tizen::Ui::Controls::Form& source)
{
	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);
	pSceneManager->GoBackward(BackwardSceneTransition(SCENE_TRANSITION_ANIMATION_TYPE_RIGHT));
}
void FormModeSelect::loginPlayerFinished(Tizen::Base::String statusCode)
{
	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);
	pSceneManager->GoForward(ForwardSceneTransition(SCENE_GAME_MULTI, SCENE_TRANSITION_ANIMATION_TYPE_DEPTH_IN));
}

bool FormModeSelect::checkHeart()
{

	return true;
}

