/*
 * GHPlayerProvider.h
 *
 *  Created on: Mar 13, 2014
 *      Author: Administrator
 */

#ifndef APPGHLEADERBOARDRANKPROVIDER_H_
#define APPGHLEADERBOARDRANKPROVIDER_H_

#include "GHLeaderboard/GHPlayerRank.h"

class AppGHLeaderboardRankProvider
: public Tizen::Ui::Controls::IListViewItemProvider
{
public:
	AppGHLeaderboardRankProvider();
	virtual ~AppGHLeaderboardRankProvider();

	int GetItemCount(void);
	Tizen::Ui::Controls::ListItemBase* CreateItem(int index, int itemWidth);
	bool DeleteItem(int index, Tizen::Ui::Controls::ListItemBase* pItem, int itemWidth);
	void addItemList(Tizen::Base::Collection::ArrayList* _list);
	void setUnit(Tizen::Base::String _unit);

private:
	Tizen::Base::Collection::ArrayList list;
	Tizen::Base::String unit;
};

#endif /* APPGHLEADERBOARDRANKPROVIDER_H_ */
