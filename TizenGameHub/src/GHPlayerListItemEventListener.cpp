/*
 * GHPlayerListItemEventListener.cpp
 *
 *  Created on: Mar 13, 2014
 *      Author: Administrator
 */

#include "GHPlayer.h"
#include "GHPlayerListItemEventListener.h"
#include "TizenGameHubFrame.h"

using namespace Tizen::Ui::Scenes;

GHPlayerListItemEventListener::GHPlayerListItemEventListener() {
	// TODO Auto-generated constructor stub

}

GHPlayerListItemEventListener::~GHPlayerListItemEventListener() {
	// TODO Auto-generated destructor stub
}
void GHPlayerListItemEventListener::OnListViewContextItemStateChanged
(Tizen::Ui::Controls::ListView &listView, int index, int elementId, Tizen::Ui::Controls::ListContextItemStatus state)
{
}
void GHPlayerListItemEventListener::OnListViewItemSwept
(Tizen::Ui::Controls::ListView &listView, int index, Tizen::Ui::Controls::SweepDirection direction)
{
}
void GHPlayerListItemEventListener::OnListViewItemStateChanged
(Tizen::Ui::Controls::ListView &listView, int index, int elementId, Tizen::Ui::Controls::ListItemStatus status)
{
	if (status == Tizen::Ui::Controls::LIST_ITEM_STATUS_SELECTED) {
		Tizen::Base::String playerId = ((GHPlayer*)(list.GetAt(index)))->getId();
//		AppLog("[GHPlayerListItemEventListener] Player Id : %s", playerId);

		Tizen::Base::Collection::ArrayList* pList = new (std::nothrow)Tizen::Base::Collection::ArrayList;
		AppAssert(pList);
		pList->Construct();
		pList->Add( playerId );	// playerId
		pList->Add( new Tizen::Base::Boolean(false) );	// isLocalPlayer
		pList->Add( new Tizen::Base::Boolean(false) );	// isFriend

		// Scene 이동
		SceneManager* pSceneManager = SceneManager::GetInstance();
//		pSceneManager->GoForward(ForwardSceneTransition(SCENE_PLAYER, SCENE_TRANSITION_ANIMATION_TYPE_LEFT));
		pSceneManager->GoForward(ForwardSceneTransition(SCENE_PLAYER, SCENE_TRANSITION_ANIMATION_TYPE_LEFT), pList);

	}
}

void GHPlayerListItemEventListener::setItemList(Tizen::Base::Collection::ArrayList* _list)
{
	for(int i=0 ; i<_list->GetCount() ; i++)
	{
		list.Add( (Tizen::Base::Object*)(_list->GetAt(i)) );
	}
}
