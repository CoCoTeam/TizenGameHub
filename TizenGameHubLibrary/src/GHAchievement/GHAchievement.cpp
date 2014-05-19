/*
 * GHAchievement.cpp
 *
 *  Created on: Mar 24, 2014
 *      Author: Administrator
 */

#include "GHAchievement/GHAchievement.h"

using namespace Tizen::Base;

GHAchievement::GHAchievement() {
	// TODO Auto-generated constructor stub

}

GHAchievement::GHAchievement(String _id, String _title, String _description, String _imgUrl, int _prize, int _isHidden, int _isComplete, int _goalPoint, int _curPoint)
{

	this->id 			= _id;
	this->title 		= _title;
	this->description 	= _description;
	this->imgUrl 		= _imgUrl;
	this->prize 		= _prize;
	this->isHidden 		= _isHidden;
	this->isComplete 	= _isComplete;
	this->goalPoint 	= _goalPoint;
	this->curPoint 		= _curPoint;

}



GHAchievement::~GHAchievement() {
	// TODO Auto-generated destructor stub
}

//// GET FUNCTION
String 	GHAchievement::getId()			{ return this->id; }
String 	GHAchievement::getTitle()		{ return this->title; }
String 	GHAchievement::getDescription()	{ return this->description; }
String 	GHAchievement::getImgUrl()		{ return this->imgUrl; }

int 	GHAchievement::getIsHidden()	{ return this->isHidden; }
int 	GHAchievement::getIsComplete()	{ return this->isComplete; }
int 	GHAchievement::getGoalPoint()	{ return this->goalPoint; }
int 	GHAchievement::getCurPoint()	{ return this->curPoint; }
int 	GHAchievement::getPrize()		{ return this->prize; }

Tizen::Base::String GHAchievement::ToString()
{
	Tizen::Base::String ret(id +"/"+ title +"/"+ description +"/"+ imgUrl +"/"+
			Integer::ToString(prize) +"/"+ Integer::ToString(isHidden) +"/"+ Integer::ToString(isComplete) +"/"+ Integer::ToString(goalPoint) +"/"+ Integer::ToString(curPoint));
	return ret;
}
