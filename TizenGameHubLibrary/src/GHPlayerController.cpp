/*
 * GHPlayerController.cpp
 *
 *  Created on: Apr 2, 2014
 *      Author: Administrator
 */

#include "GHPlayerController.h"

using namespace Tizen::Base;
using namespace Tizen::Base::Collection;
using namespace Tizen::Net::Http;
using namespace Tizen::Web::Json;

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
	String url(L"/players/login");

	Tizen::Base::Collection::HashMap* __pMap = new (std::nothrow) Tizen::Base::Collection::HashMap();
	__pMap->Construct();
	__pMap->Add(new String("email"), new String(email));
	__pMap->Add(new String("pwd"), new String(pwd));

	//post 함수 호출
	httpPost.RequestHttpPostTran(this, url, __pMap);
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
	AppLogDebug("[DEBUG] apiCode : %S", apiCode.GetPointer() );
	//AppLogDebug("[DEBUG] statusCode : %S", statusCode.GetPointer());

	if(apiCode.Equals(PLAYER_PLAYERDATA)) {	// ACHIEVEMENT LOAD
			//GHAchievement *acArr;
			GHPlayer *playerArr;

			// 정상적으로 결과를 반환했을 때
			if(statusCode == "1") {
				JsonArray* 	pJsonArray 	= static_cast<JsonArray*>(data);
				int 		arrNum 		= pJsonArray->GetCount();
				playerArr = new GHPlayer[arrNum];

				// KEY NAME
				String* pkeyId 			= new String(L"ac_id");
				String* pkeyEmail 		= new String(L"email");
				String* pkeyName 		= new String(L"name");
				String* pkeyImgUrl 		= new String(L"img_url");

				//AppLogDebug("[DEBUG] arrNum : %d", arrNum );

				for(int i=0; i<arrNum; i++) {
					JsonObject *pJsonOject 	= getJsonObjectByIndex(pJsonArray, i);

					// 데이터 파싱
					String  sId 			= getStringByKey(pJsonOject, pkeyId);  // playerID 필요할듯!!
					String  sEmail 			= getStringByKey(pJsonOject, pkeyEmail);
					String  sName			= getStringByKey(pJsonOject, pkeyName);
					String  sImgUrl 		= getStringByKey(pJsonOject, pkeyImgUrl);
					// 배열에 추가
					playerArr[i] = GHPlayer(sId, sEmail, sName, sImgUrl);

				}
				// KEY NAME DELETE
				delete pkeyId; 			delete pkeyEmail;		delete pkeyName;	 delete pkeyImgUrl;
			}
			else { // 에러가 발생했을 때
				playerArr = null;
			}

			if(this->currentListener != null) this->currentListener->doPlayerFinished(playerArr);
	}
/*	else if(apiCode.Equals(PLAYER_LOGIN))
	{
		AppLogDebug("[DEBUG] statusCode : %S", statusCode.GetPointer());

		if(this->currentListener != null) this->currentListener->doAchievementFinished(statusCode);
	}
	else if(apiCode.Equals(PLAYER_GAMEJOIN))*/
	else //PLAYER_LOGIN ,PLAYER_GAMEJOIN
	{
		//int stateCode;
		//Integer::Parse(statusCode, stateCode);
		if(this->currentListener != null) this->currentListener->doPlayerFinished(statusCode);
	}
}
