/*
 * LoginForm.h
 *
 *  Created on: Mar 25, 2014
 *      Author: Administrator
 */

#ifndef LOGINFORM_H_
#define LOGINFORM_H_

#include <GHTizen.h>
#include <GHAchievementController.h>
#include <GHAchievementLoadedListener.h>

using namespace Tizen::Ui::Controls;

class LoginForm
	: public Tizen::Ui::Controls::Form
	, public Tizen::Ui::IActionEventListener
	, public Tizen::Ui::Controls::IFormBackEventListener
	, public GHAchievementLoadedListener // TEST API
{
public:
	LoginForm();
	virtual ~LoginForm();
	bool Initialize(void);

private:
	EditField *pTextEmail, *pTextPw;

	virtual result OnInitializing(void);
	virtual result OnTerminating(void);
	//IActionEventListener
	virtual void OnActionPerformed(const Tizen::Ui::Control& source, int actionId);
	//IFormBackEventListener
	virtual void OnFormBackRequested(Tizen::Ui::Controls::Form& source);

	static const int IDA_BUTTON_LOGIN = 101;
	static const int IDA_BUTTON_JOIN = 102;
	static const int IDA_BUTTON_TEST = 103;

	// API TEST
	virtual void doAchievementFinished(GHAchievement* achievementArray);

	result doLogin();

};

#endif /* LOGINFORM_H_ */
