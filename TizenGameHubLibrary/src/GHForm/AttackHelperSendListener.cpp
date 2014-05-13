/*
 * AttackHelperSendReceiver.cpp
 *
 *  Created on: May 13, 2014
 *      Author: Administrator
 */

#include "GHForm/AttackHelperSendListener.h"

AttackHelperSendListener::AttackHelperSendListener() {
	// TODO Auto-generated constructor stub

}

AttackHelperSendListener::~AttackHelperSendListener() {
	// TODO Auto-generated destructor stub
}


void AttackHelperSendListener::OnListViewContextItemStateChanged
(Tizen::Ui::Controls::ListView &listView, int index, int elementId, Tizen::Ui::Controls::ListContextItemStatus state)
{
}
void AttackHelperSendListener::OnListViewItemSwept
(Tizen::Ui::Controls::ListView &listView, int index, Tizen::Ui::Controls::SweepDirection direction)
{
}
void AttackHelperSendListener::OnListViewItemStateChanged
(Tizen::Ui::Controls::ListView &listView, int index, int elementId, Tizen::Ui::Controls::ListItemStatus status)
{
	if (status == Tizen::Ui::Controls::LIST_ITEM_STATUS_SELECTED) {
		if(index >= list.GetCount()) {
			return ;
		}
		AppLogDebug("DDDDDDDDDDDDDDDDD");
//		listView.SetItemEnabled(index, false);
//
//
//		GHAttackhelperData* ahData = (GHAttackhelperData*)(list.GetAt(index));
//		AppLogDebug("%d, %S", ahData->getDataIndex(), ahData->getItemName().GetPointer());
//
//		ahId = ahData->getId();
	}
}

void AttackHelperSendListener::setItemList(Tizen::Base::Collection::ArrayList* _list)
{
	for(int i=0 ; i<_list->GetCount() ; i++)
	{
		list.Add( (Tizen::Base::Object*)(_list->GetAt(i)) );
	}
}
