/*
 * GHGameProvider.h
 *
 *  Created on: Mar 13, 2014
 *      Author: Administrator
 */

#ifndef GHGAMEPROVIDER_H_
#define GHGAMEPROVIDER_H_

#include <FUi.h>
#include <FSystem.h>
#include <FUix.h>
#include <FMedia.h>
#include <FGraphics.h>
#include "GHGame/GHGame.h"

class GHGameProvider
	: public Tizen::Ui::Controls::IListViewItemProvider
	, public Tizen::Media::IImageDecodeUrlEventListener
{
public:
	GHGameProvider();
	virtual ~GHGameProvider();

	//IListViewItemProvider
	virtual Tizen::Ui::Controls::ListItemBase* CreateItem(int index, int itemWidth);
	virtual bool DeleteItem(int index, Tizen::Ui::Controls::ListItemBase* pItem, int itemWidth);
	virtual int GetItemCount(void);

	void setItemList(Tizen::Base::Collection::ArrayList* _list);

	void RequestImage(const Tizen::Base::String& path, RequestId reqId, int width, int height,int timeout=5000);
	virtual void OnImageDecodeUrlReceived (RequestId reqId, Tizen::Graphics::Bitmap *pBitmap, result r, const Tizen::Base::String errorCode, const Tizen::Base::String errorMessage);


private:
	Tizen::Base::Collection::ArrayList list;
	Tizen::Base::Collection::ArrayList ItemList;
};

#endif /* GHGAMEPROVIDER_H_ */
