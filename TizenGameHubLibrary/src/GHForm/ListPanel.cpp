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

Tizen::Base::String ListPanel::getId()		{ return id;	}
Tizen::Base::String ListPanel::getTitle()	{ return title;	}
Tizen::Base::String ListPanel::getImgUrl()	{ return imgUrl;}

ListPanel::ListPanel() {
	Construct(IDL_PANEL_LISTPANEL);
}
ListPanel::~ListPanel() {
}
ListPanel::ListPanel(GHAchievement achievement)
{
	Construct(IDL_PANEL_LISTPANEL);
	isTouchEnable = false;

	id = achievement.getId();
	title = achievement.getTitle();
	imgUrl = achievement.getImgUrl();

	String desc = achievement.getDescription();

	int isHidden	= achievement.getIsHidden();		// hidden 속성 ( 0: hidden, 1: revealed(default))

	int isComplete	= achievement.getIsComplete(); 		// 업적 완료 여부
	int goalPoint	= achievement.getGoalPoint();		// 목표 점수
	int	curPoint	= achievement.getCurPoint();		// 현재 점수

	Label *pLabelTitle	= static_cast< Label* >(GetControl(IDC_LISTPANEL_LABEL_TITLE));
	Label *pLabelDesc	= static_cast< Label* >(GetControl(IDC_LISTPANEL_LABEL_DESC));
	Label *pLabelPoint	= static_cast< Label* >(GetControl(IDC_LISTPANEL_LABEL_POINT));
	Gallery *pImg = static_cast< Gallery* >(GetControl(IDC_LISTPANEL_IMG));
	Gallery *pImgComplete = static_cast< Gallery* >(GetControl(IDC_LISTPANEL_GALLERY_COMPLETE));
	Panel *pPanelOverlay= static_cast< Panel* >(GetControl(IDC_LISTPANEL_OVERLAY));

	pLabelTitle->SetText(title);
	pLabelDesc->SetText(desc);
//	pImg->Set

	if(isComplete) {
		pImgComplete->SetShowState(true);
		pLabelPoint->SetShowState(false);
	} else {
		pLabelPoint->SetText(Integer::ToString(curPoint) +"/"+ Integer::ToString(goalPoint));
		pImgComplete->SetShowState(false);
	}

	if(isHidden != 0) {
		pPanelOverlay->SetShowState(false);
	}
}
ListPanel::ListPanel(GHLeaderboard leaderboard)
{
	id = leaderboard.getId();
	title = leaderboard.getTitle();
	imgUrl = leaderboard.getImgUrl();

	setLeaderboardConfig();
}
void ListPanel::setLeaderboardConfig()
{
	Construct(IDL_PANEL_LISTPANEL);
	isTouchEnable = true;
	AddTouchEventListener(*this);

	Label *pLabelTitle = static_cast< Label* >(GetControl(IDC_LISTPANEL_LABEL_TITLE));
	Label *pLabelDesc = static_cast< Label* >(GetControl(IDC_LISTPANEL_LABEL_DESC));
	Gallery *pImg = static_cast< Gallery* >(GetControl(IDC_LISTPANEL_IMG));
	Panel *pPanelOverlay= static_cast< Panel* >(GetControl(IDC_LISTPANEL_OVERLAY));
	pPanelOverlay->SetShowState(false);
	Gallery *pImgComplete = static_cast< Gallery* >(GetControl(IDC_LISTPANEL_GALLERY_COMPLETE));
	pImgComplete->SetShowState(false);

	pLabelTitle->SetText(title);
//	pImg->Set

	pLabelTitle->AddTouchEventListener(*this);
	pLabelDesc->AddTouchEventListener(*this);
	pImg->AddTouchEventListener(*this);

}
void ListPanel::OnTouchReleased (const Tizen::Ui::Control &source, const Tizen::Graphics::Point &currentPosition, const Tizen::Ui::TouchEventInfo &touchInfo)
{
	Tizen::Ui::Controls::Frame *pFrame = Tizen::App::UiApp::GetInstance()->GetAppFrame()->GetFrame();
	LeaderboardRankForm* pForm = new (std::nothrow) LeaderboardRankForm(getId());
	pForm->Initialize();

	// Add the form to the frame
	pFrame->AddControl(pForm);
	pFrame->SetCurrentForm(pForm);
	pForm->Invalidate(true);
}
