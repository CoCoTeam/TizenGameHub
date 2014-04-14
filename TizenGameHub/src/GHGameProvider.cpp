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

	SimpleItem* pItem = new SimpleItem();
	AppAssert(pItem);
	pItem->Construct(Tizen::Graphics::Dimension(itemWidth, 80), LIST_ANNEX_STYLE_NORMAL);

	String text = ((GHGame*)(list.GetAt(index)))->getTitle();

	ByteBuffer *pBuffer = null;
	Bitmap *pBitmap = null;
	Image *pImage = new (std::nothrow) Image();
	pImage->Construct();

	pBuffer = pImage->DecodeToBufferN(Tizen::App::App::GetInstance()->GetAppRootPath()+L"res/icon.png", BITMAP_PIXEL_FORMAT_RGB565,width,height);
//	SAFE_DELETE(pImage);

	pBitmap = new (std::nothrow) Bitmap();
	pBitmap->Construct(*pBuffer, Dimension(width, height),BITMAP_PIXEL_FORMAT_RGB565 );

	pItem->SetElement(text, pBitmap);
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
