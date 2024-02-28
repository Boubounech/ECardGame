#pragma once
#include <string>
#include "Card.h"
#include "Deck.h"
#include "Board.h"

class Player
{
private:
	int score = 0;
	Board* board;
	Deck* deck;
	std::string name = "Anonymous";

public:
	Player(Board* board);

	int getChosenCard();
	void displayVictory();
	void displayDefeat();
	void displayEquality();

	void addScore(int score);
	int getScore() { return this->score; }

	void giveCards(Deck* deck);
	Card* getCardAt(int index);
	size_t getNbOfCards();
	void removeCard(int index);

	void setName(std::string name) { this->name = name; }
	std::string getName() { return this->name; }
};