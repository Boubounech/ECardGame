#pragma once
#include "Player.h"

class Board
{
public:
	virtual void mainScreen(Player* p1, Player* p2) = 0;
	virtual void cardSelection() = 0;
};