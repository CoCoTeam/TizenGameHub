/*
 * GHCloudsaveController.cpp
 *
 *  Created on: Apr 9, 2014
 *      Author: KICHUL
 */

#include "GHCloudsave/GHCloudsaveController.h"
#include "GHSharedAuthData.h"

using namespace Tizen::Web::Json;
using namespace Tizen::Net::Http;
using namespace Tizen::Base;
using namespace Tizen::Base::Collection;

GHCloudsaveController::GHCloudsaveController() {
	// TODO Auto-generated constructor stub
}

GHCloudsaveController::~GHCloudsaveController() {
	// TODO Auto-generated destructor stub
}

void GHCloudsaveController::saveCloudSlotData(Tizen::Base::String data, int slot_idx){
	//GET 함수 호출
	String game_id(GHSharedAuthData::getSharedInstance().getGameId());
	String player_id(GHSharedAuthData::getSharedInstance().getPlayerId());
	String url(L"/f_cloudsave/" + game_id + "/" + player_id);
	__pMap = new (std::nothrow) Tizen::Base::Collection::HashMap();
	__pMap->Construct();
	__pMap->Add(new String("slot_idx"), new String(Integer::ToString(slot_idx)));
	__pMap->Add(new String("slot_data"), new String(data));
	httpPost.RequestHttpPostTran(this, url, __pMap);
}

void GHCloudsaveController::saveCloudSlotData(Tizen::Base::String data, int slot_idx, GHCloudsaveSaveListener* listener){
	this->currentListener = listener;
	this->saveCloudSlotData(data, slot_idx);
}

void GHCloudsaveController::loadCloudSlotData(int slot_idx, GHCloudsaveLoadListener* listener){
	this->currentListener = listener;
	//GET 함수 호출
	String game_id(GHSharedAuthData::getSharedInstance().getGameId());
	String player_id(GHSharedAuthData::getSharedInstance().getPlayerId());
	String slot_index(Integer::ToString(slot_idx));
	String url(L"/f_cloudsave/" + game_id + "/" + player_id + "/" + slot_index);
	httpPost.RequestHttpGetTran(this, url);
}

void GHCloudsaveController::OnTransactionReadyToRead(Tizen::Base::String apiCode, Tizen::Base::String statusCode, Tizen::Web::Json::IJsonValue* data) {
	AppLogDebug("[DEBUG] apiCode : %S", apiCode.GetPointer() );
	AppLogDebug("[DEBUG] statusCode : %S", statusCode.GetPointer() );

	if(apiCode.Equals(CLOUDSAVE_SAVE)) {

		int stateCode;
		Integer::Parse(statusCode, stateCode);

		if(this->currentListener != null) this->currentListener->saveCloudsaveFinished(stateCode);


	} else if(apiCode.Equals(CLOUDSAVE_LOAD)) {
		String slotdata = null;
		int slotidx;

		// 정상적으로 결과를 반환했을 때
		// data:{value:""}
		if(statusCode == "1") {
			JsonObject* pJsonOject 	= static_cast<JsonObject*>(data);

			// KEY NAME
			String* pkeyValue		= new String(L"value");
			String* pkeyIdx		= new String(L"slot_idx");

			slotdata = getStringByKey(pJsonOject, pkeyValue);
			slotidx	= getIntByKey(pJsonOject, pkeyIdx);

			delete pkeyValue;
			delete pkeyIdx;
		}else {
			slotdata = null;
			slotidx = -1;
		}

		if(this->currentListener != null) this->currentListener->loadCloudsaveFinished(slotidx, slotdata);
	}
}
