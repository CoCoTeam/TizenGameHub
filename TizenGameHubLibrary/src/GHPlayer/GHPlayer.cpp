/*
 * GHPlayer.cpp
 *
 *  Created on: Mar 11, 2014
 *      Author: Administrator
 */

#include "GHPlayer/GHPlayer.h"

GHPlayer::GHPlayer() {
	// TODO Auto-generated constructor stub

}

GHPlayer::~GHPlayer() {
	// TODO Auto-generated destructor stub

}


GHPlayer::GHPlayer(Tizen::Base::String _id, Tizen::Base::String _email, Tizen::Base::String _name, Tizen::Base::String _imgUrl)
: id(_id), email(_email), name(_name), imgUrl(_imgUrl)
{
}

GHPlayer::GHPlayer(Tizen::Base::String _id, Tizen::Base::String _name, Tizen::Base::String _imgUrl)
: id(_id), name(_name), imgUrl(_imgUrl)
{
}

Tizen::Base::String GHPlayer::getId()		{return id;}
Tizen::Base::String GHPlayer::getEmail()	{return email;}
Tizen::Base::String GHPlayer::getName()		{return name;}
Tizen::Base::String GHPlayer::getImgUrl()	{return imgUrl;}

void GHPlayer::setId(Tizen::Base::String _id)			{this->id = _id;}
void GHPlayer::setEmail(Tizen::Base::String _email)		{this->email = _email; }
void GHPlayer::setName(Tizen::Base::String _name)		{this->name= _name; }
void GHPlayer::setImgUrl(Tizen::Base::String _imgUrl)	{this->imgUrl=_imgUrl; }

bool GHPlayer::isFriend() 			{return misFriend;}
void GHPlayer::setIsFriend(bool b) 	{misFriend = b;}
long GHPlayer::getTotalScore() 		{return 123456;}
