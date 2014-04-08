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
	: GHAttackhelperListener{
public:
	GHAttackhelperDataRespondedListener();
	virtual ~GHAttackhelperDataRespondedListener();

	virtual void respondAttackhelperDataFinished(int statusCode) = 0;
private:
	virtual void loadAttackhelperFinished(Tizen::Base::Collection::ArrayList* achievementList){};
	virtual void loadAttackhelperDataFinished(Tizen::Base::Collection::ArrayList* achievementList){};
	virtual void sendAttackhelperDataFinished(int statusCode){};
};

#endif /* GHATTACKHELPERDATARESPONDEDLISTENER_H_ */
