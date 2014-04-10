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
	: public virtual GHAttackhelperListener{
public:
	GHAttackhelperDataLoadedListener();
	virtual ~GHAttackhelperDataLoadedListener();

	virtual void loadAttackhelperDataFinished(Tizen::Base::Collection::ArrayList* achievementList) = 0;

};

#endif /* GHATTACKHELPERDATALOADEDLISTENER_H_ */
