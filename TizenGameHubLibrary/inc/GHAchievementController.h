/*
 * GHAchievementController.h
 *
 *  Created on: Mar 26, 2014
 *      Author: JOHEEYEON
 */

#ifndef GHACHIEVEMENTCONTROLLER_H_
#define GHACHIEVEMENTCONTROLLER_H_

#include <GHTizen.h>
#include <GHController.h>
#include <GHAchievement.h>
#include <GHAchievementListener.h>
#include <GHhttpClient.h>

const int ERROR					= 0;
const int ACHIEVEMENT_LOAD		= 11;
const int ACHIEVEMENT_REVEAL 	= 12;
const int ACHIEVEMENT_COMPLETE 	= 13;
const int ACHIEVEMENT_SET 		= 14;

class GHAchievementController
	: public GHController{
public:
	GHAchievementController();
	virtual ~GHAchievementController();

	// achievement 목록을 가져온다.
	void loadAchievements(GHAchievementListener * listener);							// load listener

	// hidden -> reveal 상태로 바꾼다.
	void revealAchievement(Tizen::Base::String id);
	void revealAchievement(Tizen::Base::String id, GHAchievementListener* listener); 	// update listener

	// normal achievement update
	void completeAchievement(Tizen::Base::String id);
	void completeAchievement(Tizen::Base::String id, GHAchievementListener* listener); 	// update listener

	// incremental achievement update
	void increaseAchievement(Tizen::Base::String id);
	void increaseAchievement(Tizen::Base::String id, GHAchievementListener* listener); 	// update listener


private:
	virtual void OnTransactionReadyToRead(Tizen::Base::String apiCode, Tizen::Base::String statusCode, Tizen::Web::Json::IJsonValue* data);
	Tizen::Base::Collection::HashMap* __pMap;
	GHAchievementListener* currentListener;
};

#endif /* GHACHIEVEMENTCONTROLLER_H_ */
