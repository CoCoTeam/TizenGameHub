#include "TizenGameHubPanelFactory.h"

using namespace Tizen::Ui::Scenes;


TizenGameHubPanelFactory::TizenGameHubPanelFactory(void)
{
}

TizenGameHubPanelFactory::~TizenGameHubPanelFactory(void)
{
}

Tizen::Ui::Controls::Panel*
TizenGameHubPanelFactory::CreatePanelN(const Tizen::Base::String& panelId, const Tizen::Ui::Scenes::SceneId& sceneId)
{
	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);
	Tizen::Ui::Controls::Panel* pNewPanel = null;

	// TODO: Add your panel creation code here
	return pNewPanel;
}
