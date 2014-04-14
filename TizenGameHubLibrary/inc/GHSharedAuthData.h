/*
 * GHSharedAuthData.h
 *
 *  Created on: Apr 10, 2014
 *      Author: KICHUL
 */

#ifndef GHSHAREDAUTHDATA_H_
#define GHSHAREDAUTHDATA_H_

#include <GHTizen.h>

class GHSharedAuthData {
private:
	static GHSharedAuthData* sharedInstance;

	GHSharedAuthData() : game_id(null), player_id(null){};
	GHSharedAuthData(const GHSharedAuthData& shared);
	void operator=(const GHSharedAuthData& shared);

public:
	virtual ~GHSharedAuthData(){};

	static GHSharedAuthData& getSharedInstance(){
		if(sharedInstance == null){
			sharedInstance = new GHSharedAuthData;
		}
		return *sharedInstance;
	}

private:
	Tizen::Base::String game_id;
	Tizen::Base::String player_id;
	Tizen::Base::String lb_id;

public:
	void setGameId(Tizen::Base::String gameId){
		this->game_id = gameId;
	}

	void setPlayerId(Tizen::Base::String playerId){
		this->player_id = playerId;
	}
	void setLeaderboardId(Tizen::Base::String playerId){
		this->player_id = playerId;
	}

	Tizen::Base::String getGameId(){
		return this->game_id;
	}

	Tizen::Base::String getPlayerId(){
		return this->player_id;
	}

	Tizen::Base::String getLeaderboardId(){
		return this->lb_id;
	}
};

#endif /* GHSHAREDAUTHDATA_H_ */
