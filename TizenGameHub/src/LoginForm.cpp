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
#include "GHPlayer/GHPlayerController.h"


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

	//For test(Default Id/Pw)-------------------------------
	pTextEmail->SetText(L"kichul");
	pTextPw->SetText(L"kichulbabo");
	//------------------------------------------------------

	//Button Test----------------------------
	Button* pButtonTest = static_cast< Button* >(GetControl(IDC_LOGIN_BUTTON_TEST));
	if (pButtonTest != null)
	{
		pButtonTest->SetActionId(IDA_BUTTON_TEST);
		pButtonTest->AddActionEventListener(*this);
		pButtonTest->SetText("LoginForm");
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
		pList->Add( new Tizen::Base::Integer(1) );	// isJoin
		pSceneManager->GoForward(ForwardSceneTransition(SCENE_JOIN, SCENE_TRANSITION_ANIMATION_TYPE_DEPTH_IN), pList);
		break;
	case IDA_BUTTON_LOGIN:
		//!! do Login
		doLogin();

		break;

	// API TEST
	case IDA_BUTTON_TEST:
		//---------------------------------------------------------

		//GHPlayerController* controller = new GHPlayerController();
		//controller->playerLogin("S","W");
		//controller->getPlayerData("pkeyS");

		//GHAchievementController* controller = new GHAchievementController();
	 	//controller->loadAchievements(this);
		//controller->revealAchievement("4", this);
		//controller->completeAchievement("4");
		//controller->increaseAchievement("4");

		///GHAttackhelperController* controller = new GHAttackhelperController();
		//controller->loadAttackhelpers(this);
		//controller->sendAttackhelperData("pkeykichulee", "1", 3, this);
		//controller->respondAttackhelperData(5, this); //del 점검필요
		//controller->loadAttackhelperDatas(this);


		//GHLeaderboardController* controller = new GHLeaderboardController();
		//controller->loadLeaderboardRank("key_aa_0");    // 확인 필요

		//controller->loadLeaderboardRank("key_aa_0",this);

		//controller->updateLeaderboardScore("key_aa","key_aa_0",50,this);
		//controller->updateLeaderboardScore("key_aa","key_aa_0",50);

		//controller->loadLeaderboards(this);

		//GHCloudsaveController* controller = new GHCloudsaveController();
		//controller->loadCloudSlotData(1, this);
		//controller->saveCloudSlotData("hahaha kichul zzang", 2, this);

		GHSocket* socket = new GHSocket();
		socket->ConnectSocketServer("54.238.195.222", 8081);

		break;
	}
}

// API TEST
void LoginForm::saveCloudsaveFinished(int statusCode){
	AppLogDebug("[DEBUG] saveCloud statusCode : %d", statusCode );
}

void LoginForm::loadCloudsaveFinished(String data){
	AppLogDebug("[DEBUG] loadCloud data : %S", data.GetPointer() );
}

// API TEST
void LoginForm::loadAchievementFinished(ArrayList* achievementList) {

	// TEST
	GHAchievement * test = static_cast<GHAchievement*>(achievementList->GetAt(0));
	AppLogDebug("[DEBUG] acArr ID : %S", test->getId().GetPointer() );
}
void LoginForm::loadAttackhelperFinished(ArrayList* achievementList) {

	// TEST
	GHAttackhelper * test = static_cast<GHAttackhelper*>(achievementList->GetAt(0));
	AppLogDebug("[DEBUG] ahArr ID : %S", test->getItemName().GetPointer() );
}
void LoginForm::respondAttackhelperDataFinished(int statusCode)
{
	AppLogDebug("[DEBUG] statusCode : %d", statusCode );
}

//Leaderboard Test
void LoginForm::loadLeaderboardFinished(ArrayList* leaderboardList)
{
	//TEST
	GHLeaderboard * test = static_cast<GHLeaderboard*>(leaderboardList->GetAt(0));
	AppLogDebug("[DEBUG] Leaderboard ID : %d, %S", leaderboardList->GetCount(), test->getId().GetPointer() );
}
void LoginForm::loadLeaderboardRankFinished(GHLeaderboard* _leaderboard)
{
	//AppLogDebug("[DEBUG]----------------------------------------------------------------->");
	GHLeaderboard * test = _leaderboard;
	GHPlayerRank* test2 = static_cast<GHPlayerRank*>(test->getRankList()->GetAt(0));

	//GHPlayerRank* test2 = test->getRankList()->GetAt(0);
	//GHLeaderboard * test = static_cast<GHLeaderboard*>(leaderboardList->GetAt(0));

	AppLogDebug("[DEBUG] Leaderboard ID : %S", test->getId().GetPointer());
	//GHPlayer * test3 = static_cast<GHPlayer*>(test2);
	//AppLogDebug("[DEBUG] test :  %S ", test2->getName().GetPointer() ); // 왜 데이터가 안올까  ㅠ___ㅠ;;;

	AppLogDebug("[DEBUG] P_id : %S", test2->getId().GetPointer() );

}
void LoginForm::updateLeaderboardScoreFinished(int statusCode)
{
	AppLogDebug("[DEBUG] statusCode : %d", statusCode );
}

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
		playerLogin(strEmail, strPw, this);
	}
	return r;
}

void LoginForm::loginPlayerFinished(Tizen::Base::String statusCode)
{
	AppLogDebug("STAUS : %S",statusCode.GetPointer());

	MessageBox msgBox;
	int modalResult;

	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);

	ArrayList* pList = new (std::nothrow)ArrayList;
	AppAssert(pList);
	pList->Construct();

	if(statusCode !=  "0")	// (로그인 성공 시) 로그인, 개인페이지로 이동
	{
		AppLog("success");

		String playerKey = statusCode;
		pList->Add( new Tizen::Base::String(playerKey) );	// playerId
		pList->Add( new Tizen::Base::Boolean(true) );		// isLocalPlayer
		pList->Add( new Tizen::Base::Boolean(false) );		// isFriend
		pSceneManager->GoForward(ForwardSceneTransition(SCENE_PLAYER, SCENE_TRANSITION_ANIMATION_TYPE_RIGHT, SCENE_HISTORY_OPTION_NO_HISTORY), pList);
	}
	else		// (로그인 실패 시) 로그인 실패 팝업
	{
		AppLog("fail");

		msgBox.Construct(L"Login", L"LOGIN fail", MSGBOX_STYLE_OK);
		msgBox.ShowAndWait(modalResult);
	}
}
