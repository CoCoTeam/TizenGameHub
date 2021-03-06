/*
 * GHAttackhelperListener.h
 *
 *  Created on: Apr 8, 2014
 *      Author: KICHUL
 */

#ifndef GHATTACKHELPERLISTENER_H_
#define GHATTACKHELPERLISTENER_H_

#include "GHTizen.h"
#include "GHAttackhelperData.h"

class GHAttackhelperListener {
public:
	GHAttackhelperListener();
	virtual ~GHAttackhelperListener();

	virtual void loadAttackhelperFinished(Tizen::Base::Collection::ArrayList* achievementList){};
	virtual void loadAttackhelperDataFinished(Tizen::Base::Collection::ArrayList* achievementList){};
	virtual void sendAttackhelperDataFinished(int statusCode){};
	virtual void respondAttackhelperDataFinished(GHAttackhelperData* attackhelperData, int accpet_flag){};
};

#endif /* GHATTACKHELPERLISTENER_H_ */
