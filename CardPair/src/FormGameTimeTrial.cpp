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
	String timeStr = pLabelTimer->GetText();		// mm:ss:msms
	int totalMis = getMillisec(timeStr);
//	maxCombo

}

int FormGameTimeTrial::getMillisec(String timeStr)
{
	String sMin, sSec, sMis;
	int iMin, iSec, iMis;
	timeStr.SubString(0,2,sMin);
	timeStr.SubString(3,2,sSec);
	timeStr.SubString(6,2,sMis);

	Integer::Parse(sMin, iMin);
	Integer::Parse(sSec, iSec);
	Integer::Parse(sMis, iMis);


	return iMis + iSec*100 + iMin*60*100;
}