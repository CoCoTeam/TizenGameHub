/*
 * GHAttackhelperController.h
 *
 *  Created on: Apr 7, 2014
 *      Author: KICHUL
 */

#ifndef GHATTACKHELPERCONTROLLER_H_
#define GHATTACKHELPERCONTROLLER_H_

#include <GHTizen.h>
#include <GHhttpClient.h>
#include <GHController.h>

class GHAttackhelperController
	: public GHController{
public:
	GHAttackhelperController();
	virtual ~GHAttackhelperController();

private:
	virtual void OnTransactionReadyToRead(Tizen::Base::String apiCode, Tizen::Base::String statusCode, Tizen::Web::Json::IJsonValue* data);
	Tizen::Base::Collection::HashMap* __pMap;
};

#endif /* GHATTACKHELPERCONTROLLER_H_ */
