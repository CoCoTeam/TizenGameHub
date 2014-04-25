#include "Form1.h"
#include <FApp.h>
#include <FGraphics.h>


using namespace Tizen::Base;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;
using namespace Tizen::App;
using namespace Tizen::System;

using namespace Tizen::App;

using namespace Tizen::Graphics;
using namespace Tizen::Media;

/**
 * 1. Whenever the button is pressed, a new thread and a new label is constructed.
 * 2. If the thread increases the value by +1 and sends it to the Form, the label is increased by 1.
 * 3. If the value of the label reaches 100, the thread is terminated.
 */
static const int ID_FORMAT_RECORD = 300;

//ArrayList* Form1::__pWatchTextList = null;


Form1::Form1(void)
:__threadid(0),btn_num(0),count(0),__score(0),__startTick(0),__pList(null),__pWatchTextList(null)
{

	flag_clicked = false;   // 한번만 클릭 되도록

}

Form1::~Form1(void)
{
}
bool
Form1::Initialize()
{
	// Construct an XML form
	Construct(L"GameMain");


	return true;
}

result
Form1::OnInitializing(void)
{
	result r = E_SUCCESS;

	// TODO: Add your initialization code here
	SetFormBackEventListener(this);

	// Get a button via the resource ID
	__pButtonOk = static_cast<Button *>(GetControl(L"IDC_BUTTON_OK"));
	__pButtonLank = static_cast<Button *>(GetControl(L"IDC_BUTTON_LANK"));
	__pLabel = static_cast<Label *>(GetControl(L"IDC_LABEL1"));
	__pLabel2 = static_cast<Label *>(GetControl(L"IDC_LABEL2"));

	if (__pButtonOk != null)
	{
		__pButtonOk->SetActionId(ID_BUTTON_OK);
		__pButtonOk->AddActionEventListener(*this);
	}
	if (__pButtonLank != null)
	{
		__pButtonLank->SetActionId(ID_BUTTON_LANK);
		__pButtonLank->AddActionEventListener(*this);
	}

	AppResource *pAppResource = Application::GetInstance()->GetAppResource();

	// Create Bitmap
	if (pAppResource != null)
	{
		//__pBitmapResources[0] = pAppResource->GetBitmapN(L"pumpkin.png", BITMAP_PIXEL_FORMAT_ARGB8888);

		__pBitmapResources[0] = pAppResource->GetBitmapN(L"clown.png", BITMAP_PIXEL_FORMAT_ARGB8888);
		__pBitmapResources[1] = pAppResource->GetBitmapN(L"frankenstein.png", BITMAP_PIXEL_FORMAT_ARGB8888);
		__pBitmapResources[2] = pAppResource->GetBitmapN(L"jack.png", BITMAP_PIXEL_FORMAT_ARGB8888);
		__pBitmapResources[3] = pAppResource->GetBitmapN(L"bird.png", BITMAP_PIXEL_FORMAT_ARGB8888);
		__pBitmapResources[4] = pAppResource->GetBitmapN(L"mouse.png", BITMAP_PIXEL_FORMAT_ARGB8888);
		__pBitmapResources[5] = pAppResource->GetBitmapN(L"posh.png", BITMAP_PIXEL_FORMAT_ARGB8888);
		__pBitmapResources[6] = pAppResource->GetBitmapN(L"queen.png", BITMAP_PIXEL_FORMAT_ARGB8888);
		__pBitmapResources[7] = pAppResource->GetBitmapN(L"scream.png", BITMAP_PIXEL_FORMAT_ARGB8888);
		__pBitmapResources[8] = pAppResource->GetBitmapN(L"vader.png", BITMAP_PIXEL_FORMAT_ARGB8888);
		__pBitmapResources[9] = pAppResource->GetBitmapN(L"pumpkin.png", BITMAP_PIXEL_FORMAT_ARGB8888);
	}



	__pTimer = new (std::nothrow) Timer();
	__pTimer->Construct(*this);


	pLanking->setList_boolean(true);
	// Create WatchTextList

	__pWatchTextList = new (std::nothrow) ArrayList();
	__pWatchTextList->Construct();

	// 팝업 미리 생성
	CreatePopup();


	return r;
}

