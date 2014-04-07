/*
 * GHAttackhelper.h
 *
 *  Created on: Apr 3, 2014
 *      Author: KICHUL
 */

#ifndef GHATTACKHELPER_H_
#define GHATTACKHELPER_H_

<<<<<<< HEAD
#include <GHTizen.h>
=======
#include "GHTizen.h"
>>>>>>> 568974fb17e3bc540255dc31e7c15699dff0afb1

class GHAttackhelper {
private:
	Tizen::Base::String	id;			// attack helper 고유키
	Tizen::Base::String itemName;	// attack helper item 이름
	int denyEnable;					// attack helper 거절가능여부

public:
	GHAttackhelper();
	virtual ~GHAttackhelper();

	// GET Function ------------------------------------------------
	Tizen::Base::String getId();
	Tizen::Base::String getItemName();
	int					getDenyEnable();
	//----------------------------------------------------------------
};

#endif /* GHATTACKHELPER_H_ */
