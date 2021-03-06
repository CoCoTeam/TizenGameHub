#include <new>
#include "CardPairFormFactory.h"
#include "FormMain.h"
#include "FormModeSelect.h"
#include "FormSocial.h"
#include "FormGameTimeTrial.h"
#include "FormGameSeconds.h"
#include "FormGameMulti.h"
#include "AppResourceId.h"
#include "CardPairFrame.h"

#include "LibResourceId.h"
#include "GHForm/AchievementForm.h"
#include "GHForm/LeaderboardForm.h"
#include "GHForm/LeaderboardRankForm.h"

using namespace Tizen::Ui::Scenes;


CardPairFormFactory::CardPairFormFactory(void)
{
}

CardPairFormFactory::~CardPairFormFactory(void)
{
}

Tizen::Ui::Controls::Form*
CardPairFormFactory::CreateFormN(const Tizen::Base::String& formId, const Tizen::Ui::Scenes::SceneId& sceneId)
{
	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);
	Tizen::Ui::Controls::Form* pNewForm = null;

	if (formId == IDL_FORM)
	{
		FormMain* pForm = new (std::nothrow) FormMain();
		TryReturn(pForm != null, null, "The memory is insufficient.");
		pForm->Initialize();
		pSceneManager->AddSceneEventListener(sceneId, *pForm);
		pNewForm = pForm;
	}
	else if (formId == IDL_FORM2)
	{
		FormSocial* pForm = new (std::nothrow) FormSocial();
		TryReturn(pForm != null, null, "The memory is insufficient.");
		pForm->Initialize();
		pNewForm = pForm;
	}
	else if (formId == IDL_FORM3)
	{
		FormModeSelect* pForm = new (std::nothrow) FormModeSelect();
		TryReturn(pForm != null, null, "The memory is insufficient.");
		pForm->Initialize();
		pNewForm = pForm;
	}
	else if (formId == IDL_FORM_GAME)
	{
		FormGameTimeTrial* pForm = new (std::nothrow) FormGameTimeTrial();
		TryReturn(pForm != null, null, "The memory is insufficient.");
		pForm->Initialize();
		pNewForm = pForm;
	}
	else if (formId == IDL_FORM_GAME2)
	{
		FormGameSeconds* pForm = new (std::nothrow) FormGameSeconds();
		TryReturn(pForm != null, null, "The memory is insufficient.");
		pForm->Initialize();
		pNewForm = pForm;
	}
	else if (formId == IDL_FORM_GAME3)
	{
		FormGameMulti* pForm = new (std::nothrow) FormGameMulti();
		TryReturn(pForm != null, null, "The memory is insufficient.");
		pForm->Initialize();
		pNewForm = pForm;
	}
	else if (formId == IDL_GHFORM_ACHIEVEMENT)
	{
		AchievementForm* pForm = new (std::nothrow) AchievementForm();
		TryReturn(pForm != null, null, "The memory is insufficient.");
		pForm->Initialize();
		pNewForm = pForm;
	}
	else if (formId == IDL_GHFORM_LEADERBOARD)
	{
		LeaderboardForm* pForm = new (std::nothrow) LeaderboardForm();
		TryReturn(pForm != null, null, "The memory is insufficient.");
		pForm->Initialize();
		pNewForm = pForm;
	}
	else if (formId == IDL_GHFORM_LEADERBOARDRANK)
	{
		LeaderboardRankForm* pForm = new (std::nothrow) LeaderboardRankForm();
		TryReturn(pForm != null, null, "The memory is insufficient.");
		pForm->Initialize();
		pSceneManager->AddSceneEventListener(sceneId, *pForm);
		pNewForm = pForm;
	}

	return pNewForm;
}
