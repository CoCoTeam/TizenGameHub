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

	initialTime = timespan.GetTicks();

	// 새로운 게임 시작
	for(int i=0 ; i<MAX_CARD_SIZE ; i++) {
		pButtonCard[i]->SetShowState(true);

	}
	setInitialState();

	//game_count++;


}
/*
 * 시간 종료 시 호출되는 함수 (게임 종료)
 */
void FormGameSeconds::onGameEnded()
{
	AppLog("onGameEnded()");
	pLabelTimer->SetText("00:00:00");


	GHAchievementController* Achievementcontroller = new GHAchievementController();
	GHLeaderboardController* Leaderboardcontroller = new GHLeaderboardController();

	if(maxCombo >= 5)
	{
		Achievementcontroller->completeAchievement("4",this);
		AppLog("totalMis complete !!");
	}

	Achievementcontroller->loadAchievements(this);
	Achievementcontroller->setAchievement("4", 10 , this);  // 10번 수행 했을 때
	Achievementcontroller->loadAchievements(this);


	Leaderboardcontroller->updateLeaderboardScore("key_aa_0", gameScore, this);

	// 리더보드
//	leaderboardUpdate(ld, gameScore);	// 최종 점수 리더보드 업데이트


}

//achievement
void FormGameSeconds::loadAchievementFinished(Tizen::Base::Collection::ArrayList* achievementList) {
	// TEST
	GHAchievement * test = static_cast<GHAchievement*>(achievementList->GetAt(1));
	AppLogDebug("[DEBUG] acArr ID : %S", test->getId().GetPointer() );
	AppLogDebug("[DEBUG] getGoalPoint : %d", test->getGoalPoint());
	AppLogDebug("[DEBUG] getCurPoint : %d", test->getCurPoint());

	if(test->getCurPoint() == 10)
	{
		// 10 번 게임을 했을 때
		GHAchievementController* Achievementcontroller = new GHAchievementController();
		Achievementcontroller->completeAchievement("4",this);

		/*Tizen::Ui::Controls::Popup* pPopup = new Tizen::Ui::Controls::Popup();
		pPopup->Construct(true, Tizen::Graphics::Dimension(600, 800));
		pPopup->SetTitleText("Attack-Helper");

		pPopup->SetShowState(true);
		pPopup->Show();*/
	}
}
void FormGameSeconds::setAchievementFinished(int statusCode)
{
	AppLogDebug("[DEBUG] setAchievementFinishedstatusCode : %d", statusCode);
}

void FormGameSeconds::completeAchievementFinished(int statusCode)
{
	AppLogDebug("[DEBUG] completeAchievementFinished statusCode ===> : %d", statusCode);
}


void FormGameSeconds::updateLeaderboardScoreFinished(int statusCode)
{
	AppLogDebug("[DEBUG] updateLeaderboardScoreFinished statusCode : %d", statusCode);

	if(statusCode == 1)
	{
		AppLogDebug("--------------> Update <-----------------");

	}
	else if(statusCode == 2)
	{
		AppLogDebug("--------------> No Update <-----------------");
	}
}
