/*
 * PlayerForm.h
 *
 *  Created on: Mar 25, 2014
 *      Author: Administrator
 */

#ifndef PLAYERFORM_H_
#define PLAYERFORM_H_

#include <GHTizen.h>
#include "GHGame.h"
#include "GHPlayer.h"
#include "GHGameProvider.h"
#include "GHPlayerProvider.h"
#include "GHGameListItemEventListener.h"
#include "GHPlayerListItemEventListener.h"

using namespace Tizen::Base;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Base::Collection;

class PlayerForm
	: public Tizen::Ui::Controls::Form
	, public Tizen::Ui::IActionEventListener
	, public Tizen::Ui::Controls::IFormBackEventListener
	, public Tizen::Ui::Scenes::ISceneEventListener
{
public:
	PlayerForm();
	virtual ~PlayerForm();
	bool Initialize(void);

private:
	GHPlayer *mPlayer;	// Player 자기 자신 (getPlayerInstance)
	Boolean* isLocalPlayer;
	Boolean* isFriend;

	Button* pButtonUserFriend;
	Panel* pPanelGame;
	Panel* pPanelFriend;

	ListView *pListViewGame;
	GHGameProvider *pGameProvider;
	GHGameListItemEventListener *pGameListItemEventListener;
//	ListView *pListViewFriend;
//	GHPlayerProvider *pFriendProvider;
//	GHPlayerListItemEventListener *pFriendListItemEventListener;
	ArrayList *pGameList, *pFriendList;

	virtual result OnInitializing(void);
	virtual result OnTerminating(void);
	//IActionEventListener
	virtual void OnActionPerformed(const Tizen::Ui::Control& source, int actionId);
	//IFormBackEventListener
	virtual void OnFormBackRequested(Tizen::Ui::Controls::Form& source);
	//ISceneEventListener
	virtual void OnSceneActivatedN(const Tizen::Ui::Scenes::SceneId& previousSceneId,
								   const Tizen::Ui::Scenes::SceneId& currentSceneId, Tizen::Base::Collection::IList* pArgs);
	virtual void OnSceneDeactivated(const Tizen::Ui::Scenes::SceneId& currentSceneId,
									const Tizen::Ui::Scenes::SceneId& nextSceneId);

	//
	void setCurrentPlayerData(long playerId);
	void PlayerForm::setGameList();
	void PlayerForm::setPlayerList();
};

#endif /* PLAYERFORM_H_ */
