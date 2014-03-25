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

result
TizenGameHubFrame::OnInitializing(void)
{
	// Prepare Scene management.
	SceneManager* pSceneManager = SceneManager::GetInstance();
	static TizenGameHubFormFactory formFactory;
	static TizenGameHubPanelFactory panelFactory;
	pSceneManager->RegisterFormFactory(formFactory);
	pSceneManager->RegisterPanelFactory(panelFactory);
	pSceneManager->RegisterScene(L"workflow");

	// Go to the scene.
	result r = pSceneManager->GoForward(SceneTransitionId(IDSCNT_MAIN_SCENE));

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
