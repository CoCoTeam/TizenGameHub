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

	//AppLog("-----------------> game loadAchievements <----------------------");

	//AppLog("gameScore : %d", gameScore);
	Leaderboardcontroller->updateLeaderboardScore("key_aa_0", gameScore, this);

	// 리더보드
//	leaderboardUpdate(ld, gameScore);	// 최종 점수 리더보드 업데이트
}


void FormGameSeconds::OnActionPerformed(const Tizen::Ui::Control& source, int actionId)
{
	ParentOnActionPerformed(source, actionId);
	switch(actionId) {
	case ACTION_POPUP_CLOSE:
		delete pPopup;
		pPopup = null;
		break;
	}
}

//achievement
void FormGameSeconds::loadAchievementFinished(Tizen::Base::Collection::ArrayList* achievementList) {
	// TEST
	GHAchievement * test = static_cast<GHAchievement*>(achievementList->GetAt(1));
	AppLogDebug("[DEBUG] acArr ID : %S", test->getId().GetPointer() );
	AppLogDebug("[DEBUG] getGoalPoint : %d", test->getGoalPoint());
	AppLogDebug("[DEBUG] getCurPoint : %d", test->getCurPoint());

	GHAchievementController* Achievementcontroller;
	Achievementcontroller = new GHAchievementController();

	// 게임 횟수 카운트
	game_count = test->getCurPoint();
	AppLogDebug("game_count --> %d", game_count);

	if(game_count == 14)
	{
		AppLogDebug("%d 번 게임!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!", game_count);

		// 10 번 게임을 했을 때
		Achievementcontroller->completeAchievement("4",this);
	}
	else
	{
		game_count++;
		Achievementcontroller->setAchievement("4", game_count , this);  // 게임 카운트를 증가시켜 set 함
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

		pPopup = new Popup();
		pPopup->Construct(true, Tizen::Graphics::Dimension(600, 800));
		pPopup->SetTitleText("Leaderboard update !!");

		Button* pButtonClose = new Button();
		pButtonClose->Construct(Tizen::Graphics::Rectangle(100, 600, 400, 100), "닫  기");
		pButtonClose->SetActionId(ACTION_POPUP_CLOSE);
		pButtonClose->AddActionEventListener(*this);
		pPopup->AddControl(pButtonClose);

		pPopup->SetShowState(true);
		pPopup->Show();

	}
	else if(statusCode == 2)
	{
		AppLogDebug("--------------> No Update <-----------------");
	}
}
/*void FormGameSeconds::revealAchievementFinished(int statusCode)
{
	AppLogDebug("[DEBUG] revealAchievementFinished statusCode : %d", statusCode);
}*/
