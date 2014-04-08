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

	virtual void loadAttackhelperFinished(Tizen::Base::Collection::ArrayList* achievementList) = 0;
	virtual void loadAttackhelperDataFinished(Tizen::Base::Collection::ArrayList* achievementList) = 0;
	virtual void sendAttackhelperDataFinished(int statusCode) = 0;
	virtual void respondAttackhelperDataFinished(int statusCode) = 0;
};

#endif /* GHATTACKHELPERLISTENER_H_ */
