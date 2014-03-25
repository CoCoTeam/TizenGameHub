/*
 * JoinForm.h
 *
 *  Created on: Mar 25, 2014
 *      Author: Administrator
 */

#ifndef JOINFORM_H_
#define JOINFORM_H_

#include <GHTizen.h>

class JoinForm
	: public Tizen::Ui::Controls::Form
	, public Tizen::Ui::IActionEventListener
	, public Tizen::Ui::Controls::IFormBackEventListener
{
public:
	JoinForm();
	virtual ~JoinForm();
	bool Initialize(void);

private:
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);
	//IActionEventListener
	virtual void OnActionPerformed(const Tizen::Ui::Control& source, int actionId);
	//IFormBackEventListener
	virtual void OnFormBackRequested(Tizen::Ui::Controls::Form& source);

private:
	static const int IDA_BUTTON_JOIN = 101;
	static const int IDA_BUTTON_CANCEL = 102;
};

#endif /* JOINFORM_H_ */
