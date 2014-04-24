/*
 * PrefClass.h
 *
 *  Created on: Mar 25, 2014
 *      Author: hursujung
 */

#ifndef GHAPPREGISTRY_H_
#define GHAPPREGISTRY_H_


#include <FBase.h>
#include <FUi.h>
#include <FApp.h>
#include <FGraphics.h>

using namespace Tizen::Base;
using namespace Tizen::App;
using namespace Tizen::Ui;

class GHAppRegistry
{
public:
	static String email;
	static String pwd;
public:
	GHAppRegistry();
	virtual ~GHAppRegistry();

	AppRegistry* pAppRegistry;

	void put(String key, String value);
	void get(String key, String& value);
	void get(String key, double& value);

};




#endif /* GHAPPREGISTRY_H_ */
