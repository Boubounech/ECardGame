#include "CardDealer.h"

void CardDealer::dealCards(Player* p1, Player* p2)
{
	std::random_device rd;
	std::mt19937 seed(rd()); // Mersenne Twister 19937 comme générateur
	std::uniform_int_distribution<> randomBool(0, 1);

	std::array<Card, 5> kingArray = std::array<Card, 5> {
		Card(CITIZEN),Card(CITIZEN),Card(KING),Card(CITIZEN),Card(CITIZEN),
	};
	std::array<Card, 5> slaveArray = std::array<Card, 5> {
		Card(CITIZEN),Card(CITIZEN),Card(SLAVE),Card(CITIZEN),Card(CITIZEN),
	};

	bool isKingForP1 = randomBool(seed);
	if (isKingForP1) {
		p1->giveCards(kingArray);
		p2->giveCards(slaveArray);
	}
	else {
		p1->giveCards(slaveArray);
		p2->giveCards(kingArray);
	}
}
