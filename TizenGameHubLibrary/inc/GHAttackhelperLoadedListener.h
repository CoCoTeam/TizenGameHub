/*
 * GHAttackhelperLoadedListener.h
 *
 *  Created on: Apr 8, 2014
 *      Author: KICHUL
 */

#ifndef GHATTACKHELPERLOADEDLISTENER_H_
#define GHATTACKHELPERLOADEDLISTENER_H_

#include "GHAttackhelper.h"
#include "GHAttackhelperListener.h"

class GHAttackhelperLoadedListener
	: GHAttackhelperListener{
public:
	GHAttackhelperLoadedListener();
	virtual ~GHAttackhelperLoadedListener();

	virtual void loadAttackhelperFinished(Tizen::Base::Collection::ArrayList* achievementList) = 0;
private:
	virtual void loadAttackhelperDataFinished(Tizen::Base::Collection::ArrayList* achievementList){};
	virtual void sendAttackhelperDataFinished(int statusCode){};
	virtual void respondAttackhelperDataFinished(int statusCode){};
};

#endif /* GHATTACKHELPERLOADEDLISTENER_H_ */
