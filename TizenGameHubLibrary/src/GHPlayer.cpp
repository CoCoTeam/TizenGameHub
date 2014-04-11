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
}


GHPlayer::GHPlayer(Tizen::Base::String _id, Tizen::Base::String _email, Tizen::Base::String _name, Tizen::Base::String _imgUrl)
: id(_id), email(_email), name(_name), imgUrl(_imgUrl)
{
	totalScore = this->getTotalScore();
}

GHPlayer::GHPlayer(Tizen::Base::String _id, Tizen::Base::String _name, Tizen::Base::String _imgUrl)
: id(_id), name(_name), imgUrl(_imgUrl)
{
	GHPlayer(_id, "", _name, _imgUrl);

	totalScore = this->getTotalScore();
}

Tizen::Base::String GHPlayer::getId()		{	AppLogDebug("[DEBUG] getid : %S", id.GetPointer() );  return id;}
Tizen::Base::String GHPlayer::getEmail()	{	return email;}
Tizen::Base::String GHPlayer::getName()		{	return name;}
Tizen::Base::String GHPlayer::getImgUrl()	{	return imgUrl;}
long GHPlayer::getTotalScore()
{
	//!! return Achievement.getTotalAchievementScore(id);
	return 123456;
}

