/*
 * GHPlayerApp.h
 *
 *  Created on: May 13, 2014
 *      Author: Administrator
 */

#ifndef GHPLAYERAPP_H_
#define GHPLAYERAPP_H_

#include <GHPlayer/GHPlayer.h>

class GHPlayerApp
	: public GHPlayer
{
public:
	GHPlayerApp();
	virtual ~GHPlayerApp();

	bool isFriend() {return misFriend;}
	void setIsFriend(bool b) {misFriend = b;}
	long getTotalScore() {return 123456;}

private:
	bool misFriend;
	long totalScore;	// 사용자별 Achievement 총합 점수
};

#endif /* GHPLAYERAPP_H_ */
