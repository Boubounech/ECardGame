#pragma once
#include "Board.h"
#include <iostream>
#include <sstream>
#include <map>

class TerminalBoard : public Board
{
private:
	static std::map<CardType, char> cardRenderMap;
	std::string getCardRender(Card* card);

public:
	void mainScreen(Player* p1, Player* p2) override;
	void cardSelection(Player* player) override;
	int processUserInputForCardSelection(Player* player) override;
	void displayTurnWin(Player* player) override;
	void displayTurnLose(Player* player) override;
	void displayTurnEquality() override;
};