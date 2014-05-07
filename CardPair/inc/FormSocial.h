#ifndef _CARD_PAIR_FORM_SOCIAL_H_
#define _CARD_PAIR_FORM_SOCIAL_H_

#include "tizenx.h"
#include "GHPlayer/GHPlayerController.h"
#include "GHPlayer/GHPlayerLoggedinListener.h"

class FormSocial
	: public Tizen::Ui::Controls::Form
	, public Tizen::Ui::IActionEventListener
	, public Tizen::Ui::Controls::IFormBackEventListener
 	, public GHPlayerController
 	, public GHPlayerLoggedinListener
{
public:
	FormSocial(void);
	virtual ~FormSocial(void);
	bool Initialize(void);

private:
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);
	virtual void OnActionPerformed(const Tizen::Ui::Control& source, int actionId);
	virtual void OnFormBackRequested(Tizen::Ui::Controls::Form& source);
	virtual void loginPlayerFinished(Tizen::Base::String statusCode);

	void setButtonConfig();
	Tizen::Ui::Controls::Button* pButtonLogin;
	Tizen::Ui::Controls::Button* pButtonLeaderboard;
	Tizen::Ui::Controls::Button* pButtonAchievement;

protected:
	static const int IDA_BUTTON_PLAY = 101;
	static const int IDA_BUTTON_LEADERBOARD = 102;
	static const int IDA_BUTTON_ACHIEVEMENT  = 103;
};

#endif	//_CARD_PAIR_FORM_SOCIAL_H_
