/*
 * GHAttackhelperController.h
 *
 *  Created on: Apr 7, 2014
 *      Author: KICHUL
 */

#ifndef GHATTACKHELPERCONTROLLER_H_
#define GHATTACKHELPERCONTROLLER_H_

#include "GHTizen.h"
#include "GHController.h"
#include "GHAttackhelper.h"
#include "GHAttackhelperListener.h"
#include "GHAttackhelperLoadedListener.h"
#include "GHAttackhelperDataLoadedListener.h"
#include "GHAttackhelperDataSendedListener.h"
#include "GHAttackhelperDataRespondedListener.h"
#include "GHhttpClient.h"

class GHAttackhelperController
	: public GHController{
public:
	GHAttackhelperController();
	virtual ~GHAttackhelperController();

private:
	virtual void OnTransactionReadyToRead(Tizen::Base::String apiCode, Tizen::Base::String statusCode, Tizen::Web::Json::IJsonValue* data);
	Tizen::Base::Collection::HashMap* __pMap;

	// attack helper 목록을 가져온다.
	void loadAttackhelpers(GHAttackhelperLoadedListener * listener);							// load listener

	// attack helper data 목록을 가져온다.
	void loadAttackhelperDatas(GHAttackhelperDataLoadedListener* listener); 	// update listener

	// normal achievement update
	void sendAttackhelperData(Tizen::Base::String receiver_id, Tizen::Base::String ah_id, int quantity);
	void sendAttackhelperData(Tizen::Base::String receiver_id, Tizen::Base::String ah_id, int quantity, GHAttackhelperDataSendedListener* listener); 	// update listener

	// incremental achievement update
	void respondAttackhelperData(int data_idx);
	void respondAttackhelperData(int data_idx, GHAttackhelperDataRespondedListener* listener); 	// update listener
};

#endif /* GHATTACKHELPERCONTROLLER_H_ */