result
Form1::OnTerminating(void)
{
	result r = E_SUCCESS;


	__manager.DeleteAll();

	return r;
}


void
Form1::OnActionPerformed(const Tizen::Ui::Control& source, int actionId)
{

	switch(actionId)
	{
	case ID_BUTTON_OK:
		{
			Integer num(__score);
			__pLabel->SetText(num.ToString());

			for(int i= 0 ; i < 9 ; i++){
					pButton[i] = static_cast< Button* >(GetControl(button_l[i]));
					if (pButton[i] != null)
					{
						pButton[i]->SetActionId(button_const[i]);
						pButton[i]->AddActionEventListener(*this);
						//pButton[i]->SetNormalBackgroundBitmap(*__pBitmapResources[9]);
						pButton[i]->SetColor(ButtonStatus(0),Color::GetColor(COLOR_ID_BLACK));
					}
			}

			//첫 시작시
			if(count == 0)
			{
				pThread->Construct(this,__threadid);
				//__manager.AddThread(pThread);
				pThread->Start();
			}

			//다음 시작시
			else
			{
				__score = 0;
				pThread->setlive(true);
				pThread->Start();
			}

			count ++;
			__pButtonOk->SetEnabled(false);
			__pButtonLank->SetEnabled(false);

			long long tick ;
			Tizen::Base::TimeSpan  uptime(0);
			result r = Tizen::System::SystemTime::GetUptime(uptime);
			if (IsFailed(r))
			{
				AppLog("System uptime not available\n");
				return ;
			}
			tick = uptime.GetTicks();
			TimeSpan span = static_cast<long>(tick);

			__startTick = uptime.GetTicks();
			__pTimer->Start(10);

			RequestRedraw();

		}
		break;
	case ID_BUTTON_1:
		//if(pButton[0]->SetDisabledBitmap() == __pBitmapResources[1])
		//if(pBitmapResources[1] != null)

		if(pButton[0]->GetColor(ButtonStatus(0)) == Color::GetColor(COLOR_ID_BLUE) && flag_clicked == false)

		//if(pButton[0]->GetText().CompareTo("1") == 0 && flag_clicked == false)
			{
					//if(pButton[btn_num]->GetColor(ButtonStatus(2)) == Color::GetColor(COLOR_ID_RED))
					{
						__score++;

						flag_clicked = true;

						//AppLogDebug("빨간색");
					}

				}

		//flag_clicked = true;
			break;
	case ID_BUTTON_2:
		//if((pButton[1]->GetText()).CompareTo("1") == 0)
		//if(pButton[1]->GetCapturedBitmapN() == __pBitmapResources[2])
		if(pButton[1]->GetColor(ButtonStatus(0)) == Color::GetColor(COLOR_ID_BLUE)  && flag_clicked == false)
		//if(pButton[1]->GetText().CompareTo("1") == 0 && flag_clicked == false)
		{
					//if(pButton[btn_num]->GetColor(ButtonStatus(2)) == Color::GetColor(COLOR_ID_RED))
					{
						__score++;


						flag_clicked = true;
					    //AppLogDebug("빨간색");
					}

				}


			break;
	case ID_BUTTON_3:
		//if(pButton[2]->GetText().CompareTo("1") == 0)
		//if(pButton[2]->GetCapturedBitmapN() == __pBitmapResources[3])
		if(pButton[2]->GetColor(ButtonStatus(0)) == Color::GetColor(COLOR_ID_BLUE)  && flag_clicked == false)
		//if(pButton[2]->GetText().CompareTo("1") == 0 && flag_clicked == false)
		{
					//if(pButton[btn_num]->GetColor(ButtonStatus(2)) == Color::GetColor(COLOR_ID_RED))
					{
						__score++;

						flag_clicked = true;
						//AppLogDebug("빨간색");
					}

				}

		//flag_clicked = true;
			break;
	case ID_BUTTON_4:
		//if(pButton[3]->GetText().CompareTo("1") == 0)
		//if(pButton[3]->GetCapturedBitmapN() == __pBitmapResources[4])
		if(pButton[3]->GetColor(ButtonStatus(0)) == Color::GetColor(COLOR_ID_BLUE)  && flag_clicked == false)
		//if(pButton[3]->GetText().CompareTo("1") == 0 && flag_clicked == false)
		{
					//if(pButton[btn_num]->GetColor(ButtonStatus(2)) == Color::GetColor(COLOR_ID_RED))
					{
						__score++;

						flag_clicked = true;
						//AppLogDebug("빨간색");
					}
				}
			break;
	case ID_BUTTON_5:
		//if(pButton[4]->GetText().CompareTo("1") == 0)
		//if(pButton[4]->GetCapturedBitmapN() == __pBitmapResources[5])
		if(pButton[4]->GetColor(ButtonStatus(0)) == Color::GetColor(COLOR_ID_BLUE)  && flag_clicked == false)
				{
					//if(pButton[btn_num]->GetColor(ButtonStatus(2)) == Color::GetColor(COLOR_ID_RED))
					{
						__score++;

						flag_clicked = true;
						//AppLogDebug("빨간색");
					}

				}
			break;
	case ID_BUTTON_6:
		//if(pButton[5]->GetText().CompareTo("1") == 0)
		//if(pButton[5]->GetCapturedBitmapN() == __pBitmapResources[6])
		if(pButton[5]->GetColor(ButtonStatus(0)) == Color::GetColor(COLOR_ID_BLUE)  && flag_clicked == false)
				{
					//if(pButton[btn_num]->GetColor(ButtonStatus(2)) == Color::GetColor(COLOR_ID_RED))
					{
						__score++;

						flag_clicked = true;

						//AppLogDebug("빨간색");
					}
				}
			break;
	case ID_BUTTON_7:
		//if(pButton[6]->GetText().CompareTo("1") == 0)
		//if(pButton[6]->GetCapturedBitmapN() == __pBitmapResources[7])
		if(pButton[6]->GetColor(ButtonStatus(0)) == Color::GetColor(COLOR_ID_BLUE)  && flag_clicked == false)
				{
					//if(pButton[btn_num]->GetColor(ButtonStatus(2)) == Color::GetColor(COLOR_ID_RED))
					{
						__score++;

						flag_clicked = true;
						//AppLogDebug("빨간색");
					}
				}
			break;
	case ID_BUTTON_8:
		//if(pButton[7]->GetText().CompareTo("1") == 0)
		//if(pButton[7]->GetCapturedBitmapN() == __pBitmapResources[8])
		if(pButton[7]->GetColor(ButtonStatus(0)) == Color::GetColor(COLOR_ID_BLUE)  && flag_clicked == false)
				{
					//if(pButton[btn_num]->GetColor(ButtonStatus(2)) == Color::GetColor(COLOR_ID_RED))
					{
						__score++;

						flag_clicked = true;
						//AppLogDebug("빨간색");
					}
				}
			break;
	case ID_BUTTON_9:
		//if(pButton[8]->GetText().CompareTo("1") == 0)
		//if(pButton[8]->GetCapturedBitmapN() == __pBitmapResources[9])
		if(pButton[8]->GetColor(ButtonStatus(0)) == Color::GetColor(COLOR_ID_BLUE)  && flag_clicked == false)
				{
					//if(pButton[btn_num]->GetColor(ButtonStatus(2)) == Color::GetColor(COLOR_ID_RED))
					{
						__score++;

						flag_clicked = true;
					}
				}
			break;

	//팝업
	case ID_BUTTON_POPUP_OK:
	{
			HidePopup(__pPopup);
			//재시작
			//__score = 0;
			pThread->setlive(true);
			//pThread->Start();

			__pButtonOk->SetEnabled(true);

			break;
	}


	// cancel to add new todo.
	case ID_BUTTON_POPUP_CANCEL:
	{
			HidePopup(__pPopup);

			//화면 넘어가서 결과(score) 확인하기

			__pButtonOk->SetEnabled(true);


			break;
	}

	case ID_BUTTON_LANK:
	{
			SceneManager* pSceneManager = SceneManager::GetInstance();
			AppAssert(pSceneManager);



			//String __getWatch = __pLabel2->GetText();  //__watchText 를 얻어옴
			//__pWatchTextList->Add(new String(__getWatch.GetPointer()));

			//InsertItem();

/*
			ArrayList* pList = new (std::nothrow) ArrayList;
			AppAssert(pList);
			pList->Construct();
			pList->Add(*(new (std::nothrow) String(userName)));
			pList->Add(*(new (std::nothrow) String(favoriteColor)));
*/

			//__pWatchTextList = new (std::nothrow) ArrayList();
			//AppAssert(__pWatchTextList);
			//__pWatchTextList->Construct();

			/*if(!__pWatchTextList)
			{
				__pWatchTextList->Add(new String("NULL"));
			}
			else
			{*/
				pLanking->setList_boolean(false);
				pSceneManager->GoForward(ForwardSceneTransition(SCENE_Ranking), __pWatchTextList);
			//}

			break;
	}
	default:

			break;
	}
}

