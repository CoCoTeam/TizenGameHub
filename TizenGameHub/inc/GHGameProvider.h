/*
 * GHGameProvider.h
 *
 *  Created on: Mar 13, 2014
 *      Author: Administrator
 */

#ifndef GHGAMEPROVIDER_H_
#define GHGAMEPROVIDER_H_

#include <FUi.h>
#include <FSystem.h>
#include <FUix.h>
#include <FMedia.h>
#include <FGraphics.h>
#include "GHGame.h"

class GHGameProvider
: public Tizen::Ui::Controls::IListViewItemProvider
{
public:
	GHGameProvider();
	virtual ~GHGameProvider();

	//IListViewItemProvider
	virtual Tizen::Ui::Controls::ListItemBase* CreateItem(int index, int itemWidth);
	virtual bool DeleteItem(int index, Tizen::Ui::Controls::ListItemBase* pItem, int itemWidth);
	virtual int GetItemCount(void);

	void setItemList(Tizen::Base::Collection::ArrayList* _list);

private:
	Tizen::Base::Collection::ArrayList list;
};

#endif /* GHGAMEPROVIDER_H_ */
