#pragma once
#include "Board.h"
#include <iostream>
#include <sstream>
#include <map>

class TerminalBoard : public Board
{
private:
	std::string getCardRender(Card* card);

public:
	void mainScreen(Deck* cards) override;
	void cardSelection(Deck* cards) override;
	int processUserInputForCardSelection(Deck* cards) override;
	void displayTurnWin(std::string playerName) override;
	void displayTurnLose(std::string playerName) override;
	void displayTurnEquality() override;
};