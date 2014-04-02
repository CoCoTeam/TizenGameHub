/*
 * LoginForm.cpp
 *
 *  Created on: Mar 25, 2014
 *      Author: Administrator
 */

#include "LoginForm.h"
#include "AppResourceId.h"
#include "TizenGameHubFrame.h"
#include "PrefClass.h"

using namespace Tizen::App;
using namespace Tizen::Ui::Scenes;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Base;
using namespace Tizen::Base::Collection;
using namespace Tizen::Net::Http;
using namespace Tizen::Web::Json;

/*Boolean isLogin = false;*/

LoginForm::LoginForm() {
	// TODO Auto-generated constructor stub

}

LoginForm::~LoginForm() {
	// TODO Auto-generated destructor stub
}

bool
LoginForm::Initialize(void)
{
	result r = Construct(IDL_FORM_LOGIN);
	TryReturn(r == E_SUCCESS, false, "Failed to construct form");

	return true;
}

result
LoginForm::OnInitializing(void)
{
	result r = E_SUCCESS;

	// TODO: Add your initialization code here

	// Setup back event listener
	SetFormBackEventListener(this);

	// Get a button via resource ID
	Button* pButtonLogin = static_cast< Button* >(GetControl(IDC_LOGIN_BUTTON_SIGN));
	if (pButtonLogin != null)
	{
		pButtonLogin->SetActionId(IDA_BUTTON_LOGIN);
		pButtonLogin->AddActionEventListener(*this);
	}
	Button* pButtonJoin = static_cast< Button* >(GetControl(IDC_LOGIN_BUTTON_JOIN));
	if (pButtonJoin != null)
	{
		pButtonJoin->SetActionId(IDA_BUTTON_JOIN);
		pButtonJoin->AddActionEventListener(*this);
	}

	pTextEmail = static_cast< EditField* >(GetControl(IDC_LOGIN_EDITTEXT_EMAIL));
	pTextPw = static_cast< EditField* >(GetControl(IDC_LOGIN_EDITTEXT_PW));

	//Button Test----------------------------
	Button* pButtonTest = static_cast< Button* >(GetControl(IDC_LOGIN_BUTTON_TEST));
	if (pButtonTest != null)
	{
		pButtonTest->SetActionId(IDA_BUTTON_TEST);
		pButtonTest->AddActionEventListener(*this);
	}

	return r;
}

result
LoginForm::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here
	return r;
}

void
LoginForm::OnActionPerformed(const Tizen::Ui::Control& source, int actionId)
{
	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);

	result r = E_SUCCESS;
	MessageBox msgBox;
	int modalResult;

	AppLog("[Login Form] OnActionPerformed(%d)", actionId);

	ArrayList* pList = new (std::nothrow)ArrayList;
	AppAssert(pList);
	pList->Construct();

	switch(actionId)
	{
	case IDA_BUTTON_JOIN:
		pList->Add( new Tizen::Base::Boolean(true) );	// isJoin
		pSceneManager->GoForward(ForwardSceneTransition(SCENE_JOIN, SCENE_TRANSITION_ANIMATION_TYPE_DEPTH_IN), pList);
		break;
	case IDA_BUTTON_LOGIN:
		//!! do Login
		doLogin();

		break;

	// API TEST
	case IDA_BUTTON_TEST:
		//---------------------------------------------------------
		GHAchievementController* controller = new GHAchievementController();
		//controller->loadAchievements(this);
		//controller->revealAchievement("4");
		//controller->completeAchievement("4");
		controller->increaseAchievement("4");
		break;
	}
}

// API TEST
/*
void LoginForm::doAchievementFinished(GHAchievement* achievementArray) {

}
*/

void LoginForm::OnFormBackRequested(Tizen::Ui::Controls::Form& source)
{
	UiApp* pApp = UiApp::GetInstance();
	AppAssert(pApp);
	pApp->Terminate();
}

result LoginForm::doLogin()
{
	result r = E_SUCCESS;

	//PrefClass pref;
	String strEmail;
	String strPw;
	MessageBox msgBox;
	int modalResult;

	/*if(pref.email != NULL || pref.pwd != NULL)
	{
		pref.get(pref.email, strEmail);
		pref.get(pref.pwd, strPw);

		AppLog("AppRegistry Name value1 [%ls]", strEmail.GetPointer());
	}
	else
	{*/
	strEmail = pTextEmail->GetText();
	strPw = pTextPw->GetText();

		//pref 클래스에 저장( 처음 로그인 후 )
		/*pref.put(pref.email, pTextEmail->GetText());
		pref.put(pref.pwd, pTextPw->GetText());

		AppLog("AppRegistry Name value2 [%ls]", strEmail.GetPointer());
	}*/


	if(strEmail == null && strPw == null)
	{
		msgBox.Construct(L"Login", L"이메일과 패스워드를 입력해주세요.", MSGBOX_STYLE_OK);
		msgBox.ShowAndWait(modalResult);
	}
	else if(strEmail == null)
	{
		msgBox.Construct(L"Login", L"이메일을 입력해주세요.", MSGBOX_STYLE_OK);
		msgBox.ShowAndWait(modalResult);
	}
	else if(strPw == null)
	{
		msgBox.Construct(L"Login", L"패스워드를 입력해주세요.", MSGBOX_STYLE_OK);
		msgBox.ShowAndWait(modalResult);
	}
	else
	{
		GHhttpClient* httpPost = new GHhttpClient();

		Tizen::Base::Collection::HashMap* __pMap = new (std::nothrow) Tizen::Base::Collection::HashMap();
		__pMap->Construct();
		__pMap->Add(new String("email"), new String(strEmail));
		__pMap->Add(new String("pwd"), new String(strPw));

		//post 함수 호출
		httpPost->RequestHttpPostTran(this, L"/players/login", __pMap);
	}
	return r;
}

