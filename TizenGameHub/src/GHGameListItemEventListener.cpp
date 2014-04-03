/*
 * GHGameListItemEventListener.cpp
 *
 *  Created on: Mar 13, 2014
 *      Author: Administrator
 */

#include "TizenGameHubFrame.h"
#include "GHGameListItemEventListener.h"
#include "GHGame.h"

using namespace Tizen::Ui::Scenes;

GHGameListItemEventListener::GHGameListItemEventListener() {
	// TODO Auto-generated constructor stub

}

GHGameListItemEventListener::~GHGameListItemEventListener() {
	// TODO Auto-generated destructor stub
}
void GHGameListItemEventListener::OnListViewContextItemStateChanged
(Tizen::Ui::Controls::ListView &listView, int index, int elementId, Tizen::Ui::Controls::ListContextItemStatus state)
{
}
void GHGameListItemEventListener::OnListViewItemSwept
(Tizen::Ui::Controls::ListView &listView, int index, Tizen::Ui::Controls::SweepDirection direction)
{
}
void GHGameListItemEventListener::OnListViewItemStateChanged
(Tizen::Ui::Controls::ListView &listView, int index, int elementId, Tizen::Ui::Controls::ListItemStatus status)
{
	if (status == Tizen::Ui::Controls::LIST_ITEM_STATUS_SELECTED) {
		Tizen::Base::String gameId = ((GHGame*)(list.GetAt(index)))->getId();
//		AppLog("[GHGameListItemEventListener] Game Id : %s", gameId);

		Tizen::Base::Collection::ArrayList* pList = new (std::nothrow)Tizen::Base::Collection::ArrayList;
		AppAssert(pList);
		pList->Construct();
		pList->Add( gameId );

		// Scene 이동
		SceneManager* pSceneManager = SceneManager::GetInstance();
		pSceneManager->GoForward(ForwardSceneTransition(SCENE_GAME, SCENE_TRANSITION_ANIMATION_TYPE_LEFT), pList);
	}
}

void GHGameListItemEventListener::setItemList(Tizen::Base::Collection::ArrayList* _list)
{
	for(int i=0 ; i<_list->GetCount() ; i++)
	{
		list.Add( (Tizen::Base::Object*)(_list->GetAt(i)) );
	}
}
