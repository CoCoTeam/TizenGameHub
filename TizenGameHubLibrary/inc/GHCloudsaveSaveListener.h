/*
 * GHCloudsaveSaveListener.h
 *
 *  Created on: Apr 9, 2014
 *      Author: KICHUL
 */

#ifndef GHCLOUDSAVESAVELISTENER_H_
#define GHCLOUDSAVESAVELISTENER_H_

#include "GHCloudsaveListener.h"

class GHCloudsaveSaveListener
	: public virtual GHCloudsaveListener {
public:
	GHCloudsaveSaveListener();
	virtual ~GHCloudsaveSaveListener();

	virtual void saveCloudsaveFinished(int statusCode) = 0;
};

#endif /* GHCLOUDSAVESAVELISTENER_H_ */
