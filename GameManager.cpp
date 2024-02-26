#include "GameManager.h"

GameManager::GameManager(Board* board, Player* p1, Player* p2, size_t nbTurns)
{
	this->nbTotalTurns = nbTurns;
	this->board = board;
	this->player1 = p1;
	this->player2 = p2;
}

void GameManager::startGame()
{
	this->started = true;
	this->currentTurn++;
	while (this->currentTurn <= this->nbTotalTurns) {
		this->startTurn();
		this->currentTurn++;
	}
}

void GameManager::startTurn()
{
	CardDealer::dealCards(this->player1, this->player2);
	bool endOfTurn = false;

	do {
		this->board->mainScreen(this->player1, this->player2);
		this->board->cardSelection(this->player1);
		int cardChosenP1 = this->board->processUserInputForCardSelection(this->player1);
		this->board->cardSelection(this->player2);
		int cardChosenP2 = this->board->processUserInputForCardSelection(this->player2);

		if (player1->getCardAt(cardChosenP1)->winsAgainst(
			player2->getCardAt(cardChosenP2))) {
			this->board->displayTurnWin(player1);
			this->board->displayTurnLose(player2);
			player1->addScore(player1->getCardAt(cardChosenP1)->getPoints());
			endOfTurn = true;
		}
		else if (player2->getCardAt(cardChosenP2)->winsAgainst(
			player1->getCardAt(cardChosenP1))) {
			this->board->displayTurnLose(player1);
			this->board->displayTurnWin(player2);
			player2->addScore(player2->getCardAt(cardChosenP2)->getPoints());
			endOfTurn = true;
		}
		else {
			player1->removeCard(cardChosenP1);
			player2->removeCard(cardChosenP2);
			this->board->displayTurnEquality();
		}
	} while (!endOfTurn);
}