result
Form1::OnDraw (void)
{
	result r = E_SUCCESS;

	//AppLog("----읭-----");

	if(pLanking->getList_boolean() == false)
	{
		//AppLog("----No-----");
		__pWatchTextList = new (std::nothrow) ArrayList();

		pLanking->setList_boolean(true);
	}

	return r;

}

//Process with the Data Received by the Thread
void
Form1::OnUserEventReceivedN (RequestId requestId, Tizen::Base::Collection::IList *pArgs)
//Form1::OnUserEventReceivedN (RequestId requestId,int pArgs)
{
	AppLog("OnUserEventReceivedN");

	if(requestId == 100)
	{

/*
		for(int i= 0 ; i < 9 ; i++){
			pButton[i] = static_cast< Button* >(GetControl(button_l[i]));
			if (pButton[i] != null)
			{
				pButton[i]->SetActionId(button_const[i]);
				pButton[i]->AddActionEventListener(*this);
				pButton[i]->SetNormalBackgroundBitmap(*__pBitmapResources[9]);
				//pButton[i]->SetColor(ButtonStatus(0),Color::GetColor(COLOR_ID_BLACK));
			}
		}
*/

		//색깔 깜빡이기
		/*pButton[btn_num]->SetNormalBackgroundBitmap(*__pBitmapResources[btn_num]);
		pButton[btn_num]->SetText("0");
*/
		pButton[btn_num]->SetColor(ButtonStatus(0),Color::GetColor(COLOR_ID_BLACK));
		btn_num = rand() % 9; // 0~8 -> 1~9 까지

		/*pButton[btn_num]->SetNormalBackgroundBitmap(*__pBitmapResources[btn_num]);
		pButton[btn_num]->SetText("1");*/

		pButton[btn_num]->SetColor(ButtonStatus(0),Color::GetColor(COLOR_ID_BLUE));

		flag_clicked = false;

		Integer num(__score);
		__pLabel->SetText(num.ToString());

		//점수 증가하기
		RequestRedraw(true);
	}

	if(__score >= 10)
	{
		pThread->setlive(false);  //pThread->Stop() 호출 안됨

		if(__pPopup)
		{
			ShowPopup(__pPopup);
		}

		__pButtonLank->SetEnabled(true);  // 랭킹 확인*/

		__pTimer->Cancel();  // 타이머 중지하고 리스트에 삽입

		InsertItem();

		__pButtonOk->SetEnabled(true);

	}

	if(pArgs)
	{
		pArgs->RemoveAll(true);
		delete pArgs;
	}
}

