/*
 * GHGame.h
 *
 *  Created on: Mar 11, 2014
 *      Author: Administrator
 */

#ifndef GHGAME_H_
#define GHGAME_H_

#include <GHTizen.h>
/*
game_id				게임 고유키
developer_id		해당 게임 개발자 고유키	FK_Developer
title				게임 제목
description			게임 설명
img_url				게임 대표 이미지 url
is_cloudsave		클라우드 세이브 사용 여부 	bool
category			게임 카테고리
leaderboardCount	Leaderboard 개수
achievementCount	Achievement 개수
isTurnbasedMultiEnable	multiplay 가능 여부
*/
/*
getGameInstance
 */
class GHGame {
private:
	Tizen::Base::String* id;			// 게임 고유 ID
	long developerId;					// 게임 개발자 고유 ID
	Tizen::Base::String* title;			// 게임 제목
	Tizen::Base::String* description;	// 게임 설명
	Tizen::Base::String* imgUrl;		// 게임 아이콘 이미지 URL

	int leaderboardCount;				// 게임에서 사용하는 leaderboard 개수
	int achievementCount;				// 게임에서 사용하는 achievement 개수
	int attackhelperCount;				// 게임에서 사용하는 attack-helper 개수
	bool misCloudsaveEnable;			// cloudsave 사용 여부
	bool misTurnbasedMultiEnable;		// multiplay 사용 여부


public:
	GHGame();
	GHGame(STRING _id, long _developerId, STRING _title, STRING _description, STRING _imgUrl,
		int _leaderboardCount, int _achievementCount, int _attackhelperCount, bool _isCloudsaveEnable, bool _isTurnbasedMultiEnable);
//	GHGame(Tizen::Web::Json::JsonObject *jsonData);
	virtual ~GHGame();

	/// Get Instance
	static GHGame* currentGame;
//	static GHGame* getGameInstance(long gameId)
//	{
//		if(currentGame == null)
//		{
//			Tizen::Web::Json::JsonObject *jsonData;
//			jsonData->Construct();
//			currentGame = new GHGame(jsonData);
//		}
//		return currentGame;
//	}
	//////////

	/// Get Functions
	Tizen::Base::String* getId();
	long getDeveloperId();
	Tizen::Base::String* getTitle();
	Tizen::Base::String* getDescription();
	Tizen::Base::String* getImgUrl();

	int getLeaderboardCount();
	int getAcheievementCount();
	int getAttackHelperCount();
	bool isCloudsaveEnable();
	bool isTurnbasedMultiEnable();
	//////////



};

#endif /* GHGAME_H_ */
