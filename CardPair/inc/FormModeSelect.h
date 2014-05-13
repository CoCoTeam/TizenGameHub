#ifndef _CARD_PAIR_FORM_MODESELECT_H_
#define _CARD_PAIR_FORM_MODESELECT_H_

#include "tizenx.h"
#include "GHPlayer/GHPlayerLoggedinListener.h"

class FormModeSelect
	: public Tizen::Ui::Controls::Form
	, public Tizen::Ui::IActionEventListener
	, public Tizen::Ui::Controls::IFormBackEventListener
	, public GHPlayerLoggedinListener
{
public:
		FormModeSelect(void);
	virtual ~FormModeSelect(void);
	bool Initialize(void);

private:
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);
	virtual void OnActionPerformed(const Tizen::Ui::Control& source, int actionId);
	virtual void OnFormBackRequested(Tizen::Ui::Controls::Form& source);
	virtual void loginPlayerFinished(Tizen::Base::String statusCode);

	bool checkHeart();

protected:
	static const int IDA_BUTTON_TIME 	= 101;
	static const int IDA_BUTTON_SECONDS = 102;
	static const int IDA_BUTTON_MULTI	= 103;
};

#endif	//_CARD_PAIR_FORM_MODESELECT_H_
