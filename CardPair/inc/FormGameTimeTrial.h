#ifndef _CARD_PAIR_FORM_TIMETRIAL_H_
#define _CARD_PAIR_FORM_TIMETRIAL_H_

#include "tizenx.h"
#include "FormGame.h"

class FormGameTimeTrial
	: public FormGame
{
public:
	FormGameTimeTrial(void);
	virtual ~FormGameTimeTrial(void);

private:
	virtual void setAdditionalInitialState() {};
	virtual result SetGameTimer(Tizen::Base::TimeSpan ts);
	virtual void onStageComplete();
	virtual void onReadyToStart() {};
	virtual void startMyTurnThread() {};
	virtual void onTurnFinished(int actionType, int cardNum, bool isCorrect) {};

	int getMillisec(Tizen::Base::String timeStr);
};

#endif	//_CARD_PAIR_FORM_TIMETRIAL_H_
