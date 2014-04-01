

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
	void loadAchievements(GHAchievementListener * listener);				// load listener

	// hidden -> reveal 상태로 바꾼다.
	void revealAchievement(STRING* id);
	void revealAchievement(GHAchievementListener* listener, STRING* id); 	// update listener

	// normal achievement update
	void completeAchievement(STRING* id);
	void completeAchievement(GHAchievementListener* listener, STRING* id); 	// update listener

	// incremental achievement update
	void increaseAchievement(STRING* id);
	void increaseAchievement(GHAchievementListener* listener, STRING* id); 	// update listener


private:
	virtual void OnTransactionReadyToRead(Tizen::Web::Json::IJsonValue* data);
	Tizen::Base::Collection::HashMap* __pMap;
	GHAchievementListener* currentListener;
};

#endif /* GHACHIEVEMENTCONTROLLER_H_ */

