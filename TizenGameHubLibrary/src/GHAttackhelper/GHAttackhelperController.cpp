/*
 * GHAttackhelperController.cpp
 *
 *  Created on: Apr 7, 2014
 *      Author: KICHUL
 */

#include "GHAttackhelper/GHAttackhelperController.h"
#include "GHSharedAuthData.h"
#include "GHForm/PlayerProvider.h"
#include "GHForm/AttackHelperProvider.h"
#include "GHForm/AttackHelperReceiveListener.h"
#include "GHForm/AttackHelperSendListener.h"

using namespace Tizen::Web::Json;
using namespace Tizen::Net::Http;
using namespace Tizen::Base;
using namespace Tizen::Base::Collection;

GHAttackhelperController::GHAttackhelperController() {
	// TODO Auto-generated constructor stub
	useProvidedPopup = true;
}
GHAttackhelperController::GHAttackhelperController(bool useProvidedPopup) {
	// TODO Auto-generated constructor stub
	this->useProvidedPopup = useProvidedPopup;
}

GHAttackhelperController::~GHAttackhelperController() {
	// TODO Auto-generated destructor stub
}

// attack helper 목록을 가져온다.
void GHAttackhelperController::loadAttackhelpers(GHAttackhelperLoadedListener * listener)
{
	this->currentListener = listener;

	//GET 함수 호출
	String game_id(GHSharedAuthData::getSharedInstance().getGameId());
	String player_id(GHSharedAuthData::getSharedInstance().getPlayerId());
	String url(L"/f_attackhelpers/" + game_id );
	httpPost.RequestHttpGetTran(this, url);
}

// attack helper data 목록을 가져온다.
void GHAttackhelperController::loadAttackhelperDatas(GHAttackhelperDataRespondedListener* respondListener, GHAttackhelperDataLoadedListener* loadedListener)
{
	this->respondListener = respondListener;
	this->currentListener = loadedListener;

	//GET 함수 호출
	String game_id(GHSharedAuthData::getSharedInstance().getGameId());
	String player_id(GHSharedAuthData::getSharedInstance().getPlayerId());
	String url(L"/f_attackhelpers/" + game_id + "/" + player_id);
	httpPost.RequestHttpGetTran(this, url);
}

// attack helper data를 전송한다.
void GHAttackhelperController::sendAttackhelperData(String receiver_id, int ah_id, int quantity, GHAttackhelperDataSendedListener* listener)
{
	this->sendListener = listener;

	String game_id(GHSharedAuthData::getSharedInstance().getGameId());
	String player_id(GHSharedAuthData::getSharedInstance().getPlayerId());
	String url(L"/f_attackhelpers/" + game_id );
	__pMap = new (std::nothrow) Tizen::Base::Collection::HashMap();
	__pMap->Construct();
	__pMap->Add(new String("sender_id"), new String(player_id));
	__pMap->Add(new String("receiver_id"), new String(receiver_id));
	__pMap->Add(new String("ah_id"), new String(Integer::ToString(ah_id)));
	__pMap->Add(new String("quantity"), new String(Integer::ToString(quantity)));

	httpPost.RequestHttpPostTran(this, url, __pMap);
}

// attack helper data를 수신한다.
void GHAttackhelperController::respondAttackhelperData(int data_idx, int accept_flag, GHAttackhelperDataRespondedListener* listener)
{
	this->respondListener = listener;

	String game_id(GHSharedAuthData::getSharedInstance().getGameId());
	String player_id(GHSharedAuthData::getSharedInstance().getPlayerId());
	String url(L"/f_attackhelpers/" + game_id );
	__pMap = new (std::nothrow) Tizen::Base::Collection::HashMap();
	__pMap->Construct();
	__pMap->Add(new String("data_idx"), new String(Integer::ToString(data_idx)));
	__pMap->Add(new String("accept_flag"), new String(Integer::ToString(accept_flag)));

	httpPost.RequestHttpPutTran(this, url, __pMap);
}

