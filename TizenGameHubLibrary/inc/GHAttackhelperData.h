/*
 * GHAttackhelperData.h
 *
 *  Created on: Apr 3, 2014
 *      Author: KICHUL
 */

#ifndef GHATTACKHELPERDATA_H_
#define GHATTACKHELPERDATA_H_

<<<<<<< HEAD
#include <GHTizen.h>
=======
#include "GHTizen.h"
>>>>>>> 568974fb17e3bc540255dc31e7c15699dff0afb1

class GHAttackhelperData {
private:
	int dataIndex;					// attack helper data 식별 index

	Tizen::Base::String	senderId;	// 보낸사람 id (나중에 친구 객체로 있어야 할듯!)

	Tizen::Base::String	id;			// attack helper 고유키
	Tizen::Base::String itemName;	// attack helper item 이름
	int denyEnable;					// attack helper 거절가능여부
	int quantity;

public:
	GHAttackhelperData();
	virtual ~GHAttackhelperData();
};

#endif /* GHATTACKHELPERDATA_H_ */
