/*
 * AttackHelperReceiveListener.h
 *
 *  Created on: May 12, 2014
 *      Author: Administrator
 */

#ifndef ATTACKHELPERRECEIVELISTENER_H_
#define ATTACKHELPERRECEIVELISTENER_H_

#include <GHTizen.h>

class AttackHelperReceiveListener
	: public Tizen::Ui::Controls::IListViewItemEventListener
	, public Tizen::Ui::IActionEventListener
{
public:
	AttackHelperReceiveListener();
	virtual ~AttackHelperReceiveListener();

	void OnListViewContextItemStateChanged(Tizen::Ui::Controls::ListView &listView, int index, int elementId, Tizen::Ui::Controls::ListContextItemStatus state);
	void OnListViewItemStateChanged(Tizen::Ui::Controls::ListView &listView, int index, int elementId, Tizen::Ui::Controls::ListItemStatus status);
	void OnListViewItemSwept(Tizen::Ui::Controls::ListView &listView, int index, Tizen::Ui::Controls::SweepDirection direction);

	void setItemList(Tizen::Base::Collection::ArrayList* _list);

	//IActionEventListener
	virtual void OnActionPerformed(const Tizen::Ui::Control& source, int actionId);

private:
	Tizen::Base::Collection::ArrayList list;

	int ahId;
	Tizen::Ui::Controls::Popup *pPopup;
	static const int ACTION_POPUP_ACCEPT= 101;
	static const int ACTION_POPUP_DENY	= 102;
};

#endif /* ATTACKHELPERRECEIVELISTENER_H_ */
