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

#include "SceneManagementFrame.h"
#include "SceneRegister.h"

using namespace Tizen::Base;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Ui::Scenes;


SceneManagementFrame::SceneManagementFrame(void)
{
}

SceneManagementFrame::~SceneManagementFrame(void)
{
}

result
SceneManagementFrame::OnInitializing(void)
{
	// SceneManagement initializing
	SceneRegister::RegisterAllScenes();
	// Go to the first scene.
	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);
	result r = pSceneManager->GoForward(ForwardSceneTransition(SCENE_MAIN_MENU));
	TryReturn(!IsFailed(r), r, "%s", GetErrorMessage(r));

	return E_SUCCESS;
}

result
SceneManagementFrame::OnTerminating(void)
{
	return E_SUCCESS;
}


