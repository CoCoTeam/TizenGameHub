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
}

GHGame::GHGame(Tizen::Base::String _id, Tizen::Base::String _developerId, Tizen::Base::String _title, Tizen::Base::String _description, Tizen::Base::String _imgUrl,
	int _leaderboardCount, int _achievementCount, int _attackhelperCount, bool _cloudsaveEnablility, bool _turnbasedMultiEnablility)
: id(_id), developerId(_developerId), title(_title), description(_description), imgUrl(_imgUrl)
, leaderboardCount(_leaderboardCount), achievementCount(_achievementCount), attackhelperCount(_attackhelperCount)
, misCloudsaveEnable(_cloudsaveEnablility), misTurnbasedMultiEnable(_turnbasedMultiEnablility)
{}

Tizen::Base::String GHGame::getId()				{	return id;}
Tizen::Base::String GHGame::getDeveloperId()	{	return developerId;}
Tizen::Base::String GHGame::getTitle()			{	return title;}
Tizen::Base::String GHGame::getDescription()	{	return description;}
Tizen::Base::String GHGame::getImgUrl()			{	return imgUrl;}
int GHGame::getLeaderboardCount()		{	return leaderboardCount;}
int GHGame::getAcheievementCount()		{	return achievementCount;}
int GHGame::getAttackHelperCount()		{	return attackhelperCount;}
bool GHGame::isCloudsaveEnable()		{	return misCloudsaveEnable;}
bool GHGame::isTurnbasedMultiEnable()	{	return misTurnbasedMultiEnable;}


bool GHGame::isPlaying()			{return misPlaying;}
void GHGame::setIsPlaying(bool b)	{misPlaying = b;}
