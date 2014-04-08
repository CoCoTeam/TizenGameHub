/*
 * GHAttackhelper.cpp
 *
 *  Created on: Apr 3, 2014
 *      Author: KICHUL
 */

#include "GHAttackhelper.h"

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


