/*
 * GHLeaderboard.h
 *
 *  Created on: Mar 24, 2014
 *      Author: Administrator
 */

#ifndef GHLEADERBOARD_H_
#define GHLEADERBOARD_H_

#include "GHTizen.h"

class GHLeaderboard
: public Tizen::Base::Object {

private:

	//----------------------------------------------------------------
	// variables
	Tizen::Base::String id;		// leaderboard 고유키
	Tizen::Base::String title;	// leaderboard 제목
	Tizen::Base::String imgUrl;	// leaderboard 대표 이미지
	Tizen::Base::String unit;	// leaderboard 표시 단위

	bool isAscendingOrder;		// 정렬 순서 ()
	bool isTimeFormat;			// 데이터 타입 시간 ()

	Tizen::Base::Collection::ArrayList* learderboardRankList;	// 해당 leaderboard의 ranking List

public:
	GHLeaderboard();
	GHLeaderboard(Tizen::Base::String _id, Tizen::Base::String _title, Tizen::Base::String _imgUrl, Tizen::Base::String _unit, bool _isAscendingOrder, bool _isTimeFormat);
	GHLeaderboard(Tizen::Base::String _id, Tizen::Base::String _title, Tizen::Base::String _imgUrl);
	GHLeaderboard(Tizen::Base::String _id, Tizen::Base::String _unit, bool _isAscendingOrder, bool _isTimeFormat, Tizen::Base::Collection::ArrayList* _learderboardRankList);
	virtual ~GHLeaderboard();

	// GET Functions--------------------------------------------------
	Tizen::Base::String getId();
	Tizen::Base::String getTitle();
	Tizen::Base::String getImgUrl();
	Tizen::Base::String getUnit();

	bool getIsAscendingOrder();
	bool getIsTimeFormat();

	Tizen::Base::Collection::ArrayList* getRankList();
	//----------------------------------------------------------------
};

#endif /* GHLEADERBOARD_H_ */
