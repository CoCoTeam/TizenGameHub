
#ifndef CROPFORM_H_
#define CROPFORM_H_

#include <FApp.h>
#include <FBase.h>
#include <FUi.h>
#include <FMedia.h>
#include <FGraphics.h>
#include "AppResourceId.h"
//#include "TizenGameHubFrame.h"
//#include "TizenGameHubMainForm.h"

/*namespace myNamespace
{
	#define CROPPING_COMPLETE 2001
}*/

#define CROPPING_COMPLETE 2001
#define USER_CROPPED_FILE_PATH (Tizen::App::App::GetInstance()->GetAppDataPath() + L"UserCropped.jpg")
#define MAIN_FORM_NAME IDL_FORM_JOIN

class CropForm :
public Tizen::Ui::Controls::Form,
public Tizen::Ui::IActionEventListener,
public Tizen::Ui::ITouchEventListener,
public Tizen::App::IAppControlResponseListener,
public Tizen::Ui::Controls::IFormBackEventListener
{
	// Construction
public:
	CropForm(void);
	virtual ~CropForm(void);
	bool Initialize(void);
	static const int ID_FOOTERITEMCROP = 200;
	static const RequestId REQUEST_ID_DISPLAYIMAGE 	= 201;
	static const RequestId REQUEST_ID_DISPLAYWEBIMAGE 	= 202;
//	static const int CROPPING_COMPLETE = 2001;

	// Implementation
protected:
	Tizen::Graphics::Bitmap * __pBitmapOriginal;
	Tizen::Graphics::Rectangle __Croprectangle;
	int __x_min;
	int __x_max;
	int __y_min;
	int __y_max;

protected:
	void LoadImage(Tizen::Base::String* fileName);
	void LoadWebImage(Tizen::Graphics::Bitmap* bmp);
	void GetCordinates(const Tizen::Graphics::Point point);

public:
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);
	virtual void OnActionPerformed(const Tizen::Ui::Control& source, int actionId);
	virtual void OnUserEventReceivedN(RequestId requestId, Tizen::Base::Collection::IList* pArgs);
	result OnDraw(void);
	virtual void  OnTouchDoublePressed (const Tizen::Ui::Control &source,	const Tizen::Graphics::Point &currentPosition, const Tizen::Ui::TouchEventInfo &touchInfo);
	virtual void  OnTouchFocusIn (const Tizen::Ui::Control &source, const Tizen::Graphics::Point &currentPosition, const Tizen::Ui::TouchEventInfo &touchInfo);
	virtual void  OnTouchFocusOut (const Tizen::Ui::Control &source, const Tizen::Graphics::Point &currentPosition, const Tizen::Ui::TouchEventInfo &touchInfo);
	virtual void  OnTouchLongPressed (const Tizen::Ui::Control &source, const Tizen::Graphics::Point &currentPosition, const Tizen::Ui::TouchEventInfo &touchInfo);
	virtual void  OnTouchMoved (const Tizen::Ui::Control &source, const Tizen::Graphics::Point &currentPosition, const Tizen::Ui::TouchEventInfo &touchInfo);
	virtual void  OnTouchPressed (const Tizen::Ui::Control &source, const Tizen::Graphics::Point &currentPosition, const Tizen::Ui::TouchEventInfo &touchInfo);
	virtual void  OnTouchReleased (const Tizen::Ui::Control &source, const Tizen::Graphics::Point &currentPosition, const Tizen::Ui::TouchEventInfo &touchInfo);
	virtual void  OnAppControlCompleteResponseReceived(const Tizen::App::AppId& appId, const Tizen::Base::String& operationId, const Tizen::App::AppCtrlResult appControlResult, const Tizen::Base::Collection::IMap* pResultList);
	virtual void  OnFormBackRequested (Tizen::Ui::Controls::Form &source);


};
#endif /* CROPFORM_H_ */
