/*
 * GHPlayerApp.h
 *
 *  Created on: May 13, 2014
 *      Author: Administrator
 */

#ifndef APPGHPLAYER_H_
#define APPGHPLAYER_H_

#include <GHPlayer/GHPlayer.h>

class AppGHPlayer
	: public GHPlayer
{
public:
	AppGHPlayer();
	virtual ~AppGHPlayer();

	bool isFriend() {return misFriend;}
	void setIsFriend(bool b) {misFriend = b;}
	long getTotalScore() {return 123456;}

private:
	bool misFriend;
	long totalScore;	// 사용자별 Achievement 총합 점수
};

#endif /* APPGHPLAYER_H_ */
