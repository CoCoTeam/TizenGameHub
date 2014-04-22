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

{
public:
	JoinForm();
	virtual ~JoinForm();
	bool Initialize(void);

private:
	Tizen::Ui::Controls::EditField *pTextEmail, *pTextPw, *pTextPwconfirm, *pTextName;
	Tizen::Ui::Controls::Button* pButtonJoin;
	Tizen::Ui::Controls::Gallery* pGalleryProfile;
	Tizen::Ui::Controls::Button* pButtonGalleryEdit;

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

	result doJoin();


	// CROP
	virtual void OnUserEventReceivedN(RequestId requestId, Tizen::Base::Collection::IList* pArgs);
	Tizen::Graphics::Bitmap *__pCroppedBmp;
	//Tizen::Graphics::Rectangle __rcCropDisplay;
	virtual result OnDraw();

	void saveImage();
	Tizen::Base::String CreateUniqueFileName( void );
	void ShowMessageBox(const Tizen::Base::String& title, const Tizen::Base::String& message);

	 //IGalleryItemProvider
	 virtual Tizen::Ui::Controls::GalleryItem* CreateItem (int index);
	 virtual bool DeleteItem (int index, Tizen::Ui::Controls::GalleryItem *pItem);
	 virtual int GetItemCount(void);
};

#endif /* JOINFORM_H_ */
