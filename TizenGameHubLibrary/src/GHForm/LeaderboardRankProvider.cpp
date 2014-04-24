/*
 * GHPlayerProvider.cpp
 *
 *  Created on: Mar 13, 2014
 *      Author: Administrator
 */

#include "GHForm/LeaderboardRankProvider.h"

LeaderboardRankProvider::LeaderboardRankProvider() {
	// TODO Auto-generated constructor stub
}

LeaderboardRankProvider::~LeaderboardRankProvider() {
	// TODO Auto-generated destructor stub
}

int LeaderboardRankProvider::GetItemCount(void)
{
	AppLog("[LeaderboardRankProvider] Rank List Count : %d",list.GetCount());
	return list.GetCount();
}
Tizen::Ui::Controls::ListItemBase* LeaderboardRankProvider::CreateItem(int index, int itemWidth)
{

	Tizen::Ui::Controls::SimpleItem* pItem = new Tizen::Ui::Controls::SimpleItem();
	AppAssert(pItem);

	GHPlayerRank* rank = (GHPlayerRank*)(list.GetAt(index));
	Tizen::Base::String sRank, sScore;
	sRank.Append(rank->getRank());
	sScore.Append(rank->getScore());

	Tizen::Base::String text(sRank +"/"+ rank->getName() +"/"+ sScore);
	pItem->Construct(Tizen::Graphics::Dimension(itemWidth, 80), Tizen::Ui::Controls::LIST_ANNEX_STYLE_NORMAL);
	pItem->SetElement(text);

	return pItem;
}
bool LeaderboardRankProvider::DeleteItem
(int index, Tizen::Ui::Controls::ListItemBase* pItem, int itemWidth)
{
	return false;
}
void LeaderboardRankProvider::setItemList(Tizen::Base::Collection::ArrayList* _list)
{
	for(int i=0 ; i<_list->GetCount() ; i++)
	{
		list.Add( (Tizen::Base::Object*)(_list->GetAt(i)) );
	}
}
