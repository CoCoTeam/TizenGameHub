/*
 * GHPlayerLank.h
 *
 *  Created on: Apr 9, 2014
 *      Author: hursujung
 */

#ifndef GHPLAYERRANK_H_
#define GHPLAYERRANK_H_

#include "GHPlayer.h"

class GHPlayerRank
	: public GHPlayer
{
private:
	int score; // 개인당 score
	int rank;  // 개인 순위

public:
	GHPlayerRank();
	virtual ~GHPlayerRank();
	GHPlayerRank(Tizen::Base::String _id, Tizen::Base::String _name, Tizen::Base::String _imgUrl, int _rank, int _score);

	//String getid();
	int getScore();
	int getRank();

	void setScore(int score);
	void setRank(int rank);

};
#endif /* GHPLAYERRANK_H_ */