void LoginForm::OnTransactionReadyToRead(Tizen::Web::Json::IJsonValue* data)
{
	JsonObject* pJsonObj = static_cast<JsonObject*>(data);

	// reveal TEST /////////////////////////////////////////////////////////
	//JsonArray* pJsonArray = static_cast<JsonArray*>(data);
	String* pStrFNKey      = new String(L"statusCode");
	IJsonValue* pObjValue = null;
	pJsonObj->GetValue(pStrFNKey, pObjValue);
	JsonString* pJsonStr = static_cast<JsonString*>(pObjValue);
	AppLogDebug("value : %S", pJsonStr->GetPointer());

	//JsonNumber* pJsonStr = static_cast<JsonNumber*>(pObjValue);
	//AppLogDebug("value : %d", pJsonStr->ToInt());
	///////////////////////////////////////////////////////////////////
	//형변환
	String zString(pJsonStr->GetPointer());


	MessageBox msgBox;
	int modalResult;

	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);

	ArrayList* pList = new (std::nothrow)ArrayList;
	AppAssert(pList);
	pList->Construct();

	if(zString !=  "0")	// (로그인 성공 시) 로그인, 개인페이지로 이동
	{
		AppLog("success");

		pList->Add( new Tizen::Base::String("1001") );	// playerId
		pList->Add( new Tizen::Base::Boolean(true) );	// isLocalPlayer
		pList->Add( new Tizen::Base::Boolean(false) );	// isFriend
		pSceneManager->GoForward(ForwardSceneTransition(SCENE_PLAYER, SCENE_TRANSITION_ANIMATION_TYPE_RIGHT, SCENE_HISTORY_OPTION_NO_HISTORY), pList);
	}
	else		// (로그인 실패 시) 로그인 실패 팝업
	{
		AppLog("fail");

		msgBox.Construct(L"Login", L"LOGIN fail", MSGBOX_STYLE_OK);
		msgBox.ShowAndWait(modalResult);
	}

	/*if(pJsonStr->GetPointer() != null )
	{
			isLogin = true;
			AppLog("success!!");
	}
	else
	{
			isLogin = false;
			AppLog("fail!!");
	}*/
}



// HTTP 통신 Listener -------------------------------------------------------------------------------------------------------
/*
// Request 후 Response 를 받았을 때 처리
void LoginForm::OnTransactionReadyToRead(HttpSession& httpSession, HttpTransaction& httpTransaction, int availableBodyLen)
{

	// 현재는 response data를 받아서 화면에 뿌리도록 함.

	AppLog("OnTransactionReadyToRead");

	HttpResponse* pHttpResponse = httpTransaction.GetResponse();
	if (pHttpResponse->GetHttpStatusCode() == HTTP_STATUS_OK)
	{
		HttpHeader* pHttpHeader = pHttpResponse->GetHeader();
		if (pHttpHeader != null)
		{

			String* tempHeaderString = pHttpHeader->GetRawHeaderN();

			// 응답받은 데이터를 버퍼에 가져온다.
			ByteBuffer* pBuffer = pHttpResponse->ReadBodyN();

			AppLogDebug("[HTTP] response body size : %d " , availableBodyLen );

			// 버퍼의 데이터를 string으로 추출.
			byte* tempBody = new byte[availableBodyLen+1];
			pBuffer->GetArray(tempBody, 0, availableBodyLen);
			tempBody[availableBodyLen] = '\0';

			AppLogDebug("[HTTP] response data : %s", (char *)tempBody);

			if(tempBody !=  )
			{
				isLogin = true;

				AppLog("success!!");
			}
			else
			{
				isLogin = false;

				AppLog("fail!!");
			}


			//////////////////////////////////////////////////////////////////
			// 실제로는 리턴값을 상황에 따라 가공해서 넘겨준다.//////////////////////
//			if(tmpeBody->header == "updateLeaderboardScore") {
//				currentListener->doLeaderboardScoreUpdateFineshed();
//			}
//			else if(tmpeBody->header == "loadLeaderboardRank") {
//				currentListener->fdfdf();
//			}
			//////////////////////////////////////////////////////////////////
			//////////////////////////////////////////////////////////////////

			delete tempHeaderString;
			delete pBuffer;
		}
	}
}*/

