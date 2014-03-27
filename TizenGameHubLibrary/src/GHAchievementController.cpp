/*
 * GHAchievementController.cpp
 *
 *  Created on: Mar 26, 2014
 *      Author: JOHEEYEON
 */

#include "GHAchievementController.h"

//game id: key_aa
//player id: pkeykichul

GHAchievementController::GHAchievementController() {
	// TODO Auto-generated constructor stub

}

GHAchievementController::~GHAchievementController() {
	// TODO Auto-generated destructor stub
}

// Achievement 목록을 가져온다.
void loadAchievements(GHAchievementsLoadedListener* listener) {

	//통신끝난 후 호출하면서 데이터를 전달해야 한다. // 개발자는 GHAchievementLoadedListener를 상속받아서 아래 함수를 구현해놔야 한다.
	GHAchievement* array = new GHAchievement[3];
	listener->loadAchievementsFinished(array);
}

// hidden -> reveal 상태로 바꾼다.
void revealAchievement(STRING* id) {

}
void revealAchievement(GHAchievementsUpdatedListener* listener, STRING* id) {
	listener->updateAchievementsFinished();
}

// normal achievement update
void completeAchievement(STRING* id) {

}
void completeAchievement(GHAchievementsUpdatedListener* listener, STRING* id) {
	listener->updateAchievementsFinished();
}

// incremental achievement update
void increaseAchievement(STRING* id) {

}
void increaseAchievement(GHAchievementsUpdatedListener* listener, STRING* id) {
	listener->updateAchievementsFinished();
}
