/*
 * GHAttackhelperDataRespondedListener.h
 *
 *  Created on: Apr 8, 2014
 *      Author: KICHUL
 */

#ifndef GHATTACKHELPERDATARESPONDEDLISTENER_H_
#define GHATTACKHELPERDATARESPONDEDLISTENER_H_

#include "GHAttackhelperListener.h"

class GHAttackhelperDataRespondedListener
	: public virtual GHAttackhelperListener{
public:
	GHAttackhelperDataRespondedListener();
	virtual ~GHAttackhelperDataRespondedListener();

	virtual void respondAttackhelperDataFinished(GHAttackhelperData* attackhelperData, int accpet_flag) = 0;

};

#endif /* GHATTACKHELPERDATARESPONDEDLISTENER_H_ */