void
Form1::SetTimer(void)
{
	long long tick ;

	// Get current tick value
	Tizen::Base::TimeSpan uptime(0);
	result r = Tizen::System::SystemTime::GetUptime(uptime);
	if (IsFailed(r))
	{
		AppLog("System uptime not available\n");
		return ;
	}
	tick = uptime.GetTicks();


	tick -= __startTick;
	TimeSpan span = static_cast<long>(tick);


	String __watchText;
	// Set StopWatch String
	__watchText.Clear();

	if(span.GetMinutes() < 10)
	{
		__watchText.Append("0");
	}
	__watchText.Append(span.GetMinutes());
	__watchText.Append(":");
	if(span.GetSeconds() < 10)
	{
		__watchText.Append("0");
	}
	__watchText.Append(span.GetSeconds());
	__watchText.Append(":");
	if(span.GetMilliseconds() / 10 < 10)
	{
		__watchText.Append("0");
	}
	__watchText.Append(span.GetMilliseconds() / 10);

	__pLabel2->SetText(__watchText);
	__pLabel2->Invalidate(false);
	__pLabel2->Show();

	return;
}


void
Form1::InsertItem(void)
{
	//__pWatchTextList = new (std::nothrow) ArrayList();
	String __getWatch = __pLabel2->GetText();  //__watchText 를 얻어옴

	if (__pWatchTextList)
	{
		//__pWatchTextList->Add(*(new (std::nothrow) String(__watchText)));
		//__pWatchTextList->InsertAt(*(new (std::nothrow) String(__getWatch)), 0);

		AppLog("num : %ls", __getWatch.GetPointer());

		//AppLog("---------------------------------------------");

		int i = __pWatchTextList->GetCount();
		//AppLog("num : %d", i);

		__pWatchTextList->Add(new String(__getWatch.GetPointer()));
		//__pWatchTextList->InsertAt(*(new (std::nothrow) String(__getWatch.GetPointer())), 0);

		//AppLog("!!!!!!!");
	}
}

