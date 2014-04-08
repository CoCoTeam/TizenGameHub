/*
 * GHAttackhelperDataLoadedListener.h
 *
 *  Created on: Apr 8, 2014
 *      Author: KICHUL
 */

#ifndef GHATTACKHELPERDATALOADEDLISTENER_H_
#define GHATTACKHELPERDATALOADEDLISTENER_H_

#include "GHAttackhelperListener.h"

class GHAttackhelperDataLoadedListener
	: GHAttackhelperListener{
public:
	GHAttackhelperDataLoadedListener();
	virtual ~GHAttackhelperDataLoadedListener();

	virtual void loadAttackhelperDataFinished(Tizen::Base::Collection::ArrayList* achievementList) = 0;
private:
	virtual void loadAttackhelperFinished(Tizen::Base::Collection::ArrayList* achievementList){};
	virtual void sendAttackhelperDataFinished(int statusCode){};
	virtual void respondAttackhelperDataFinished(int statusCode){};
};

#endif /* GHATTACKHELPERDATALOADEDLISTENER_H_ */
