#pragma once
#include "Card.h"
#include "Deck.h"
#include <string>

class Board
{
public:
	virtual void mainScreen(Deck* cards) = 0;
	virtual void cardSelection(Deck* cards) = 0;
	virtual int processUserInputForCardSelection(Deck* cards) = 0;
	virtual void displayTurnWin(std::string playerName) = 0;
	virtual void displayTurnLose(std::string playerName) = 0;
	virtual void displayTurnEquality() = 0;
};