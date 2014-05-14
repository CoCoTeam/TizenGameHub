/*
 * AttackHelperSendReceiver.cpp
 *
 *  Created on: May 13, 2014
 *      Author: Administrator
 */

#include "GHForm/AttackHelperSendListener.h"
#include "GHAttackhelper/GHAttackhelperController.h"

AttackHelperSendListener::AttackHelperSendListener() {
	// TODO Auto-generated constructor stub

}
AttackHelperSendListener::AttackHelperSendListener(GHAttackhelperDataSendedListener* sendListener, int ah_id, int quantity) {
	this->sendListener = sendListener;
	this->ah_id = ah_id;
	this->quantity = quantity;
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
		Tizen::Base::String receiver_id( ((GHPlayer*)(list.GetAt(index)))->getId() );

		GHAttackhelperController *ahController = new GHAttackhelperController();
		ahController->sendAttackhelperData(receiver_id, ah_id, quantity, sendListener);
	}
}

void AttackHelperSendListener::setItemList(Tizen::Base::Collection::ArrayList* _list)
{
	for(int i=0 ; i<_list->GetCount() ; i++)
	{
		list.Add( (Tizen::Base::Object*)(_list->GetAt(i)) );
	}
}
