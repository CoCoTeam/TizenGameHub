/*
 * GHAttackhelper.h
 *
 *  Created on: Apr 3, 2014
 *      Author: KICHUL
 */

#ifndef GHATTACKHELPER_H_
#define GHATTACKHELPER_H_

#include "GHTizen.h"

class GHAttackhelper
: public Tizen::Base::Object {
private:
	Tizen::Base::String	id;			// attack helper 고유키
	Tizen::Base::String itemName;	// attack helper item 이름
	int denyEnable;					// attack helper 거절가능여부

public:
	GHAttackhelper();
	GHAttackhelper(Tizen::Base::String _id, Tizen::Base::String _itemName, int _denyEnable);

	virtual ~GHAttackhelper();

	// GET Function ------------------------------------------------
	Tizen::Base::String getId();
	Tizen::Base::String getItemName();
	int					getDenyEnable();
	//----------------------------------------------------------------
};

#endif /* GHATTACKHELPER_H_ */
