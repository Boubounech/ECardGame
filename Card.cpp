#include "Card.h"

std::map<CardType, CardType> Card::winsAgainstMap = {
	{ CITIZEN, SLAVE },
	{ KING, CITIZEN },
	{ SLAVE, KING }
};

std::map<CardType, int> Card::pointsInCaseOfVictory = {
	{ CITIZEN, 1 },
	{ KING, 1 },
	{ SLAVE, 5 }
};

Card::Card(CardType type)
{
	this->type = type;
}

bool Card::winsAgainst(Card* opponent)
{
	return this->winsAgainstMap.at(this->type) == opponent->type;
}

int Card::getPoints()
{
	return this->pointsInCaseOfVictory.at(this->type);
}
