#include "GameManager.h"

GameManager::GameManager(Board* board, Player* p1, Player* p2)
{
	this->board = board;
	this->player1 = p1;
	this->player2 = p2;
}

void GameManager::startGame()
{
	this->started = true;
	CardDealer::dealCards(this->player1, this->player2);
	this->board->mainScreen(this->player1, this->player2);
}
