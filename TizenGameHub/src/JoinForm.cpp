/*
 * JoinForm.cpp
 *
 *  Created on: Mar 25, 2014
 *      Author: Administrator
 */

#include "JoinForm.h"
#include "AppResourceId.h"
#include "TizenGameHubFrame.h"
#include "GHSharedAuthData.h"

using namespace Tizen::Ui::Controls;
using namespace Tizen::Ui::Scenes;
using namespace Tizen::Web::Json;
using namespace Tizen::Base;
using namespace Tizen::Base::Collection;

using namespace Tizen::App;
using namespace Tizen::Ui;
using namespace Tizen::Io;
using namespace Tizen::Graphics;
using namespace Tizen::Media;
using namespace Tizen::Base::Collection;
using namespace Tizen::Base::Utility;
using namespace Tizen::Content;
using namespace Tizen::System;

/*
using namespace Tizen::Graphics;*/
#define DEFAULT_CROPPED_FILE_PATH (Tizen::App::App::GetInstance()->GetAppDataPath() + L"DefCropped.jpg")

JoinForm::JoinForm() : __pCroppedBmp(null)
{
	// TODO Auto-generated constructor stub
}

JoinForm::~JoinForm() {
	// TODO Auto-generated destructor stub
}

bool
JoinForm::Initialize(void)
{
	result r = Construct(IDL_FORM_JOIN);
	TryReturn(r == E_SUCCESS, false, "Failed to construct form");

	return true;
}

result
JoinForm::OnInitializing(void)
{
	result r = E_SUCCESS;

	// TODO: Add your initialization code here

	// Setup back event listener
	SetFormBackEventListener(this);

	// Get a button via resource ID
	pButtonJoin = static_cast< Button* >(GetControl(IDC_JOIN_BUTTON_JOIN));
	pButtonJoin->SetActionId(IDA_BUTTON_JOIN);
	pButtonJoin->AddActionEventListener(*this);
	Button* pButtonCancel = static_cast< Button* >(GetControl(IDC_JOIN_BUTTON_CANCEL));
	pButtonCancel->SetActionId(IDA_BUTTON_CANCEL);
	pButtonCancel->AddActionEventListener(*this);

	pTextEmail = static_cast< EditField* >(GetControl(IDC_JOIN_EDITTEXT_EMAIL));
	pTextPw = static_cast< EditField* >(GetControl(IDC_JOIN_EDITTEXT_PW));
	pTextPwconfirm = static_cast< EditField* >(GetControl(IDC_JOIN_EDITTEXT_PWCONFIRM));
	pTextName = static_cast< EditField* >(GetControl(IDC_JOIN_EDITTEXT_NAME));

	pGalleryProfile = static_cast< Gallery* >(GetControl(IDC_JOIN_GALLERY_PROFILE));
	pGalleryProfile->SetShowState(false);
	//pGalleryProfile->AddTouchEventListener(*this);
	//pGalleryProfile->Construct(GetBounds());
	//pGalleryProfile->SetItemProvider(*this);
	//pGalleryProfile->AddGalleryEventListener(*this);


	pButtonGalleryEdit = static_cast< Button* >(GetControl(IDC_JOIN_GALLERY_EDIT));
	pButtonGalleryEdit->SetActionId(IDA_BUTTON_GALLERY_EDIT);
	pButtonGalleryEdit->AddActionEventListener(*this);


	return r;
}

result
JoinForm::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here
	return r;
}

void
JoinForm::OnActionPerformed(const Tizen::Ui::Control& source, int actionId)
{
	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);

	switch(actionId)
	{
	case IDA_BUTTON_JOIN:
		doJoin();
		break;
	case IDA_BUTTON_CANCEL:
		pSceneManager->GoBackward(BackwardSceneTransition(SCENE_TRANSITION_ANIMATION_TYPE_DEPTH_OUT));
		break;
	case IDA_BUTTON_GALLERY_EDIT:

		CropForm *pCropForm = new CropForm();
		pCropForm->Initialize();
		Frame *pFrame = Application::GetInstance()->GetAppFrame()->GetFrame();
		if(pFrame)
		{
			pFrame->AddControl(*pCropForm);
			pCropForm->SendUserEvent(CropForm::REQUEST_ID_DISPLAYIMAGE, null);
			pFrame->SetCurrentForm(*pCropForm);
			pCropForm->Draw();
			pCropForm->Show();
		}

		break;
	}

}

