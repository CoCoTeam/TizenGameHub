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
	virtual void loadCloudsaveFinished(Tizen::Base::String achievementList){};
};

#endif /* GHCLOUDSAVELISTENER_H_ */
