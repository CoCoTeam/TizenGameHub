/*
 * JoinForm.h
 *
 *  Created on: Mar 25, 2014
 *      Author: Administrator
 */

#ifndef JOINFORM_H_
#define JOINFORM_H_

#include <GHTizen.h>


#include <FBase.h>
#include <FUi.h>
#include <FIo.h>
#include <FGraphics.h>
#include <FMedia.h>
#include <FApp.h>
#include <FContent.h>
#include <FSystem.h>

#include "CropForm.h"
#include "GHAchievement/GHAchievementController.h"

#include "GHAppRegistry.h"


const Tizen::Base::String IMAGE_UPLOAD = "00";
const Tizen::Base::String PLAYER_JOIN = "01";
const Tizen::Base::String PLAYER_MODIFY = "03";

/*
#include "GHPlayer/GHPlayerController.h"
#include "GHPlayer/GHPlayerLoggedinListener.h"
*/

class JoinForm
	: public Tizen::Ui::Controls::Form
	, public Tizen::Ui::IActionEventListener
	, public Tizen::Ui::Controls::IFormBackEventListener
	, public Tizen::Ui::Scenes::ISceneEventListener
	, public GHController
    , public Tizen::Ui::Controls::IGalleryItemProvider
    , public Tizen::Ui::ITouchEventListener
    , public Tizen::Net::Http::IHttpProgressEventListener
    , public Tizen::Media::IImageDecodeUrlEventListener
    ,  public Tizen::Content::IDownloadListener

{
public:
	JoinForm();
	virtual ~JoinForm();
	bool Initialize(void);
	Tizen::Graphics::Bitmap *__pCroppedBmp;
	Tizen::Graphics::Bitmap* __ptempBitmap;

private:
	Tizen::Ui::Controls::EditField *pTextEmail, *pTextPw, *pTextPwconfirm, *pTextName;
	Tizen::Ui::Controls::Button* pButtonJoin;

	//Tizen::Ui::Controls::Button* pButtonGalleryEdit;

	Tizen::Base::Boolean *isPlayerJoin;		//가입하는 시퀀스(true:가입, false:수정)

	virtual result OnInitializing(void);
	virtual result OnTerminating(void);
	//IActionEventListener
	virtual void OnActionPerformed(const Tizen::Ui::Control& source, int actionId);
	//IFormBackEventListener
	virtual void OnFormBackRequested(Tizen::Ui::Controls::Form& source);
	//ISceneEventListener
	virtual void OnSceneActivatedN(const Tizen::Ui::Scenes::SceneId& previousSceneId,
								   const Tizen::Ui::Scenes::SceneId& currentSceneId, Tizen::Base::Collection::IList* pArgs);
	virtual void OnSceneDeactivated(const Tizen::Ui::Scenes::SceneId& currentSceneId,
									const Tizen::Ui::Scenes::SceneId& nextSceneId);

	static const int IDA_BUTTON_JOIN = 101;
	static const int IDA_BUTTON_CANCEL = 102;
	static const int IDA_BUTTON_GALLERY_EDIT = 103;

	// GHController
	virtual void OnTransactionReadyToRead(Tizen::Base::String apiCode, Tizen::Base::String statusCode, Tizen::Web::Json::IJsonValue* data);
	virtual void OnTransactionCompleted(Tizen::Net::Http::HttpSession& httpSession, Tizen::Net::Http::HttpTransaction& httpTransaction);


	result doJoin();


	// CROP
	virtual void OnUserEventReceivedN(RequestId requestId, Tizen::Base::Collection::IList* pArgs);
	//Tizen::Graphics::Rectangle __rcCropDisplay;
	virtual result OnDraw();

	void saveImage();
	void storeImageInternal(Tizen::Graphics::Bitmap *bitmap);
	Tizen::Base::String CreateUniqueFileName( void );
	void ShowMessageBox(const Tizen::Base::String& title, const Tizen::Base::String& message);

	 //IGalleryItemProvider
	 virtual Tizen::Ui::Controls::GalleryItem* CreateItem (int index);
	 virtual bool DeleteItem (int index, Tizen::Ui::Controls::GalleryItem *pItem);
	 virtual int GetItemCount(void);

	 Tizen::Graphics::Bitmap* CreateBitmapFromByteBufferN(Tizen::Base::ByteBuffer* pBuffer, const int& width, const int& height);

	 //gallery
	 Tizen::Ui::Controls::Gallery* pGalleryProfile;

	 //ITouchEventListener
	 virtual void  OnTouchDoublePressed (const Tizen::Ui::Control &source,	const Tizen::Graphics::Point &currentPosition, const Tizen::Ui::TouchEventInfo &touchInfo){};
	 virtual void  OnTouchFocusIn (const Tizen::Ui::Control &source, const Tizen::Graphics::Point &currentPosition, const Tizen::Ui::TouchEventInfo &touchInfo){};
	 virtual void  OnTouchFocusOut (const Tizen::Ui::Control &source, const Tizen::Graphics::Point &currentPosition, const Tizen::Ui::TouchEventInfo &touchInfo){};
	 virtual void  OnTouchLongPressed (const Tizen::Ui::Control &source, const Tizen::Graphics::Point &currentPosition, const Tizen::Ui::TouchEventInfo &touchInfo){};
	 virtual void  OnTouchMoved (const Tizen::Ui::Control &source, const Tizen::Graphics::Point &currentPosition, const Tizen::Ui::TouchEventInfo &touchInfo){};
	 virtual void  OnTouchReleased (const Tizen::Ui::Control &source, const Tizen::Graphics::Point &currentPosition, const Tizen::Ui::TouchEventInfo &touchInfo){};
	 virtual void  OnTouchPressed (const Tizen::Ui::Control &source, const Tizen::Graphics::Point &currentPosition, const Tizen::Ui::TouchEventInfo &touchInfo);

	 //touch event 제한
	 int count;
	 Tizen::Base::String simg_url;  //img_url 저장

	 // IHttpProgressEventListener
     virtual void OnHttpDownloadInProgress(Tizen::Net::Http::HttpSession& httpSession, Tizen::Net::Http::HttpTransaction& httpTransaction, long long currentLength, long long totalLength);
	 virtual void OnHttpUploadInProgress(Tizen::Net::Http::HttpSession &httpSession, Tizen::Net::Http::HttpTransaction &httpTransaction, long long currentLength, long long totalLength);

	 //
	 void RequestImage(const Tizen::Base::String& path,int width, int height,int timeout);
	 virtual void  OnImageDecodeUrlReceived (RequestId reqId, Tizen::Graphics::Bitmap *pBitmap, result r, const Tizen::Base::String errorCode, const Tizen::Base::String errorMessage);


	 virtual void  OnDownloadCanceled (RequestId reqId) {}
	 virtual void  OnDownloadCompleted (RequestId reqId, const Tizen::Base::String &path);
	 virtual void  OnDownloadFailed (RequestId reqId, result r, const Tizen::Base::String &errorCode) {}
	 virtual void  OnDownloadInProgress (RequestId reqId,unsigned long long receivedSize, unsigned long long totalSize);
	 virtual void  OnDownloadPaused (RequestId reqId) {}

	     void DownloadStart();

	protected:
	     RequestId __requestId;

};

#endif /* JOINFORM_H_ */
