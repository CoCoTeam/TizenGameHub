/*
 * GHAttackhelperUpdatedListener.h
 *
 *  Created on: Apr 8, 2014
 *      Author: KICHUL
 */

#ifndef GHATTACKHELPERUPDATEDLISTENER_H_
#define GHATTACKHELPERUPDATEDLISTENER_H_

#include "GHAttackhelper.h"
#include "GHAttackhelperListener.h"

class GHAttackhelperUpdatedListener
	: GHAttackhelperListener{
public:
	GHAttackhelperUpdatedListener();
	virtual ~GHAttackhelperUpdatedListener();
	virtual void doAttackhelperFinished(int statusCode) = 0;

private:
	void doAttackhelperFinished(Tizen::Base::Collection::ArrayList* achievementList);
};

#endif /* GHATTACKHELPERUPDATEDLISTENER_H_ */
