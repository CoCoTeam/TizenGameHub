/*
 * LoginForm.h
 *
 *  Created on: Mar 25, 2014
 *      Author: Administrator
 */

#ifndef LOGINFORM_H_
#define LOGINFORM_H_

#include <GHTizen.h>
#include <GHhttpClient.h>
#include <GHAchievementController.h>
#include <GHAchievementLoadedListener.h>
#include <GHAttackhelperController.h>
#include <GHAttackhelperLoadedListener.h>
#include <GHAttackhelperDataRespondedListener.h>
using namespace Tizen::Ui::Controls;

class LoginForm
	: public Tizen::Ui::Controls::Form
	, public Tizen::Ui::IActionEventListener
	, public Tizen::Ui::Controls::IFormBackEventListener
	, public GHController
	, public GHAchievementLoadedListener // TEST API
	, public GHAttackhelperLoadedListener // TEST API
	, public GHAttackhelperDataRespondedListener // TEST API
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
	virtual void loadAchievementFinished(Tizen::Base::Collection::ArrayList* achievementList);
	virtual void loadAttackhelperFinished(Tizen::Base::Collection::ArrayList* achievementList);
	virtual void respondAttackhelperDataFinished(int statusCode);
	result doLogin();

	// GHController
	virtual void OnTransactionReadyToRead(Tizen::Base::String apiCode, Tizen::Base::String statusCode, Tizen::Web::Json::IJsonValue* data);

};

#endif /* LOGINFORM_H_ */
