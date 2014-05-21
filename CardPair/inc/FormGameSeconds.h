#ifndef _CARD_PAIR_FORM_SECONDS_H_
#define _CARD_PAIR_FORM_SECONDS_H_

#include "tizenx.h"
#include "FormGame.h"
#include "GHTizen.h"
#include "GHAchievement/GHAchievementController.h"
#include "GHLeaderboard/GHLeaderboardController.h"
#include "GHAchievement/GHAchievementLoadedListener.h"
//#include "GHAchievement/GHAchievementRevealedListener.h"
#include "GHAchievement/GHAchievementCompletedListener.h"
#include "GHLeaderboard/GHLeaderboardScoreUpdatedListener.h"
#include "GHAchievement/GHAchievementSettedListener.h"

class FormGameSeconds
	: public FormGame
	, public GHAchievementCompletedListener
	, public GHLeaderboardScoreUpdatedListener
	, public GHAchievementSettedListener
	, public GHAchievementLoadedListener
	//, public GHAchievementRevealedListener
	, public virtual Tizen::Ui::IActionEventListener
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
	static const int GAME_SEC = 10;
	int game_count = 0; // 게임횟수

	virtual void loadAchievementFinished(Tizen::Base::Collection::ArrayList* achievementList);
	virtual void completeAchievementFinished(int statusCode);
	virtual void updateLeaderboardScoreFinished(int statusCode);
	virtual void setAchievementFinished(int statusCode);
	//virtual void revealAchievementFinished(int statusCode);

	static const int ACTION_POPUP_CLOSE = 111;
	Tizen::Ui::Controls::Popup* pPopup;

	void OnActionPerformed(const Tizen::Ui::Control& source, int actionId);


};

#endif	//_CARD_PAIR_FORM_SECONDS_H_
