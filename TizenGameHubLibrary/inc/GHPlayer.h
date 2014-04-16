/*
 * GHPlayer.h
 *
 *  Created on: Mar 11, 2014
 *      Author: Administrator
 */

#ifndef GHPLAYER_H_
#define GHPLAYER_H_

#include "GHTizen.h"
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
class GHPlayer
	: public Tizen::Base::Object
{
protected:
	// variable
	Tizen::Base::String id;			// 사용자 고유 ID
	Tizen::Base::String email;		// 사용자 이메일
	Tizen::Base::String name;		// 사용자 이름
	Tizen::Base::String imgUrl;		// 사용자 프로필이미지 URL

	long totalScore;	// 사용자별 Achievement 총합 점수

public:
	GHPlayer();
	GHPlayer(Tizen::Base::String _id, Tizen::Base::String _email, Tizen::Base::String _name, Tizen::Base::String _imgUrl);
	GHPlayer(Tizen::Base::String _id, Tizen::Base::String _name, Tizen::Base::String _imgUrl);

	//	GHPlayer(Tizen::Web::Json::JsonObject *jsonData);
	~GHPlayer();

	// GET Function ------------------------------------------------
	Tizen::Base::String getId();
	Tizen::Base::String getEmail();
	Tizen::Base::String getName();
	Tizen::Base::String getImgUrl();


	void setId(Tizen::Base::String _id);
	void setEmail(Tizen::Base::String _email);
	void setName(Tizen::Base::String _name);
	void setImgUrl(Tizen::Base::String _imgUrl);



	long getTotalScore();
	//----------------------------------------------------------------
	//void setId(Tizen::Base::String _id){id = _id;}
	//void setName(Tizen::Base::String _name){name = _name;}

};

#endif /* GHUSER_H_ */
