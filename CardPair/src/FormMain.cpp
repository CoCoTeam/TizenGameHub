#include "FormMain.h"
#include "AppResourceId.h"
#include "CardPairFrame.h"
#include "GHLeaderboard/GHLeaderboardController.h"
#include "GHAchievement/GHAchievementController.h"

using namespace Tizen::Base;
using namespace Tizen::App;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Ui::Scenes;


FormMain::FormMain(void)
{
}

FormMain::~FormMain(void)
{
}

bool
FormMain::Initialize(void)
{
	result r = Construct(IDL_FORM);
	TryReturn(r == E_SUCCESS, false, "Failed to construct form");

	return true;
}

result
FormMain::OnInitializing(void)
{
	result r = E_SUCCESS;

	// TODO: Add your initialization code here

	// Setup back event listener
	SetFormBackEventListener(this);

	// Get a button via resource ID
	Tizen::Ui::Controls::Button* pButtonPlay = static_cast< Button* >(GetControl(IDC_MAIN_BUTTON_PLAY));
	if (pButtonPlay != null)
	{
		pButtonPlay->SetActionId(IDA_BUTTON_PLAY);
		pButtonPlay->AddActionEventListener(*this);
	}
	Tizen::Ui::Controls::Button* pButtonLeaderboard = static_cast< Button* >(GetControl(IDC_MAIN_BUTTON_LEADERBOARD));
	if (pButtonLeaderboard != null)
	{
		pButtonLeaderboard->SetText("Social");
		pButtonLeaderboard->SetActionId(IDA_BUTTON_LEADERBOARD);
		pButtonLeaderboard->AddActionEventListener(*this);
	}
	Tizen::Ui::Controls::Button* pButtonAchievement = static_cast< Button* >(GetControl(IDC_MAIN_BUTTON_ACHIEVEMENT));
	if (pButtonAchievement != null)
	{
		pButtonAchievement->SetShowState(false);
		pButtonAchievement->SetActionId(IDA_BUTTON_ACHIEVEMENT);
		pButtonAchievement->AddActionEventListener(*this);
	}

	playerLogin();

	return r;
}

result
FormMain::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here
	return r;
}

void
FormMain::OnActionPerformed(const Tizen::Ui::Control& source, int actionId)
{
	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);

	GHLeaderboardController leaderboardController;
	GHAchievementController achievementController;

	switch(actionId)
	{
	case IDA_BUTTON_PLAY:
		AppLogDebug("Play Button is clicked!");
		pSceneManager->GoForward(ForwardSceneTransition(SCENE_MODESELECT, SCENE_TRANSITION_ANIMATION_TYPE_LEFT));
		break;

	case IDA_BUTTON_LEADERBOARD:
		pSceneManager->GoForward(ForwardSceneTransition(SCENE_SOCIAL, SCENE_TRANSITION_ANIMATION_TYPE_LEFT));
//		AppLogDebug("Leaderboard Button is clicked!");
//		leaderboardController.loadLeaderboardForm();
		break;

	case IDA_BUTTON_ACHIEVEMENT:
//		AppLogDebug("Achievement Button is clicked!");
//		achievementController.loadAchievementForm();
		break;

	}
}

void
FormMain::OnFormBackRequested(Tizen::Ui::Controls::Form& source)
{
	UiApp* pApp = UiApp::GetInstance();
	AppAssert(pApp);
	pApp->Terminate();
}

void
FormMain::OnSceneActivatedN(const Tizen::Ui::Scenes::SceneId& previousSceneId,
										  const Tizen::Ui::Scenes::SceneId& currentSceneId, Tizen::Base::Collection::IList* pArgs)
{
	// TODO: Activate your scene here.

}

void
FormMain::OnSceneDeactivated(const Tizen::Ui::Scenes::SceneId& currentSceneId,
										   const Tizen::Ui::Scenes::SceneId& nextSceneId)
{
	// TODO: Deactivate your scene here.

}

