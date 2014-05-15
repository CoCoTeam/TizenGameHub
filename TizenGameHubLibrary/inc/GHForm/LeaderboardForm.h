/*
 * LeaderboardForm.h
 *
 *  Created on: Apr 1, 2014
 *      Author: Administrator
 */

#ifndef LEADERBOARDFORM_H_
#define LEADERBOARDFORM_H_

#include <GHTizen.h>
#include "GHLeaderboard/GHLeaderboard.h"
#include "GHLeaderboard/GHLeaderboardDataLoadedListener.h"

class LeaderboardForm
	: public Tizen::Ui::Controls::Form
	, public Tizen::Ui::Controls::IFormBackEventListener
	, public GHLeaderboardDataLoadedListener
{
public:
	LeaderboardForm();
	virtual ~LeaderboardForm();
	bool Initialize(void);

private:
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);
	//IFormBackEventListener
	virtual void OnFormBackRequested(Tizen::Ui::Controls::Form& source);
	//GHLeaderboardDataLoadedListener
	virtual void loadLeaderboardFinished(Tizen::Base::Collection::ArrayList* leaderboardList);

	virtual void OnInitialized();

	void setLeaderboardList();

protected:
	Tizen::Base::Collection::ArrayList* lb_list;
	Tizen::Ui::Controls::ScrollPanel* pLeaderboard_scrollpanel;

};

#endif /* LEADERBOARDFORM_H_ */
