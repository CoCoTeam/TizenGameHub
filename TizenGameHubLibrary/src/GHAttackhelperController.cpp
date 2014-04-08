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

GHAttackhelperController::GHAttackhelperController() {
	// TODO Auto-generated constructor stub

}

GHAttackhelperController::~GHAttackhelperController() {
	// TODO Auto-generated destructor stub
}

// 모든 통신의 콜백에서 호출하는 함수
void GHAttackhelperController::OnTransactionReadyToRead(String apiCode, String statusCode, IJsonValue* data){

}

// attack helper 목록을 가져온다.
void GHAttackhelperController::loadAttackhelpers(GHAttackhelperLoadedListener * listener){

}

// attack helper data 목록을 가져온다.
void GHAttackhelperController::loadAttackhelperDatas(GHAttackhelperDataLoadedListener* listener){

}

// normal achievement update
void GHAttackhelperController::sendAttackhelperData(Tizen::Base::String receiver_id, Tizen::Base::String ah_id, int quantity){

}
void GHAttackhelperController::sendAttackhelperData(Tizen::Base::String receiver_id, Tizen::Base::String ah_id, int quantity, GHAttackhelperDataSendedListener* listener){

}

// incremental achievement update
void GHAttackhelperController::respondAttackhelperData(int data_idx){

}
void GHAttackhelperController::respondAttackhelperData(int data_idx, GHAttackhelperDataRespondedListener* listener){

}
