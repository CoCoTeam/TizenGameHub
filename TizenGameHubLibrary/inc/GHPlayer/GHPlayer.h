/*
 * GHPlayer.h
 *
 *  Created on: Mar 11, 2014
 *      Author: Administrator
 */

#ifndef GHPLAYER_H_
#define GHPLAYER_H_

#include "GHTizen.h"

class GHPlayer
	: public Tizen::Base::Object
{
protected:
	// variable
	Tizen::Base::String id;			// 사용자 고유 ID
	Tizen::Base::String email;		// 사용자 이메일
	Tizen::Base::String name;		// 사용자 이름
	Tizen::Base::String imgUrl;		// 사용자 프로필이미지 URL

	bool is_Friend;


public:
	GHPlayer();
	GHPlayer(Tizen::Base::String _id, Tizen::Base::String _email, Tizen::Base::String _name, Tizen::Base::String _imgUrl);
	GHPlayer(Tizen::Base::String _id, Tizen::Base::String _name, Tizen::Base::String _imgUrl);
	~GHPlayer();

	// GET Function ------------------------------------------------
	Tizen::Base::String getId();
	Tizen::Base::String getEmail();
	Tizen::Base::String getName();
	Tizen::Base::String getImgUrl();
	//----------------------------------------------------------------

	void setId(Tizen::Base::String _id);
	void setEmail(Tizen::Base::String _email);
	void setName(Tizen::Base::String _name);
	void setImgUrl(Tizen::Base::String _imgUrl);

	bool isFriend();
	void setIsFriend(bool b);
};

#endif /* GHUSER_H_ */
