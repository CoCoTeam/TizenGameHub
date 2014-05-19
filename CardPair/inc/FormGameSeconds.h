#ifndef _CARD_PAIR_FORM_SECONDS_H_
#define _CARD_PAIR_FORM_SECONDS_H_

#include "tizenx.h"
#include "FormGame.h"

#include "GHAchievement/GHAchievementController.h"
#include "GHLeaderboard/GHLeaderboardController.h"
//#include "GHAchievement/GHAchievementLoadedListener.h"
//#include "GHAchievement/GHAchievementRevealedListener.h"
#include "GHAchievement/GHAchievementCompletedListener.h"
#include "GHLeaderboard/GHLeaderboardScoreUpdatedListener.h"

class FormGameSeconds
	: public FormGame
	, public GHAchievementCompletedListener
	, public GHLeaderboardScoreUpdatedListener
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

	virtual void completeAchievementFinished(int statusCode);
	virtual void updateLeaderboardScoreFinished(int statusCode);
};

#endif	//_CARD_PAIR_FORM_SECONDS_H_
