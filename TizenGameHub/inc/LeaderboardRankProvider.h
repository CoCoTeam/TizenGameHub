/*
 * GHPlayerProvider.h
 *
 *  Created on: Mar 13, 2014
 *      Author: Administrator
 */

#ifndef LEADERBOARDRANKPROVIDER_H_
#define LEADERBOARDRANKPROVIDER_H_

#include "GHPlayerRank.h"

class LeaderboardRankProvider
: public Tizen::Ui::Controls::IListViewItemProvider
{
public:
	LeaderboardRankProvider();
	virtual ~LeaderboardRankProvider();

	int GetItemCount(void);
	Tizen::Ui::Controls::ListItemBase* CreateItem(int index, int itemWidth);
	bool DeleteItem(int index, Tizen::Ui::Controls::ListItemBase* pItem, int itemWidth);
	void addItemList(Tizen::Base::Collection::ArrayList* _list);
	void setUnit(Tizen::Base::String _unit);

private:
	Tizen::Base::Collection::ArrayList list;
	Tizen::Base::String unit;
};

#endif /* LEADERBOARDRANKPROVIDER_H_ */
