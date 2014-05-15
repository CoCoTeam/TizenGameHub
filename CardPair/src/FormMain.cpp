#include "FormMain.h"
#include "AppResourceId.h"
#include "AppGameData.h"
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
	Tizen::Ui::Controls::Button* pButtonTmp = static_cast< Button* >(GetControl(IDC_MAIN_BUTTON_LOGIN));
	pButtonTmp->SetShowState(false);
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

	playerLogin(this);

	// cloud save
	csLoadCount = 0;
	playNum = 5;

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
	Tizen::Ui::Controls::Label * pLabelPlayNum = static_cast < Label* >(GetControl(IDC_LABEL_PLAYNUM));
	String str = Integer::ToString(playNum);
	pLabelPlayNum->SetText(str);
	pLabelPlayNum->Draw();


	// clound save 데이터를 불러온다. (멀티플레이 전적)
	csController = new GHCloudsaveController();
	csController->loadCloudSlotData(1,this); // 멀티플레이 승 데이터
	csController->loadCloudSlotData(2,this); // 멀티플레이 패 데이터


}

void
FormMain::OnSceneDeactivated(const Tizen::Ui::Scenes::SceneId& currentSceneId,
										   const Tizen::Ui::Scenes::SceneId& nextSceneId)
{
	// TODO: Deactivate your scene here.

}

void FormMain::loginPlayerFinished(Tizen::Base::String statusCode)
{
	if(statusCode != "0") {
		ahController = new GHAttackhelperController();
		ahController->loadAttackhelperDatas(this);

		// clound save 데이터를 불러온다. (멀티플레이 전적)
		csController = new GHCloudsaveController();
		csController->loadCloudSlotData(1,this); // 멀티플레이 승 데이터
		csController->loadCloudSlotData(2,this); // 멀티플레이 패 데이터

	}
}
void FormMain::loadCloudsaveFinished(int slotIdx, Tizen::Base::String data)
{
	if(slotIdx == 1) { // 승
		csLoadCount++;
		multiplay_winNum = data;
		AppLogDebug("loadCloudsaveFinished : 1");
	}else if(slotIdx == 2) { // 패
		AppLogDebug("loadCloudsaveFinished : 2");
		multiplay_loseNum = data;
		csLoadCount++;
	}

	if(csLoadCount % 2 == 0) {	// 승/패 데이터가 모두 왔을 때
		Tizen::Ui::Controls::Label * pLabelRecord = static_cast < Label* >(GetControl(IDC_LABEL_RECORD));
		String str = multiplay_winNum + "승 " + multiplay_loseNum + "패";

		if(pLabelRecord != null) {
			pLabelRecord->SetText(str);
			pLabelRecord->Draw();
		}
	}
}



void FormMain::respondAttackhelperDataFinished(GHAttackhelperData* attackhelperData, int accpet_flag)
{
	AppLogDebug("respondAttackhelperDataFinished");

	if(attackhelperData == null) {
		return;
	}

	if(accpet_flag == 1) {	 // 수락
		int quantity = attackhelperData->getQuantity();
		playNum += quantity;

		AppLogDebug("respondAttackhelperDataFinished : %d", playNum);
		Tizen::Ui::Controls::Label * pLabelPlayNum = static_cast < Label* >(GetControl(IDC_LABEL_PLAYNUM));
		String str = Integer::ToString(playNum);
		pLabelPlayNum->SetText(str);
		pLabelPlayNum->Draw();

	}else {
		return;
	}


}



