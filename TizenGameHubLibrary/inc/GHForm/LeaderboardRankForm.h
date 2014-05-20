/*
 * LeaderboardRankForm.h
 *
 *  Created on: Apr 11, 2014
 *      Author: Administrator
 */

#ifndef LEADERBOARDRANKFORM_H_
#define LEADERBOARDRANKFORM_H_

#include "GHTizen.h"
#include "GHLeaderboard/GHLeaderboard.h"
#include "GHLeaderboard/GHLeaderboardController.h"
#include "GHLeaderboard/GHLeaderboardListLoadedListener.h"
#include "GHLeaderboard/GHLeaderboardMyRankLoadedListener.h"
#include "LeaderboardRankProvider.h"

class LeaderboardRankForm
	: public Tizen::Ui::Controls::Form
	, public Tizen::Ui::Controls::IFormBackEventListener
	, virtual public Tizen::Ui::Scenes::ISceneEventListener
	, public Tizen::Ui::Controls::IScrollEventListener
	, public Tizen::Media::IImageDecodeUrlEventListener
	, public GHLeaderboardController
	, public GHLeaderboardListLoadedListener
	, public GHLeaderboardMyRankLoadedListener
{
public:
	LeaderboardRankForm();
	LeaderboardRankForm(Tizen::Base::String leaderboardId);
	virtual ~LeaderboardRankForm();
	bool Initialize(void);

private:
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);
	// IFormBackEventListener
	virtual void OnFormBackRequested(Tizen::Ui::Controls::Form& source);
	//ISceneEventListener
	virtual void OnSceneActivatedN(const Tizen::Ui::Scenes::SceneId& previousSceneId,
								   const Tizen::Ui::Scenes::SceneId& currentSceneId, Tizen::Base::Collection::IList* pArgs);
	virtual void OnSceneDeactivated(const Tizen::Ui::Scenes::SceneId& currentSceneId,
									const Tizen::Ui::Scenes::SceneId& nextSceneId);
	// IScrollEventListener
	virtual void OnScrollEndReached(Tizen::Ui::Control &source, Tizen::Ui::Controls::ScrollEndEvent type);

	// GHLeaderboardListLoadedListener
	virtual void loadLeaderboardRankFinished(GHLeaderboard* _leaderboard);
	// GHLeaderboardMyRankLoadedListener
	virtual void loadLeaderboardMyRankFinished(GHPlayerRank* pPlayerRank);
	void RequestImage(const Tizen::Base::String& path,int width, int height, int timeout=5000);
	virtual void OnImageDecodeUrlReceived(RequestId reqId, Tizen::Graphics::Bitmap *pBitmap, result r, const Tizen::Base::String errorCode, const Tizen::Base::String errorMessage);


	virtual void OnInitialized();

	GHLeaderboard* leaderboard;						// 해당 리더보드의 정보
	Tizen::Base::Collection::ArrayList* rank_list;	// ranking 정보를 포함한 ArrayList
	Tizen::Ui::Controls::ListView *pRankListView;	// ranking 정보를 뿌려주는 ListView
	LeaderboardRankProvider *pRankProvider;			// ranking 정보를 지니고 있는 Provider

	void setMyRank();
	GHPlayerRank *myRank;
	Tizen::Ui::Controls::Panel *pPanelMyrank;
	Tizen::Ui::Controls::Label *pImgProfile;
	Tizen::Base::String strUnit;

protected:
	Tizen::Base::String leaderboardId;		// 이전 Form에서 전달받은 리더보드의 Id값
	int offset;

};

#endif /* LEADERBOARDRANKFORM_H_ */
