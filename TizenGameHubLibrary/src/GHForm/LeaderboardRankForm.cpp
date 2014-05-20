/*
 * LeaderboardRankForm.cpp
 *
 *  Created on: Apr 11, 2014
 *      Author: Administrator
 */

#include "GHForm/LeaderboardRankForm.h"
#include "LibResourceId.h"

using namespace Tizen::Base;
using namespace Tizen::Ui::Scenes;
using namespace Tizen::Ui::Controls;

LeaderboardRankForm::LeaderboardRankForm()
: offset(0)
{
}
LeaderboardRankForm::LeaderboardRankForm(Tizen::Base::String leaderboardId)
: offset(0)
{
	this->leaderboardId = leaderboardId;
}
LeaderboardRankForm::~LeaderboardRankForm() {
}
bool LeaderboardRankForm::Initialize(void)
{
	result r = Construct(IDL_GHFORM_LEADERBOARDRANK);
	TryReturn(r == E_SUCCESS, false, "Failed to construct form");

	return true;
}
result LeaderboardRankForm::OnInitializing(void)
{
	result r = E_SUCCESS;

	// Setup back event listener
	SetFormBackEventListener(this);

	// Get a button via resource ID
	pRankListView = static_cast<ListView*>(GetControl(IDC_LEADERBOARDRANK_LIST_RANK));
	pRankListView->AddScrollEventListener(*this);
	pRankProvider = new LeaderboardRankProvider();
	pPanelMyrank = static_cast<Panel*>(GetControl(IDC_LEADERBOARDRANK_PANEL_MYRANK));
	pImgProfile = static_cast<Label*>(pPanelMyrank->GetControl(IDC_LEADERBOARDRANK_MYRANK_GALLERY));
	pImgProfile->SetShowState(false);

	OnInitialized();

	return r;
}
void LeaderboardRankForm::OnInitialized()
{
	if(leaderboardId != null) {
		loadLeaderboardRank(leaderboardId, this);
		loadLeaderboardMyRank(leaderboardId, this);
	}
}
result LeaderboardRankForm::OnTerminating(void)
{
	result r = E_SUCCESS;

//	rank_list->RemoveAll();	delete rank_list;

	return r;
}
void LeaderboardRankForm::OnSceneActivatedN(const Tizen::Ui::Scenes::SceneId& previousSceneId,
										  const Tizen::Ui::Scenes::SceneId& currentSceneId, Tizen::Base::Collection::IList* pArgs)
{
	// TODO: Activate your scene here.
	if (pArgs != null)
	{
		if (pArgs->GetCount())
		{
			String* lb_id = static_cast<Tizen::Base::String*>(pArgs->GetAt(0));
			AppLogDebug("dhskljfhsdjkhgkjhsdjkf %S", lb_id->GetPointer());

			// 사용자 데이터 수신
			loadLeaderboardRank(*lb_id, this);
			loadLeaderboardMyRank(*lb_id, this);
		}
//		pArgs->RemoveAll(true);
		delete pArgs;
	}
}

void LeaderboardRankForm::OnSceneDeactivated(const Tizen::Ui::Scenes::SceneId& currentSceneId,
										   const Tizen::Ui::Scenes::SceneId& nextSceneId)
{
}
// IFormBackEventListener
void LeaderboardRankForm::OnFormBackRequested(Tizen::Ui::Controls::Form& source)
{
	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);
	pSceneManager->GoBackward(BackwardSceneTransition(SCENE_TRANSITION_ANIMATION_TYPE_RIGHT));
}
// IScrollEventListener
void LeaderboardRankForm::OnScrollEndReached(Tizen::Ui::Control &source, Tizen::Ui::Controls::ScrollEndEvent type)
{
	if(type == SCROLL_END_EVENT_END_BOTTOM) {
		loadLeaderboardRank(leaderboardId, this, offset, 8);
	}
}
// GHLeaderboardListLoadedListener
void LeaderboardRankForm::loadLeaderboardRankFinished(GHLeaderboard* _leaderboard)
{
	if(_leaderboard == null) {
		return;
	}
	leaderboard = _leaderboard;
	rank_list = leaderboard->getRankList();
	offset += rank_list->GetCount();
	AppLogDebug("[LeaderboardRankForm] leaderboardRankList Received. (listSize : %d)", rank_list->GetCount() );

	strUnit = leaderboard->getUnit();
	pRankProvider->setUnit(strUnit);
	pRankProvider->addItemList(rank_list);
	pRankListView->SetItemProvider( *pRankProvider );
	Draw();
}

void LeaderboardRankForm::loadLeaderboardMyRankFinished(GHPlayerRank* pPlayerRank)
{
	if(pPlayerRank == null) {
		pImgProfile->SetShowState(false);
		Tizen::Ui::Controls::Label *pLabelName = static_cast<Label*>(pPanelMyrank->GetControl(IDC_LEADERBOARDRANK_MYRANK_LABEL_NAME));
		pLabelName->SetText("No data");
		Draw();
		return;
	}
	myRank = pPlayerRank;
	setMyRank();
}

void LeaderboardRankForm::setMyRank()
{
	// Set My rank Info.
	Tizen::Ui::Controls::Label *pLabelName = static_cast<Label*>(pPanelMyrank->GetControl(IDC_LEADERBOARDRANK_MYRANK_LABEL_NAME));
	Tizen::Ui::Controls::Label *pLabelScore = static_cast<Label*>(pPanelMyrank->GetControl(IDC_LEADERBOARDRANK_MYRANK_LABEL_SCORE));
	Tizen::Ui::Controls::Label *pLabelRank = static_cast<Label*>(pPanelMyrank->GetControl(IDC_LEADERBOARDRANK_MYRANK_LABEL_RANK));

	pLabelName->SetText(myRank->getName());
	pLabelScore->SetText(Integer::ToString(myRank->getScore()) + strUnit);
	pLabelRank->SetText(Integer::ToString(myRank->getRank()) + " 위");
	pImgProfile->SetShowState(true);
	RequestImage(myRank->getId(), pImgProfile->GetWidth(), pImgProfile->GetHeight());
	Draw();
}

void LeaderboardRankForm::RequestImage(const Tizen::Base::String& path,int width, int height, int timeout)
{
	Tizen::Media::Image* pImage = new Tizen::Media::Image();
	pImage->Construct();

	// Set a URL
	Tizen::Base::Utility::Uri uri;
	uri.SetUri(L"http://54.238.195.222:80/players/"+ path +"/image");

	RequestId reqId;

	//서버에 보내기
	pImage->DecodeUrl(uri, Tizen::Graphics::BITMAP_PIXEL_FORMAT_RGB565, width, height, reqId, *this, timeout);
}
// Receive the image and call the delete timer
void LeaderboardRankForm::OnImageDecodeUrlReceived(RequestId reqId, Tizen::Graphics::Bitmap *pBitmap, result r, const Tizen::Base::String errorCode, const Tizen::Base::String errorMessage)
{
	if(IsFailed(r)) {
		AppLog("Request failed: errorCode(%ls) errorMessage(%ls)", errorCode.GetPointer(), errorMessage.GetPointer());
	}
	else {
		pImgProfile->SetBackgroundBitmap(*pBitmap);
		pImgProfile->Draw();
	}
}
