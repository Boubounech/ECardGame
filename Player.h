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

	virtual int getChosenCard();
	virtual void displayVictory();
	virtual void displayDefeat();
	virtual void displayEquality();

	virtual void addScore(int score);
	virtual int getScore() { return this->score; }

	virtual void giveCards(Deck* deck);
	virtual Card* getCardAt(int index);
	virtual size_t getNbOfCards();
	virtual void removeCard(int index);

	virtual void setName(std::string name) { this->name = name; }
	virtual std::string getName() { return this->name; }
};