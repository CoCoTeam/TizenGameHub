#include "CardPairFrame.h"
#include "CardPairFormFactory.h"
#include "AppResourceId.h"

using namespace Tizen::Base;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Ui::Scenes;

CardPairFrame::CardPairFrame(void)
{
}

CardPairFrame::~CardPairFrame(void)
{
}

const wchar_t* SCENE_MAIN 			= L"MainScene";
const wchar_t* SCENE_MODESELECT 	= L"ModeSelectScene";
const wchar_t* SCENE_SOCIAL 		= L"SocialScene";
const wchar_t* SCENE_GAME_TIMETRIAL = L"TimeTrialScene";
const wchar_t* SCENE_GAME_SECONDS 	= L"GameSecondsScene";
const wchar_t* SCENE_GAME_MULTI 	= L"GameMulti";

result
CardPairFrame::OnInitializing(void)
{
	// Prepare Scene management.
	SceneManager* pSceneManager = SceneManager::GetInstance();
	static CardPairFormFactory formFactory;
	pSceneManager->RegisterFormFactory(formFactory);
	pSceneManager->RegisterScene(L"workflow");
	pSceneManager->RegisterScene(SCENE_MAIN, IDL_FORM, L"");
	pSceneManager->RegisterScene(SCENE_SOCIAL, IDL_FORM2, L"");
	pSceneManager->RegisterScene(SCENE_MODESELECT, IDL_FORM3, L"");
	pSceneManager->RegisterScene(SCENE_GAME_TIMETRIAL, IDL_FORM_GAME, L"");
	pSceneManager->RegisterScene(SCENE_GAME_SECONDS, IDL_FORM_GAME2, L"");
	pSceneManager->RegisterScene(SCENE_GAME_MULTI, IDL_FORM_GAME3, L"");

	// Go to the scene.
	result r = pSceneManager->GoForward(ForwardSceneTransition(SCENE_MAIN));

	// TODO: Add your frame initialization code here.
	return r;
}

result
CardPairFrame::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your frame termination code here.
	return r;
}
