/*
 * GHAttackhelperController.h
 *
 *  Created on: Apr 7, 2014
 *      Author: KICHUL
 */

#ifndef GHATTACKHELPERCONTROLLER_H_
#define GHATTACKHELPERCONTROLLER_H_

#include "GHTizen.h"
#include "GHController.h"
#include "GHAttackhelper.h"
#include "GHAttackhelperData.h"
#include "GHAttackhelperListener.h"
#include "GHAttackhelperLoadedListener.h"
#include "GHAttackhelperDataLoadedListener.h"
#include "GHAttackhelperDataSendedListener.h"
#include "GHAttackhelperDataRespondedListener.h"
#include "GHhttpClient.h"
#include "GHGame/GHGameController.h"
#include "GHGame/GHGamePlayingFriendListener.h"

const Tizen::Base::String ATTACKHELPER_LOAD			= "31";
const Tizen::Base::String ATTACKHELPER_DATA_LOAD 	= "32";
const Tizen::Base::String ATTACKHELPER_DATA_SEND 	= "33";
const Tizen::Base::String ATTACKHELPER_DATA_RESPOND = "34";


class GHAttackhelperController
	: public GHController
	, public Tizen::Ui::IActionEventListener
	, public GHGamePlayingFriendListener
{
public:
	GHAttackhelperController();
	GHAttackhelperController(bool useProvidedPopup);
	virtual ~GHAttackhelperController();

	// attack helper 목록을 가져온다.

	void loadAttackhelpers(GHAttackhelperLoadedListener* listener = null);				// load listener

	// attack helper data 목록을 가져온다.
	void loadAttackhelperDatas(GHAttackhelperDataRespondedListener* respondListener, GHAttackhelperDataLoadedListener* loadedListener = null); 	// update listener

	// attack helper data를 전송한다.
	void sendAttackhelperData(Tizen::Base::String receiver_id, int ah_id, int quantity, GHAttackhelperDataSendedListener* listener = null); 	// update listener

	// attack helper data를 수신한다.
	void respondAttackhelperData(int data_idx, int accept_flag, GHAttackhelperDataRespondedListener* listener = null); 	// update listener

	// attack helper 발신 팝업을 호출한다.
	void loadDataSendPopup(GHAttackhelperDataSendedListener* listener, int ah_id, int quantity=1);
	// attack helper 수신 팝업을 호출한다.
	void loadDataReceievedPopup(Tizen::Base::Collection::ArrayList* pArr);

	virtual void OnActionPerformed(const Tizen::Ui::Control& source, int actionId);
private:
	virtual void OnTransactionReadyToRead(Tizen::Base::String apiCode, Tizen::Base::String statusCode, Tizen::Web::Json::IJsonValue* data);
	Tizen::Base::Collection::HashMap* __pMap;
	GHAttackhelperListener* currentListener;
	GHAttackhelperDataRespondedListener* respondListener;	// attack helper 수신 완료 리스너 (providedPopup을 사용할 때)
	GHAttackhelperDataSendedListener* sendListener;			// attack helper 발신 완료 리스너 (providedPopup을 사용할 때)

	Tizen::Ui::Controls::Popup *pPopup;		// providedPopup
	static const int ACTION_POPUP_CLOSE = 101;

	bool useProvidedPopup;					// providedPopup 사용 여부
	int ah_id, quantity;					// attack helper 발신 시 사용되는 ah_id 값 및 quantity (providedPopup을 사용할 때)

	//GHGamePlayingFriendListener
	virtual void loadGamePlayingFriendFinished(Tizen::Base::Collection::ArrayList* friendsList);	// (providedPopup을 사용할 때)
};

#endif /* GHATTACKHELPERCONTROLLER_H_ */
