/*
 * GHPlayer.h
 *
 *  Created on: Mar 11, 2014
 *      Author: Administrator
 */

#ifndef GHPLAYER_H_
#define GHPLAYER_H_

#include <GHTizen.h>
/*
player_id	사용자 고유키
email		사용자 계정 id (email)
pwd			password
name		보여지는 이름 (NickName)
img_url		프로필 이미지 url
*/
/*
getGameInstance();
 */
class GHPlayer{
protected:
	long id;			// 사용자 고유 ID
	STRING* email;		// 사용자 이메일
	STRING* name;		// 사용자 이름
	STRING* imgUrl;		// 사용자 프로필이미지 URL

	long totalScore;	// 사용자별 Achievement 총합 점수

public:
	GHPlayer();
	GHPlayer(long _id, STRING _email, STRING _name, STRING _imgUrl);
//	GHPlayer(Tizen::Web::Json::JsonObject *jsonData);
	~GHPlayer();

	/// Get Instance
//	static GHPlayer* getPlayerInstance(long playerId)
//	{
//		Tizen::Web::Json::JsonObject *jsonData;
//		jsonData->Construct();
//		return new GHPlayer(jsonData);
//	}
	//////////

	/// Get Functions
	long getId();
	STRING* getEmail();
	STRING* getName();
	STRING* getImgUrl();

	long getTotalScore();
	//////////


};

#endif /* GHUSER_H_ */
