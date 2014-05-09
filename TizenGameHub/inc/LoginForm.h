/*
 * LoginForm.h
 *
 *  Created on: Mar 25, 2014
 *      Author: Administrator
 */

#ifndef LOGINFORM_H_
#define LOGINFORM_H_

#include "GHTizen.h"

#include "GHAppRegistry.h"

#include "GHhttpClient.h"
#include "GHPlayer/GHPlayerController.h"
#include "GHPlayer/GHPlayerLoggedinListener.h"

using namespace Tizen::Ui::Controls;

class LoginForm
	: public Tizen::Ui::Controls::Form
	, public Tizen::Ui::IActionEventListener
	, public Tizen::Ui::Controls::IFormBackEventListener
	, public GHPlayerController
	, public GHPlayerLoggedinListener
{
public:
	LoginForm();
	virtual ~LoginForm();
	bool Initialize(void);

private:
	EditField *pTextEmail, *pTextPw;
	GHAppRegistry appReg;

	virtual result OnInitializing(void);
	virtual result OnTerminating(void);
	//IActionEventListener
	virtual void OnActionPerformed(const Tizen::Ui::Control& source, int actionId);
	//IFormBackEventListener
	virtual void OnFormBackRequested(Tizen::Ui::Controls::Form& source);
	//GHPlayerLoggedinListener
	virtual void loginPlayerFinished(Tizen::Base::String statusCode);

	static const int IDA_BUTTON_LOGIN = 101;
	static const int IDA_BUTTON_JOIN = 102;

	void doLogin();
	void login(Tizen::Base::String email, Tizen::Base::String pw);

};

#endif /* LOGINFORM_H_ */
