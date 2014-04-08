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
	: GHAttackhelperListener {
public:
	GHAttackhelperDataSendedListener();
	virtual ~GHAttackhelperDataSendedListener();

	virtual void sendAttackhelperDataFinished(int statusCode) = 0;
private:
	virtual void loadAttackhelperFinished(Tizen::Base::Collection::ArrayList* achievementList){};
	virtual void loadAttackhelperDataFinished(Tizen::Base::Collection::ArrayList* achievementList){};
	virtual void respondAttackhelperDataFinished(int statusCode){};
};

#endif /* GHATTACKHELPERDATASENDEDLISTENER_H_ */
