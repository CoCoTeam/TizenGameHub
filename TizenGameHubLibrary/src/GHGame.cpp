/*
 * GHGame.cpp
 *
 *  Created on: Mar 11, 2014
 *      Author: Administrator
 */

#include "GHGame.h"

GHGame::GHGame() {
	// TODO Auto-generated constructor stub

}

GHGame::~GHGame() {
	// TODO Auto-generated destructor stub
	delete title;
	delete description;
	delete imgUrl;
}

GHGame::GHGame(STRING _id, long _developerId, STRING _title, STRING _description, STRING _imgUrl,
	int _leaderboardCount, int _achievementCount, int _attackhelperCount, bool _cloudsaveEnablility, bool _turnbasedMultiEnablility)
: developerId(_developerId), leaderboardCount(_leaderboardCount), achievementCount(_achievementCount), attackhelperCount(_attackhelperCount)
, misCloudsaveEnable(_cloudsaveEnablility), misTurnbasedMultiEnable(_turnbasedMultiEnablility)
{
	id = new Tizen::Base::String(_id);
	title = new Tizen::Base::String(_title);
	description = new Tizen::Base::String(_description);
	imgUrl = new Tizen::Base::String(_imgUrl);
}

STRING* GHGame::getId()					{	return id;}
long GHGame::getDeveloperId()			{	return developerId;}
STRING* GHGame::getTitle()				{	return title;}
STRING* GHGame::getDescription()		{	return description;}
STRING* GHGame::getImgUrl()				{	return imgUrl;}
int GHGame::getLeaderboardCount()		{	return leaderboardCount;}
int GHGame::getAcheievementCount()		{	return achievementCount;}
int GHGame::getAttackHelperCount()		{	return attackhelperCount;}
bool GHGame::isCloudsaveEnable()		{	return misCloudsaveEnable;}
bool GHGame::isTurnbasedMultiEnable()	{	return misTurnbasedMultiEnable;}
