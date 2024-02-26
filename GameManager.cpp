#include "GameManager.h"

GameManager::GameManager(Board* board, Player* p1, Player* p2)
{
	this->nbTotalTurns = 0;
	this->board = board;
	this->player1 = p1;
	this->player2 = p2;
}

void GameManager::startGame(size_t nbTotalTurns)
{
	this->nbTotalTurns = nbTotalTurns;
	this->started = true;
	this->currentTurn++;
	while (this->currentTurn <= nbTotalTurns) {
		this->startTurn();
		this->currentTurn++;
	}
}

void GameManager::startTurn()
{
	CardDealer::dealCards(this->player1, this->player2);
	bool endOfTurn = false;
	this->board->mainScreen(this->player1, this->player2);

	do {
		this->board->cardSelection(this->player1);
		int cardChosenP1 = this->board->processUserInputForCardSelection(this->player1);
		this->board->cardSelection(this->player2);
		int cardChosenP2 = this->board->processUserInputForCardSelection(this->player2);

		if (player1->getCardAt(cardChosenP1)->winsAgainst(
			player2->getCardAt(cardChosenP2))) {
			this->board->displayTurnWin(player1);
			this->board->displayTurnLose(player2);
			endOfTurn = true;
		}
		else if (player2->getCardAt(cardChosenP2)->winsAgainst(
			player1->getCardAt(cardChosenP1))) {
			this->board->displayTurnLose(player1);
			this->board->displayTurnWin(player2);
			endOfTurn = true;
		}
		else {
			this->board->displayTurnEquality();
		}
	} while (!endOfTurn);
}
