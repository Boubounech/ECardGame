#pragma once
#include "Board.h"
#include "Player.h"
#include "CardDealer.h"

class GameManager
{
private:
	const static size_t NB_TURNS = 6;
	size_t nbTotalTurns;
	Board* board;
	Player* player1;
	Player* player2;
	size_t currentTurn = 0;

protected:
	bool started = false;

public:
	GameManager(Board* board, Player* p1, Player* p2, size_t nbTurns = NB_TURNS);
	virtual void startGame();
	virtual void startTurn();
	bool hasGameStarted() { return this->started; }
};