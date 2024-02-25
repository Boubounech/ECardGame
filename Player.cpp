#include "Player.h"

Player::Player()
{

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