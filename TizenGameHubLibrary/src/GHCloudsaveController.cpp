/*
 * GHCloudsaveController.cpp
 *
 *  Created on: Apr 9, 2014
 *      Author: KICHUL
 */

#include "GHCloudsaveController.h"

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
	String game_id("key_aa");
	String player_id("pkeykichul");
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
	String game_id("key_aa");
	String player_id("pkeykichul");
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

		// 정상적으로 결과를 반환했을 때
		// data:{value:""}
		if(statusCode == "1") {
			JsonObject* pJsonOject 	= static_cast<JsonObject*>(data);

			// KEY NAME
			String* pkeyValue		= new String(L"value");
			slotdata = getStringByKey(pJsonOject, pkeyValue);

			delete pkeyValue;
		}else {
			slotdata = null;
		}

		if(this->currentListener != null) this->currentListener->loadCloudsaveFinished(slotdata);
	}
}
