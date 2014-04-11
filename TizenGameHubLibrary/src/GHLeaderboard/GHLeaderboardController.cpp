/*
 * GHLeaderboardController.cpp
 *
 *  Created on: Mar 28, 2014
 *      Author: Administrator
 */

#include "GHLeaderboard/GHLeaderboardController.h"


using namespace Tizen::Base::Collection;
using namespace Tizen::Web::Json;
using namespace Tizen::Net::Http;
using namespace Tizen::Base;

GHLeaderboardController::GHLeaderboardController() {
	// TODO Auto-generated constructor stub

}

GHLeaderboardController::~GHLeaderboardController() {
	// TODO Auto-generated destructor stub
}

void GHLeaderboardController::loadLeaderboards(GHLeaderboardDataLoadedListener * listener)
{
	this->currentListener = listener;

	//GET 함수 호출
	String game_id("key_aa");
	String url(L"/f_leaderboards/" + game_id);
	httpPost.RequestHttpGetTran(this, url);
}

// leaderboard의 랭킹 목록을 가져온다.
void GHLeaderboardController::loadLeaderboardRank(Tizen::Base::String leaderboardId)
{

	//GET 함수 호출
	String game_id("key_aa");
	String lb_id("key_aa_0");
	String external = "?order=true&start_pos=0&max_length=10";
	String url(L"/f_leaderboards/rank/" + game_id +"/"+ lb_id);

	httpPost.RequestHttpGetTran(this, url);

}
void GHLeaderboardController::loadLeaderboardRank(Tizen::Base::String leaderboardId, GHLeaderboardListLoadedListener * listener)
{
	this->currentListener = listener;
	loadLeaderboardRank(leaderboardId);
}


// 해당 leaderboard에 점수를 업데이트한다.
void GHLeaderboardController::updateLeaderboardScore(Tizen::Base::String GameId, Tizen::Base::String leaderboardId, long score)
{

	String* game_id = new String(GameId);
	String* lb_id = new String(leaderboardId);
	Long* pScore = new Long(score);
	String* player_id = new String("pkeykichul");

	__pMap = new (std::nothrow) Tizen::Base::Collection::HashMap();
	__pMap->Construct();
	__pMap->Add(new String("game_id"), game_id);
	__pMap->Add(new String("lb_id"), lb_id);
	__pMap->Add(new String("score"), pScore);
	__pMap->Add(new String("player_id"), player_id);


	//Put 함수 호출
	String url(L"/f_leaderboards/update");
	httpPost.RequestHttpPutTran(this, url, __pMap);
}
void GHLeaderboardController::updateLeaderboardScore(Tizen::Base::String GameId, Tizen::Base::String leaderboardId, long score, GHLeaderboardScoreUpdatedListener * listener)
{
	this->currentListener = listener;
	updateLeaderboardScore(GameId, leaderboardId, score);
}