// create popup
void
Form1::CreatePopup(void) {

    __pPopup = new (std::nothrow) Popup();
	__pPopup->Construct(true, Dimension(600, 450));
	__pPopup->SetTitleText(L"Input to do");

	Rectangle rect;
	rect = __pPopup->GetClientAreaBounds();

	__pEditField = new (std::nothrow) Label();
	__pEditField->Construct(Rectangle(50, 50, 450, 100), L"Continue?");
	__pPopup->AddControl(*__pEditField);

	// create "ok" button
	Button *pButtonOK = new (std::nothrow) Button();
	pButtonOK->Construct(Rectangle(50, 230, 150, 74), L"OK");
	pButtonOK->SetActionId(ID_BUTTON_POPUP_OK);
	pButtonOK->AddActionEventListener(*this);
	__pPopup->AddControl(*pButtonOK);

	// create "cancel" button
	Button *pButtonClose = new (std::nothrow) Button();
	pButtonClose->Construct(Rectangle(350, 230, 150, 74), L"Cancel");
	pButtonClose->SetActionId(ID_BUTTON_POPUP_CANCEL);
	//if(pButtonClose)
	//{
	pButtonClose->AddActionEventListener(*this);
	//}
	__pPopup->AddControl(*pButtonClose);

}

void Form1::ShowPopup(Popup* __pPopup) {
	__pPopup->SetShowState(true);
	__pPopup->Show();
}

void Form1::HidePopup(Popup* __pPopup) {
	__pPopup->SetShowState(false);
	Invalidate(true);
}
//

// timer 작동
void
Form1::OnTimerExpired(Timer&  timer)
{
	SetTimer();

	result r = __pTimer->Start(10);
	if (IsFailed(r))
	{
		AppLog("Timer Start Fail.\n");
		return;
	}
}

void
Form1::OnFormBackRequested(Tizen::Ui::Controls::Form& source)
{
//	AppLog("--------------------8-----------------");
//
//	UiApp* pApp = UiApp::GetInstance();
//	AppAssert(pApp);
//	pApp->Terminate();

	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);
	pSceneManager->GoBackward(BackwardSceneTransition(SCENE_TRANSITION_ANIMATION_TYPE_RIGHT));


}

void
Form1::OnSceneActivatedN(
		const Tizen::Ui::Scenes::SceneId& previousSceneId,
		const Tizen::Ui::Scenes::SceneId& currentSceneId,
		Tizen::Base::Collection::IList* pArgs) {

	// TODO:
	// Add your scene activate code here
}

void
Form1::OnSceneDeactivated(
		const Tizen::Ui::Scenes::SceneId& currentSceneId,
		const Tizen::Ui::Scenes::SceneId& nextSceneId) {


	// TODO:
	// Add your scene deactivate code here
}



