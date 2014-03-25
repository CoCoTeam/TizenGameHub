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

#include "SceneRegister.h"
#include "AppResourceId.h"
#include "FormFactory.h"
/*
#include "PanelFactory.h"
#include "SceneChangeLogger.h"
#include "SceneTransitionPolicyProvider.h"
*/
#include <FUi.h>

using namespace Tizen::Ui::Scenes;

// Definitions of extern.

const wchar_t* SCENE_MAIN_MENU = L"ScnGameMain";
const wchar_t* SCENE_MAIN_MENU2 = L"ScnGameMain2";
const wchar_t* SCENE_Ranking = L"ScnRanking";
const wchar_t* SCENE_GAME_SECLECT = L"ScnGameSelect";


//SceneChangeLogger SceneRegister::changeLogger;

SceneRegister::SceneRegister(void)
{
}

SceneRegister::~SceneRegister(void)
{
}

void
SceneRegister::RegisterAllScenes(void)
{
	static const wchar_t* PANEL_BLANK = L"";
	static FormFactory formFactory;
	//static PanelFactory panelFactory;
	//static SceneTransitionPolicyProvider policyProvider;

	//AppLog("----------------------------------------------------------------");

	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);
	pSceneManager->RegisterFormFactory(formFactory);

	/*
	pSceneManager->RegisterPanelFactory(panelFactory);
	pSceneManager->SetSceneTransitionPolicyProvider(&policyProvider);*/
	//pSceneManager->AddSceneManagerEventListener(SceneRegister::changeLogger);

	pSceneManager->RegisterScene(SCENE_MAIN_MENU, GameMain, PANEL_BLANK);
	pSceneManager->RegisterScene(SCENE_MAIN_MENU2, GameMain2, PANEL_BLANK);
	pSceneManager->RegisterScene(SCENE_Ranking, Ranking, PANEL_BLANK);
	pSceneManager->RegisterScene(SCENE_GAME_SECLECT, GameSelect, PANEL_BLANK);

}



