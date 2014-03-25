/*
 * GHPlayerListItemEventListener.h
 *
 *  Created on: Mar 13, 2014
 *      Author: Administrator
 */

#ifndef GHPLAYERLISTITEMEVENTLISTENER_H_
#define GHPLAYERLISTITEMEVENTLISTENER_H_

#include <GHTizen.h>

class GHPlayerListItemEventListener
: public Tizen::Ui::Controls::IListViewItemEventListener
{
public:
	GHPlayerListItemEventListener();
	virtual ~GHPlayerListItemEventListener();

	void OnListViewContextItemStateChanged(Tizen::Ui::Controls::ListView &listView, int index, int elementId, Tizen::Ui::Controls::ListContextItemStatus state);
	void OnListViewItemStateChanged(Tizen::Ui::Controls::ListView &listView, int index, int elementId, Tizen::Ui::Controls::ListItemStatus status);
	void OnListViewItemSwept(Tizen::Ui::Controls::ListView &listView, int index, Tizen::Ui::Controls::SweepDirection direction);

	void setItemList(Tizen::Base::Collection::ArrayList* _list);

private:
	Tizen::Base::Collection::ArrayList list;
};

#endif /* GHGAMELISTITEMEVENTLISTENER_H_ */
