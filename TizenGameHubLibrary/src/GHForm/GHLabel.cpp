/*
 * GHLabel.cpp
 *
 *  Created on: May 19, 2014
 *      Author: Administrator
 */

#include "GHForm/GHLabel.h"

GHLabel::GHLabel() : Label() {

}
GHLabel::~GHLabel(){}

void GHLabel::SetBackgroundFromUrl(Tizen::Base::String url)
{
	Tizen::Base::String sURL = L"http://54.238.195.222:80/players/pkeykichul/image";
	RequestImage(sURL, this->GetWidth(), this->GetHeight(), 5000);
}
// Request the image and add the image pointer to the list
void GHLabel::RequestImage(const Tizen::Base::String& path,int width, int height, int timeout)
{
	Tizen::Media::Image* pImage = new Tizen::Media::Image();
	pImage->Construct();

	// Set a URL
	Tizen::Base::Utility::Uri uri;
	uri.SetUri(path);

	RequestId reqId;

AppLogDebug("%S %d %d", path.GetPointer(), width, height);
	//서버에 보내기
	pImage->DecodeUrl(uri, Tizen::Graphics::BITMAP_PIXEL_FORMAT_RGB565, width, height, reqId, *this, timeout);
AppLogDebug("2");
}
// Receive the image and call the delete timer
void GHLabel::OnImageDecodeUrlReceived(RequestId reqId, Tizen::Graphics::Bitmap *pBitmap, result r, const Tizen::Base::String errorCode, const Tizen::Base::String errorMessage)
{
AppLogDebug("3");
	if(IsFailed(r)) {
		AppLog("Request failed: errorCode(%ls) errorMessage(%ls)", errorCode.GetPointer(), errorMessage.GetPointer());
	}
	else {
AppLogDebug("32");
		_pBitmap = pBitmap;
		this->SetBackgroundBitmap(*_pBitmap);
	}
}
