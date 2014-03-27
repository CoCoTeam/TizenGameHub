//
// Copyright (c) 2012 Samsung Electronics Co., Ltd.
//
// Licensed under the Flora License, Version 1.1 (the License);
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://floralicense.org/license
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an AS IS BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#include <new>
#include "FormFactory.h"
#include "Mode1.h"
#include "Mode2.h"
#include "Lanking.h"
#include "GameSelectForm.h"
#include "AppResourceId.h"

using namespace Tizen::Ui::Scenes;


// Definitions of extern.
const wchar_t* FORM_MAIN = L"FormMain";
const wchar_t* FORM_MAIN2 = L"FormMain2";
const wchar_t* FORM_Lanking = L"FormLanking";
const wchar_t* FORM_GameSelect = L"FormGameSelect";

FormFactory::FormFactory(void)
{
}

FormFactory::~FormFactory(void)
{
}

Tizen::Ui::Controls::Form*
FormFactory::CreateFormN(const Tizen::Base::String& formId, const Tizen::Ui::Scenes::SceneId& sceneId)
{
	Tizen::Ui::Controls::Form* pNewForm = null;
	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);

	if (formId == GameMain)
	{
		Mode1* pForm = new (std::nothrow) Mode1();
		pForm->Initialize();
		pNewForm = pForm;
	}
	else if (formId == Ranking)
	{
		Lanking* pForm = new (std::nothrow) Lanking();
		pForm->Initialize();
		pSceneManager->AddSceneEventListener(sceneId, *pForm);
		pNewForm = pForm;
	}
	else if (formId == GameSelect)
	{
		GameSelectForm* pForm = new (std::nothrow) GameSelectForm();
		pForm->Initialize();
		//pSceneManager->AddSceneEventListener(sceneId, *pForm);
		pNewForm = pForm;
	}
	else if (formId == GameMain2)
	{
		Mode2* pForm = new (std::nothrow) Mode2();
		pForm->Initialize();
		//pSceneManager->AddSceneEventListener(sceneId, *pForm);
		pNewForm = pForm;
	}


	return pNewForm;
}
