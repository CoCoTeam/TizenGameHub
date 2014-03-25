#include "TizenGameHubFrame.h"
#include "TizenGameHubFormFactory.h"
#include "TizenGameHubPanelFactory.h"
#include "AppResourceId.h"

using namespace Tizen::Base;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Ui::Scenes;

TizenGameHubFrame::TizenGameHubFrame(void)
{
}

TizenGameHubFrame::~TizenGameHubFrame(void)
{
}

const wchar_t* SCENE_MAIN = L"MainScene";
const wchar_t* SCENE_JOIN = L"JoinScene";
const wchar_t* SCENE_LOGIN = L"LoginScene";
const wchar_t* SCENE_GAME = L"GameScene";
const wchar_t* SCENE_PLAYER = L"PlayerScene";

result
TizenGameHubFrame::OnInitializing(void)
{
	// Prepare Scene management.
	SceneManager* pSceneManager = SceneManager::GetInstance();
	static TizenGameHubFormFactory formFactory;
	static TizenGameHubPanelFactory panelFactory;
	pSceneManager->RegisterFormFactory(formFactory);
	pSceneManager->RegisterPanelFactory(panelFactory);
//	pSceneManager->RegisterScene(L"workflow");

	pSceneManager->RegisterScene(SCENE_JOIN, IDL_FORM_JOIN, L"");
	pSceneManager->RegisterScene(SCENE_LOGIN, IDL_FORM_LOGIN, L"");
	pSceneManager->RegisterScene(SCENE_GAME, IDL_FORM_GAME, L"");
	pSceneManager->RegisterScene(SCENE_PLAYER, IDL_FORM_PLAYER, L"");

	// Go to the scene.
//	result r = pSceneManager->GoForward(SceneTransitionId(IDSCNT_MAIN_SCENE));
	result r = pSceneManager->GoForward(ForwardSceneTransition(SCENE_LOGIN));

	// TODO: Add your frame initialization code here.
	return r;
}

result
TizenGameHubFrame::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your frame termination code here.
	return r;
}
