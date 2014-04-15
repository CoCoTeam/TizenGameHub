#ifndef _FORM2_H_
#define _FORM2_H_

#include <FBase.h>
#include <FUi.h>
#include <FGraphics.h>
#include "Struct.h"
#include "DataThread.h"
#include "DataThreadManager.h"
#include "ThreadUI.h"
#include "SceneRegister.h"
#include "Lanking.h"

using namespace Tizen::Ui::Scenes;
using namespace Tizen::Graphics;
using namespace Tizen::Base::Collection;

class Form2: public Tizen::Ui::Controls::Form
		, public Tizen::Ui::IActionEventListener
		, public Tizen::Base::Runtime::ITimerEventListener
		, public Tizen::Ui::Controls::IFormBackEventListener
	 	, public Tizen::Ui::Scenes::ISceneEventListener
{

// Construction
public:
	Form2(void);
	virtual ~Form2(void);
	bool Initialize(void);


// Implementation
protected:
	static const int ID_BUTTON_OK = 301;
	static const int ID_BUTTON_1 = 302;
	static const int ID_BUTTON_2 = 303;
	static const int ID_BUTTON_3 = 304;
	static const int ID_BUTTON_4 = 305;
	static const int ID_BUTTON_5 = 306;
	static const int ID_BUTTON_6 = 307;
	static const int ID_BUTTON_7 = 308;
	static const int ID_BUTTON_8 = 309;
	static const int ID_BUTTON_9 = 3010;
	static const int ID_BUTTON_LANK = 3011;

private:
	int __threadid;
	int btn_num;
	int count;
	bool flag_clicked;

	Tizen::Ui::Controls::Button *__pButtonOk;
	Tizen::Ui::Controls::Button *__pButtonLank;
	Tizen::Ui::Controls::Label *__pLabel;
	Tizen::Ui::Controls::Label *__pLabel2;
	Tizen::Ui::Controls::Button* pButton[9];

	DataThreadManager __manager;
	DataThread* pThread = new DataThread();
	Lanking *pLanking = new Lanking();
	//Tizen::Graphics::Bitmap* __pBitmapResources[15];
	Tizen::Ui::Controls::Popup *__pPopup;
	Tizen::Ui::Controls::Label *__pEditField;
	Tizen::Ui::Controls::ListView* __pList;

	const wchar_t* button_l[9] = {
				L"IDC_BUTTON1", L"IDC_BUTTON2", L"IDC_BUTTON3", L"IDC_BUTTON4", L"IDC_BUTTON5", L"IDC_BUTTON6", L"IDC_BUTTON7", L"IDC_BUTTON8", L"IDC_BUTTON9"
	};

	int button_const[9] = {
			ID_BUTTON_1 , ID_BUTTON_2 , ID_BUTTON_3, ID_BUTTON_4, ID_BUTTON_5, ID_BUTTON_6, ID_BUTTON_7, ID_BUTTON_8, ID_BUTTON_9
	};

public:

	virtual result OnInitializing(void);
	virtual result OnTerminating(void);


	virtual result OnDraw (void);

	virtual void OnActionPerformed(const Tizen::Ui::Control& source, int actionId);

	virtual void OnTimerExpired(Tizen::Base::Runtime::Timer& timer);

	int __score;

	void HidePopup(Tizen::Ui::Controls::Popup* __pPopup);
	void ShowPopup(Tizen::Ui::Controls::Popup* __pPopup);
	void CreatePopup(void);

	void SetTimer(void);

	void InsertItem(void);

	static const int ID_BUTTON_CREATE = 201;
	static const int ID_BUTTON_DONE = 202;
	static const int ID_BUTTON_POPUP_OK = 203;
	static const int ID_BUTTON_POPUP_CANCEL = 204;

	Tizen::Base::Collection::ArrayList* __pWatchTextList;

	//Tizen::Base::String __watchText;
	long long __startTick;
	Tizen::Base::Runtime::Timer* __pTimer;


	virtual void OnFormBackRequested(Tizen::Ui::Controls::Form& source);
	virtual void OnSceneActivatedN(const Tizen::Ui::Scenes::SceneId& previousSceneId,
									   const Tizen::Ui::Scenes::SceneId& currentSceneId, Tizen::Base::Collection::IList* pArgs);
	virtual void OnSceneDeactivated(const Tizen::Ui::Scenes::SceneId& currentSceneId,
										const Tizen::Ui::Scenes::SceneId& nextSceneId);

	//IListViewItemProvider
	/*virtual Tizen::Ui::Controls::ListItemBase* CreateItem(int index, int itemWidth);
	virtual bool DeleteItem(int index, Tizen::Ui::Controls::ListItemBase *pItem, int itemWidth);
	virtual int GetItemCount(void); */


public:
	virtual void OnUserEventReceivedN(RequestId requestId,
			Tizen::Base::Collection::IList *pArgs);
};

#endif	//_FORM1_H_
