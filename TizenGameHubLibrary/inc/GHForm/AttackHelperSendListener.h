/*
 * AttackHelperSendReceiver.h
 *
 *  Created on: May 13, 2014
 *      Author: Administrator
 */

#ifndef ATTACKHELPERSENDRECEIVER_H_
#define ATTACKHELPERSENDLISTENER_H_

#include <GHTizen.h>
#include "GHAttackhelper/GHAttackhelperDataSendedListener.h"

class AttackHelperSendListener
	: public Tizen::Ui::Controls::IListViewItemEventListener
{
public:
	AttackHelperSendListener();
	AttackHelperSendListener(GHAttackhelperDataSendedListener* sendListener, int ah_id, int quantity);
	virtual ~AttackHelperSendListener();

	void OnListViewContextItemStateChanged(Tizen::Ui::Controls::ListView &listView, int index, int elementId, Tizen::Ui::Controls::ListContextItemStatus state);
	void OnListViewItemStateChanged(Tizen::Ui::Controls::ListView &listView, int index, int elementId, Tizen::Ui::Controls::ListItemStatus status);
	void OnListViewItemSwept(Tizen::Ui::Controls::ListView &listView, int index, Tizen::Ui::Controls::SweepDirection direction);

	void setItemList(Tizen::Base::Collection::ArrayList* _list);

private:
	Tizen::Base::Collection::ArrayList list;
	int ah_id;
	int quantity;
	GHAttackhelperDataSendedListener* sendListener;
};

#endif /* ATTACKHELPERSENDRECEIVER_H_ */
