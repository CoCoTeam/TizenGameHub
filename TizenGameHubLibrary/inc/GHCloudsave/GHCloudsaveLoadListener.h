/*
 * GHCloudsaveLoadListener.h
 *
 *  Created on: Apr 9, 2014
 *      Author: KICHUL
 */

#ifndef GHCLOUDSAVELOADLISTENER_H_
#define GHCLOUDSAVELOADLISTENER_H_

#include "GHCloudsaveListener.h"

class GHCloudsaveLoadListener
	: public virtual GHCloudsaveListener {
public:
	GHCloudsaveLoadListener();
	virtual ~GHCloudsaveLoadListener();

	virtual void loadCloudsaveFinished(Tizen::Base::String data) = 0;
};

#endif /* GHCLOUDSAVELOADLISTENER_H_ */
