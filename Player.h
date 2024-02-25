#include "Card.h"
#include <array>
#pragma once

class Player
{
private:
	std::array<Card, 5> cards;
	int score = 0;

public:
	Player();
	void giveCards(std::array<Card, 5> &cards);
	Card* getCardAt(int index);
	void addScore(int score);
	int getScore() { return this->score; }
};