#pragma once
#include <map>

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
	Card() = default;
	Card(CardType type);
	bool winsAgainst(Card* opponent);
	int getPoints();
	CardType getType();
};

