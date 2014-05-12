/*
 * AttackHelperProvider.h
 *
 *  Created on: May 12, 2014
 *      Author: Administrator
 */

#ifndef ATTACKHELPERPROVIDER_H_
#define ATTACKHELPERPROVIDER_H_

#include "GHTizen.h"
#include "GHAttackhelperData.h"

class AttackHelperProvider
	: public Tizen::Ui::Controls::IListViewItemProvider
{
public:
	AttackHelperProvider();
	virtual ~AttackHelperProvider();

	int GetItemCount(void);
	Tizen::Ui::Controls::ListItemBase* CreateItem(int index, int itemWidth);
	bool DeleteItem(int index, Tizen::Ui::Controls::ListItemBase* pItem, int itemWidth);

	void addItemList(Tizen::Base::Collection::ArrayList* _list);

private:
	Tizen::Base::Collection::ArrayList list;
};

#endif /* ATTACKHELPERPROVIDER_H_ */
