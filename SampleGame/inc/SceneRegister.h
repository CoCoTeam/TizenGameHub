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

#ifndef _SCENE_REGISTER_H_
#define _SCENE_REGISTER_H_

// Use 'extern' to eliminate duplicate data allocation.
extern const wchar_t* SCENE_MAIN_MENU;
extern const wchar_t* SCENE_MAIN_MENU2;
extern const wchar_t* SCENE_Ranking;
extern const wchar_t* SCENE_GAME_SECLECT;


//class SceneChangeLogger;

class SceneRegister
{
public:
	static void RegisterAllScenes(void);
	//static SceneChangeLogger changeLogger;

private:
	SceneRegister(void);
	~SceneRegister(void);
};

#endif // _SCENE_REGISTER_H_
