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
	: public virtual GHAttackhelperListener{
public:
	GHAttackhelperLoadedListener();
	virtual ~GHAttackhelperLoadedListener();

	virtual void loadAttackhelperFinished(Tizen::Base::Collection::ArrayList* achievementList) = 0;

};

#endif /* GHATTACKHELPERLOADEDLISTENER_H_ */
