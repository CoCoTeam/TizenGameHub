/*
 * FriendSeachForm.h
 *
 *  Created on: May 12, 2014
 *      Author: Administrator
 */

#ifndef FRIENDSEACHFORM_H_
#define FRIENDSEACHFORM_H_

#include "GHTizen.h"
#include "GHPlayer/GHPlayerController.h"
#include "GHPlayer/GHPlayerSearchFriendListener.h"

class FriendSeachForm
	: public Tizen::Ui::Controls::Form
	, public Tizen::Ui::IActionEventListener
	, public Tizen::Ui::Controls::IFormBackEventListener
	, public GHPlayerController
	, public GHPlayerSearchFriendListener
{
public:
	FriendSeachForm();
	virtual ~FriendSeachForm();
	virtual bool Initialize(void);

private:
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);
	//IActionEventListener
	virtual void OnActionPerformed(const Tizen::Ui::Control& source, int actionId);
	//IFormBackEventListener
	virtual void OnFormBackRequested(Tizen::Ui::Controls::Form& source);

	// GHPlayerSearchFriendListener
	virtual void searchFriendFinished(Tizen::Base::Collection::ArrayList* friendsList);

	Tizen::Ui::Controls::EditField 	*pTextEmail;
	Tizen::Ui::Controls::Button 	*pButtonSearch;
	Tizen::Ui::Controls::ListView 	*pListViewFriend;
	static const int IDA_BUTTON_SEARCH = 101;


};

#endif /* FRIENDSEACHFORM_H_ */
