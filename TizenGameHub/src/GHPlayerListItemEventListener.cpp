/*
 * GHPlayerListItemEventListener.cpp
 *
 *  Created on: Mar 13, 2014
 *      Author: Administrator
 */

#include "GHPlayer.h"
#include "GHPlayerListItemEventListener.h"
#include "TizenGameHubFrame.h"
#include "GHSharedAuthData.h"

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
		if(index < list.GetCount())
		{
			Tizen::Base::String playerId = ((GHPlayer*)(list.GetAt(index)))->getId();

			Tizen::Base::Collection::ArrayList* pList = new (std::nothrow)Tizen::Base::Collection::ArrayList;
			AppAssert(pList);
			pList->Construct();
			pList->Add( playerId );	// playerId

			// Scene 이동
			SceneManager* pSceneManager = SceneManager::GetInstance();
			SceneId sceneId = (playerId.Equals(GHSharedAuthData::getSharedInstance().getPlayerId()) ? SCENE_PLAYER : SCENE_PLAYERFRIEND);
			pSceneManager->GoForward(ForwardSceneTransition(sceneId, SCENE_TRANSITION_ANIMATION_TYPE_LEFT), pList);
		}
	}
}

void GHPlayerListItemEventListener::setItemList(Tizen::Base::Collection::ArrayList* _list)
{
	for(int i=0 ; i<_list->GetCount() ; i++)
	{
		list.Add( (Tizen::Base::Object*)(_list->GetAt(i)) );
	}
}
