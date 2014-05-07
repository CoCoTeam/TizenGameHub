#include "FormGameSeconds.h"
#include "AppResourceId.h"

using namespace Tizen::Base;
using namespace Tizen::App;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Ui::Scenes;


FormGameSeconds::FormGameSeconds(void)
{
	initialTime = GAME_SEC*1000;
}

FormGameSeconds::~FormGameSeconds(void)
{
}
/*
 * 게임 진행 시간 Timer Label 설정
 */
result FormGameSeconds::SetGameTimer(Tizen::Base::TimeSpan ts)
{
	result r = E_SUCCESS;

	Tizen::Base::TimeSpan span(initialTime - ts.GetTicks());
	timespan = span;

	// Set StopWatch String
	setTimeLabel(span);

	if(span.GetTicks() <= 0) {
		// 게임 종료
		isClickable = false;

		onGameEnded();

	}
	else {
		if( !isComplete ) {
			r = pTimerGame->Start(10);
			if (IsFailed(r))
			{
				AppLog("Timer Start Fail.\n");
				return r;
			}
		}
	}

	return r;
}
/*
 * 스테이지 클리어 시 호출되는 함수
 */
void FormGameSeconds::onStageComplete()
{
	AppLog("Complete Stage");

	pTimerGame->Cancel();
	initialTime = timespan.GetTicks();

	// 새로운 게임 시작
	for(int i=0 ; i<MAX_CARD_SIZE ; i++) {
		pButtonCard[i]->SetShowState(true);

	}
	setInitialState();
}
/*
 * 시간 종료 시 호출되는 함수 (게임 종료)
 */
void FormGameSeconds::onGameEnded()
{
	AppLog("onGameEnded()");
	pTimerGame->Cancel();
	pLabelTimer->SetText("00:00:00");

}
