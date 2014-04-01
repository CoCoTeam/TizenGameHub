/*
 * PrefClass.h
 *
 *  Created on: Mar 25, 2014
 *      Author: hursujung
 */

#ifndef PREFCLASS_H_
#define PREFCLASS_H_


#include <FBase.h>
#include <FUi.h>
#include <FApp.h>
#include <FGraphics.h>

using namespace Tizen::Base;
using namespace Tizen::App;
using namespace Tizen::Ui;

class PrefClass
{
public:
	static String email;
	static String pwd;
public:
	PrefClass();
	virtual ~PrefClass();

	AppRegistry* pAppRegistry;

	void put(String key, String value);
	void get(String key, String& value);
	void get(String key, double& value);

};




#endif /* PREFCLASS_H_ */
