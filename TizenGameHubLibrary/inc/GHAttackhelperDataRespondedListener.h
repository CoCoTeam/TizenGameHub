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

	virtual void respondAttackhelperDataFinished(int statusCode) = 0;

};

#endif /* GHATTACKHELPERDATARESPONDEDLISTENER_H_ */
