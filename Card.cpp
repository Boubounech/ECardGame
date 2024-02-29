#include "Card.h"

std::map<CardType, CardType> Card::winsAgainstMap = {
	{ CITIZEN, SLAVE },
	{ KING, CITIZEN },
	{ SLAVE, KING },
	{ NONE, NONE }
};

std::map<CardType, int> Card::pointsInCaseOfVictory = {
	{ CITIZEN, 1 },
	{ KING, 1 },
	{ SLAVE, 5 },
	{ NONE, 0 }
};

std::map<CardType, char> Card::cardToIdentifier = {
	{ CITIZEN, 'C'},
	{ KING, 'K'},
	{ SLAVE, 'S'},
	{ NONE, '#'}
};

std::map<char, CardType> Card::identifierToCard = {
	{ 'C', CITIZEN},
	{ 'K', KING },
	{ 'S', SLAVE },
	{ '#', NONE }
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

CardType Card::getType()
{
	return this->type;
}

char Card::getCardIdentifier()
{
	return this->cardToIdentifier.at(this->type);
}

Card Card::createFromIdentifier(char id)
{
	return Card(identifierToCard.at(id));
}
