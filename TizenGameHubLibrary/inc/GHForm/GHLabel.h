/*
 * GHLabel.h
 *
 *  Created on: May 19, 2014
 *      Author: Administrator
 */

#ifndef GHLABEL_H_
#define GHLABEL_H_

#include <FUiCtrlLabel.h>
#include <FMedia.h>

class GHLabel
	: public Tizen::Ui::Controls::Label
	, public Tizen::Media::IImageDecodeUrlEventListener
{
public:
	GHLabel();
	virtual ~GHLabel();

	void SetBackgroundFromUrl(Tizen::Base::String url);

private:
	Tizen::Graphics::Bitmap *_pBitmap;

	void RequestImage(const Tizen::Base::String& path,int width, int height, int timeout);
	// IImageDecodeUrlEventListener
	virtual void OnImageDecodeUrlReceived(RequestId reqId, Tizen::Graphics::Bitmap *pBitmap, result r, const Tizen::Base::String errorCode, const Tizen::Base::String errorMessage);
};

#endif /* GHLABEL_H_ */