// attack helper 발신 팝업을 호출한다.
void GHAttackhelperController::loadDataSendPopup(GHAttackhelperDataSendedListener* listener, int ah_id, int quantity)
{
	this->sendListener = listener;
	this->ah_id = ah_id;
	this->quantity = quantity;

	GHGameController *gameController = new GHGameController();
	gameController->getGamePlayingFriends(GHSharedAuthData::getSharedInstance().getGameId(), this, 0, 20);
}
void GHAttackhelperController::loadGamePlayingFriendFinished(Tizen::Base::Collection::ArrayList* friendsList)
{
	pPopup = new Tizen::Ui::Controls::Popup();
	pPopup->Construct(true, Tizen::Graphics::Dimension(600, 800));
	pPopup->SetTitleText("Attack-Helper");

	if(friendsList != null && friendsList->GetCount() > 0) {	// (데이터가 있으면) 친구 목록 생성

		Tizen::Ui::Controls::Label *pLabelText = new Tizen::Ui::Controls::Label();
		pLabelText->Construct(Tizen::Graphics::Rectangle(25, 10, 550, 80), "친구에게 아이템을 보내세요.");
		pPopup->AddControl(pLabelText);

		Tizen::Ui::Controls::ListView* pAhList = new Tizen::Ui::Controls::ListView();
		pAhList->Construct(Tizen::Graphics::Rectangle(25, 100, 550, 500), false, false);

		PlayerProvider *pProvider = new PlayerProvider();
		pProvider->setItemList(friendsList);
		pAhList->SetItemProvider( *pProvider );
		AttackHelperSendListener *pListener = new AttackHelperSendListener(this->sendListener, ah_id, quantity);
		pListener->setItemList(friendsList);
		pAhList->AddListViewItemEventListener( *pListener );

		pPopup->AddControl(pAhList);
	}
	else
	{	// (데이터가 없으면) 메시지
		Tizen::Ui::Controls::Label *pLabelNoItem = new Tizen::Ui::Controls::Label();
		pLabelNoItem->Construct(Tizen::Graphics::Rectangle(25, 100, 550, 100), "아이템을 보낼 친구가 없습니다.");
		pPopup->AddControl(pLabelNoItem);
	}

	Tizen::Ui::Controls::Button* pButtonClose = new Tizen::Ui::Controls::Button();
	pButtonClose->Construct(Tizen::Graphics::Rectangle(100, 620, 400, 80), "닫  기");
	pButtonClose->SetActionId(ACTION_POPUP_CLOSE);
	pButtonClose->AddActionEventListener(*this);
	pPopup->AddControl(pButtonClose);

	pPopup->SetShowState(true);
	pPopup->Show();

}

// attack helper 수신 팝업을 호출한다.
void GHAttackhelperController::loadDataReceievedPopup(ArrayList* pArr)
{
	if(!useProvidedPopup) {
		return;
	}

	pPopup = new Tizen::Ui::Controls::Popup();
	pPopup->Construct(true, Tizen::Graphics::Dimension(600, 800));
	pPopup->SetTitleText("Attack-Helper");

	if(pArr == null || pArr->GetCount() == 0) {	// (데이터가 없으면) 메시지
		Tizen::Ui::Controls::Label *pLabelNoItem = new Tizen::Ui::Controls::Label();
		pLabelNoItem->Construct(Tizen::Graphics::Rectangle(25, 100, 550, 100), "새로 받은 아이템이 없습니다.");
		pPopup->AddControl(pLabelNoItem);
	}
	else {	// (데이터가 있으면) 리스트 뷰 생성
		Tizen::Ui::Controls::ListView* pAhList = new Tizen::Ui::Controls::ListView();
		pAhList->Construct(Tizen::Graphics::Rectangle(25, 20, 550, 550), false, false);

		AttackHelperProvider *pProvider = new AttackHelperProvider();
		pProvider->addItemList(pArr);
		AttackHelperReceiveListener *pListener = new AttackHelperReceiveListener(this->respondListener);
		pListener->setItemList(pArr);
		pAhList->SetItemProvider( *pProvider );
		pAhList->AddListViewItemEventListener( *pListener );

		pPopup->AddControl(pAhList);
	}

	Tizen::Ui::Controls::Button* pButtonClose = new Tizen::Ui::Controls::Button();
	pButtonClose->Construct(Tizen::Graphics::Rectangle(100, 600, 400, 100), "닫  기");
	pButtonClose->SetActionId(ACTION_POPUP_CLOSE);
	pButtonClose->AddActionEventListener(*this);
	pPopup->AddControl(pButtonClose);

	pPopup->SetShowState(true);
	pPopup->Show();
}


void GHAttackhelperController::OnActionPerformed(const Tizen::Ui::Control& source, int actionId)
{
	switch(actionId) {
	case ACTION_POPUP_CLOSE:
		delete pPopup;
		pPopup = null;
		break;
	}

}

