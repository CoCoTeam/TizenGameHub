/*
 * GHLeaderboardController.cpp
 *
 *  Created on: Mar 28, 2014
 *      Author: Administrator
 */

#include "GHSharedAuthData.h"
#include "GHForm/LeaderboardForm.h"
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

// LeaderboardForm(Page)을 로드한다.
void GHLeaderboardController::loadLeaderboardForm()
{
	Tizen::Ui::Controls::Frame *pFrame = Tizen::App::UiApp::GetInstance()->GetAppFrame()->GetFrame();
	LeaderboardForm* pForm = new (std::nothrow) LeaderboardForm();
	pForm->Initialize();

	// Add the form to the frame
	pFrame->AddControl(pForm);
	pFrame->SetCurrentForm(pForm);
	pForm->Invalidate(true);
}

// Leaderboard 목록을 가져온다.
void GHLeaderboardController::loadLeaderboards(GHLeaderboardDataLoadedListener * listener)
{
	this->currentListener = listener;

	//GET 함수 호출
	String game_id(GHSharedAuthData::getSharedInstance().getGameId());
	String url(L"/f_leaderboards/" + game_id);
	httpPost.RequestHttpGetTran(this, url);
}

// 각 Leaderboard에 해당하는 랭킹 목록을 가져온다.
void GHLeaderboardController::loadLeaderboardRank(Tizen::Base::String leaderboardId, int startPosition, int loadSize)
{
	this->currentListener = null;

	//GET 함수 호출
	String game_id(GHSharedAuthData::getSharedInstance().getGameId());
	Tizen::Base::String sOffset, sSize;
	sOffset.Append(startPosition);
	sSize.Append(loadSize);
	String external = "?order=true&start_pos="+sOffset+"&max_length="+sSize;
	String url(L"/f_leaderboards/rank/" + game_id +"/"+ leaderboardId );//+ external);

	httpPost.RequestHttpGetTran(this, url);
}
void GHLeaderboardController::loadLeaderboardRank(Tizen::Base::String leaderboardId, GHLeaderboardListLoadedListener * listener, int startPosition, int loadSize)
{
	this->loadLeaderboardRank(leaderboardId, startPosition, loadSize);
	this->currentListener = listener;
}

// 해당 Leaderboard에 점수를 업데이트한다.
void GHLeaderboardController::updateLeaderboardScore(Tizen::Base::String leaderboardId, long score)
{
	this->currentListener = null;

	String* game_id = new String(GHSharedAuthData::getSharedInstance().getGameId());
	String* lb_id = new String(leaderboardId);
	Long* pScore = new Long(score);
	String* player_id = new String(GHSharedAuthData::getSharedInstance().getPlayerId());

	//Put 함수 호출
	String url(L"/f_leaderboards/update");
	__pMap = new (std::nothrow) Tizen::Base::Collection::HashMap();
	__pMap->Construct();
	__pMap->Add(new String("game_id"), game_id);
	__pMap->Add(new String("lb_id"), lb_id);
	__pMap->Add(new String("score"), pScore);
	__pMap->Add(new String("player_id"), player_id);

	httpPost.RequestHttpPutTran(this, url, __pMap);
}
void GHLeaderboardController::updateLeaderboardScore(Tizen::Base::String leaderboardId, long score, GHLeaderboardScoreUpdatedListener * listener)
{
	this->updateLeaderboardScore(leaderboardId, score);
	this->currentListener = listener;
}

// HTTP 통신 Listener -------------------------------------------------------------------------------------------------------
void GHLeaderboardController::OnTransactionReadyToRead(String apiCode, String statusCode, IJsonValue* data){
	//전달받은 데이터(부모 리스너에서 다시 보내주는 데이터)

		AppLogDebug("[DEBUG] apiCode : %S", apiCode.GetPointer() );
		AppLogDebug("[DEBUG] statusCode : %S", statusCode.GetPointer());

		//AppLogDebug("================ [DEBUG] ====================");

		//{apiCode:21, statusCode:1, data:[{lb_id, title, img_url}, {}...]}
		if(apiCode.Equals(LEADERBOARD_LEADERBOARDS)) {	// LEADERBOARD_LEADERBOARDS
				//GHLeaderboard *leaderboard;
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
							leArr->Add(new GHLeaderboard(sLb_id, sTitle, sImgUrl));

					}

					delete pkeyLb_id;		delete pkeyTitle;	 delete pkeyImgUrl;
				}
				else
				{ // 에러가 발생했을 때
					leArr = null;
				}

				if(this->currentListener != null) this->currentListener->loadLeaderboardFinished(leArr);
		}

		// object 형안에  array형이 있을때
		//{apiCode:22, statusCode:1, data: {lb_id, unit, lb_order, is_time, values:[{p_id, p_name, p_url, rank, score}, {p_id, p_name, p_url, rank, score}...]}
		else if(apiCode.Equals(LEADERBOARD_RANK)){
			GHLeaderboard *leaderboard;
			ArrayList* leRankArr;

			// 정상적으로 결과를 반환했을 때
			if(statusCode == "1") {

				JsonObject *pJsonOject 	= static_cast<JsonObject*>(data);
				leRankArr = new ArrayList();

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
//				AppLogDebug("[DEBUG] arrNum : %d", arrNum );

				String* pkeyP_id	= new String(L"p_id");
				String* pkeyP_name	= new String(L"p_name");
				String* pkeyP_url 	= new String(L"p_imgurl");
				String* pkeyRank	= new String(L"rank");
				String* pkeyScore 	= new String(L"score");

				for(int i=0; i<arrNum; i++) {

						JsonObject *pArrayJsonOject 	= getJsonObjectByIndex(pJsonArray, i);

						String sP_id		= getStringByKey(pArrayJsonOject, pkeyP_id);
						String sP_name		= getStringByKey(pArrayJsonOject, pkeyP_name);
						String sP_url 		= getStringByKey(pArrayJsonOject, pkeyP_url);
						int iRank			= getIntByKey(pArrayJsonOject, pkeyRank);
						int iScore			= getIntByKey(pArrayJsonOject, pkeyScore);

						// 리스트에 추가
						GHPlayerRank* PlayerRank = new GHPlayerRank(sP_id, sP_name, sP_url, iRank, iScore);

						PlayerRank->setId(sP_id);
						PlayerRank->setName(sP_name);
						PlayerRank->setImgUrl(sP_url);
						PlayerRank->setRank(iRank);
						PlayerRank->setScore(iScore);

						leRankArr->Add(PlayerRank);

						//delete PlayerRank;
				}
				//lb_id, unit, lb_order, is_time
				leaderboard = new GHLeaderboard(slb_Id, sUnit, ilb_order, iIs_time, leRankArr);

				// KEY NAME DELETE
				delete pkeyP_id;	delete pkeyP_name;		delete pkeyP_url; 	delete pkeyRank;	delete pkeyScore;
				delete pkeylb_Id; 			delete pkeyUnit;		delete pkeylb_order;	 delete pkeyIs_time;		delete pKeyValues;
			}
			else { // 에러가 발생했을 때
				leRankArr = null;
				leaderboard = null;
			}

			if(this->currentListener != null) this->currentListener->loadLeaderboardRankFinished(leaderboard);

		}
		else if(apiCode.Equals(LEADERBOARD_SCORE))
		{
			int stateCode;
			Integer::Parse(statusCode, stateCode);

			//AppLogDebug("[DEBUG] : %d", stateCode);

			if(this->currentListener != null) this->currentListener->updateLeaderboardScoreFinished(stateCode);

		}
}
