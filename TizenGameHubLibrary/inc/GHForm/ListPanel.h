/*
 * ListPanel.h
 *
 *  Created on: Apr 9, 2014
 *      Author: Administrator
 */

#ifndef LISTPANEL_H_
#define LISTPANEL_H_

#include <FUiCtrlPanel.h>
#include "GHTizen.h"
#include "GHAchievement/GHAchievement.h"
#include "GHLeaderboard/GHLeaderboard.h"

class ListPanel
	: public Tizen::Ui::Controls::Panel
	, public Tizen::Ui::ITouchEventListener
{
public:
	ListPanel();
	virtual ~ListPanel();
	ListPanel(GHLeaderboard leaderboard);
	ListPanel(GHAchievement achievement);
	//ITouchEventListener
	virtual void OnTouchFocusIn (const Tizen::Ui::Control &source, const Tizen::Graphics::Point &currentPosition, const Tizen::Ui::TouchEventInfo &touchInfo){};
	virtual void OnTouchFocusOut (const Tizen::Ui::Control &source, const Tizen::Graphics::Point &currentPosition, const Tizen::Ui::TouchEventInfo &touchInfo){};
	virtual void OnTouchMoved (const Tizen::Ui::Control &source, const Tizen::Graphics::Point &currentPosition, const Tizen::Ui::TouchEventInfo &touchInfo){};
	virtual void OnTouchPressed (const Tizen::Ui::Control &source, const Tizen::Graphics::Point &currentPosition, const Tizen::Ui::TouchEventInfo &touchInfo){};
	virtual void OnTouchReleased (const Tizen::Ui::Control &source, const Tizen::Graphics::Point &currentPosition, const Tizen::Ui::TouchEventInfo &touchInfo);


protected:
	Tizen::Base::String getId();
	Tizen::Base::String getTitle();
	Tizen::Base::String getImgUrl();

	Tizen::Base::String id;
	Tizen::Base::String title;
	Tizen::Base::String imgUrl;

	bool isTouchEnable;

};

#endif /* LISTPANEL_H_ */
