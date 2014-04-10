/*
 * GHAchievementController.h
 *
 *  Created on: Mar 26, 2014
 *      Author: JOHEEYEON
 */

#ifndef GHACHIEVEMENTCONTROLLER_H_
#define GHACHIEVEMENTCONTROLLER_H_

#include "GHTizen.h"
#include "GHController.h"
#include "GHAchievement.h"
#include "GHAchievementListener.h"
#include "GHAchievementLoadedListener.h"
#include "GHAchievementRevealedListener.h"
#include "GHAchievementCompletedListener.h"
#include "GHAchievementSettedListener.h"
#include "GHhttpClient.h"

//const String ERROR					= "0";
const Tizen::Base::String ACHIEVEMENT_LOAD		= "11";
const Tizen::Base::String ACHIEVEMENT_REVEAL 	= "12";
const Tizen::Base::String ACHIEVEMENT_COMPLETE 	= "13";
const Tizen::Base::String ACHIEVEMENT_SET 		= "14";

class GHAchievementController
	: public GHController{
public:
	GHAchievementController();
	virtual ~GHAchievementController();

	// achievement 목록을 가져온다.
	void loadAchievements(GHAchievementLoadedListener * listener);							// load listener

	// hidden -> reveal 상태로 바꾼다.
	void revealAchievement(Tizen::Base::String ac_id);
	void revealAchievement(Tizen::Base::String ac_id, GHAchievementRevealedListener* listener); 	// update listener

	// normal achievement update
	void completeAchievement(Tizen::Base::String ac_id);
	void completeAchievement(Tizen::Base::String ac_id, GHAchievementCompletedListener* listener); 	// update listener

	// incremental achievement update
	void setAchievement(Tizen::Base::String ac_id);
	void setAchievement(Tizen::Base::String ac_id, GHAchievementSettedListener* listener); 	// update listener



private:
	virtual void OnTransactionReadyToRead(Tizen::Base::String apiCode, Tizen::Base::String statusCode, Tizen::Web::Json::IJsonValue* data);
	Tizen::Base::Collection::HashMap* __pMap;
	GHAchievementListener* currentListener;
};

#endif /* GHACHIEVEMENTCONTROLLER_H_ */
