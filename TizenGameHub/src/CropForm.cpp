#include <CropForm.h>

using namespace Tizen::App;
using namespace Tizen::Base;
using namespace Tizen::Base::Collection;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Graphics;
using namespace Tizen::Media;
using namespace Tizen::Ui::Scenes;

#define EDIT_HEIGHT 61

CropForm::CropForm(void):__pBitmapOriginal(null)
{
}

CropForm::~CropForm(void)
{
}

bool
CropForm::Initialize(void)
{
	Construct(L"IDF_CROPFORM");
	return true;
}

result
CropForm::OnInitializing(void)
{
	result r = E_SUCCESS;

	Footer *pFooter = GetFooter();
	if(pFooter)
	{
		pFooter->AddActionEventListener(*this);
		SetFormBackEventListener(this);
	}

	AddTouchEventListener(*this);

	//initialize to extreme values
	__x_min = GetClientAreaBounds().width;
	__y_min = GetClientAreaBounds().height;
	__x_max = 0;
	__y_max = 0;
	return r;
}

void
CropForm::OnUserEventReceivedN(RequestId requestId, Tizen::Base::Collection::IList* pArgs)
{
	result r = E_SUCCESS;
	if(requestId == REQUEST_ID_DISPLAYIMAGE)
	{
		HashMap extraData;
		extraData.Construct();
		String typeKey = L"type";
		String typeVal = L"image";
		String selectKey = L"selectionType";
		String selectVal = L"single";
		extraData.Add(&typeKey, &typeVal);
		extraData.Add(&selectKey, &selectVal);

		AppControl* pAc = AppManager::FindAppControlN(L"tizen.filemanager",  L"http://tizen.org/appcontrol/operation/pick");
		if (pAc)
		{
			result r = pAc->Start(null, null, &extraData, this);
			if(r != E_SUCCESS)
				AppLogException("Error launching appcontrol, %s", GetErrorMessage(r));
			delete pAc;
		}
	}
	else if(requestId == REQUEST_ID_DISPLAYWEBIMAGE)
	{
		if(pArgs!= null && pArgs->GetCount()>0)
		{
			Bitmap*  pBitmap = static_cast<Bitmap* >(pArgs->GetAt(0));
			LoadWebImage(pBitmap);
			RequestRedraw();
		}
	}
}

void
CropForm::OnAppControlCompleteResponseReceived(const Tizen::App::AppId& appId,
		const Tizen::Base::String& operationId,
		const Tizen::App::AppCtrlResult appControlResult,
		const Tizen::Base::Collection::IMap* pResultList)
{
	if (appId.Equals(L"tizen.filemanager", true) && operationId.Equals(L"http://tizen.org/appcontrol/operation/pick", true))
	{
		AppCtrlResult selectResult = appControlResult;
		if (selectResult == APP_CTRL_RESULT_SUCCEEDED)
		{
			//Get the file name
			result r ;
			String filename;
			String* pFilePath ;
			pFilePath = (String*)(Tizen::Base::String*)pResultList->GetValue(String(L"path"));
			LoadImage(pFilePath);
		}
		else
		{
			result r;
			Frame *pFrame = Application::GetInstance()->GetAppFrame()->GetFrame();
			Form *pForm = (Form*)pFrame->GetControl(MAIN_FORM_NAME, false);
			if(pForm)
			{
				r = pFrame->SetCurrentForm(*pForm);
				pForm->Draw();
				pForm->Show();
				pFrame->RemoveControl(*this);
			}
		}
	}
}

result
CropForm::OnTerminating(void)
{
	result r = E_SUCCESS;

	if(__pBitmapOriginal)
	{
		delete __pBitmapOriginal;
		__pBitmapOriginal = null;
	}

	return r;
}

void
CropForm::LoadWebImage(Bitmap *bmp)
{
	__Croprectangle.x = __x_min ;
	__Croprectangle.y = __y_min ;
	__Croprectangle.width = __x_max - __x_min;
	__Croprectangle.height = __y_max - __y_min;

	if(__pBitmapOriginal)
		delete __pBitmapOriginal;

	__pBitmapOriginal = new Bitmap();
	__pBitmapOriginal->Construct(*bmp, Rectangle(0, 0, bmp->GetWidth(), bmp->GetHeight()));
}

result
CropForm::OnDraw(void)
{
	Canvas *pCanvas = null;
	pCanvas = GetCanvasN();
	if(!pCanvas)
		return GetLastResult();

	if (__pBitmapOriginal)
	{
		pCanvas->Clear();
		pCanvas->DrawBitmap(GetClientAreaBounds(), *__pBitmapOriginal);

		pCanvas->SetForegroundColor(Color::GetColor(COLOR_ID_BLACK));
		pCanvas->SetLineWidth(5);
		pCanvas->SetLineStyle(LINE_STYLE_SOLID);
		if(__Croprectangle.width > 0)
			pCanvas->DrawRectangle(__Croprectangle);
	}

	delete pCanvas;
	return E_SUCCESS;
}

