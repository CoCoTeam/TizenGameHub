/*
 * GHGame.h
 *
 *  Created on: Mar 11, 2014
 *      Author: Administrator
 */

#ifndef GHGAME_H_
#define GHGAME_H_

#include <GHTizen.h>
class GHGame
	: public Tizen::Base::Object
{
private:
	Tizen::Base::String id;				// 게임 고유 ID
	Tizen::Base::String developerId;	// 게임 개발자 고유 ID
	Tizen::Base::String title;			// 게임 제목
	Tizen::Base::String description;	// 게임 설명
	Tizen::Base::String imgUrl;			// 게임 아이콘 이미지 URL

	int leaderboardCount;				// 게임에서 사용하는 leaderboard 개수
	int achievementCount;				// 게임에서 사용하는 achievement 개수
	int attackhelperCount;				// 게임에서 사용하는 attack-helper 개수
	bool misCloudsaveEnable;			// cloudsave 사용 여부
	bool misTurnbasedMultiEnable;		// multiplay 사용 여부

	bool misPlaying;					// 사용자 플레이 여부

public:
	GHGame();
	GHGame(Tizen::Base::String _id, Tizen::Base::String _developerId, Tizen::Base::String _title, Tizen::Base::String _description, Tizen::Base::String _imgUrl,
		int _leaderboardCount, int _achievementCount, int _attackhelperCount, bool _isCloudsaveEnable, bool _isTurnbasedMultiEnable);
	virtual ~GHGame();

	/// Get Instance
	static GHGame* currentGame;

	// GET Functions--------------------------------------------------
	Tizen::Base::String getId();
	Tizen::Base::String getDeveloperId();
	Tizen::Base::String getTitle();
	Tizen::Base::String getDescription();
	Tizen::Base::String getImgUrl();

	int getLeaderboardCount();
	int getAcheievementCount();
	int getAttackHelperCount();
	bool isCloudsaveEnable();
	bool isTurnbasedMultiEnable();
	//----------------------------------------------------------------

	bool isPlaying();
	void setIsPlaying(bool b);


};

#endif /* GHGAME_H_ */
