/*
 * AppGHAchievementController.h
 *
 *  Created on: May 9, 2014
 *      Author: Administrator
 */

#ifndef APPGHACHIEVEMENTCONTROLLER_H_
#define APPGHACHIEVEMENTCONTROLLER_H_

#include <GHAchievement/GHAchievementController.h>

class AppGHAchievementController
	: public GHAchievementController
{
public:
	AppGHAchievementController();
	virtual ~AppGHAchievementController();

	void loadAchievements(GHAchievementLoadedListener* listener, Tizen::Base::String game_Id, Tizen::Base::String player_Id);
};

#endif /* APPGHACHIEVEMENTCONTROLLER_H_ */
