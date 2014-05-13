/*
 * GHGameProvider.cpp
 *
 *  Created on: Mar 13, 2014
 *      Author: Administrator
 */

#include "GHGameProvider.h"

using namespace Tizen::Base;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Graphics;
using namespace Tizen::Media;

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
	int width = 0;
	int height = 0;

	CustomItem* pItem = new CustomItem();
	AppAssert(pItem);
	pItem->Construct(Tizen::Graphics::Dimension(itemWidth, 150), LIST_ANNEX_STYLE_NORMAL);

	GHGame* game = (GHGame*)(list.GetAt(index));

	ByteBuffer *pBuffer = null;
	Bitmap *pBitmap = null;
	Image *pImage = new (std::nothrow) Image();
	pImage->Construct();
	pBuffer = pImage->DecodeToBufferN(Tizen::App::App::GetInstance()->GetAppRootPath()+L"res/icon.png", BITMAP_PIXEL_FORMAT_RGB565,width,height);
	pBitmap = new (std::nothrow) Bitmap();
	pBitmap->Construct(*pBuffer, Dimension(width, height),BITMAP_PIXEL_FORMAT_RGB565 );

	Color cBlack(0x00, 0x00, 0x00);
	Color cGray(0x93, 0x93, 0x93);

	pItem->AddElement(Rectangle(10, 15, 120, 120), 0, *pBitmap);
	pItem->AddElement(Rectangle(150, 10, itemWidth-160, 60), 1, game->getTitle(), 45, cBlack, cBlack, cBlack);
	pItem->AddElement(Rectangle(150, 70, itemWidth-160, 60), 2, game->getDescription(), 30, cGray, cGray, cGray);

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
