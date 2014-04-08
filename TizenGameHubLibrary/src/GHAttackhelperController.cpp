/*
 * GHAttackhelperController.cpp
 *
 *  Created on: Apr 7, 2014
 *      Author: KICHUL
 */

#include "GHAttackhelperController.h"

using namespace Tizen::Web::Json;
using namespace Tizen::Net::Http;
using namespace Tizen::Base;
using namespace Tizen::Base::Collection;

GHAttackhelperController::GHAttackhelperController() {
	// TODO Auto-generated constructor stub

}

GHAttackhelperController::~GHAttackhelperController() {
	// TODO Auto-generated destructor stub
}

// attack helper 목록을 가져온다.
void GHAttackhelperController::loadAttackhelpers(GHAttackhelperLoadedListener * listener){
	this->currentListener = listener;

	//GET 함수 호출
	String game_id("key_aa");
	String player_id("pkeykichul");
	String url(L"/f_attackhelpers/" + game_id );
	httpPost.RequestHttpGetTran(this, url);
}

// attack helper data 목록을 가져온다.
void GHAttackhelperController::loadAttackhelperDatas(GHAttackhelperDataLoadedListener* listener){

	//GET 함수 호출
	String game_id("key_aa");
	String player_id("pkeykichul");
	String url(L"/f_attackhelpers/" + game_id + "/" + player_id);
	httpPost.RequestHttpGetTran(this, url);
}

// normal achievement update
void GHAttackhelperController::sendAttackhelperData(String receiver_id, String ah_id, int quantity){
	String game_id("key_aa");
	String player_id("pkeykichul");
	String url(L"/f_attackhelpers/" + game_id );
	__pMap = new (std::nothrow) Tizen::Base::Collection::HashMap();
	__pMap->Construct();
	__pMap->Add(new String("sender_id"), new String(player_id));
	__pMap->Add(new String("receiver_id"), new String(receiver_id));
	__pMap->Add(new String("ah_id"), new String(ah_id));
	__pMap->Add(new String("quantity"), new String(quantity));

	httpPost.RequestHttpPostTran(this, url, __pMap);
}
void GHAttackhelperController::sendAttackhelperData(String receiver_id, String ah_id, int quantity, GHAttackhelperDataSendedListener* listener){
	this->currentListener = listener;
	this->sendAttackhelperData(receiver_id, ah_id, quantity);
}

// incremental achievement update
void GHAttackhelperController::respondAttackhelperData(int data_idx){
	String game_id("key_aa");
	String player_id("pkeykichul");
	String url(L"/f_attackhelpers/" + game_id );
	__pMap = new (std::nothrow) Tizen::Base::Collection::HashMap();
	__pMap->Construct();
	__pMap->Add(new String("data_idx"), new String(data_idx));

	//httpPost.RequestHttpDelTran(this, url, __pMap);
}
void GHAttackhelperController::respondAttackhelperData(int data_idx, GHAttackhelperDataRespondedListener* listener){
	this->currentListener = listener;
	this->respondAttackhelperData(data_idx);
}

// 모든 통신의 콜백에서 호출하는 함수
void GHAttackhelperController::OnTransactionReadyToRead(String apiCode, String statusCode, IJsonValue* data){

	AppLogDebug("[DEBUG] apiCode : %S", apiCode.GetPointer() );
	AppLogDebug("[DEBUG] statusCode : %S", statusCode.GetPointer() );

	if(apiCode.Equals(ATTACKHELPER_LOAD)) {
		ArrayList* ahArr;

		// 정상적으로 결과를 반환했을 때
		if(statusCode == "1") {
			JsonArray* 	pJsonArray 	= static_cast<JsonArray*>(data);
			int 		arrNum 		= pJsonArray->GetCount();
			ahArr = new ArrayList();

			// KEY NAME
			String* pkeyId 			= new String(L"ah_id");
			String* pkeyItemName	= new String(L"item_name");
			String* pkeyDenyEnbale	= new String(L"deny_enable");

			for(int i=0; i<arrNum; i++) {
				JsonObject *pJsonOject 	= getJsonObjectByIndex(pJsonArray, i);

				// 데이터 파싱
				String  sId 			= getStringByKey(pJsonOject, pkeyId);
				String  sItenName		= getStringByKey(pJsonOject, pkeyItemName);
				int iDenyEnable			= getIntByKey(pJsonOject, pkeyDenyEnbale);

				// 리스트에 추가
				ahArr->Add(new GHAttackhelper(sId, sItenName, iDenyEnable));
			}

		}else {
			ahArr = null;
		}

		if(this->currentListener != null) this->currentListener->loadAttackhelperFinished(ahArr);


	} else if(apiCode.Equals(ATTACKHELPER_DATA_LOAD)) {
		ArrayList* ahdArr;

		// 정상적으로 결과를 반환했을 때
		if(statusCode == "1") {
			JsonArray* 	pJsonArray 	= static_cast<JsonArray*>(data);
			int 		arrNum 		= pJsonArray->GetCount();
			ahdArr = new ArrayList();

			// KEY NAME
			String* pkeyDataIdx		= new String(L"data_idx");
			String* pkeySenderId	= new String(L"sender_id");
			String* pkeyId 			= new String(L"ah_id");
			String* pkeyItemName	= new String(L"item_name");
			String* pkeyDenyEnbale	= new String(L"deny_enable");
			String* pkeyQuantity	= new String(L"quantity");

			for(int i=0; i<arrNum; i++) {
				JsonObject *pJsonOject 	= getJsonObjectByIndex(pJsonArray, i);

				// 데이터 파싱
				int iDataIdx			= getIntByKey(pJsonOject, pkeyDataIdx);
				String  sSenderId 		= getStringByKey(pJsonOject, pkeySenderId);
				String  sId 			= getStringByKey(pJsonOject, pkeyId);
				String  sItemName		= getStringByKey(pJsonOject, pkeyItemName);
				int iDenyEnable			= getIntByKey(pJsonOject, pkeyDenyEnbale);
				int iQuantity			= getIntByKey(pJsonOject, pkeyQuantity);

				// 리스트에 추가
				ahdArr->Add(new GHAttackhelperData(iDataIdx, sSenderId, sId, sItemName, iDenyEnable, iQuantity));

			}

		}else {
			ahdArr = null;
		}

		if(this->currentListener != null) this->currentListener->loadAttackhelperDataFinished(ahdArr);

	} else if(apiCode.Equals(ATTACKHELPER_DATA_SEND)) {
		int stateCode;
		Integer::Parse(statusCode, stateCode);

		if(this->currentListener != null) this->currentListener->sendAttackhelperDataFinished(stateCode);


	} else if(apiCode.Equals(ATTACKHELPER_DATA_RESPOND)) {
		int stateCode;
		Integer::Parse(statusCode, stateCode);

		if(this->currentListener != null) this->currentListener->respondAttackhelperDataFinished(stateCode);

	}

}
