/*
 * GHPlayerProvider.cpp
 *
 *  Created on: Mar 13, 2014
 *      Author: Administrator
 */

#include "GHPlayerProvider.h"

GHPlayerProvider::GHPlayerProvider() {
	// TODO Auto-generated constructor stub

}

GHPlayerProvider::~GHPlayerProvider() {
	// TODO Auto-generated destructor stub
}

int GHPlayerProvider::GetItemCount(void)
{
	AppLog("[GameHub] Friend List Count : %d",list.GetCount());
	return list.GetCount();
}
Tizen::Ui::Controls::ListItemBase* GHPlayerProvider::CreateItem(int index, int itemWidth)
{

	Tizen::Ui::Controls::SimpleItem* pItem = new Tizen::Ui::Controls::SimpleItem();
	AppAssert(pItem);

	Tizen::Base::String* text = static_cast<Tizen::Base::String*>( ((GHPlayer*)(list.GetAt(index)))->getName() );
	pItem->Construct(Tizen::Graphics::Dimension(itemWidth, 80), Tizen::Ui::Controls::LIST_ANNEX_STYLE_NORMAL);
	pItem->SetElement(*text);

	return pItem;
}
bool GHPlayerProvider::DeleteItem
(int index, Tizen::Ui::Controls::ListItemBase* pItem, int itemWidth)
{
	return false;
}
void GHPlayerProvider::setItemList(Tizen::Base::Collection::ArrayList* _list)
{
	for(int i=0 ; i<_list->GetCount() ; i++)
	{
		list.Add( (Tizen::Base::Object*)(_list->GetAt(i)) );
	}
}
