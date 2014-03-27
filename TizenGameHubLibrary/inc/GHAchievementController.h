/*
 * GHAchievementController.h
 *
 *  Created on: Mar 26, 2014
 *      Author: JOHEEYEON
 */

#ifndef GHACHIEVEMENTCONTROLLER_H_
#define GHACHIEVEMENTCONTROLLER_H_

#include <GHTizen.h>
#include <GHAchievementsLoadedListener.h>
#include <GHAchievementsUpdatedListener.h>
#include <httpClient.h>

class GHAchievementController
	: public Tizen::Net::Http::IHttpTransactionEventListener{
public:
	GHAchievementController();
	virtual ~GHAchievementController();

	// achievement 목록을 가져온다.
	void loadAchievements(GHAchievementsLoadedListener * listener);
	//void loadAchievements();

	// hidden -> reveal 상태로 바꾼다.
	void revealAchievement(STRING* id);
	void revealAchievement(GHAchievementsUpdatedListener* listener, STRING* id);

	// normal achievement update
	void completeAchievement(STRING* id);
	void completeAchievement(GHAchievementsUpdatedListener* listener, STRING* id);

	// incremental achievement update
	void increaseAchievement(STRING* id);
	void increaseAchievement(GHAchievementsUpdatedListener* listener, STRING* id);



public:
	// IHttpTransactionEventListener
	virtual void OnTransactionReadyToRead(Tizen::Net::Http::HttpSession& httpSession, Tizen::Net::Http::HttpTransaction& httpTransaction, int availableBodyLen);
	virtual void OnTransactionAborted(Tizen::Net::Http::HttpSession& httpSession, Tizen::Net::Http::HttpTransaction& httpTransaction, result r);
	virtual void OnTransactionReadyToWrite(Tizen::Net::Http::HttpSession& httpSession, Tizen::Net::Http::HttpTransaction& httpTransaction, int recommendedChunkSize);
	virtual void OnTransactionHeaderCompleted(Tizen::Net::Http::HttpSession& httpSession, Tizen::Net::Http::HttpTransaction& httpTransaction, int headerLen, bool authRequired);
	virtual void OnTransactionCompleted(Tizen::Net::Http::HttpSession& httpSession, Tizen::Net::Http::HttpTransaction& httpTransaction);
	virtual void OnTransactionCertVerificationRequiredN(Tizen::Net::Http::HttpSession& httpSession, Tizen::Net::Http::HttpTransaction& httpTransaction, Tizen::Base::String* pCert);
};


// Interface Class (Listener)
//class GHAchievementsLoadedListener {
//};
//
//

// Interface Class (Listener)
//class GHAchievementsUpdatedListener {
//};


#endif /* GHACHIEVEMENTCONTROLLER_H_ */