result
JoinForm::doJoin()
{
	result r = E_SUCCESS;

	MessageBox msgBox;
	int modalResult;

	String strEmail = pTextEmail->GetText();
	String strPw = pTextPw->GetText();
	String strPwconfirm = pTextPwconfirm->GetText();
	String strName = pTextName->GetText();

	if(strEmail == null || strPw == null || strPwconfirm == null || strName == null)
	{
		msgBox.Construct(L"Join", L"빈칸을 채워주세요.", MSGBOX_STYLE_OK);
		msgBox.ShowAndWait(modalResult);
	}
	else if(strPw != strPwconfirm)
	{
		msgBox.Construct(L"Join", L"비밀번호가 다릅니다.", MSGBOX_STYLE_OK);
		msgBox.ShowAndWait(modalResult);
	}
	else
	{
		if( isPlayerJoin->ToBool() ) {

			//AppLog("-----------Enter1--------------");

			GHhttpClient* httpPost = new GHhttpClient();

			Tizen::Base::Collection::HashMap* __pMap = new (std::nothrow) Tizen::Base::Collection::HashMap();
			__pMap->Construct();

			__pMap->Add(new String("email"), new String(strEmail));
			__pMap->Add(new String("pwd"), new String(strPw));
			__pMap->Add(new String("name"), new String(strName));

			//post 함수 호출
			httpPost->RequestHttpPostTran(this, L"/players", __pMap);
		}
		else {

			//AppLog("-----------Enter2--------------");


			GHhttpClient* httpPost = new GHhttpClient();

			String player_id(GHSharedAuthData::getSharedInstance().getPlayerId());

			String url(L"/players" + player_id );

			Tizen::Base::Collection::HashMap* __pMap  = new (std::nothrow) Tizen::Base::Collection::HashMap();
			__pMap->Construct();

			__pMap->Add(new String("pwd"), new String(strPw));
			__pMap->Add(new String("name"), new String(strName));

			httpPost->RequestHttpPutTran(this, url, __pMap);
		}
	}
	return r;
}

void
JoinForm::OnFormBackRequested(Tizen::Ui::Controls::Form& source)
{
	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);
	pSceneManager->GoBackward(BackwardSceneTransition(SCENE_TRANSITION_ANIMATION_TYPE_DEPTH_OUT));
}


void
JoinForm::OnSceneActivatedN(const Tizen::Ui::Scenes::SceneId& previousSceneId,
										  const Tizen::Ui::Scenes::SceneId& currentSceneId, Tizen::Base::Collection::IList* pArgs)
{
	// TODO: Activate your scene here.
	if (pArgs != null)
	{
		if (pArgs->GetCount())
		{
			AppLog("[JoinForm] Argument Received");
			Tizen::Base::Integer *tmpInt = static_cast<Tizen::Base::Integer*>(pArgs->GetAt(0));
			if((*tmpInt).ToInt() == 1)
				isPlayerJoin = new Tizen::Base::Boolean(true);
			else
				isPlayerJoin = new Tizen::Base::Boolean(false);

			if( !(isPlayerJoin->ToBool()) )	// (수정 시퀀스면) 프로필 편집 Panel 추가
			{
				pButtonJoin->SetText( "Edit" );
				pTextEmail->SetText("kichul");
				pTextEmail->SetEnabled(false);

				pGalleryProfile->SetShowState(true);


				//pGalleryProfile->


				//pGalleryProfile->
				//!! pGalleryProfile->Set이미지
			}

		}
		pArgs->RemoveAll(true);
		delete pArgs;
	}

}

void
JoinForm::OnSceneDeactivated(const Tizen::Ui::Scenes::SceneId& currentSceneId,
										   const Tizen::Ui::Scenes::SceneId& nextSceneId)
{
	// TODO: Deactivate your scene here.

}

void JoinForm::OnTransactionReadyToRead(String apiCode, String statusCode,IJsonValue* data)
{
//	JsonObject* pJsonObj = static_cast<JsonObject*>(data);
//
//	// reveal TEST /////////////////////////////////////////////////////////
//	//JsonArray* pJsonArray = static_cast<JsonArray*>(data);
//	String* pStrFNKey      = new String(L"statusCode");
//	IJsonValue* pObjValue = null;
//	pJsonObj->GetValue(pStrFNKey, pObjValue);
//	JsonString* pJsonStr = static_cast<JsonString*>(pObjValue);
//	AppLogDebug("value : %S", pJsonStr->GetPointer());
//
//	//JsonNumber* pJsonStr = static_cast<JsonNumber*>(pObjValue);
//	AppLogDebug("value : %d", pJsonStr->ToInt());
//	///////////////////////////////////////////////////////////////////
//	//형변환
//	String zString(pJsonStr->GetPointer());

	//AppLogDebug("value : %s", statusCode->GetPointer());

	MessageBox msgBox;
	int modalResult;

	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);


	if(statusCode ==  "0")	// 로그인 실패
	{
		AppLog("fail");
		msgBox.Construct(L"Join", L"Join fail", MSGBOX_STYLE_OK);
		msgBox.ShowAndWait(modalResult);
	}
/*	else if(statusCode == "2")
	{
		msgBox.Construct(L"Join", L"Join 중복", MSGBOX_STYLE_OK);
		msgBox.ShowAndWait(modalResult);
	}*/
	else	// (가입 성공 시)
	{
		AppLog("success");
		pSceneManager->GoBackward(BackwardSceneTransition(SCENE_TRANSITION_ANIMATION_TYPE_DEPTH_OUT));
	}
}



