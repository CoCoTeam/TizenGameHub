#ifndef _CARD_PAIR_FORM_SECONDS_H_
#define _CARD_PAIR_FORM_SECONDS_H_

#include "tizenx.h"
#include "FormGame.h"

class FormGameSeconds
	: public FormGame
{
public:
	FormGameSeconds(void);
	virtual ~FormGameSeconds(void);
//	bool Initialize(void);

private:
	virtual void setAdditionalInitialState() {};
	virtual result SetGameTimer(Tizen::Base::TimeSpan ts);
	virtual void onStageComplete();
	virtual void onReadyToStart() {};
	virtual void startMyTurnThread() {};
	virtual void onTurnFinished(int actionType, int cardNum, bool isCorrect) {};

	void onGameEnded();
	Tizen::Base::TimeSpan timespan = null;
	static const int GAME_SEC = 60;
};

#endif	//_CARD_PAIR_FORM_SECONDS_H_
