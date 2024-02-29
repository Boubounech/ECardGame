#pragma once
#include "Board.h"

class EmptyBoard : public Board
{
public:
	void mainScreen(Deck* cards) {}
	void cardSelection(Deck* cards) {}
	int processUserInputForCardSelection(Deck* cards) { return 0; }
	void displayTurnWin(std::string playerName) {}
	void displayTurnLose(std::string playerName) {}
	void displayTurnEquality() {}
};