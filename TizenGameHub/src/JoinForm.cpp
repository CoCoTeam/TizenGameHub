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



JoinForm::JoinForm()
	: __pCroppedBmp(null), count(0), simg_url(null)
{}

JoinForm::~JoinForm() {}

bool JoinForm::Initialize(void)
{
	result r = Construct(IDL_FORM_JOIN);
	TryReturn(r == E_SUCCESS, false, "Failed to construct form");

	return true;
}

result JoinForm::OnInitializing(void)
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
	pGalleryProfile->AddTouchEventListener(*this);

/*	Gallery *pGalleryProfile;
	pGalleryProfile = static_cast< Gallery* >(GetControl(IDC_JOIN_GALLERY_PROFILE));
	pGalleryProfile->SetItemProvider(*this);
	pGalleryProfile->AddTouchEventListener(*this);*/



/*	String path = L"http://54.238.195.222:80/players/"+ GHSharedAuthData::getSharedInstance().getPlayerId()  +"/image";
	this->RequestImage(path,500,500,5000);*/

	//AppLog("INITIAL");

	//다운로드 받은 이미지 경로를 통해 사진을 설정함

	/*	String user_image_path = Environment::GetMediaPath() + L"Downloads/profile.jpg";
	AppLogDebug("USER_IMAGE --> %S", user_image_path.GetPointer());

	Image img;
	img.Construct();
	__pCroppedBmp = img.DecodeN(user_image_path, BITMAP_PIXEL_FORMAT_ARGB8888);*/

	//simg_url = new String();

	return r;
}

result
JoinForm::OnTerminating(void)
{
	result r = E_SUCCESS;
	return r;
}

// Request the image and add the image pointer to the list
void JoinForm::RequestImage(const String& path,int width, int height,int timeout)
{
	Image* pImage = new Image();
	pImage->Construct();

	// Set a URL
	Uri uri;
	RequestId reqId;

	uri.SetUri(path);

	//서버에 보내기
	pImage->DecodeUrl(uri, BITMAP_PIXEL_FORMAT_RGB565, width, height, reqId, *this, timeout);
}

// Receive the image and call the delete timer
void
JoinForm::OnImageDecodeUrlReceived(RequestId reqId, Tizen::Graphics::Bitmap *pBitmap, result r, const Tizen::Base::String errorCode, const Tizen::Base::String errorMessage)
{
	AppLog("OnImageDecodeUrlReceived");
	AppLog("reqId : %d",reqId);
	if(IsFailed(r))
	{
		AppLog("Request failed: errorCode(%ls) errorMessage(%ls)", errorCode.GetPointer(), errorMessage.GetPointer());
	}
	else
	{
		__pCroppedBmp = pBitmap;


		AppLog("Request SUCCESS");

		pGalleryProfile = static_cast< Gallery* >(GetControl(IDC_JOIN_GALLERY_PROFILE));
		pGalleryProfile->SetItemProvider(*this);
		pGalleryProfile->AddTouchEventListener(*this);

		pGalleryProfile->RefreshGallery(0,GALLERY_REFRESH_TYPE_ITEM_MODIFY);

		//pGalleryProfile->RefreshGallery(0,GALLERY_REFRESH_TYPE_ITEM_MODIFY);

		AppLog("RefreshGallery add");
	}
}

void
JoinForm::DownloadStart()
{
	 String url =L"http://54.238.195.222:80/players/pkeykichul/image";

	// DownloadRequest request(url);
	// DownloadRequest* requestpath = new DownloadRequest();
	// requestpath->DownloadRequest(url, Environment::GetMediaPath());


	 //파일에 있는 목록 삭제하고 저장!! profile_1, profile_2 이런식으로 저장되기 때문..
	 File file;
	 file.Remove(Environment::GetDefaultDownloadPath() + "profile.jpg");

	 DownloadRequest request(url);
	 request.SetFileName("profile");

	 DownloadManager* pManager = DownloadManager::GetInstance();

	 pManager->SetDownloadListener(this);
	 pManager->Start(request,__requestId);
}

