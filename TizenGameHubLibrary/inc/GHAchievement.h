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
	Tizen::Base::String	id;			// achievement 고유키
	Tizen::Base::String title;		// achievement 제목
	Tizen::Base::String description;// achievement 설명
	Tizen::Base::String imgUrl;		// achievement 대표 이미지
	int 	prize;		// 완료에 따른 보상 (point)

	int 	isHidden;	// hidden 속성 ( 0: hidden, 1: revealed(default))
	int 	isComplete; // 업적 완료 여부

	int 	goalPoint;	// 목표 점수
	int		curPoint;	// 현재 점수

	//----------------------------------------------------------------
	// GET Function
	int 	getId();
	Tizen::Base::String getTitle();
	Tizen::Base::String getDescription();
	Tizen::Base::String getImgUrl();

	int 	getIsHidden();
	int 	getIsComplete();
	int 	getType();

	int 	getGoalPoint();
	int 	getCurPoint();
	int 	getPrize();

	//----------------------------------------------------------------

};

#endif /* GHACHIEVEMENT_H_ */
