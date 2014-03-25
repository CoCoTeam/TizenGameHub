/*
 * GHGameListItemEventListener.h
 *
 *  Created on: Mar 13, 2014
 *      Author: Administrator
 */

#ifndef GHGAMELISTITEMEVENTLISTENER_H_
#define GHGAMELISTITEMEVENTLISTENER_H_

#include <GHTizen.h>

class GHGameListItemEventListener
: public Tizen::Ui::Controls::IListViewItemEventListener
{
public:
	GHGameListItemEventListener();
	virtual ~GHGameListItemEventListener();

	void OnListViewContextItemStateChanged(Tizen::Ui::Controls::ListView &listView, int index, int elementId, Tizen::Ui::Controls::ListContextItemStatus state);
	void OnListViewItemStateChanged(Tizen::Ui::Controls::ListView &listView, int index, int elementId, Tizen::Ui::Controls::ListItemStatus status);
	void OnListViewItemSwept(Tizen::Ui::Controls::ListView &listView, int index, Tizen::Ui::Controls::SweepDirection direction);

	void setItemList(Tizen::Base::Collection::ArrayList* _list);

private:
	Tizen::Base::Collection::ArrayList list;
};

#endif /* GHGAMELISTITEMEVENTLISTENER_H_ */
