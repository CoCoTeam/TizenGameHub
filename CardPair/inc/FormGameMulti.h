#ifndef _CARD_PAIR_FORM_MULTI_H_
#define _CARD_PAIR_FORM_MULTI_H_

#include "tizenx.h"
#include "FormGame.h"
#include "GHTurnbasedMatch/GHTurnbasedMatchController.h"
#include "GHTurnbasedMatch/GHTurnbasedMatchListener.h"
#include "GHCloudsave/GHCloudsaveController.h"
#include "GHCloudsave/GHCloudsaveSaveListener.h"

class FormGameMulti
	: public FormGame
	, public GHTurnbasedMatchListener
	, public GHCloudsaveSaveListener
{
public:
	FormGameMulti(void);
	virtual ~FormGameMulti(void);

private:
	virtual void setAdditionalInitialState();
	virtual result SetGameTimer(Tizen::Base::TimeSpan ts);
	virtual void onReadyToStart();
	virtual void onStageComplete();
	virtual void onTurnFinished(int actionType, int cardNum, bool isCorrect);
	virtual void startMyTurnThread();


	void shuffleCard(Tizen::Base::String data);
	Tizen::Web::Json::JsonObject* parseJson(Tizen::Base::String data);

	GHTurnbasedMatchController *multiController;
	virtual void onMatchConnect();
	virtual void onMatchSetting();
	virtual void onMatchStart(Tizen::Base::String data);
	virtual void onMatchMyturn(Tizen::Base::String data);
	virtual void onMatchTurnWait();
	virtual void onMatchFinish(Tizen::Base::String data);

	int firstSelected, secondSelected;
	bool isGameFirst;
	Tizen::Ui::Controls::Label *pLabelScore2;

	// Cloud Save
	GHCloudsaveController *csController;
	virtual void saveCloudsaveFinished(int statusCode);
	bool isWin;



};

#endif	//_CARD_PAIR_FORM_MULTI_H_
