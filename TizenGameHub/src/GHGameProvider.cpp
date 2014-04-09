/*
 * GHGameProvider.cpp
 *
 *  Created on: Mar 13, 2014
 *      Author: Administrator
 */

#include "GHGameProvider.h"

GHGameProvider::GHGameProvider() {
	// TODO Auto-generated constructor stub
}

GHGameProvider::~GHGameProvider() {
	// TODO Auto-generated destructor stub
}

int GHGameProvider::GetItemCount(void)
{
	AppLog("[GHGameProvider] Game List Count : %d",list.GetCount());
	return list.GetCount();
}
Tizen::Ui::Controls::ListItemBase* GHGameProvider::CreateItem(int index, int itemWidth)
{

	Tizen::Ui::Controls::SimpleItem* pItem = new Tizen::Ui::Controls::SimpleItem();
	AppAssert(pItem);

	Tizen::Base::String text =  ((GHGame*)(list.GetAt(index)))->getTitle();
	pItem->Construct(Tizen::Graphics::Dimension(itemWidth, 80), Tizen::Ui::Controls::LIST_ANNEX_STYLE_NORMAL);
	pItem->SetElement(text);

	return pItem;
}
bool GHGameProvider::DeleteItem
(int index, Tizen::Ui::Controls::ListItemBase* pItem, int itemWidth)
{
	return false;
}
void GHGameProvider::setItemList(Tizen::Base::Collection::ArrayList* _list)
{
	for(int i=0 ; i<_list->GetCount() ; i++)
	{
		list.Add( _list->GetAt(i) );
	}
}