// 모든 통신의 콜백에서 호출하는 함수
void GHAttackhelperController::OnTransactionReadyToRead(String apiCode, String statusCode, IJsonValue* data){

	AppLogDebug("[DEBUG] apiCode : %S", apiCode.GetPointer() );
	AppLogDebug("[DEBUG] statusCode : %S", statusCode.GetPointer() );

	if(apiCode.Equals(ATTACKHELPER_LOAD)) {
		ArrayList* ahArr;

		// 정상적으로 결과를 반환했을 때
		if(statusCode == "1") {
			JsonArray* 	pJsonArray 	= static_cast<JsonArray*>(data);
			int 		arrNum 		= pJsonArray->GetCount();
			ahArr = new ArrayList();

			// KEY NAME
			String* pkeyId 			= new String(L"ah_id");
			String* pkeyItemName	= new String(L"item_name");
			String* pkeyDenyEnbale	= new String(L"deny_enable");

			for(int i=0; i<arrNum; i++) {
				JsonObject *pJsonOject 	= getJsonObjectByIndex(pJsonArray, i);

				// 데이터 파싱
				String  sId 			= getStringByKey(pJsonOject, pkeyId);
				String  sItemName		= getStringByKey(pJsonOject, pkeyItemName);
				int iDenyEnable			= getIntByKey(pJsonOject, pkeyDenyEnbale);

				// 리스트에 추가
				ahArr->Add(new GHAttackhelper(sId, sItemName, iDenyEnable));
			}
		}else {
			ahArr = null;
		}

		if(this->currentListener != null) this->currentListener->loadAttackhelperFinished(ahArr);
	}
	else if(apiCode.Equals(ATTACKHELPER_DATA_LOAD)) {
		ArrayList* ahdArr;

		// 정상적으로 결과를 반환했을 때
		if(statusCode == "1") {
			JsonArray* 	pJsonArray 	= static_cast<JsonArray*>(data);
			int 		arrNum 		= pJsonArray->GetCount();
			ahdArr = new ArrayList();

			// KEY NAME
			String* pkeyDataIdx		= new String(L"data_idx");
			String* pkeySenderId	= new String(L"sender_id");
			String* pkeySenderName	= new String(L"sender_name");
			String* pkeyId 			= new String(L"ah_id");
			String* pkeyItemName	= new String(L"item_name");
			String* pkeyDenyEnbale	= new String(L"deny_enable");
			String* pkeyQuantity	= new String(L"quantity");

			for(int i=0; i<arrNum; i++) {
				JsonObject *pJsonOject 	= getJsonObjectByIndex(pJsonArray, i);

				// 데이터 파싱
				int iDataIdx			= getIntByKey(pJsonOject, pkeyDataIdx);
				String  sSenderId 		= getStringByKey(pJsonOject, pkeySenderId);
				String  sSenderName		= getStringByKey(pJsonOject, pkeySenderName);
				String  sId 			= getStringByKey(pJsonOject, pkeyId);
				String  sItemName		= getStringByKey(pJsonOject, pkeyItemName);
				int iDenyEnable			= getIntByKey(pJsonOject, pkeyDenyEnbale);
				int iQuantity			= getIntByKey(pJsonOject, pkeyQuantity);

				// 리스트에 추가
				ahdArr->Add(new GHAttackhelperData(iDataIdx, sSenderId, sSenderName, sId, sItemName, iDenyEnable, iQuantity));

			}

			delete pkeyDataIdx; delete pkeySenderId; delete pkeyId; delete pkeySenderName;
			delete pkeyItemName;delete pkeyDenyEnbale; delete pkeyQuantity;

		}else {
			ahdArr = null;
		}

		// 사용자에게 팝업 제공
		loadDataReceievedPopup(ahdArr);

		if(this->currentListener != null) this->currentListener->loadAttackhelperDataFinished(ahdArr);
	}
	else if(apiCode.Equals(ATTACKHELPER_DATA_SEND)) {
		int stateCode;
		Integer::Parse(statusCode, stateCode);

		if(this->sendListener != null) this->sendListener->sendAttackhelperDataFinished(stateCode);
	}
	else if(apiCode.Equals(ATTACKHELPER_DATA_RESPOND)) { // 데이터를 보내줘야함.
		int stateCode;
		Integer::Parse(statusCode, stateCode);

		GHAttackhelperData * ahdObj = null;
		int accept_flag;

		// 정상적으로 결과를 반환했을 때
		if(statusCode == "1") {
			JsonObject* pJsonOject 	= static_cast<JsonObject*>(data);

			// KEY NAME
			String* pkeyDataIdx		= new String(L"data_idx");
			String* pkeySenderId	= new String(L"sender_id");
			String* pkeySenderName	= new String(L"sender_name");
			String* pkeyId 			= new String(L"ah_id");
			String* pkeyItemName	= new String(L"item_name");
			String* pkeyDenyEnbale	= new String(L"deny_enable");
			String* pkeyQuantity	= new String(L"quantity");
			String* pkeyAcceptFlag	= new String(L"accept_flag");

			// 데이터 파싱
			int iDataIdx		= getIntByKey(pJsonOject, pkeyDataIdx);
			String  sSenderId 	= getStringByKey(pJsonOject, pkeySenderId);
			String  sSenderName	= getStringByKey(pJsonOject, pkeySenderName);
			String  sId 		= getStringByKey(pJsonOject, pkeyId);
			String  sItemName	= getStringByKey(pJsonOject, pkeyItemName);
			int iDenyEnable		= getIntByKey(pJsonOject, pkeyDenyEnbale);
			int iQuantity		= getIntByKey(pJsonOject, pkeyQuantity);
			accept_flag			= getIntByKey(pJsonOject, pkeyAcceptFlag);


			ahdObj = new GHAttackhelperData(iDataIdx, sSenderId, sSenderName, sId, sItemName, iDenyEnable, iQuantity);

			delete pkeyDataIdx;	delete pkeySenderId;	delete pkeySenderName;
			delete pkeyId;		delete pkeyItemName;	delete pkeyDenyEnbale;
			delete pkeyQuantity;delete pkeyAcceptFlag;
		}else {
			ahdObj = null;
		}

		if(this->respondListener != null) {
			this->respondListener->respondAttackhelperDataFinished(ahdObj, accept_flag);
		}

	}

}
