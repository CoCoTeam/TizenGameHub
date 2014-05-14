/*
 * GHAttackhelperData.h
 *
 *  Created on: Apr 3, 2014
 *      Author: KICHUL
 */

#ifndef GHATTACKHELPERDATA_H_
#define GHATTACKHELPERDATA_H_


#include "GHTizen.h"


class GHAttackhelperData
: public Tizen::Base::Object {
private:
	int dataIndex;					// attack helper data 식별 index

	Tizen::Base::String	senderId;	// 보낸사람 id
	Tizen::Base::String	senderName;	// 보낸사람 이름
	Tizen::Base::String	id;			// attack helper 고유키
	Tizen::Base::String itemName;	// attack helper item 이름
	int denyEnable;					// attack helper 거절가능여부
	int quantity;

public:
	GHAttackhelperData();
	virtual ~GHAttackhelperData();
	GHAttackhelperData(int _dataIndex, Tizen::Base::String _senderId, Tizen::Base::String _senderName, Tizen::Base::String _id, Tizen::Base::String _itemName, int _denyEnable, int _quantity);


	// GET FUNCTION
	int getDataIndex();
	Tizen::Base::String getSenderId();
	Tizen::Base::String getSenderName();
	Tizen::Base::String getId();
	Tizen::Base::String getItemName();
	int getDenyEnable();
	int getQuantity();


};

#endif /* GHATTACKHELPERDATA_H_ */
