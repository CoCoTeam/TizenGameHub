/*
 * GHPlayerProvider.cpp
 *
 *  Created on: Mar 13, 2014
 *      Author: Administrator
 */

#include "LeaderboardRankProvider.h"
#include "FMedia.h"
#include "GHSharedAuthData.h"

using namespace Tizen::Base;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Graphics;
using namespace Tizen::Media;

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
	AppLog("[LeaderboardRankProvider] CreateItem() : %d / %d",index+1, list.GetCount());

	Tizen::Ui::Controls::CustomItem* pItem = new Tizen::Ui::Controls::CustomItem();
	AppAssert(pItem);
	pItem->Construct(Tizen::Graphics::Dimension(itemWidth, 130), Tizen::Ui::Controls::LIST_ANNEX_STYLE_NORMAL);

	GHPlayerRank* rank = (GHPlayerRank*)(list.GetAt(index));

	// Image===
	ByteBuffer *pBuffer = null;
	Bitmap *pBitmap = null;
	Image *pImage = new (std::nothrow) Image();
	pImage->Construct();
	int width, height;
	pBuffer = pImage->DecodeToBufferN(Tizen::App::App::GetInstance()->GetAppRootPath()+L"res/profile_default.png", BITMAP_PIXEL_FORMAT_RGB565,width,height);
	pBitmap = new (std::nothrow) Bitmap();
	pBitmap->Construct(*pBuffer, Dimension(width, height),BITMAP_PIXEL_FORMAT_RGB565 );
	//==========
	Color cBlack(0x00, 0x00, 0x00);
	Color cGray(0x93, 0x93, 0x93);
	String strScore(Integer::ToString(rank->getScore()) +" "+ unit);
	String strRank(Integer::ToString(rank->getRank()) + " 위");

	pItem->AddElement(Rectangle(10, 15, 100, 100), 0,  *pBitmap);
	pItem->AddElement(Rectangle(120, 10, 300, 50), 1, String(rank->getName()), 50, cBlack, cBlack, cBlack);
	pItem->AddElement(Rectangle(120, 70, 300, 50), 2, strScore, 40, cGray, cGray, cGray);
	pItem->AddElement(Rectangle(itemWidth - 150, 40, 150, 50), 3, strRank, 40, cBlack, cBlack, cBlack);

	// 내 정보에 하이라이트 표시
	String player_id(GHSharedAuthData::getSharedInstance().getPlayerId());
	if(rank->getId().Equals(player_id)) {
		pItem->SetBackgroundColor(LIST_ITEM_DRAWING_STATUS_NORMAL, Color(0x77, 0x77, 0x00, 0x33));
	}

	return pItem;
}
bool LeaderboardRankProvider::DeleteItem
(int index, Tizen::Ui::Controls::ListItemBase* pItem, int itemWidth)
{
	return false;
}
void LeaderboardRankProvider::addItemList(Tizen::Base::Collection::ArrayList* _list)
{
	for(int i=0 ; i<_list->GetCount() ; i++)
	{
		list.Add( (Tizen::Base::Object*)(_list->GetAt(i)) );
	}
}
void LeaderboardRankProvider::setUnit(Tizen::Base::String _unit)
{
	unit = _unit;
}