//CROP IMAGE
void
JoinForm::OnUserEventReceivedN(RequestId requestId, Tizen::Base::Collection::IList* pArgs)
{
	AppLog("Cropping complete");
	if(requestId == CROPPING_COMPLETE)
	{
		if(__pCroppedBmp)
		{
			delete __pCroppedBmp;
			__pCroppedBmp = null;
		}

		Image img;
		img.Construct();

		//Load the appropriate Cropped bitmap
		if(File::IsFileExist(USER_CROPPED_FILE_PATH))
			__pCroppedBmp = img.DecodeN(USER_CROPPED_FILE_PATH, BITMAP_PIXEL_FORMAT_ARGB8888);
		else
			__pCroppedBmp = img.DecodeN(DEFAULT_CROPPED_FILE_PATH, BITMAP_PIXEL_FORMAT_RGB565);

		__rcCropDisplay.width = __pCroppedBmp->GetWidth();
		__rcCropDisplay.height = __pCroppedBmp->GetHeight();

		saveImage(); //이미지 저장
		RequestRedraw();
	}
}

result
JoinForm::OnDraw()
{
	//AppLogDebug("%S", __pCroppedBmp);


	Canvas *pCanvas = GetCanvasN();
	if(!pCanvas)
		return GetLastResult();

	if(pCanvas)
	{
		pCanvas->Clear();
		//pCanvas->Copy(pCanvas->GetBounds(), *__pCanvas, __pCanvas->GetBounds());
		pCanvas->DrawBitmap(__rcCropDisplay, *__pCroppedBmp);

		//pGalleryProfile->SetBitmapOfEmptyGallery(__pCroppedBmp);

	}
	delete pCanvas;

	//pGalleryProfile->SetBackgroundColor(Color::GetColor(COLOR_ID_RED));
	//pGalleryProfile->SetShowState(true);
	//pGalleryProfile->SetBitmapOfEmptyGallery(__pCroppedBmp);


	return E_SUCCESS;
}

void
JoinForm::saveImage()
{
		result r ;
		String strOK = L"Saved as ";
		String strError = L"Saving image failed ";

		Image img;
		img.Construct();
		r = img.EncodeToFile(*__pCroppedBmp, IMG_FORMAT_JPG, Tizen::App::App::GetInstance()->GetAppDataPath() + L"temp.jpg", true);
		if(IsFailed(r))
		{
			AppLog("__pImage->EncodeToFile %s \n", GetErrorMessage(r));
			ShowMessageBox(L"Error",strError);
			return;
		}
		ContentManager contentManager;
		ContentId contentId;
		r = contentManager.Construct();
		if(IsFailed(r))
		{
			AppLog("contentManager %s \n", GetErrorMessage(r));
			ShowMessageBox(L"Error", strError);
			return;
		}
		String imagePath = CreateUniqueFileName();
		contentId = contentManager.CreateContent(Tizen::App::App::GetInstance()->GetAppDataPath() + L"temp.jpg", imagePath, true);
		if (Tizen::Base::UuId::GetInvalidUuId() == contentId)
		{
			AppLog("contentManager.CreateContent %s \n", GetErrorMessage(r));
			ShowMessageBox(L"Error", strError);
			return;
		}
		else
		{
			ImageContentInfo* pImageContentInfo = null;
			pImageContentInfo = (ImageContentInfo*)contentManager.GetContentInfoN(contentId);
			pImageContentInfo->SetKeyword(L"Crop application");
			pImageContentInfo->SetProvider(L"Crop");
			contentManager.UpdateContent(*pImageContentInfo);
			strOK.Append(imagePath);

			ShowMessageBox(L"Saved", strOK);
			return;
		}
}


String
JoinForm::CreateUniqueFileName( void )
{
	// System Current time is always unique, so the same has been used to create a unique name
	DateTime currentTime ;
	SystemTime::GetCurrentTime (WALL_TIME, currentTime);
	String imagePath = Environment::GetMediaPath() + L"Images/";

	imagePath.Append(currentTime.GetYear());
	if(currentTime.GetMonth() < 10)
		imagePath.Append(L"0");
	imagePath.Append(currentTime.GetMonth());
	if(currentTime.GetDay() < 10)
		imagePath.Append(L"0");
	imagePath.Append(currentTime.GetDay());
	if(currentTime.GetHour() < 10)
		imagePath.Append(L"0");
	imagePath.Append(currentTime.GetHour());
	if(currentTime.GetMinute() < 10)
		imagePath.Append(L"0");
	imagePath.Append(currentTime.GetMinute());
	if(currentTime.GetSecond() < 10)
		imagePath.Append(L"0");
	imagePath.Append(currentTime.GetSecond());

	imagePath.Append(L".jpg");
	return imagePath;
}

void
JoinForm::ShowMessageBox(const String& title, const String& message)
{
	MessageBox messageBox;
	int modalResult = 0;
	messageBox.Construct(title, message, MSGBOX_STYLE_OK, 3000);
	messageBox.ShowAndWait(modalResult);
}
