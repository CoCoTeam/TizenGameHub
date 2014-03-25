/*
 * GHLeaderboard.cpp
 *
 *  Created on: Mar 24, 2014
 *      Author: Administrator
 */

#include "GHLeaderboard.h"

GHLeaderboard::GHLeaderboard() {
	// TODO Auto-generated constructor stub

}

GHLeaderboard::~GHLeaderboard() {
	// TODO Auto-generated destructor stub
}

long GHLeaderboard::getId()				{	return id;}
//long GHLeaderboard::getGameId()		{	return gameId;}
STRING* GHLeaderboard::getTitle()		{	return title;}
STRING* GHLeaderboard::getImgUrl()		{	return imgUrl;}
STRING* GHLeaderboard::getUnit()		{	return unit;}
bool GHLeaderboard::isAscendingOrder()	{	return misAscendingOrder;}
bool GHLeaderboard::isTimeFormat()		{	return misTimeFormat;}

// 현재 리더보드의 View 호출
//(Default view)
void GHLeaderboard::getLeaderboardList(int start, int max)
{
	getLeaderboardList(id, start, max);
}
void GHLeaderboard::getLeaderboardList(long leaderboardId, int start, int max)
{
	getLeaderboardList(leaderboardId, misAscendingOrder, start, max);
}
void GHLeaderboard::getLeaderboardList(long leaderboardId, bool order, int start, int max)
{
	Tizen::Ui::Scenes::SceneManager* pSceneManager = Tizen::Ui::Scenes::SceneManager::GetInstance();
	AppAssert(pSceneManager);

	Tizen::Base::Collection::ArrayList* pList = new (std::nothrow)Tizen::Base::Collection::ArrayList;
	AppAssert(pList);
	pList->Construct();
//	pSceneManager->GoForward(Tizen::Ui::Scenes::ForwardSceneTransition("SCENE_MAIN"), pList);
}
//(for Custom view)
//Tizen::Web::Json::JsonObject*
//GHLeaderboard::getLeaderboardListData(int start, int max)
//{
//	return getLeaderboardListData(id, start, max);
//}
//Tizen::Web::Json::JsonObject*
//GHLeaderboard::getLeaderboardListData(long leaderboardId, int start, int max)
//{
//	return getLeaderboardListData(id, misAscendingOrder, start, max);
//}
//Tizen::Web::Json::JsonObject*
//GHLeaderboard::getLeaderboardListData(long leaderboardId, bool order, int start, int max)
//{
//	Tizen::Web::Json::JsonObject *jsonData = new Tizen::Web::Json::JsonObject();
//	jsonData->Construct();
//	return jsonData;
//}


// 해당 player의 랭킹 호출(API)
long GHLeaderboard::getLeaderboardRanking()
{
//	getLeaderboardRanking();
}
long GHLeaderboard::getLeaderboardRanking(long playerId)
{
	getLeaderboardRanking(playerId, id);
}
long GHLeaderboard::getLeaderboardRanking(long playerId, long leaderboardId)
{

}

// 해당 player의 점수 호출(API)
long GHLeaderboard::getLeaderboardScore()
{
//	getLeaderboardScore();
}
long GHLeaderboard::getLeaderboardScore(long playerId)
{
	getLeaderboardScore(playerId, id);
}
long GHLeaderboard::getLeaderboardScore(long playerId, long leaderboardId)
{

}

// 해당 player의 GameTotal 점수 호출(API)
long GHLeaderboard::getTotalLeaderboardGAMETotalScore()
{
//	getTotalLeaderboardGameTotalScore();
}
long GHLeaderboard::getTotalLeaderboardGameTotalScore(long playerId)
{
	getTotalLeaderboardGameTotalScore(playerId, gameId);
}
long GHLeaderboard::getTotalLeaderboardGameTotalScore(long playerId, long gameId)
{

}

// 해당 player의 총 점수 호출(API)	//!!GHPlayer로?
long GHLeaderboard::getTotalLeaderboardTotalScore()
{
//	getTotalLeaderboardTotalScore();
}
long GHLeaderboard::getTotalLeaderboardTotalScore(long playerId)
{

}