void
JoinForm::OnActionPerformed(const Tizen::Ui::Control& source, int actionId)
{
	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);

	switch(actionId)
	{
	case IDA_BUTTON_JOIN:
/*		if( !(isPlayerJoin->ToBool()) )	// (수정 시퀀스면) 뒤로
		{
			pSceneManager->GoBackward(BackwardSceneTransition(SCENE_TRANSITION_ANIMATION_TYPE_DEPTH_OUT));
		}
		else
		{*/
			doJoin();
	/*	}*/
		break;
	case IDA_BUTTON_CANCEL:
		pSceneManager->GoBackward(BackwardSceneTransition(SCENE_TRANSITION_ANIMATION_TYPE_DEPTH_OUT));

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


	/*if(strEmail == null || strPw == null || strPwconfirm == null || strName == null)
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
			String url(L"/players/" + player_id );


			Tizen::Base::Object* tmpobj = static_cast<Tizen::Base::Object*>(&simg_url);

			Tizen::Base::Collection::HashMap* __pMap  = new (std::nothrow) Tizen::Base::Collection::HashMap();
			__pMap->Construct();

			__pMap->Add(new String("pwd"), new String(strPw));
			__pMap->Add(new String("name"), new String(strName));
			__pMap->Add(new String("img_url"), tmpobj);


			//__pMap->Add(new String("img_url"),  new String(simg_url));

			AppLog("simg_url put : %S",simg_url.GetPointer());

			httpPost->RequestHttpPutTran(this, url, __pMap);
		}
	}*/


	// 가입 시퀀스

	if( isPlayerJoin->ToBool() )
	{
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
				GHhttpClient* httpPost = new GHhttpClient();

				Tizen::Base::Collection::HashMap* __pMap = new (std::nothrow) Tizen::Base::Collection::HashMap();
				__pMap->Construct();

				__pMap->Add(new String("email"), new String(strEmail));
				__pMap->Add(new String("pwd"), new String(strPw));
				__pMap->Add(new String("name"), new String(strName));

				//post 함수 호출
				httpPost->RequestHttpPostTran(this, L"/players", __pMap);

			}
	}

	// 수정 시퀀스
	else
	{
			GHhttpClient* httpPost = new GHhttpClient();
			String player_id(GHSharedAuthData::getSharedInstance().getPlayerId());
			String url(L"/players/" + player_id );


			Tizen::Base::Object* tmpobj = static_cast<Tizen::Base::Object*>(&simg_url);

			Tizen::Base::Collection::HashMap* __pMap  = new (std::nothrow) Tizen::Base::Collection::HashMap();
			__pMap->Construct();

			__pMap->Add(new String("pwd"), new String(strPw));
			__pMap->Add(new String("name"), new String(strName));
			__pMap->Add(new String("img_url"), tmpobj);


			//__pMap->Add(new String("img_url"),  new String(simg_url));

			AppLog("simg_url put : %S",simg_url.GetPointer());

			httpPost->RequestHttpPutTran(this, url, __pMap);
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
				GHAppRegistry appReg;
				String strEmail;

				appReg.get(appReg.email, strEmail);

				pButtonJoin->SetText( "Edit" );

				pTextEmail->SetText(strEmail);
				pTextEmail->SetEnabled(false);

				String path = L"http://54.238.195.222:80/players/"+ GHSharedAuthData::getSharedInstance().getPlayerId()  +"/image";
				this->RequestImage(path, 500, 500, 5000);

				/*if(pGalleryProfile)
				{
					pGalleryProfile->RefreshGallery(0, GALLERY_REFRESH_TYPE_ITEM_MODIFY);
					pGalleryProfile->SetItemProvider(*this);
				}*/

				pGalleryProfile->SetShowState(true);
				//!! pGalleryProfile->Set이미지
			}
			else
			{
				pGalleryProfile->SetShowState(false);
			}

		}
		pArgs->RemoveAll(true);
		delete pArgs;
	}

}

// IGalleryItemProvider implementation  ( 이걸 해야 Galley 에 추가할 수 있음 ... !! )
GalleryItem* JoinForm::CreateItem(int index)
{
    // Gets an instance of Bitmap
   // AppResource* pAppResource = Application::GetInstance()->GetAppResource();
   // Bitmap* pImageTemp = pAppResource->GetBitmapN(L"Image.jpg");

    // Creates an instance of GalleryItem and registers the bitmap to the gallery item

	//AppLog("========================test1 ");

	GalleryItem* pGallery = new GalleryItem();

	//AppLog("========================test2");

	pGallery->Construct(*__pCroppedBmp);

	//AppLog("========================test3");

	return pGallery;

    // Deallocates the bitmap
   // delete pImageTemp;
}

bool JoinForm::DeleteItem(int index, GalleryItem *pItem)
{
    delete pItem;
    return true;
}

int JoinForm::GetItemCount(void)
{
    return 1;
}


void JoinForm::OnSceneDeactivated(const Tizen::Ui::Scenes::SceneId& currentSceneId,
										   const Tizen::Ui::Scenes::SceneId& nextSceneId)
{
	// TODO: Deactivate your scene here.

}

