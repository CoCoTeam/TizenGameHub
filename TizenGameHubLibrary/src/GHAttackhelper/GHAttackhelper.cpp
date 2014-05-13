/*
 * GHAttackhelper.cpp
 *
 *  Created on: Apr 3, 2014
 *      Author: KICHUL
 */

#include "GHAttackhelper.h"

using namespace Tizen::Base;

GHAttackhelper::GHAttackhelper() {
	// TODO Auto-generated constructor stub

}

GHAttackhelper::~GHAttackhelper() {
	// TODO Auto-generated destructor stub
}

GHAttackhelper::GHAttackhelper(Tizen::Base::String _id, Tizen::Base::String _itemName, int _denyEnable)
{
	this->id 			= _id;
	this->itemName		= _itemName;
	this->denyEnable	= _denyEnable;

}

// GET Function ------------------------------------------------
String GHAttackhelper::getId()
{
	return this->id;
}
String GHAttackhelper::getItemName()
{
	return this->itemName;
}
int	GHAttackhelper::getDenyEnable()
{
	return this->denyEnable;
}

