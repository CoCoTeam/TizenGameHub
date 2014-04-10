/*
 * ListPanel.cpp
 *
 *  Created on: Apr 9, 2014
 *      Author: Administrator
 */

#include "ListPanel.h"
#include "AppResourceId.h"

using namespace Tizen::Base;
using namespace Tizen::Ui::Controls;

ListPanel::ListPanel() {
	// TODO Auto-generated constructor stub
	result r = Construct(IDL_PANEL_LISTPANEL);
//	TryReturn(r == E_SUCCESS, false, "Failed to construct panel");
}

ListPanel::~ListPanel() {
	// TODO Auto-generated destructor stub
}


ListPanel::ListPanel(Tizen::Base::String _id, Tizen::Base::String _title, Tizen::Base::String _imgUrl)
	: id(_id), title(_title), imgUrl(_imgUrl)
{
	Construct(IDL_PANEL_LISTPANEL);

	Label *pLabelTitle = static_cast< Label* >(GetControl(IDC_LISTPANEL_LABEL_TITLE));
//	Gallery *pImg = static_cast< Gallery* >(GetControl(IDC_LISTPANEL_IMG));

	AppLogDebug("aaaaa %S", getTitle().GetPointer());
	pLabelTitle->SetText(_title);
//	pImg->Set
}

Tizen::Base::String ListPanel::getId()		{ return id;	}
Tizen::Base::String ListPanel::getTitle()	{ return title;	}
Tizen::Base::String ListPanel::getImgUrl()	{ return imgUrl;}
