#include "GameManager.h"

GameManager::GameManager()
{
}

void GameManager::addPlayer(Player* player)
{
	if (this->player1 == NULL) {
		this->player1 = player;
	}
	else {
		this->player2 = player;
	}
}

void GameManager::startGame()
{
	if (this->isGameReady()) {
		this->started = true;
		this->currentTurn++;
		while (this->currentTurn <= this->nbTotalTurns) {
			this->startTurn();
			this->currentTurn++;
		}
	}
}

void GameManager::startTurn()
{
	CardDealer::dealCards(this->player1, this->player2);
	bool endOfTurn = false;

	do {
		int cardChosenP1 = this->player1->getChosenCard();
		int cardChosenP2 = this->player2->getChosenCard();

		if (player1->getCardAt(cardChosenP1)->winsAgainst(
			player2->getCardAt(cardChosenP2))) {
			this->player1->displayVictory();
			this->player2->displayDefeat();
			player1->addScore(player1->getCardAt(cardChosenP1)->getPoints());
			endOfTurn = true;
		}
		else if (player2->getCardAt(cardChosenP2)->winsAgainst(
			player1->getCardAt(cardChosenP1))) {
			this->player1->displayDefeat();
			this->player2->displayVictory();
			player2->addScore(player2->getCardAt(cardChosenP2)->getPoints());
			endOfTurn = true;
		}
		else {
			player1->removeCard(cardChosenP1);
			player2->removeCard(cardChosenP2);
			this->player1->displayEquality();
			this->player2->displayEquality();
		}
	} while (!endOfTurn);
}

bool GameManager::isGameReady()
{
	return this->player1 != NULL && this->player2 != NULL;
}
