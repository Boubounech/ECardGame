#pragma once
#include <map>

enum CardType {
	CITIZEN,
	KING,
	SLAVE,
	NONE
};

class Card
{
private:
	CardType type;

	static std::map<CardType, CardType> winsAgainstMap;
	static std::map<CardType, int> pointsInCaseOfVictory;
	static std::map<CardType, char> cardToIdentifier;
	static std::map<char, CardType> identifierToCard;

public:
	Card() = default;
	Card(CardType type);
	bool winsAgainst(Card* opponent);
	int getPoints();
	CardType getType();
	char getCardIdentifier();
	static Card createFromIdentifier(char id);
};

