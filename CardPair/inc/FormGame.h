#ifndef _CARDPAIR_FORM_GAME_H_
#define _CARDPAIR_FORM_GAME_H_

#include "tizenx.h"
#include "AppResourceId.h"


class FormGame
	: public Tizen::Ui::Controls::Form
	, public virtual Tizen::Ui::IActionEventListener
	, public Tizen::Ui::Controls::IFormBackEventListener
	, public Tizen::Base::Runtime::ITimerEventListener
{
public:
	FormGame(void);
	virtual ~FormGame(void);
	bool Initialize(void);

	virtual result OnInitializing(void);
	virtual result OnTerminating(void);
	virtual void OnActionPerformed(const Tizen::Ui::Control& source, int actionId);
	void ParentOnActionPerformed(const Tizen::Ui::Control& source, int actionId);
	virtual void OnFormBackRequested(Tizen::Ui::Controls::Form& source);

	long initialTime;
	int initialScore;
	void setTimeLabel(Tizen::Base::TimeSpan span);

	void setTimer(void);
	result setInitialState();
	virtual void setAdditionalInitialState()=0;
	void shuffleCard();
	void startInitState();
	result startGame();
	virtual void onReadyToStart() = 0;
	virtual result SetGameTimer(Tizen::Base::TimeSpan ts) = 0;
	virtual void onStageComplete() = 0;
	virtual void onTurnFinished(int actionType, int cardNum, bool isCorrect) = 0;

	virtual void OnTimerExpired(Tizen::Base::Runtime::Timer& timer);
	Tizen::Base::TimeSpan getCurrentTimeSpan(long long prevTick);

	long long gameTick, initTick, compareTick, flipTick, multiTick;		// 각 Timer 별 초기 tick value
	Tizen::Base::Runtime::Timer *pTimerGame, *pTimerInit, *pTimerCompare, *pTimerFlip, *pTimerMulti;
	Tizen::Ui::Controls::Label *pLabelTimer, *pLabelCount, *pLabelScore;

	static const int MAX_CARD_SIZE = 20;
	Tizen::Ui::Controls::Button *pButtonCard[MAX_CARD_SIZE];
	Tizen::Base::String cardChar[MAX_CARD_SIZE];

	bool isClickable, isComplete;
	int prevSelected, nowSelected, countRemoved, gameScore, combo, maxCombo;
	void setGameScore();
	void setCardVisible(int cardNum, bool visibility = true);
	void removeCard();
	void compareCard();
	void onTurnExpired();
	virtual void startMyTurnThread() = 0;

	bool onMyTurn;
	bool isMultiplay;
	Tizen::Ui::Controls::Label *pLabelMyTurn, *pLabelYourTurn;

protected:
	static const int IDA_CARD_BASE = 300;
};

#endif	//_CARDPAIR_FORM_GAME_H_
