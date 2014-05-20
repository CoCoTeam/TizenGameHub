/*
 * GHLeaderboard.cpp
 *
 *  Created on: Mar 24, 2014
 *      Author: Administrator
 */

#include "GHLeaderboard/GHLeaderboard.h"

using namespace Tizen::Base;

GHLeaderboard::GHLeaderboard() {
	// TODO Auto-generated constructor stub

}

GHLeaderboard::GHLeaderboard(Tizen::Base::String _id, Tizen::Base::String _unit, bool _isAscendingOrder, bool _isTimeFormat, Tizen::Base::Collection::ArrayList* _learderboardRankList)
	:id(_id), unit(_unit), isAscendingOrder(_isAscendingOrder), isTimeFormat(_isTimeFormat)
{
	learderboardRankList = _learderboardRankList;
}
GHLeaderboard::GHLeaderboard(String _id, String _title, String _imgUrl, String _unit, bool _isAscendingOrder, bool _isTimeFormat)
	:id(_id), title(_title), imgUrl(_imgUrl), unit(_unit), isAscendingOrder(_isAscendingOrder), isTimeFormat(_isTimeFormat)
{
}
GHLeaderboard::GHLeaderboard(String _id, String _title, String _imgUrl)
	:id(_id), title(_title), imgUrl(_imgUrl)
{
	GHLeaderboard(_id, _title, _imgUrl, "", 0, 0 );

}

GHLeaderboard::~GHLeaderboard() {
	// TODO Auto-generated destructor stub
}
Tizen::Base::Collection::ArrayList* GHLeaderboard::getRankList() 	{ return learderboardRankList;}

Tizen::Base::String GHLeaderboard::getId()			{return id;}
Tizen::Base::String GHLeaderboard::getTitle()		{return title;}
Tizen::Base::String GHLeaderboard::getImgUrl()		{return imgUrl;}
Tizen::Base::String GHLeaderboard::getUnit()		{return unit;}
bool GHLeaderboard::getIsAscendingOrder()	{return isAscendingOrder;}
bool GHLeaderboard::getIsTimeFormat()		{return isTimeFormat;}
