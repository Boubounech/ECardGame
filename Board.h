#pragma once
#include "Player.h"

class Board
{
public:
	virtual void mainScreen(Player* p1, Player* p2) = 0;
	virtual void cardSelection(Player* player) = 0;
	virtual int processUserInputForCardSelection(Player* player) = 0;
	virtual void displayTurnWin(Player* player) = 0;
	virtual void displayTurnLose(Player* player) = 0;
	virtual void displayTurnEquality() = 0;
};