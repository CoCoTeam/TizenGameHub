/*
 * GHCloudsaveController.h
 *
 *  Created on: Apr 9, 2014
 *      Author: KICHUL
 */

#ifndef GHCLOUDSAVECONTROLLER_H_
#define GHCLOUDSAVECONTROLLER_H_

#include "GHTizen.h"
#include "GHController.h"
#include "GHhttpClient.h"
#include "GHCloudsaveListener.h"

#include "GHCloudsaveLoadListener.h"
#include "GHCloudsaveSaveListener.h"

const Tizen::Base::String CLOUDSAVE_SAVE	= "51";
const Tizen::Base::String CLOUDSAVE_LOAD 	= "52";

class GHCloudsaveController
	: public GHController{
public:
	GHCloudsaveController();
	virtual ~GHCloudsaveController();

	void saveCloudSlotData(Tizen::Base::String data, int slot_idx);
	void saveCloudSlotData(Tizen::Base::String data, int slot_idx, GHCloudsaveSaveListener* listner);
	void loadCloudSlotData(int slot_idx, GHCloudsaveLoadListener* listener);

private:
	virtual void OnTransactionReadyToRead(Tizen::Base::String apiCode, Tizen::Base::String statusCode, Tizen::Web::Json::IJsonValue* data);
	Tizen::Base::Collection::HashMap* __pMap;
	GHCloudsaveListener* currentListener;
};

#endif /* GHCLOUDSAVECONTROLLER_H_ */
