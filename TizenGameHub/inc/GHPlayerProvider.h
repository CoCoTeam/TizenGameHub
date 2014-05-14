/*
 * GHPlayerProvider.h
 *
 *  Created on: Mar 13, 2014
 *      Author: Administrator
 */

#ifndef GHPLAYERPROVIDER_H_
#define GHPLAYERPROVIDER_H_

#include "GHPlayer.h"

class PlayerProvider
: public Tizen::Ui::Controls::IListViewItemProvider
{
public:
	PlayerProvider();
	virtual ~PlayerProvider();

	int GetItemCount(void);
	Tizen::Ui::Controls::ListItemBase* CreateItem(int index, int itemWidth);
	bool DeleteItem(int index, Tizen::Ui::Controls::ListItemBase* pItem, int itemWidth);
	void setItemList(Tizen::Base::Collection::ArrayList* _list);

private:
	Tizen::Base::Collection::ArrayList list;
};

#endif /* GHPLAYERPROVIDER_H_ */
