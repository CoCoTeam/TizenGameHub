/*
 * GHAttackhelperDataSendedListener.h
 *
 *  Created on: Apr 8, 2014
 *      Author: KICHUL
 */

#ifndef GHATTACKHELPERDATASENDEDLISTENER_H_
#define GHATTACKHELPERDATASENDEDLISTENER_H_

#include "GHAttackhelperListener.h"

class GHAttackhelperDataSendedListener
	: public virtual GHAttackhelperListener {
public:
	GHAttackhelperDataSendedListener();
	virtual ~GHAttackhelperDataSendedListener();

	virtual void sendAttackhelperDataFinished(int statusCode) = 0;

};

#endif /* GHATTACKHELPERDATASENDEDLISTENER_H_ */
