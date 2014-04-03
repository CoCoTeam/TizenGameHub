/*
 * GHPlayerController.cpp
 *
 *  Created on: Apr 2, 2014
 *      Author: Administrator
 */

#include "GHPlayerController.h"

using namespace Tizen::Base;

GHPlayerController::GHPlayerController() {
	// TODO Auto-generated constructor stub

}

GHPlayerController::~GHPlayerController() {
	// TODO Auto-generated destructor stub
}

// 사용자 로그인
/*
 * Method : 사용자 로그인
 * Type : POST
 * url : /players/login
 * data : email, pwd
 * return : status code ( 0: 실패, key: 성공) // {statusCode : 0}
 */
void GHPlayerController::playerLogin(Tizen::Base::String email, Tizen::Base::String pwd)
{

}
//String playerLogin(Tizen::Base::String email, Tizen::Base::String pwd, GHPlayerListener* listener);

// 사용자 정보 가져오기
/*
 * Method : 사용자 정보 가져오기
 * Type : GET
 * url : /players/{player_id}
 * data : player_id /
 * return : { statusCode : 1, data:{ email:"", name:"", img_url:"" } }
 */
void GHPlayerController::getPlayerData(Tizen::Base::String playerId)
{

}
//GHPlayer getPlayerData(Tizen::Base::String playerId, GHPlayerListener* listener);

// 사용자 로그아웃


// 특정 게임에 사용자 등록하기(게임가입)
/*
 * Method : 특정 게임에 사용자 등록 (게임가입)
 * Type : POST
 * url : /players/gamejoin
 * data : player_id, game_id
 * return : status code ( 0: 실패, 1: 성공) // {statusCode : 0}
 */


void GHPlayerController::OnTransactionReadyToRead(Tizen::Base::String apiCode, Tizen::Base::String statusCode, Tizen::Web::Json::IJsonValue* data)
{

}
