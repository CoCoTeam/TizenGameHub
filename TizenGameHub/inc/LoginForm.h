/*
 * LoginForm.h
 *
 *  Created on: Mar 25, 2014
 *      Author: Administrator
 */

#ifndef LOGINFORM_H_
#define LOGINFORM_H_

#include "GHTizen.h"
#include "GHhttpClient.h"
#include "GHPlayer/GHPlayerController.h"
#include "GHPlayer/GHPlayerLoggedinListener.h"

#include <GHAchievementController.h>
#include <GHAchievementLoadedListener.h>
#include <GHAttackhelperController.h>
#include <GHAttackhelperLoadedListener.h>
#include <GHAttackhelperDataRespondedListener.h>


#include <GHLeaderboard/GHLeaderboardController.h>
#include <GHLeaderboard/GHLeaderboardDataLoadedListener.h>
#include <GHLeaderboard/GHLeaderboardListLoadedListener.h>
#include <GHLeaderboard/GHLeaderboardScoreUpdatedListener.h>

#include <GHCloudsaveController.h>
#include <GHCloudsaveSaveListener.h>
#include <GHCloudsaveLoadListener.h>


using namespace Tizen::Ui::Controls;

class LoginForm
	: public Tizen::Ui::Controls::Form
	, public Tizen::Ui::IActionEventListener
	, public Tizen::Ui::Controls::IFormBackEventListener
	, public GHPlayerController
	, public GHPlayerLoggedinListener
	, public GHAchievementLoadedListener // TEST API
	, public GHAttackhelperLoadedListener // TEST API
	, public GHAttackhelperDataRespondedListener // TEST API

	, public GHLeaderboardDataLoadedListener //Test API
	, public GHLeaderboardListLoadedListener
	, public GHLeaderboardScoreUpdatedListener

	, public GHCloudsaveSaveListener	// TEST API
	, public GHCloudsaveLoadListener	// TEST API

{
public:
	LoginForm();
	virtual ~LoginForm();
	bool Initialize(void);

private:
	EditField *pTextEmail, *pTextPw;

	virtual result OnInitializing(void);
	virtual result OnTerminating(void);
	//IActionEventListener
	virtual void OnActionPerformed(const Tizen::Ui::Control& source, int actionId);
	//IFormBackEventListener
	virtual void OnFormBackRequested(Tizen::Ui::Controls::Form& source);
	//GHPlayerLoggedinListener
	virtual void loginPlayerFinished(Tizen::Base::String statusCode);

	static const int IDA_BUTTON_LOGIN = 101;
	static const int IDA_BUTTON_JOIN = 102;
	static const int IDA_BUTTON_TEST = 103;

	// API TEST
	virtual void loadAchievementFinished(Tizen::Base::Collection::ArrayList* achievementList);
	virtual void loadAttackhelperFinished(Tizen::Base::Collection::ArrayList* achievementList);
	virtual void respondAttackhelperDataFinished(int statusCode);
	virtual void saveCloudsaveFinished(int statusCode);
	virtual void loadCloudsaveFinished(Tizen::Base::String data);

	result doLogin();

	// GHLeaderboard
	virtual void loadLeaderboardFinished(Tizen::Base::Collection::ArrayList* leaderboardList);
	virtual void loadLeaderboardRankFinished(Tizen::Base::Collection::ArrayList* leaderboardList);
	virtual void updateLeaderboardScoreFinished(int statusCode);

};

#endif /* LOGINFORM_H_ */
