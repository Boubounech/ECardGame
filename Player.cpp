#include "Player.h"

Player::Player()
{
	this->cards = std::array<Card, 5> {
			Card(CITIZEN),
			Card(CITIZEN),
			Card(CITIZEN),
			Card(CITIZEN),
			Card(CITIZEN)
	};
}

void Player::giveCards(std::array<Card, 5> &cards) 
{
	this->cards = cards;
}

Card* Player::getCardAt(int index)
{
	return &this->cards[index];
}

void Player::addScore(int score)
{
	this->score += score;
}