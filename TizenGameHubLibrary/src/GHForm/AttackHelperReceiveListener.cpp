/*
 * AttackHelperReceiveListener.cpp
 *
 *  Created on: May 12, 2014
 *      Author: Administrator
 */

#include "GHAttackhelperData.h"
#include "GHAttackhelper/GHAttackhelperController.h"
#include "GHForm/AttackHelperReceiveListener.h"

AttackHelperReceiveListener::AttackHelperReceiveListener() {
	// TODO Auto-generated constructor stub

}

AttackHelperReceiveListener::~AttackHelperReceiveListener() {
	// TODO Auto-generated destructor stub
}


void AttackHelperReceiveListener::OnListViewContextItemStateChanged
(Tizen::Ui::Controls::ListView &listView, int index, int elementId, Tizen::Ui::Controls::ListContextItemStatus state)
{
}
void AttackHelperReceiveListener::OnListViewItemSwept
(Tizen::Ui::Controls::ListView &listView, int index, Tizen::Ui::Controls::SweepDirection direction)
{
}
void AttackHelperReceiveListener::OnListViewItemStateChanged
(Tizen::Ui::Controls::ListView &listView, int index, int elementId, Tizen::Ui::Controls::ListItemStatus status)
{
	if (status == Tizen::Ui::Controls::LIST_ITEM_STATUS_SELECTED) {
		if(index >= list.GetCount()) {
			return ;
		}
		listView.SetItemEnabled(index, false);


		GHAttackhelperData* ahData = (GHAttackhelperData*)(list.GetAt(index));
		AppLogDebug("%d, %S", ahData->getDataIndex(), ahData->getItemName().GetPointer());

		ahId = ahData->getDataIndex();

		pPopup = new Tizen::Ui::Controls::Popup();
		pPopup->Construct(false, Tizen::Graphics::Dimension(400, 350));

		Tizen::Ui::Controls::Button* pButtonAccept = new Tizen::Ui::Controls::Button();
		pButtonAccept->Construct(Tizen::Graphics::Rectangle(50, 50, 300, 100), "수  락");
		pButtonAccept->SetActionId(ACTION_POPUP_ACCEPT);
		pButtonAccept->AddActionEventListener(*this);
		pPopup->AddControl(pButtonAccept);

		Tizen::Ui::Controls::Button* pButtonDeny = new Tizen::Ui::Controls::Button();
		pButtonDeny->Construct(Tizen::Graphics::Rectangle(50, 200, 300, 100), "거  부");
		pButtonDeny->SetActionId(ACTION_POPUP_DENY);
		pButtonDeny->AddActionEventListener(*this);
		pButtonDeny->SetEnabled(ahData->getDenyEnable());
		pPopup->AddControl(pButtonDeny);

		pPopup->SetShowState(true);
		pPopup->Show();
	}
}
void AttackHelperReceiveListener::OnActionPerformed(const Tizen::Ui::Control& source, int actionId)
{
	GHAttackhelperController *ahController = new GHAttackhelperController();

	ahController->respondAttackhelperData(ahId, 1); // 일단 임시로 1 넣어놓음~

	switch(actionId)
	{
	case ACTION_POPUP_ACCEPT:
		break;

	case ACTION_POPUP_DENY:
		break;
	}
	if(pPopup != null) {
		delete pPopup;
		pPopup = null;
	}
}

void AttackHelperReceiveListener::setItemList(Tizen::Base::Collection::ArrayList* _list)
{
	for(int i=0 ; i<_list->GetCount() ; i++)
	{
		list.Add( (Tizen::Base::Object*)(_list->GetAt(i)) );
	}
}
