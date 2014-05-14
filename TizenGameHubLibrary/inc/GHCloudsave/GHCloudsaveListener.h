/*
 * GHCloudsaveListener.h
 *
 *  Created on: Apr 9, 2014
 *      Author: KICHUL
 */

#ifndef GHCLOUDSAVELISTENER_H_
#define GHCLOUDSAVELISTENER_H_

#include "GHTizen.h"

class GHCloudsaveListener {
public:
	GHCloudsaveListener();
	virtual ~GHCloudsaveListener();

	virtual void saveCloudsaveFinished(int statusCode){};
	virtual void loadCloudsaveFinished(int slotIdx, Tizen::Base::String data){};
};

#endif /* GHCLOUDSAVELISTENER_H_ */
