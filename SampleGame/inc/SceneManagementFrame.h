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

#ifndef _SCENE_MANAGEMENT_FRAME_H_
#define _SCENE_MANAGEMENT_FRAME_H_

#include <FBase.h>
#include <FUi.h>


class SceneManagementFrame
	: public Tizen::Ui::Controls::Frame
{
public:
	SceneManagementFrame(void);
	virtual ~SceneManagementFrame(void);

	virtual result OnInitializing(void);
	virtual result OnTerminating(void);
};

#endif // _SCENE_MANAGEMENT_FRAME_H_
