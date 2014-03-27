/*
 * GHPlayer.cpp
 *
 *  Created on: Mar 11, 2014
 *      Author: Administrator
 */

#include "GHPlayer.h"

GHPlayer::GHPlayer() {
	// TODO Auto-generated constructor stub

}

GHPlayer::~GHPlayer() {
	// TODO Auto-generated destructor stub
	delete email;
	delete name;
	delete imgUrl;
}


GHPlayer::GHPlayer(STRING _id, STRING _email, STRING _name, STRING _imgUrl)
{
	id = new Tizen::Base::String(_id);
	email = new Tizen::Base::String(_email);
	name = new Tizen::Base::String(_name);
	imgUrl = new Tizen::Base::String(_imgUrl);

	totalScore = this->getTotalScore();
}

STRING* GHPlayer::getId()		{	return id;}
STRING* GHPlayer::getEmail()	{	return email;}
STRING* GHPlayer::getName()		{	return name;}
STRING* GHPlayer::getImgUrl()	{	return imgUrl;}
long GHPlayer::getTotalScore()
{
	//!! return Achievement.getTotalAchievementScore(id);
	return 123456;
}

