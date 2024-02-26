#pragma once
#include "Card.h"
#include <array>
#include <string>

class Player
{
private:
	std::array<Card, 5> cards;
	int score = 0;
	std::string name = "Anonymous";

	int getIndexWithNone(int index);

public:
	Player();
	void giveCards(std::array<Card, 5> &cards);
	Card* getCardAt(int index);
	void addScore(int score);
	int getScore() { return this->score; }
	void setName(std::string name) { this->name = name; }
	std::string getName() { return this->name; }
	size_t getNbOfCards();
	void removeCard(int index);
};