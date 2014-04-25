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

				//pGalleryProfile->SetShowState(true);

				//!! pGalleryProfile->Set이미지
			}

		}
		pArgs->RemoveAll(true);
		delete pArgs;
	}

}

// IGalleryItemProvider implementation  ( 이걸 해야 Galley 에 추가할 수 있음 ... !! )
GalleryItem*
JoinForm::CreateItem(int index)
{
    // Gets an instance of Bitmap
   // AppResource* pAppResource = Application::GetInstance()->GetAppResource();
   // Bitmap* pImageTemp = pAppResource->GetBitmapN(L"Image.jpg");

    // Creates an instance of GalleryItem and registers the bitmap to the gallery item
    GalleryItem* pGallery = new GalleryItem();
    pGallery->Construct(*__pCroppedBmp);

    // Deallocates the bitmap
   // delete pImageTemp;

    return pGallery;
}

bool
JoinForm::DeleteItem(int index, GalleryItem *pItem)
{
    delete pItem;
    return true;
}

int
JoinForm::GetItemCount(void)
{
    return 1;
}

//////////////////////////////////////////////////////////////////////////////////////////////////



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

		//__rcCropDisplay.width = __pCroppedBmp->GetWidth();
		//__rcCropDisplay.height = __pCroppedBmp->GetHeight();


		RequestRedraw();
		storeImageInternal(__pCroppedBmp);
		//saveImage();
	}
}

result
JoinForm::OnDraw()
{
	Tizen::Ui::Controls::Gallery* pGalleryProfile;

	pGalleryProfile = static_cast< Gallery* >(GetControl(IDC_JOIN_GALLERY_PROFILE));

	//pGalleryProfile->
	//pGalleryProfile->SetShowState(false);
	pGalleryProfile->SetItemProvider(*this);

	//이미지 전환
	GalleryItem* pGallery = new GalleryItem();
    pGallery->Construct(*__ptempBitmap);

	return E_SUCCESS;
}

Bitmap*
JoinForm::CreateBitmapFromByteBufferN(ByteBuffer* pBuffer, const int& width, const int& height)
{
		Dimension dim(width, height);
		Bitmap* pBmp = new (std::nothrow) Bitmap;
		TryReturn(pBmp != null, pBmp,"E_OUT_OF_MEMORY Bitmap creation failed");
		result r = pBmp->Construct(*pBuffer, dim, Tizen::Graphics::BITMAP_PIXEL_FORMAT_ARGB8888);
		TryReturn(r == E_SUCCESS, pBmp,"[%s] Bitmap->Construct", GetErrorMessage(r));
		return pBmp;
}

void
JoinForm::storeImageInternal(Bitmap *bitmap)
{
			AppLog("22222");

			result r ;
			///////////////////////////////////////////////////////////////// 버퍼 ///////////////////////////////////////////////////////////////////


			String filePath(Environment::GetMediaPath() + L"TempPicture");
			File file;

			int width = 0, height = 0;
			int readCnt;

			ByteBuffer* pImageByteBuff = null;
			pImageByteBuff = new (std::nothrow) ByteBuffer;

			//r = ImageBuffer::GetImageInfo(*filePath, imgFormat, originalWidth, originalHeight);

			// Create an Image instance.
			Image img;
			img.Construct();

			String imagePath = CreateUniqueFileName();

			// Get the image's size.
		     width = __pCroppedBmp->GetWidth();
		     height = __pCroppedBmp->GetHeight();

			//이미지를   바이트로 변환
			//pImageByteBuff = img.DecodeToBufferN(imagePath, BITMAP_PIXEL_FORMAT_ARGB8888, width, height);
		     pImageByteBuff = img.EncodeToBufferN(*__pCroppedBmp, IMG_FORMAT_JPG);

			//파일 생성
			r = file.Construct(filePath, "w+");

			//파일에 바이트 쓰기
			r = file.Write(*pImageByteBuff);
			readCnt = file.Read(*pImageByteBuff);

			AppLog("Successed.\n");

			//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

			//////////////// 바이트를 다시 이미지로 변환
			__ptempBitmap = CreateBitmapFromByteBufferN(pImageByteBuff, width, height);


/*			AppLog("22222");

			//바이트 버퍼////////////////////////////wq////////////////////////////////////////////////
			ByteBuffer* pTempByteBuff = null;
			pTempByteBuff = new (std::nothrow) ByteBuffer;

			pTempByteBuff->SetByte();
			TryCatch(pTempByteBuff != null, ,"pResizeByteBuffer is null, no memory");
			////////////////////////////////////////////////////////////////////////////////////

			AppLog("-------------------------check---------------------");

			File *pFile;
			pFile = new (std::nothrow) File;
			r = pFile->Construct(imagePath, L"w", true);
			r = pFile->Write(*pTempByteBuff);

			pFile->Flush();

			AppLog("-------------------------check2------------------");

			//r = pFile->Read(*pTempByteBuff);

			if(IsFailed(r))
			{
				AppLog("pTempImageByteBuff %s \n", GetErrorMessage(r));
				ShowMessageBox(L"Error", strError);
				return;
			}

			AppLog("-------------------------check3------------------");
			//r = pFile->Write(pTempImageByteBuff);    //버퍼에 씀

			CATCH:
				return;
			//
			File copyFile = filePath;
			BufferedOutputStream out = null;

			try {
				copyFile.createNewFile();
				out = new BufferedOutputStream(new FileOutputStream(copyFile));
				bitmap.compress(CompressFormat.JPEG, 100, out);
				out.flush();
				out.close();
				*/

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
