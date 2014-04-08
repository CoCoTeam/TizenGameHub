/*
 * GHAttackhelperData.cpp
 *
 *  Created on: Apr 3, 2014
 *      Author: KICHUL
 */

#include "GHAttackhelperData.h"

GHAttackhelperData::GHAttackhelperData() {
	// TODO Auto-generated constructor stub

}

GHAttackhelperData::~GHAttackhelperData() {
	// TODO Auto-generated destructor stub
}


GHAttackhelperData::GHAttackhelperData(int _dataIndex, Tizen::Base::String _senderId, Tizen::Base::String _id, Tizen::Base::String _itemName, int _denyEnable, int _quantity)
{
	this->dataIndex 	= _dataIndex;
	this->senderId		= _senderId;
	this->id 			= _id;
	this->itemName		= _itemName;
	this->denyEnable	= _denyEnable;
	this->quantity		= _quantity;

}



