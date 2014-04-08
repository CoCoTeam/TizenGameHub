/*
 * GHAttackhelperListener.h
 *
 *  Created on: Apr 8, 2014
 *      Author: KICHUL
 */

#ifndef GHATTACKHELPERLISTENER_H_
#define GHATTACKHELPERLISTENER_H_

#include "GHAttackhelper.h"

class GHAttackhelperListener {
public:
	GHAttackhelperListener();
	virtual ~GHAttackhelperListener();

	virtual void doAttackhelperFinished(int statusCode) = 0;
	virtual void doAttackhelperFinished(Tizen::Base::Collection::ArrayList* attackhelperList) = 0;
};

#endif /* GHATTACKHELPERLISTENER_H_ */