void JoinForm::OnTransactionReadyToRead(String apiCode, String statusCode,IJsonValue* data)
{
	if(apiCode.Equals(PLAYER_JOIN))
	{
		MessageBox msgBox;
		int modalResult;

		SceneManager* pSceneManager = SceneManager::GetInstance();
		AppAssert(pSceneManager);

		if(statusCode ==  "0")	// (가입 실패)
		{
			AppLog("PLAYER_JOIN fail");
			msgBox.Construct(L"Join", L"Join fail", MSGBOX_STYLE_OK);
			msgBox.ShowAndWait(modalResult);
		}
		else if(statusCode == "1")	// (가입 성공)
		{
			AppLog("PLAYER_JOIN success");
			pSceneManager->GoBackward(BackwardSceneTransition(SCENE_TRANSITION_ANIMATION_TYPE_DEPTH_OUT));
		}
		else if(statusCode == "2")  // (가입 중복)
		{
			msgBox.Construct(L"Join", L"Join 중복", MSGBOX_STYLE_OK);
			msgBox.ShowAndWait(modalResult);
		}
	}
	else if(apiCode.Equals(IMAGE_UPLOAD))
	{
		if(statusCode ==  "0")	// (이미지 업로드 실패)
		{
			AppLog("IMAGE_UPLOAD fail");
		}
		else if(statusCode == "1")	// (이미지 업로드 성공)
		{
			AppLog("IMAGE_UPLOAD success");

			JsonObject *pJsonOject 	= static_cast<JsonObject*>(data);

			String* img_url	= new String(L"img_url");
			simg_url= getStringByKey(pJsonOject, img_url);

			AppLog("simg_url : %S", simg_url.GetPointer());
		}
	}
	else if(apiCode.Equals(PLAYER_MODIFY))
	{
		if(statusCode ==  "0")	// (정보 수정 실패)
		{
			AppLog("PLAYER_MODIFY fail");
		}
		else if(statusCode == "1")	// (정보 수정 성공)
		{
			AppLog("PLAYER_MODIFY success");

			//서버에서 image 다운로드
			DownloadStart();
		}
	}

	 AppLog("1");



}

void JoinForm::OnTransactionCompleted(Tizen::Net::Http::HttpSession& httpSession, Tizen::Net::Http::HttpTransaction& httpTransaction)
{
	AppLog("success");

	Tizen::Net::Http::HttpMultipartEntity* pMultipartEntity = static_cast< Tizen::Net::Http::HttpMultipartEntity* >(httpTransaction.GetUserObject());

/*	 ByteBuffer* pReceiveImageByteBuff = new (std::nothrow) ByteBuffer;
	 pReceiveImageByteBuff = pMultipartEntity->GetNextDataN(100);

	 AppLog("pReceiveImageByteBuff : %S",pReceiveImageByteBuff);*/

/*	Tizen::Net::Http::HttpResponse* pHttpResponse = httpTransaction.GetResponse();
	ByteBuffer* pBuffer = pHttpResponse->ReadBodyN();
	String htmlContent((char *)(pBuffer->GetPointer()));*/

	//AppLog("%S",htmlContent);

	 if (pMultipartEntity)
	      delete pMultipartEntity;

	 delete &httpTransaction;

}
//CROP IMAGE
void JoinForm::OnUserEventReceivedN(RequestId requestId, Tizen::Base::Collection::IList* pArgs)
{
	AppLog("Cropping complete");
	if(requestId == CROPPING_COMPLETE)
	{
		AppLogDebug("test1");
/*
		if(__pCroppedBmp)
		{
			AppLogDebug("__pCroppedBmp !!");

			delete __pCroppedBmp;
			__pCroppedBmp = null;

			AppLogDebug("__pCroppedBmp null");
		}
*/

		AppLogDebug("test2");

		Image img;
		img.Construct();

		AppLogDebug("test3");

		//Load the appropriate Cropped bitmap
		if(File::IsFileExist(USER_CROPPED_FILE_PATH))
			__pCroppedBmp = img.DecodeN(USER_CROPPED_FILE_PATH, BITMAP_PIXEL_FORMAT_ARGB8888);
		else
			__pCroppedBmp = img.DecodeN(DEFAULT_CROPPED_FILE_PATH, BITMAP_PIXEL_FORMAT_RGB565);

		AppLogDebug("test3");


		RequestRedraw();

		AppLogDebug("test4");

		pGalleryProfile->SetItemProvider(*this);
		pGalleryProfile->RefreshGallery(0,GALLERY_REFRESH_TYPE_ITEM_MODIFY);

		AppLogDebug("------------------crop image set----------------");
		storeImageInternal(__pCroppedBmp);
		//saveImage();
	}
}

result JoinForm::OnDraw()
{
	AppLogDebug("---------------------Redraw-----------------");


	//pGalleryProfile->RefreshGallery(0,GALLERY_REFRESH_TYPE_ITEM_MODIFY);

	AppLogDebug("test5");

	//이미지 전환
/*	GalleryItem* pGallery = new GalleryItem();
    pGallery->Construct(*__pCroppedBmp);*/


    count = 0; // 터치 이벤트 재초기화

	return E_SUCCESS;
}

