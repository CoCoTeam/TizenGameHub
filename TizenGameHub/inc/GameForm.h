/*
 * GameForm.h
 *
 *  Created on: Mar 25, 2014
 *      Author: Administrator
 */

#ifndef GAMEFORM_H_
#define GAMEFORM_H_

#include <GHTizen.h>
#include "GHGame.h"

class GameForm
	: public Tizen::Ui::Controls::Form
	, public Tizen::Ui::IActionEventListener
	, public Tizen::Ui::Controls::IFormBackEventListener
	, public Tizen::Ui::Scenes::ISceneEventListener
{
public:
	GameForm();
	virtual ~GameForm();
	bool Initialize(void);

private:
	GHGame *mGame;

	virtual result OnInitializing(void);
	virtual result OnTerminating(void);
	//IActionEventListener
	virtual void OnActionPerformed(const Tizen::Ui::Control& source, int actionId);
	//IFormBackEventListener
	virtual void OnFormBackRequested(Tizen::Ui::Controls::Form& source);
	//ISceneEventListener
	virtual void OnSceneActivatedN(const Tizen::Ui::Scenes::SceneId& previousSceneId,
								   const Tizen::Ui::Scenes::SceneId& currentSceneId, Tizen::Base::Collection::IList* pArgs);
	virtual void OnSceneDeactivated(const Tizen::Ui::Scenes::SceneId& currentSceneId,
									const Tizen::Ui::Scenes::SceneId& nextSceneId);

	GHGame* getGameInstance(long id);
};

#endif /* GAMEFORM_H_ */
