#include "FormGameTimeTrial.h"
#include "AppResourceId.h"

using namespace Tizen::Base;
using namespace Tizen::App;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Ui::Scenes;


FormGameTimeTrial::FormGameTimeTrial(void)
{
}

FormGameTimeTrial::~FormGameTimeTrial(void)
{
}
/*
 * 게임 진행 시간 Timer Label 설정
 */
result FormGameTimeTrial::SetGameTimer(Tizen::Base::TimeSpan ts)
{
	result r = E_SUCCESS;

	// Set StopWatch String
	setTimeLabel(ts);

	if( !isComplete ) {
		r = pTimerGame->Start(10);
		if (IsFailed(r))
		{
			AppLog("Timer Start Fail.\n");
			return r;
		}
	}

	return r;
}
/*
 * 스테이지 클리어 시 호출되는 함수(게임 종료)
 */
void FormGameTimeTrial::onStageComplete()
{
	AppLog("Complete Stage");


}
