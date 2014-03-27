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
	String *mPlayerId;
	GHPlayer *mPlayer;	// Player 자기 자신 (getPlayerInstance)
	Boolean *isLocalPlayer, *isFriend;

	Panel *pPanelUser;
	Label *pLabelUserName, *pLabelUserScore;
	Gallery *pGalleryUserProfile;
	Button *pButtonUserFriend;

	Panel *pPanelScroll, *pPanelGame, *pPanelFriend;
	ListView *pListViewGame, *pListViewFriend;

	ArrayList *pGameList, *pFriendList;
	GHGameProvider *pGameProvider;
	GHGameListItemEventListener *pGameListItemEventListener;
	GHPlayerProvider *pFriendProvider;
	GHPlayerListItemEventListener *pFriendListItemEventListener;

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
	void getCurrentPlayerData(String playerId);	// 서버로부터 플레이어의 정보를 받아온다.
	void setPlayerData();						// 플레이어의 정보를 뷰에 적용한다.
	void getGames(String playerId);				// 서버로부터 플레이어의 게임 리스트를 받아온다.
	void setGameList();							// 플레이어의 게임 정보를 리스트뷰에 적용한다.
	void getFriends(String playerId);			// 서버로부터 플레이어의 친구 리스트를 받아온다.
	void setPlayerList();						// 플레이어의 친구 정보를 리스트뷰에 적용한다.

	void changePanel(int selected);
	void setFooterMenu();
	static const int ID_FOOTER_FIRST_TAB = 801;
	static const int ID_FOOTER_SECOND_TAB = 802;
	static const int IDA_BUTTON_USER = 101;
};

#endif /* PLAYERFORM_H_ */