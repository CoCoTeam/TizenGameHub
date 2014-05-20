/*
 * ListPanel.h
 *
 *  Created on: Apr 9, 2014
 *      Author: Administrator
 */

#ifndef APPLISTPANEL_H_
#define APPLISTPANEL_H_

#include "GHForm/ListPanel.h"

class AppListPanel
	: public ListPanel
{
public:
	AppListPanel();
	AppListPanel(GHLeaderboard leaderboard);
	virtual ~AppListPanel();
	virtual void OnTouchReleased (const Tizen::Ui::Control &source, const Tizen::Graphics::Point &currentPosition, const Tizen::Ui::TouchEventInfo &touchInfo);

	void setGameId(Tizen::Base::String game_id);
private:
	Tizen::Base::String game_id;
};

#endif /* APPLISTPANEL_H_ */
