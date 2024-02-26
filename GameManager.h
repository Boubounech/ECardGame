#pragma once
#include "Board.h"
#include "Player.h"
#include "CardDealer.h"

class GameManager
{
private:
	Board* board;
	Player* player1;
	Player* player2;

protected:
	bool started = false;

public:
	GameManager(Board* board, Player* p1, Player* p2);
	virtual void startGame();
	bool hasGameStarted() { return this->started; }
};