void
CropForm::OnFormBackRequested (Tizen::Ui::Controls::Form &source)
{

	Frame *pFrame = Application::GetInstance()->GetAppFrame()->GetFrame();
	Form *pForm = (Form*)pFrame->GetControl(MAIN_FORM_NAME, false);
	if(pForm)
	{
		pFrame->SetCurrentForm(*pForm);
		pForm->Draw();
		pForm->Show();
		pFrame->RemoveControl(*this);
	}


/*	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);
	pSceneManager->GoBackward(BackwardSceneTransition(SCENE_TRANSITION_ANIMATION_TYPE_DEPTH_OUT));*/
}


void
CropForm::OnTouchDoublePressed (const Tizen::Ui::Control &source,	const Tizen::Graphics::Point &currentPosition, const Tizen::Ui::TouchEventInfo &touchInfo)
{

}
void
CropForm::OnTouchFocusIn (const Tizen::Ui::Control &source, const Tizen::Graphics::Point &currentPosition, const Tizen::Ui::TouchEventInfo &touchInfo)
{

}
void
CropForm::OnTouchFocusOut (const Tizen::Ui::Control &source, const Tizen::Graphics::Point &currentPosition, const Tizen::Ui::TouchEventInfo &touchInfo)
{

}
void
CropForm::OnTouchLongPressed (const Tizen::Ui::Control &source, const Tizen::Graphics::Point &currentPosition, const Tizen::Ui::TouchEventInfo &touchInfo)
{

}

void
CropForm::OnTouchMoved (const Tizen::Ui::Control &source, const Tizen::Graphics::Point &currentPosition, const Tizen::Ui::TouchEventInfo &touchInfo)
{
	GetCordinates(currentPosition);
	RequestRedraw();
}

void
CropForm::OnTouchPressed (const Tizen::Ui::Control &source, const Tizen::Graphics::Point &currentPosition, const Tizen::Ui::TouchEventInfo &touchInfo)
{
	__x_min = currentPosition.x;
	__y_min = currentPosition.y;
	__x_max = currentPosition.x;
	__y_max = currentPosition.x;

	__Croprectangle.x = currentPosition.x ;
	__Croprectangle.y = currentPosition.y ;
	__Croprectangle.width = __x_max -__x_min;
	__Croprectangle.height = __y_max -__y_min;
	RequestRedraw();
}

void
CropForm::OnTouchReleased (const Tizen::Ui::Control &source, const Tizen::Graphics::Point &currentPosition, const Tizen::Ui::TouchEventInfo &touchInfo)
{
	GetCordinates(currentPosition);
	RequestRedraw();
}

void
CropForm::LoadImage(String *filename)
{
	__Croprectangle.x = __x_min ;
	__Croprectangle.y = __y_min ;
	__Croprectangle.width = __x_max-__x_min;
	__Croprectangle.height = __y_max-__y_min;

	int width = GetClientAreaBounds().width;
	int height = GetClientAreaBounds().height;

	Image img;
	img.Construct();

	__pBitmapOriginal = img.DecodeN(*filename, BITMAP_PIXEL_FORMAT_ARGB8888 , width, height);
	__pBitmapOriginal->Scale(Dimension(width, height));
	RequestRedraw();
}

void
CropForm::GetCordinates(Point pnt)
{
	// to take the cordinates of rectangle region over region of interest
	if(pnt.x < __x_min)
		__x_min = pnt.x;
	if(pnt.x > __x_max)
		__x_max = pnt.x;
	if(pnt.y < __y_min)
		__y_min = pnt.y;
	if(pnt.y > __y_max)
		__y_max = pnt.y;

	__Croprectangle.x = __x_min ;
	__Croprectangle.y = __y_min ;
	__Croprectangle.width = __x_max-__x_min;
	__Croprectangle.height = __y_max-__y_min;
}

void
CropForm::OnActionPerformed(const Tizen::Ui::Control& source, int actionId)
{
	if(actionId == ID_FOOTERITEMCROP)
	{

		__Croprectangle.x = __x_min ;
		__Croprectangle.y = __y_min ;
		__Croprectangle.width = __x_max - __x_min;
		__Croprectangle.height = __y_max - __y_min;

		if ((__Croprectangle.width <= 0) || (__Croprectangle.height <= 0))
		{
			MessageBox messageBox;
			messageBox.Construct(L"Noting to crop", L"Please select region using finger to crop.", MSGBOX_STYLE_OK, 3000);
			int modalResult = 0;
			messageBox.ShowAndWait(modalResult);
			return;
		}

		Bitmap *pBitmapCroped = new Bitmap();
		pBitmapCroped->Construct(*__pBitmapOriginal,__Croprectangle);
		Image img;
		result r = img.Construct();

		if(!IsFailed(r))
		{
			img.EncodeToFile(*pBitmapCroped, IMG_FORMAT_JPG, USER_CROPPED_FILE_PATH, true);

			AppLogDebug("Save_location : %S", USER_CROPPED_FILE_PATH.GetPointer());

			Frame *pFrame = Application::GetInstance()->GetAppFrame()->GetFrame();
			Form *pForm = (Form*)pFrame->GetControl(MAIN_FORM_NAME, false);
			if(pForm)
			{
				pFrame->SetCurrentForm(*pForm);
				pForm->SendUserEvent(CROPPING_COMPLETE, null);
				pForm->Draw();
				pForm->Show();
				pFrame->RemoveControl(*this);
			}
		}

		delete pBitmapCroped;
	}
}
