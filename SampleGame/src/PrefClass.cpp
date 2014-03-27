/*
 * PrefClass.cpp
 *
 *  Created on: Mar 25, 2014
 *      Author: hursujung
 */

#include "PrefClass.h"

String PrefClass::name = "PREF_ID";

PrefClass::PrefClass() {
	// TODO Auto-generated constructor stub

	pAppRegistry = Tizen::App::AppRegistry::GetInstance();
}

PrefClass::~PrefClass() {
	// TODO Auto-generated destructor stub
}

void PrefClass::put(String key, String value)
{
	result r = E_SUCCESS;

	r = pAppRegistry->Get(key, value);
	if (r == E_KEY_NOT_FOUND)
	{
		pAppRegistry->Add(key, value);
	}

	r = pAppRegistry->Save();
}

void PrefClass::get(String key, String& value)
{
	pAppRegistry->Get(key, value);
}
void PrefClass::get(String key, double& value)
{
	pAppRegistry->Get(key, value);
}
