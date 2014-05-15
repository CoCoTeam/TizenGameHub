/*
 * GHPlayerProvider.h
 *
 *  Created on: Mar 13, 2014
 *      Author: Administrator
 */

#ifndef APPGHPLAYERPROVIDER_H_
#define APPGHPLAYERPROVIDER_H_

#include "GHPlayer/GHPlayer.h"

class AppGHPlayerProvider
: public Tizen::Ui::Controls::IListViewItemProvider
{
public:
	AppGHPlayerProvider();
	virtual ~AppGHPlayerProvider();

	int GetItemCount(void);
	Tizen::Ui::Controls::ListItemBase* CreateItem(int index, int itemWidth);
	bool DeleteItem(int index, Tizen::Ui::Controls::ListItemBase* pItem, int itemWidth);
	void setItemList(Tizen::Base::Collection::ArrayList* _list);

private:
	Tizen::Base::Collection::ArrayList list;
};

#endif /* APPGHPLAYERPROVIDER_H_ */
