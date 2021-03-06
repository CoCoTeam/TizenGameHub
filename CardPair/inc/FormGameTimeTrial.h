#ifndef _CARD_PAIR_FORM_TIMETRIAL_H_
#define _CARD_PAIR_FORM_TIMETRIAL_H_

#include "tizenx.h"
#include "FormGame.h"



#include "GHAchievement/GHAchievementController.h"
#include "GHLeaderboard/GHLeaderboardController.h"
#include "GHAchievement/GHAchievementLoadedListener.h"
#include "GHAchievement/GHAchievementRevealedListener.h"
#include "GHAchievement/GHAchievementCompletedListener.h"
#include "GHLeaderboard/GHLeaderboardScoreUpdatedListener.h"


//#include "GHAchievement/GHAchievementLoadedListener.h"
//#include "GHAchievement/GHAchievementRevealedListener.h"

class FormGameTimeTrial
	: public FormGame
	, public GHAchievementLoadedListener
	, public GHAchievementRevealedListener
	, virtual public GHAchievementCompletedListener
	, virtual public GHLeaderboardScoreUpdatedListener
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


	// GHLeaderboard
	virtual void loadAchievementFinished(Tizen::Base::Collection::ArrayList* achievementList);
	virtual void revealAchievementFinished(int statusCode);
	virtual void completeAchievementFinished(int statusCode);
	virtual void updateLeaderboardScoreFinished(int statusCode);
};

#endif	//_CARD_PAIR_FORM_TIMETRIAL_H_
