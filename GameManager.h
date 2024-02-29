#pragma once
#include "Board.h"
#include "Player.h"
#include "CardDealer.h"

class GameManager
{
private:
	const static size_t NB_TURNS = 6;
	size_t nbTotalTurns = NB_TURNS;
	Player* player1;
	Player* player2;
	size_t currentTurn = 0;

protected:
	bool started = false;

public:
	GameManager();
	size_t getNumberOfTurns() { return this->nbTotalTurns; }
	void setNumberOfTurns(size_t nbTurns) { this->nbTotalTurns = nbTurns; }
	void addPlayer(Player* player);
	virtual void startGame();
	virtual void startTurn();
	bool isGameReady();
	bool hasGameStarted() { return this->started; }
};