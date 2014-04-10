/*
 * ListPanel.h
 *
 *  Created on: Apr 9, 2014
 *      Author: Administrator
 */

#ifndef LISTPANEL_H_
#define LISTPANEL_H_

#include <FUiCtrlPanel.h>
#include "GHTizen.h"

class ListPanel
	: public Tizen::Ui::Controls::Panel
{
public:
	ListPanel();
	virtual ~ListPanel();

	ListPanel(Tizen::Base::String _id, Tizen::Base::String _title, Tizen::Base::String _imgUrl);

	Tizen::Base::String getId();
	Tizen::Base::String getTitle();
	Tizen::Base::String getImgUrl();

private:
	Tizen::Base::String id;
	Tizen::Base::String title;
	Tizen::Base::String imgUrl;
};

#endif /* LISTPANEL_H_ */
