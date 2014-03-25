#include <new>
#include "TizenGameHubFormFactory.h"
#include "TizenGameHubMainForm.h"
#include "AppResourceId.h"

using namespace Tizen::Ui::Scenes;


TizenGameHubFormFactory::TizenGameHubFormFactory(void)
{
}

TizenGameHubFormFactory::~TizenGameHubFormFactory(void)
{
}

Tizen::Ui::Controls::Form*
TizenGameHubFormFactory::CreateFormN(const Tizen::Base::String& formId, const Tizen::Ui::Scenes::SceneId& sceneId)
{
	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);
	Tizen::Ui::Controls::Form* pNewForm = null;

	if (formId == IDL_FORM)
	{
		TizenGameHubMainForm* pForm = new (std::nothrow) TizenGameHubMainForm();
		TryReturn(pForm != null, null, "The memory is insufficient.");
		pForm->Initialize();
		pSceneManager->AddSceneEventListener(sceneId, *pForm);
		pNewForm = pForm;
	}
	// TODO: Add your form creation code here

	return pNewForm;
}
