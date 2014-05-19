/*
 * PlayerForm.h
 *
 *  Created on: Mar 25, 2014
 *      Author: Administrator
 */

#ifndef PLAYERFORM_H_
#define PLAYERFORM_H_

#include "GHTizen.h"
#include "GHGame/GHGame.h"
//리스트
#include "GHPlayer/GHPlayer.h"
#include "GHGameProvider.h"
#include "GHForm/PlayerProvider.h"
#include "GHGameListItemEventListener.h"
#include "GHPlayerListItemEventListener.h"
//통신
#include "GHhttpClient.h"
#include "GHPlayer/GHPlayerController.h"
#include "GHPlayer/GHPlayerLoadedListener.h"
#include "GHPlayer/GHPlayerGamesLoadedListener.h"
#include "GHPlayer/GHPlayerFriendsLoadedListener.h"
#include "GHPlayer/GHPlayerAddFriendListener.h"

#include <FBase.h>
#include <FUi.h>
#include <FIo.h>
#include <FGraphics.h>
#include <FMedia.h>
#include <FApp.h>
#include <FContent.h>
#include <FSystem.h>

using namespace Tizen::Base;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Base::Collection;

class PlayerForm
	: public Tizen::Ui::Controls::Form
	, public Tizen::Ui::IActionEventListener
	, public Tizen::Ui::Controls::IFormBackEventListener
	, public Tizen::Ui::Scenes::ISceneEventListener
	, public Tizen::Ui::Controls::IScrollEventListener
	, public GHPlayerController
	, public GHPlayerLoadedListener
	, public GHPlayerGamesLoadedListener
	, public GHPlayerFriendsLoadedListener
	, public GHPlayerAddFriendListener
	, public Tizen::Media::IImageDecodeUrlEventListener
	, public Tizen::Ui::Controls::IGalleryItemProvider
	/*,  public Tizen::Content::IDownloadListener*/
/*	, public GHController*/
{
public:
	PlayerForm();
	virtual ~PlayerForm();
	bool Initialize(void);

private:
	String *mPlayerId;
	GHPlayer *mPlayer;
	bool isLocalPlayer, isFriend;

	Panel *pPanelUser;
	Label *pLabelUserName, *pLabelUserScore;
	Gallery *pGalleryUserProfile;
	Button *pButtonUserFriend, *pButtonSearchFriend;

	Panel *pPanelScroll, *pPanelGame, *pPanelFriend;
	ArrayList *pGameList, *pFriendList;
	ListView *pListViewGame, *pListViewFriend;
	int gameOffset, friendOffset;

	GHGameProvider *pGameProvider;
	GHGameListItemEventListener *pGameListItemEventListener;


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
	//GHPlayerLoadedListener
	virtual void loadPlayerDataFinished(GHPlayer* player);
	//GHPlayerGamesLoadedListener
	virtual void loadPlayerGamesFinished(Tizen::Base::Collection::ArrayList* gameList);
	//GHPlayerFriendsLoadedListener
	virtual void loadPlayerFriendsFinished(Tizen::Base::Collection::ArrayList* friendsList);
	//GHPlayerAddFriendListener
	virtual void addFriendFinished(Tizen::Base::String statusCode);

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
	static const int IDA_BUTTON_SEARCHFRIEND = 102;

	 //
	 void RequestImage(const Tizen::Base::String& path,int width, int height,int timeout);
	 virtual void  OnImageDecodeUrlReceived (RequestId reqId, Tizen::Graphics::Bitmap *pBitmap, result r, const Tizen::Base::String errorCode, const Tizen::Base::String errorMessage);

	 //IGalleryItemProvider
	 virtual Tizen::Ui::Controls::GalleryItem* CreateItem (int index);
	 virtual bool DeleteItem (int index, Tizen::Ui::Controls::GalleryItem *pItem);
	 virtual int GetItemCount(void);

	Tizen::Graphics::Bitmap *__pUserBmp;


   /*  virtual void  OnDownloadCanceled (RequestId reqId) {}
     virtual void  OnDownloadCompleted (RequestId reqId, const Tizen::Base::String &path);
     virtual void  OnDownloadFailed (RequestId reqId, result r, const Tizen::Base::String &errorCode) {}
     virtual void  OnDownloadInProgress (RequestId reqId,unsigned long long receivedSize, unsigned long long totalSize);
     virtual void  OnDownloadPaused (RequestId reqId) {}

     void DownloadStart();
protected:
     RequestId __requestId;*/
	// GHController
/*	virtual void OnTransactionReadyToRead(Tizen::Base::String apiCode, Tizen::Base::String statusCode, Tizen::Web::Json::IJsonValue* data);
	virtual void OnTransactionCompleted(Tizen::Net::Http::HttpSession& httpSession, Tizen::Net::Http::HttpTransaction& httpTransaction);*/

};

#endif /* PLAYERFORM_H_ */
