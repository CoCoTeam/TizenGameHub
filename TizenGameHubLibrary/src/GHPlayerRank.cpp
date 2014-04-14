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
{
//	this->id = _id;
//	this->name = _name;

	GHPlayer(id, name, imgUrl);
	//this->imgUrl = _imgUrl;
	this->score = _score;
	this->rank  = _rank;
}

GHPlayerRank::~GHPlayerRank() {
	// TODO Auto-generated destructor stub


}

/*String GHPlayerRank::getid()
{
	return this->id;
}*/

/*int setScore()
{
	return this->score;
}

int setRank()
{
	return this->rank;
}*/

int GHPlayerRank::getScore()
{
	return this->score;
}

int GHPlayerRank::getRank()
{
	return this->rank;
}

void GHPlayerRank::setScore(int _score)		{	this->score = _score;}
void GHPlayerRank::setRank(int _rank)	{	this->rank = _rank; }
