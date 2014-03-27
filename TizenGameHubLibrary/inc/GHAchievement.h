/*
 * GHAchievement.h
 *
 *  Created on: Mar 24, 2014
 *      Author: Administrator
 */

#ifndef GHACHIEVEMENT_H_
#define GHACHIEVEMENT_H_

#include <GHTizen.h>

class GHAchievement {
public:
	GHAchievement();
	virtual ~GHAchievement();

	//----------------------------------------------------------------
	// variable
	int 	id;			// achievement 고유키
	STRING* title;		// achievement 제목
	STRING* description;// achievement 설명
	STRING* imgUrl;		// achievement 대표 이미지
	int 	type;		// 종류 (0 : normal, 1 : incremental)
	int 	prize;		// 완료에 따른 보상 (point)

	int 	isHidden;	// hidden 속성 ( 0: hidden, 1: revealed(default))
	int 	isComplete; // 업적 완료 여부

	int 	goalPoint;	// 목표 점수
	int		curPoint;	// 현재 점수 (type:incremental)

	//----------------------------------------------------------------
	// GET Function
	int 	getId();
	STRING* getTitle();
	STRING* getDescription();
	STRING* getImgUrl();

	int 	getIsHidden();
	int 	getIsComplete();
	int 	getType();

	int 	getGoalPoint();
	int 	getCurPoint();
	int 	getPrize();

	//----------------------------------------------------------------




};

#endif /* GHACHIEVEMENT_H_ */
