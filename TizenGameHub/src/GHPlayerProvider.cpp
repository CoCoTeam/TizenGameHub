/*
 * GHPlayerProvider.cpp
 *
 *  Created on: Mar 13, 2014
 *      Author: Administrator
 */

#include <FMedia.h>
#include "GHPlayerProvider.h"

using namespace Tizen::Base;
using namespace Tizen::Graphics;

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
	int width = 0;
	int height = 0;

	Tizen::Ui::Controls::CustomItem* pItem = new Tizen::Ui::Controls::CustomItem();
	AppAssert(pItem);

	GHPlayer *player = (GHPlayer*)(list.GetAt(index));
	pItem->Construct(Dimension(itemWidth, 120), Tizen::Ui::Controls::LIST_ANNEX_STYLE_NORMAL);

	ByteBuffer *pBuffer = null;
	Bitmap *pBitmap = null;
	Tizen::Media::Image *pImage = new (std::nothrow) Tizen::Media::Image();
	pImage->Construct();
	pBuffer = pImage->DecodeToBufferN(Tizen::App::App::GetInstance()->GetAppRootPath()+L"res/profile_default.png", BITMAP_PIXEL_FORMAT_RGB565,width,height);
	pBitmap = new (std::nothrow) Bitmap();
	pBitmap->Construct(*pBuffer, Dimension(width, height),BITMAP_PIXEL_FORMAT_RGB565 );

	Color cBlack(0x00, 0x00, 0x00);
	Color cGray(0x93, 0x93, 0x93);

	pItem->AddElement(Rectangle(10, 10, 100, 100), 0, *pBitmap);
	pItem->AddElement(Rectangle(120, 10, 300, 70), 1, player->getName(), 40, cBlack, cBlack, cBlack);
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
