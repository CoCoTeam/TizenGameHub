/*
 * ListPanel.cpp
 *
 *  Created on: Apr 9, 2014
 *      Author: Administrator
 */

#include "AppResourceId.h"
#include "GHForm/ListPanel.h"
#include "GHForm/LeaderboardRankForm.h"
//#include "TizenGameHubFrame.h"

using namespace Tizen::Base;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Ui::Scenes;

ListPanel::ListPanel() {
	// TODO Auto-generated constructor stub
	Construct(IDL_PANEL_LISTPANEL);
//	TryReturn(r == E_SUCCESS, false, "Failed to construct panel");
}

ListPanel::~ListPanel() {
	// TODO Auto-generated destructor stub
	if(isTouchEnable) {
		RemoveTouchEventListener(*this);
	}
}

ListPanel::ListPanel(GHLeaderboard leaderboard)
{

}
ListPanel::ListPanel(GHAchievement achievement)
{
	Construct(IDL_PANEL_LISTPANEL);
	isTouchEnable = false;

	id = achievement.getId();
	title = achievement.getTitle();
	imgUrl = achievement.getImgUrl();

	String desc = achievement.getDescription();
//	int isHidden = achievement.getIsHidden();		// hidden 속성 ( 0: hidden, 1: revealed(default))
//	int isComplete = achievement.getIsComplete(); 	// 업적 완료 여부
//	int goalPoint = achievement.getGoalPoint();		// 목표 점수
//	int	curPoint = achievement.getCurPoint();		// 현재 점수

	Label *pLabelTitle = static_cast< Label* >(GetControl(IDC_LISTPANEL_LABEL_TITLE));
	Label *pLabelDesc = static_cast< Label* >(GetControl(IDC_LISTPANEL_LABEL_DESC));
//	Gallery *pImg = static_cast< Gallery* >(GetControl(IDC_LISTPANEL_IMG));

	pLabelTitle->SetText(title);
	pLabelDesc->SetText(desc);
//	pImg->Set
}

ListPanel::ListPanel(Tizen::Base::String _id, Tizen::Base::String _title, Tizen::Base::String _imgUrl)
	: id(_id), title(_title), imgUrl(_imgUrl)
{
	Construct(IDL_PANEL_LISTPANEL);
	isTouchEnable = true;
	AddTouchEventListener(*this);

	Label *pLabelTitle = static_cast< Label* >(GetControl(IDC_LISTPANEL_LABEL_TITLE));
	Label *pLabelDesc = static_cast< Label* >(GetControl(IDC_LISTPANEL_LABEL_DESC));
	Gallery *pImg = static_cast< Gallery* >(GetControl(IDC_LISTPANEL_IMG));

	pLabelTitle->SetText(title);
//	pImg->Set

	pLabelTitle->AddTouchEventListener(*this);
	pLabelDesc->AddTouchEventListener(*this);
	pImg->AddTouchEventListener(*this);
}

Tizen::Base::String ListPanel::getId()		{ return id;	}
Tizen::Base::String ListPanel::getTitle()	{ return title;	}
Tizen::Base::String ListPanel::getImgUrl()	{ return imgUrl;}

void ListPanel::OnTouchReleased (const Tizen::Ui::Control &source, const Tizen::Graphics::Point &currentPosition, const Tizen::Ui::TouchEventInfo &touchInfo)
{
	AppLogDebug("[ListPanel] OnTouchReleased. (id:%S)", getId().GetPointer());
	Tizen::Base::Collection::ArrayList* pList = new (std::nothrow)Tizen::Base::Collection::ArrayList;
	AppAssert(pList);
	pList->Construct();
	pList->Add( new String(getId()) );

	// Scene 이동
	SceneManager* pSceneManager = SceneManager::GetInstance();
//	pSceneManager->GoForward(ForwardSceneTransition(SCENE_LEADERBOARDRANK, SCENE_TRANSITION_ANIMATION_TYPE_LEFT), pList);

	Tizen::Ui::Controls::Frame *pFrame = Tizen::App::UiApp::GetInstance()->GetAppFrame()->GetFrame();
	LeaderboardRankForm* pForm = new (std::nothrow) LeaderboardRankForm(getId());
	pForm->Initialize();

	// Add the form to the frame
	pFrame->AddControl(pForm);

	// Set the current form
	pFrame->SetCurrentForm(pForm);

	// Draw the form
	pForm->Invalidate(true);
}
