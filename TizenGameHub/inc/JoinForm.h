/*
 * JoinForm.h
 *
 *  Created on: Mar 25, 2014
 *      Author: Administrator
 */

#ifndef JOINFORM_H_
#define JOINFORM_H_

#include <GHTizen.h>
#include "GHAchievement/GHAchievementController.h"


class JoinForm
	: public Tizen::Ui::Controls::Form
	, public Tizen::Ui::IActionEventListener
	, public Tizen::Ui::Controls::IFormBackEventListener
	, public Tizen::Ui::Scenes::ISceneEventListener
	, public GHController
{
public:
	JoinForm();
	virtual ~JoinForm();
	bool Initialize(void);

private:
	Tizen::Ui::Controls::EditField *pTextEmail, *pTextPw, *pTextPwconfirm, *pTextName;
	Tizen::Ui::Controls::Button* pButtonJoin;

	Tizen::Base::Boolean *isPlayerJoin;		//가입하는 시퀀스(true:가입, false:수정)

	virtual result OnInitializing(void);
	virtual result OnTerminating(void);
	//IActionEventListener
	virtual void OnActionPerformed(const Tizen::Ui::Control& source, int actionId);
	//IFormBackEventListener
	virtual void OnFormBackRequested(Tizen::Ui::Controls::Form& source);
	//ISceneEventListener
	virtual void OnSceneActivatedN(const Tizen::Ui::Scenes::SceneId& previousSceneId,
								   const Tizen::Ui::Scenes::SceneId& currentSceneId, Tizen::Base::Collection::IList* pArgs);
	virtual void OnSceneDeactivated(const Tizen::Ui::Scenes::SceneId& currentSceneId,
									const Tizen::Ui::Scenes::SceneId& nextSceneId);

	static const int IDA_BUTTON_JOIN = 101;
	static const int IDA_BUTTON_CANCEL = 102;

	// GHController
	virtual void OnTransactionReadyToRead(Tizen::Base::String apiCode, Tizen::Base::String statusCode, Tizen::Web::Json::IJsonValue* data);

	result doJoin();


};

#endif /* JOINFORM_H_ */
