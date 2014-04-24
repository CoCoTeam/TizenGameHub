/*
 * GameSelectForm.h
 *
 *  Created on: Mar 17, 2014
 *      Author: hursujung
 */

#ifndef GAMESELECTFORM_H_
#define GAMESELECTFORM_H_


#include <FBase.h>
#include <FUi.h>
#include <FGraphics.h>
#include "SceneRegister.h"
#include "GHPlayer/GHPlayerController.h"


using namespace Tizen::Ui::Scenes;
using namespace Tizen::Graphics;
using namespace Tizen::Base::Collection;
using namespace Tizen::Base;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;
using namespace Tizen::App;

class GameSelectForm
: public Tizen::Ui::Controls::Form
	, public Tizen::Ui::IActionEventListener
	, public Tizen::Ui::Controls::IFormBackEventListener
	, public GHPlayerController
{
public:
	GameSelectForm();
	virtual ~GameSelectForm();
	bool Initialize(void);

	virtual result OnInitializing(void);
	virtual result OnTerminating(void);
	virtual void OnActionPerformed(const Tizen::Ui::Control& source, int actionId);
	//IFormBackEventListener
	virtual void OnFormBackRequested(Tizen::Ui::Controls::Form& source);

	Tizen::Ui::Controls::Button *__pButtonMODE1;
	Tizen::Ui::Controls::Button *__pButtonMODE2;

protected:
	static const int ID_BUTTON_MODE1 = 101;
	static const int ID_BUTTON_MODE2 = 102;

};

#endif /* GAMESELECTFORM_H_ */
