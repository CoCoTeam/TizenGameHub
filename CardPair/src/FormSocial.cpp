#include "FormSocial.h"
#include "AppResourceId.h"
#include "CardPairFrame.h"
#include "GHLeaderboard/GHLeaderboardController.h"
#include "GHAchievement/GHAchievementController.h"

using namespace Tizen::Base;
using namespace Tizen::App;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Ui::Scenes;


FormSocial::FormSocial(void)
{
}

FormSocial::~FormSocial(void)
{
}

bool
FormSocial::Initialize(void)
{
	result r = Construct(IDL_FORM);
	TryReturn(r == E_SUCCESS, false, "Failed to construct form");

	return true;
}

result
FormSocial::OnInitializing(void)
{
	result r = E_SUCCESS;

	// Setup back event listener
	SetFormBackEventListener(this);

	// Get a button via resource ID
	pButtonLogin = static_cast< Button* >(GetControl(IDC_MAIN_BUTTON_PLAY));
	pButtonLeaderboard = static_cast< Button* >(GetControl(IDC_MAIN_BUTTON_LEADERBOARD));
	pButtonAchievement = static_cast< Button* >(GetControl(IDC_MAIN_BUTTON_ACHIEVEMENT));
	if (pButtonLogin != null)
	{
		pButtonLogin->SetActionId(IDA_BUTTON_PLAY);
		pButtonLogin->AddActionEventListener(*this);
	}
	if (pButtonLeaderboard != null)
	{
		pButtonLeaderboard->SetText("Leaderboard");
		pButtonLeaderboard->SetActionId(IDA_BUTTON_LEADERBOARD);
		pButtonLeaderboard->AddActionEventListener(*this);
	}
	if (pButtonAchievement != null)
	{
		pButtonAchievement->SetText("Achievement");
		pButtonAchievement->SetActionId(IDA_BUTTON_ACHIEVEMENT);
		pButtonAchievement->AddActionEventListener(*this);
	}
	setButtonConfig();

	return r;
}

result
FormSocial::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here
	return r;
}

void
FormSocial::OnActionPerformed(const Tizen::Ui::Control& source, int actionId)
{
	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);

	GHLeaderboardController leaderboardController;
	GHAchievementController achievementController;

	switch(actionId)
	{
	case IDA_BUTTON_PLAY:
		AppLogDebug("Play Button is clicked!");
		if(!isLogin()) {
			playerLogin(this);
		} else {
			playerLogout();
			setButtonConfig();
		}
		break;

	case IDA_BUTTON_LEADERBOARD:
		AppLogDebug("Leaderboard Button is clicked!");
		leaderboardController.loadLeaderboardForm();
		break;

	case IDA_BUTTON_ACHIEVEMENT:
		AppLogDebug("Achievement Button is clicked!");
		achievementController.loadAchievementForm();
		break;

	}
}

void
FormSocial::OnFormBackRequested(Tizen::Ui::Controls::Form& source)
{
	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);
	pSceneManager->GoBackward(BackwardSceneTransition(SCENE_TRANSITION_ANIMATION_TYPE_RIGHT));
}

void FormSocial::loginPlayerFinished(Tizen::Base::String statusCode)
{
	setButtonConfig();
}

void FormSocial::setButtonConfig()
{
	if(!isLogin()) {
		pButtonLogin->SetText("Log In");
	} else {
		pButtonLogin->SetText("Log Out");
	}
	pButtonLeaderboard->SetEnabled(isLogin());
	pButtonAchievement->SetEnabled(isLogin());
}
