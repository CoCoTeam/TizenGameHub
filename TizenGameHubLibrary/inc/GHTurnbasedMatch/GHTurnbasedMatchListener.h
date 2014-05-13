/*
 * GHTurnbasedMatchListener.h
 *
 *  Created on: Apr 17, 2014
 *      Author: KICHUL
 */

#ifndef GHTURNBASEDMATCHLISTENER_H_
#define GHTURNBASEDMATCHLISTENER_H_

#include "GHTizen.h"

class GHTurnbasedMatchListener {
public:
	GHTurnbasedMatchListener();
	virtual ~GHTurnbasedMatchListener();

	virtual void onMatchConnect()  = 0;
	virtual void onMatchSetting() = 0;
	virtual void onMatchStart(Tizen::Base::String data)    = 0;
	virtual void onMatchMyturn(Tizen::Base::String data)   = 0;
	virtual void onMatchTurnWait() = 0;
	virtual void onMatchFinish(Tizen::Base::String data)   = 0;
};

#endif /* GHTURNBASEDMATCHLISTENER_H_ */
