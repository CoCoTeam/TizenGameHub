/*
 * GHAttackhelperData.cpp
 *
 *  Created on: Apr 3, 2014
 *      Author: KICHUL
 */

#include "GHAttackhelperData.h"

using namespace Tizen::Base;
GHAttackhelperData::GHAttackhelperData() {
	// TODO Auto-generated constructor stub

}

GHAttackhelperData::~GHAttackhelperData() {
	// TODO Auto-generated destructor stub
}


GHAttackhelperData::GHAttackhelperData(int _dataIndex, Tizen::Base::String _senderId, Tizen::Base::String _senderName, Tizen::Base::String _id, Tizen::Base::String _itemName, int _denyEnable, int _quantity)
{
	this->dataIndex 	= _dataIndex;
	this->senderId		= _senderId;
	this->senderName	= _senderName;
	this->id 			= _id;
	this->itemName		= _itemName;
	this->denyEnable	= _denyEnable;
	this->quantity		= _quantity;

}



int GHAttackhelperData::getDataIndex()
{
	return this->dataIndex;
}
String GHAttackhelperData::getSenderId()
{
	return this->senderId;
}
String GHAttackhelperData::getSenderName()
{
	return this->senderName;
}
String GHAttackhelperData::getId()
{
	return this->id;
}
String GHAttackhelperData::getItemName()
{
	return this->itemName;
}
int GHAttackhelperData::getDenyEnable()
{
	return this->denyEnable;
}
int GHAttackhelperData::getQuantity()
{
	return this->quantity;
}
