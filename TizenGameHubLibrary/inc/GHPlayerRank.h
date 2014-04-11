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
public:
	GHPlayerRank();
	virtual ~GHPlayerRank();

	int score; // 개인당 score
	int rank;  // 개인 순위

	// {lb_id, unit, lb_order, is_time, values:[{p_id, p_name, p_url, rank, score}, {}...]}

	GHPlayerRank(Tizen::Base::String _id, Tizen::Base::String _name, Tizen::Base::String _imgUrl, int _rank, int _score);
};
#endif /* GHPLAYERRANK_H_ */
