/*
 * GHPlayerLank.cpp
 *
 *  Created on: Apr 9, 2014
 *      Author: hursujung
 */

#include "GHPlayerRank.h"

using namespace Tizen::Base;

GHPlayerRank::GHPlayerRank() {
	// TODO Auto-generated constructor stub

}

GHPlayerRank::GHPlayerRank(String _id, String _name, String _imgUrl, int _rank, int _score)
// : id(_id), name(_name), imgUrl(_imgUrl)
{
//	this->id = _id;
//	this->name = _name;
	setId(_id);
	setName(_name);
	this->imgUrl = _imgUrl;
	this->score = _score;
	this->rank  = _rank;
}

GHPlayerRank::~GHPlayerRank() {
	// TODO Auto-generated destructor stub
}


int GHPlayerRank::getScore()
{
	return this->score;
}

int GHPlayerRank::getRank()
{
	return this->rank;
}
