/*
 * GHAchievementController.h
 *
 *  Created on: Mar 26, 2014
 *      Author: JOHEEYEON
 */

#ifndef GHACHIEVEMENTCONTROLLER_H_
#define GHACHIEVEMENTCONTROLLER_H_

class GHAchievementController {
public:
	GHAchievementController();
	virtual ~GHAchievementController();

	// achievement 목록을 가져온다.
	void loadAchievements(GHAchievementsLoadedListener * listener);

	// hidden -> reveal 상태로 바꾼다.
	void revealAchievement(STRING* id);
	void revealAchievement(GHAchievementsUpdatedListener* listener, STRING* id);

	// normal achievement update
	void completeAchievement(STRING* id);
	void completeAchievement(GHAchievementsUpdatedListener* listner, STRING* id);

	// incremental achievement update
	void increaseAchievement(STRING* id);
	void increaseAchievement(GHAchievementsUpdatedListener* listner, STRING* id);
};

// Interface Class (Listener)
class GHAchievementsLoadedListener {
};


// Interface Class (Listener)
class GHAchievementsUpdatedListener {
};


#endif /* GHACHIEVEMENTCONTROLLER_H_ */
