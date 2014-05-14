/*
 * GameForm.h
 *
 *  Created on: Mar 25, 2014
 *      Author: Administrator
 */

#ifndef GAMEFORM_H_
#define GAMEFORM_H_

#include <GHTizen.h>
#include "GHGame/GHGame.h"
#include "GHPlayer/GHPlayer.h"
#include "GHPlayerProvider.h"
#include "GHPlayerListItemEventListener.h"
//통신
#include "GHhttpClient.h"
#include "GHGame/GHGameController.h"
#include "GHGame/GHGameLoadedListener.h"
#include "GHGame/GHGamePlayingFriendListener.h"

using namespace Tizen::Ui::Controls;
using namespace Tizen::Base::Collection;

class GameForm
	: public Tizen::Ui::Controls::Form
	, public Tizen::Ui::IActionEventListener
	, public Tizen::Ui::Controls::IFormBackEventListener
	, public Tizen::Ui::Scenes::ISceneEventListener
	, public Tizen::Ui::Controls::IScrollEventListener
	, public GHGameController
	, public GHGameLoadedListener
	, public GHGamePlayingFriendListener
{
public:
	GameForm();
	virtual ~GameForm();
	bool Initialize(void);

private:
	GHGame *mGame;

	Panel *pPanelGame;
	Gallery *pGalleryGameImg;
	Label *pLabelGameName, *pLabelDeveloper;
	Button *pButtonGame;
	Panel *pPanelScroll, *pPanelGameDetail, *pPanelFriend, *pPanelFunction;
	Button *pButtonLeaderboard, *pButtonAchievement;
	Label *pLabelGameDesc;

	ListView *pListViewFriend;

	ArrayList *pFriendList;
	PlayerProvider *pFriendProvider;
	GHPlayerListItemEventListener *pFriendListItemEventListener;
	int friendOffset;

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
	//IScrollEventListener
	virtual void OnScrollEndReached(Tizen::Ui::Control &source, Tizen::Ui::Controls::ScrollEndEvent type);

	//GHGameLoadedListener
	void loadPlayerDataFinished(GHGame* game);
	//GHGamePlayingFriendListener
	void loadGamePlayingFriendFinished(Tizen::Base::Collection::ArrayList* friendsList);

	void getGameInstance(Tizen::Base::String id);
	void setGameData();
	void setPlayerList();

	void changePanel(int selected);
	void setFooterMenu();
	static const int ID_FOOTER_FIRST_TAB = 101;
	static const int ID_FOOTER_SECOND_TAB = 102;
	static const int ID_BUTTON_LEADERBOARD = 201;
	static const int ID_BUTTON_ACHIEVEMENT = 202;

};

#endif /* GAMEFORM_H_ */
