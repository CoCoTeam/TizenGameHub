#include <new>
#include "TizenGameHubFormFactory.h"
#include "TizenGameHubMainForm.h"
#include "AppResourceId.h"
#include "LoginForm.h"
#include "JoinForm.h"
#include "PlayerForm.h"
#include "PlayerFriendForm.h"
#include "GameForm.h"
#include "AchievementForm.h"
#include "LeaderboardForm.h"
#include "LeaderboardRankForm.h"
#include "FriendSeachForm.h"

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
	else if(formId == IDL_FORM_LOGIN)
	{
		LoginForm* pForm = new (std::nothrow) LoginForm();
		TryReturn(pForm != null, null, "The memory is insufficient.");
		pForm->Initialize();
		pNewForm = pForm;
	}
	else if(formId == IDL_FORM_JOIN)
	{
		JoinForm *pForm = new (std::nothrow) JoinForm();
		TryReturn(pForm != null, null, "The memory is insufficient.");
		pSceneManager->AddSceneEventListener(sceneId, *pForm);
		pForm->Initialize();
		pNewForm = pForm;
	}
	else if(formId == IDL_FORM_PLAYER)
	{
		PlayerForm *pForm = new (std::nothrow) PlayerForm();
		TryReturn(pForm != null, null, "The memory is insufficient.");
		pSceneManager->AddSceneEventListener(sceneId, *pForm);
		pForm->Initialize();
		pNewForm = pForm;
	}
	else if(formId == IDL_FORM_PLAYERFRIEND)
	{
		PlayerFriendForm *pForm = new (std::nothrow) PlayerFriendForm();
		TryReturn(pForm != null, null, "The memory is insufficient.");
		pSceneManager->AddSceneEventListener(sceneId, *pForm);
		pForm->Initialize();
		pNewForm = pForm;
	}
	else if(formId == IDL_FORM_GAME)
	{
		GameForm *pForm = new (std::nothrow) GameForm();
		TryReturn(pForm != null, null, "The memory is insufficient.");
		pSceneManager->AddSceneEventListener(sceneId, *pForm);
		pForm->Initialize();
		pNewForm = pForm;
	}
	else if(formId == IDL_FORM_ACHIEVEMENT)
	{
		AchievementForm *pForm = new (std::nothrow) AchievementForm();
		TryReturn(pForm != null, null, "The memory is insufficient.");
		pSceneManager->AddSceneEventListener(sceneId, *pForm);
		pForm->Initialize();
		pNewForm = pForm;
	}
	else if(formId == IDL_FORM_LEADERBOARD)
	{
		LeaderboardForm *pForm = new (std::nothrow) LeaderboardForm();
		TryReturn(pForm != null, null, "The memory is insufficient.");
		pSceneManager->AddSceneEventListener(sceneId, *pForm);
		pForm->Initialize();
		pNewForm = pForm;
	}
	else if(formId == IDL_FORM_LEADERBOARDRANK)
	{
		LeaderboardRankForm *pForm = new (std::nothrow) LeaderboardRankForm();
		TryReturn(pForm != null, null, "The memory is insufficient.");
		pSceneManager->AddSceneEventListener(sceneId, *pForm);
		pForm->Initialize();
		pNewForm = pForm;
	}
	else if(formId == IDL_FORM_SEARCHFRIEND)
	{
		FriendSeachForm *pForm = new (std::nothrow) FriendSeachForm();
		TryReturn(pForm != null, null, "The memory is insufficient.");
		pForm->Initialize();
		pNewForm = pForm;
	}

	return pNewForm;
}