// HTTP 통신 Listener -------------------------------------------------------------------------------------------------------
void GHLeaderboardController::OnTransactionReadyToRead(String apiCode, String statusCode, IJsonValue* data){
	//전달받은 데이터(부모 리스너에서 다시 보내주는 데이터)

		AppLogDebug("[DEBUG] apiCode : %S", apiCode.GetPointer() );
		AppLogDebug("[DEBUG] statusCode : %S", statusCode.GetPointer());

		//{apiCode:21, statusCode:1, data:[{lb_id, title, img_url}, {}...]}
		if(apiCode.Equals(LEADERBOARD_LEADERBOARDS)) {	// PLAYER_PLAYERDATA
				GHLeaderboard *leaderboard;
				ArrayList* leArr;

				// 정상적으로 결과를 반환했을 때
				if(statusCode == "1") {

					JsonArray* 	pJsonArray 	= static_cast<JsonArray*>(data);
					int 		arrNum 		= pJsonArray->GetCount();
					leArr = new ArrayList();

					String* pkeyLb_id 		= new String(L"lb_id");
					String* pkeyTitle 		= new String(L"title");
					String* pkeyImgUrl 		= new String(L"img_url");

					// KEY NAME
					for(int i=0; i<arrNum; i++) {
							JsonObject *pJsonOject 	= getJsonObjectByIndex(pJsonArray, i);

							String  sLb_id			= getStringByKey(pJsonOject, pkeyLb_id);
							String  sTitle			= getStringByKey(pJsonOject, pkeyTitle);
							String  sImgUrl 		= getStringByKey(pJsonOject, pkeyImgUrl);

							// 리스트에 추가
							//leaderboard = new GHLeaderboard(sLb_id, sTitle, sImgUrl);
							//leArr->Add((Object*)leaderboard);
							leArr->Add(new GHLeaderboard(sLb_id, sTitle, sImgUrl));

							AppLogDebug("[DEBUG] id : %S", sLb_id.GetPointer() );
					}

					delete pkeyLb_id;		delete pkeyTitle;	 delete pkeyImgUrl;
				}
				else
				{ // 에러가 발생했을 때
					leaderboard = null;
				}

				if(this->currentListener != null) this->currentListener->loadLeaderboardFinished(leArr);
		}

		// object 형안에  array형이 있을때
		//{apiCode:22, statusCode:1, data: {lb_id, unit, lb_order, is_time, values:[{p_id, p_name, p_url, rank, score}, {}...]}

		else if(apiCode.Equals(LEADERBOARD_RANK)){
			GHLeaderboard *leaderboard;
			ArrayList* leRankArr;
			ArrayList* leArr;

			// 정상적으로 결과를 반환했을 때
			if(statusCode == "1") {

				JsonObject *pJsonOject 	= static_cast<JsonObject*>(data);
				leRankArr = new ArrayList();
				leArr = new ArrayList();

				String* pkeylb_Id 		= new String(L"lb_id");
				String* pkeyUnit		= new String(L"unit");
				String* pkeylb_order	= new String(L"lb_order");
				String* pkeyIs_time 	= new String(L"is_time");
				String* pKeyValues 		= new String(L"values");

				String slb_Id 		= getStringByKey(pJsonOject, pkeylb_Id);
				String sUnit		= getStringByKey(pJsonOject, pkeyUnit);
				int ilb_order 		= getIntByKey(pJsonOject, pkeylb_order);
				int iIs_time		= getIntByKey(pJsonOject, pkeyIs_time);
				JsonArray* pJsonArray = getJsonArrayByKey(pJsonOject, pKeyValues);

				int 		arrNum 		= pJsonArray->GetCount();
				AppLogDebug("[DEBUG] arrNum : %d", arrNum );

				for(int i=0; i<arrNum; i++) {

						JsonObject *pArrayJsonOject 	= getJsonObjectByIndex(pJsonArray, i);

						String* pkeyP_id	= new String(L"p_id");
						String* pkeyP_name	= new String(L"p_name");
						String* pkeyP_url 	= new String(L"p_imgurl");
						String* pkeyRank	= new String(L"rank");
						String* pkeyScore 	= new String(L"score");

						String sP_id		= getStringByKey(pArrayJsonOject, pkeyP_id);
						String sP_name		= getStringByKey(pArrayJsonOject, pkeyP_name);
						String sP_url 		= getStringByKey(pArrayJsonOject, pkeyP_url);
						int iRank			= getIntByKey(pArrayJsonOject, pkeyRank);
						int iScore			= getIntByKey(pArrayJsonOject, pkeyScore);

						// 리스트에 추가
						//acArr->Add(new GHPlayerRank(sP_id, sP_name, sP_url, iRank, iScore));
						GHPlayerRank* PlayerRank = new GHPlayerRank(sP_id, sP_name, sP_url, iRank, iScore);
						leRankArr->Add((Object*)PlayerRank);

						delete pkeyP_id;	delete pkeyP_name;		delete pkeyP_url; 	delete pkeyRank;	delete pkeyScore;
						delete PlayerRank;
				}

				//lb_id, unit, lb_order, is_time
				//leaderboard = new GHLeaderboard(slb_Id, "", "", sUnit, ilb_order, iIs_time, leArr);
				leaderboard = new GHLeaderboard(slb_Id, sUnit, ilb_order, iIs_time, leRankArr);
				leArr->Add(leaderboard);

				// KEY NAME DELETE
				delete pkeylb_Id; 			delete pkeyUnit;		delete pkeylb_order;	 delete pkeyIs_time;		delete pKeyValues;
			}
			else { // 에러가 발생했을 때
				leaderboard = null;
			}
			if(this->currentListener != null) this->currentListener->loadLeaderboardRankFinished(leArr);//leaderboard, leArr);
		}
		else if(apiCode.Equals(LEADERBOARD_SCORE))
		{
			int stateCode;
			Integer::Parse(statusCode, stateCode);

			if(this->currentListener != null) this->currentListener->updateLeaderboardScoreFinished(stateCode);
		}
}
