#include "Player.h"

Player::Player(Board* board)
{
	this->board = board;
	this->deck = new Deck();
}

int Player::getChosenCard()
{
	this->board->mainScreen(this->deck);
	this->board->cardSelection(this->deck);
	return this->board->processUserInputForCardSelection(this->deck);
}

void Player::displayVictory()
{
	this->board->displayTurnWin(this->name);
}

void Player::displayDefeat()
{
	this->board->displayTurnLose(this->name);
}

void Player::displayEquality()
{
	this->board->displayTurnEquality();
}


void Player::addScore(int score)
{
	this->score += score;
}

void Player::giveCards(Deck* deck)
{
	this->deck = deck;
}

Card* Player::getCardAt(int index)
{
	return this->deck->getCardAt(index);
}

size_t Player::getNbOfCards()
{
	return this->deck->getNbOfCards();
}

void Player::removeCard(int index)
{
	this->deck->removeCard(index);
}
