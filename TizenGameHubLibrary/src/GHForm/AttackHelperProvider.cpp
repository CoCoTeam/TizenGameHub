/*
 * AttackHelperProvider.cpp
 *
 *  Created on: May 12, 2014
 *      Author: Administrator
 */

#include <FMedia.h>
#include "GHForm/AttackHelperProvider.h"

using namespace Tizen::Base;
using namespace Tizen::Graphics;

AttackHelperProvider::AttackHelperProvider() {
	// TODO Auto-generated constructor stub

}

AttackHelperProvider::~AttackHelperProvider() {
	// TODO Auto-generated destructor stub
}

int AttackHelperProvider::GetItemCount(void)
{
	return list.GetCount();
}
Tizen::Ui::Controls::ListItemBase* AttackHelperProvider::CreateItem(int index, int itemWidth)
{
	int width = 0, height = 0;
	Tizen::Ui::Controls::CustomItem* pItem = new Tizen::Ui::Controls::CustomItem();
	AppAssert(pItem);
	pItem->Construct(Dimension(itemWidth, 150), Tizen::Ui::Controls::LIST_ANNEX_STYLE_NORMAL);
	pItem->SetBackgroundColor(Tizen::Ui::Controls::LIST_ITEM_DRAWING_STATUS_NORMAL, Color(0xDD, 0xDD, 0xDD));

	GHAttackhelperData *ahData = (GHAttackhelperData*)(list.GetAt(index));

	ByteBuffer *pBuffer = null;
	Bitmap *pBitmap = null;
	Tizen::Media::Image *pImage = new (std::nothrow) Tizen::Media::Image();
	pImage->Construct();
	pBuffer = pImage->DecodeToBufferN(Tizen::App::App::GetInstance()->GetAppRootPath()+L"res/profile_default.png", BITMAP_PIXEL_FORMAT_RGB565,width,height);
	pBitmap = new (std::nothrow) Bitmap();
	pBitmap->Construct(*pBuffer, Dimension(width, height),BITMAP_PIXEL_FORMAT_RGB565 );

	Color cBlack(0x00, 0x00, 0x00);
	String text(ahData->getSenderName() +"님이 " + ahData->getItemName());
	String text2(Integer::ToString(ahData->getQuantity()) +"개를 보냈습니다");

	pItem->AddElement(Rectangle(10, 15, 120, 120), 0, *pBitmap);
	pItem->AddElement(Rectangle(140, 10, 300, 70), 1, text, 40, cBlack, cBlack, cBlack);
	pItem->AddElement(Rectangle(140, 60, 300, 70), 2, text2, 40, cBlack, cBlack, cBlack);

	return pItem;
}
bool AttackHelperProvider::DeleteItem
(int index, Tizen::Ui::Controls::ListItemBase* pItem, int itemWidth)
{
	return false;
}
void AttackHelperProvider::addItemList(Tizen::Base::Collection::ArrayList* _list)
{
	for(int i=0 ; i<_list->GetCount() ; i++)
	{
		list.Add( (Tizen::Base::Object*)(_list->GetAt(i)) );
	}
}