Bitmap* JoinForm::CreateBitmapFromByteBufferN(ByteBuffer* pBuffer, const int& width, const int& height)
{
	Dimension dim(width, height);
	Bitmap* pBmp = new (std::nothrow) Bitmap;
	TryReturn(pBmp != null, pBmp,"E_OUT_OF_MEMORY Bitmap creation failed");
	result r = pBmp->Construct(*pBuffer, dim, Tizen::Graphics::BITMAP_PIXEL_FORMAT_ARGB8888);
	TryReturn(r == E_SUCCESS, pBmp,"[%s] Bitmap->Construct", GetErrorMessage(r));
	return pBmp;
}

void JoinForm::storeImageInternal(Bitmap *bitmap)
{
	result r ;

	///////////////////////////////////////////////////////////////// 버퍼 ///////////////////////////////////////////////////////////////////
	//String filePath(Environment::GetMediaPath() + L"TempPicture");
	//String imagePath = CreateUniqueFileName();

	File file;

	int width = 0, height = 0;
	int readCnt;

	ByteBuffer* pImageByteBuff = null;
	pImageByteBuff = new (std::nothrow) ByteBuffer;

	//r = ImageBuffer::GetImageInfo(*filePath, imgFormat, originalWidth, originalHeight);

	// Create an Image instance.
	Image img;
	img.Construct();

	// Get the image's size.
	 width = __pCroppedBmp->GetWidth();
	 height = __pCroppedBmp->GetHeight();

	//이미지를   바이트로 변환
	//pImageByteBuff = img.DecodeToBufferN(imagePath, BITMAP_PIXEL_FORMAT_ARGB8888, width, height);
	 pImageByteBuff = img.EncodeToBufferN(*__pCroppedBmp, IMG_FORMAT_JPG);

	//파일 생성
	r = file.Construct(USER_CROPPED_FILE_PATH, "w+");

	//파일에 바이트 쓰기
	r = file.Write(*pImageByteBuff);
	readCnt = file.Read(*pImageByteBuff);

	AppLog("Successed.\n");

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////// 바이트를 다시 이미지로 변환
	__ptempBitmap = CreateBitmapFromByteBufferN(pImageByteBuff, width, height);

	//서버에 업로드 요청하기
	GHhttpClient* httpPost = new GHhttpClient();
	httpPost->RequestImageUpload(this, this, L"/players/imageupload", pImageByteBuff);
}

String JoinForm::CreateUniqueFileName( void )
{
	AppLog("-------------------------check3------------------");

	// System Current time is always unique, so the same has been used to create a unique name
	DateTime currentTime ;
	SystemTime::GetCurrentTime (WALL_TIME, currentTime);
	String player_id(GHSharedAuthData::getSharedInstance().getPlayerId());
	//String imagePath = Environment::GetMediaPath() + L"TempPicture/";
	//String imagePath = Environment::GetMediaPath() + L"Others/" + player_id + L"_";
	//String imagePath = Tizen::App::App::GetInstance()->GetAppRootPath() +L"Images/";


	String imagePath = Tizen::App::App::GetInstance()->GetAppRootPath();

	AppLog("%S", imagePath.GetPointer());

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

	AppLog("%S", imagePath.GetPointer());
	//AppLog("%S", imagePath2.GetPointer());

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

// IHttpProgressEventListener
//void JoinForm::OnHttpDownloadInProgress(Tizen::Net::Http::HttpSession& httpSession,Tizen::Net::Http::HttpTransaction& httpTransaction, long long currentLength, long long totalLength)
//{
//   AppLog("---Download Current Bytes: %lld, Total Bytes: %ll d---", currentLength, totalLength);
//}
//void JoinForm::OnHttpUploadInProgress(Tizen::Net::Http::HttpSession& httpSession, Tizen::Net::Http::HttpTransaction& httpTransaction, long long currentLength, long long totalLength)
//{
//   AppLog("---Upload Current Bytes: %lld, Total Bytes: %lld---", currentLength, totalLength);
//}
// IDownloadListener
//void JoinForm::OnDownloadInProgress (RequestId reqId, unsigned long long receivedSize, unsigned long long totalSize)
//{
//	 String strMessage =L"";
//	 strMessage.Append((long)receivedSize);
//	 strMessage.Append("/ ");
//	 strMessage.Append((long)totalSize);
//}
//
//void JoinForm::OnDownloadCompleted (RequestId reqId, const Tizen::Base::String &path)
//{
//	AppLogDebug("path -----------------------> %S", path.GetPointer());
//}

void
JoinForm::OnTouchPressed (const Tizen::Ui::Control &source, const Tizen::Graphics::Point &currentPosition, const Tizen::Ui::TouchEventInfo &touchInfo)
{

    if(count < 1)
    {
		AppLogDebug("-----------------------------------------------------------111100000000000");

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

		count++;
    }
}

