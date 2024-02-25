#include <map>
#pragma once

enum CardType {
	CITIZEN,
	KING,
	SLAVE
};

class Card
{
private:
	CardType type;

	static std::map<CardType, CardType> winsAgainstMap;
	static std::map<CardType, int> pointsInCaseOfVictory;

public:
	Card(CardType type);
	bool winsAgainst(Card* opponent);
	int getPoints();
};
