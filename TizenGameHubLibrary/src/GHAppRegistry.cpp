/*
 * PrefClass.cpp
 *
 *  Created on: Mar 25, 2014
 *      Author: hursujung
 */

#include "GHAppRegistry.h"

String GHAppRegistry::email = "APPREGISTRY_EMAIL";
String GHAppRegistry::pwd = "APPREGISTRY_PWD";

GHAppRegistry::GHAppRegistry() {
	// TODO Auto-generated constructor stub

	pAppRegistry = Tizen::App::AppRegistry::GetInstance();
}

GHAppRegistry::~GHAppRegistry() {
	// TODO Auto-generated destructor stub
}

void GHAppRegistry::put(String key, String value)
{
	result r = E_SUCCESS;

	r = pAppRegistry->Get(key, value);
	if (r == E_KEY_NOT_FOUND)
	{
		pAppRegistry->Add(key, value);
	}

	r = pAppRegistry->Save();
}

void GHAppRegistry::get(String key, String& value)
{
	pAppRegistry->Get(key, value);
}
void GHAppRegistry::get(String key, double& value)
{
	pAppRegistry->Get(key, value);
}
