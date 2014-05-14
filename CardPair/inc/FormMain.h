#ifndef _CARD_PAIR_FORM_MAIN_H_
#define _CARD_PAIR_FORM_MAIN_H_

#include "tizenx.h"
#include "GHPlayer/GHPlayerController.h"
#include "GHPlayer/GHPlayerLoggedinListener.h"
#include "GHAttackhelper/GHAttackhelperController.h"
#include "GHCloudsave/GHCloudsaveController.h"
#include "GHCloudsave/GHCloudsaveLoadListener.h"

class FormMain
	: public Tizen::Ui::Controls::Form
	, public Tizen::Ui::IActionEventListener
	, public Tizen::Ui::Controls::IFormBackEventListener
 	, public Tizen::Ui::Scenes::ISceneEventListener
 	, public GHPlayerController
 	, public GHPlayerLoggedinListener
 	, public GHCloudsaveLoadListener

{
public:
	FormMain(void);
	virtual ~FormMain(void);
	bool Initialize(void);

private:
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);
	virtual void OnActionPerformed(const Tizen::Ui::Control& source, int actionId);
	virtual void OnFormBackRequested(Tizen::Ui::Controls::Form& source);
	virtual void OnSceneActivatedN(const Tizen::Ui::Scenes::SceneId& previousSceneId,
								   const Tizen::Ui::Scenes::SceneId& currentSceneId, Tizen::Base::Collection::IList* pArgs);
	virtual void OnSceneDeactivated(const Tizen::Ui::Scenes::SceneId& currentSceneId,
									const Tizen::Ui::Scenes::SceneId& nextSceneId);
	// GHPlayerLoggedinListener
	virtual void loginPlayerFinished(Tizen::Base::String statusCode);
	GHAttackhelperController *ahController;


	// Cloud Save
	GHCloudsaveController *csController;
	virtual void loadCloudsaveFinished(int slotIdx, Tizen::Base::String data);
	int csLoadCount = 0;

protected:
	static const int IDA_BUTTON_PLAY = 101;
	static const int IDA_BUTTON_LEADERBOARD = 102;
	static const int IDA_BUTTON_ACHIEVEMENT  = 103;
};

#endif	//_CARD_PAIR_FORM_MAIN_H_
