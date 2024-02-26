#include "Player.h"

Player::Player()
{
	this->cards = std::array<Card, 5> {
			Card(NONE),
			Card(NONE),
			Card(NONE),
			Card(NONE),
			Card(NONE)
	};
}

void Player::giveCards(std::array<Card, 5> &cards) 
{
	this->cards = cards;
}

Card* Player::getCardAt(int index)
{
	return &this->cards[this->getIndexWithNone(index)];
}

int Player::getIndexWithNone(int index)
{
	size_t realCardCounter = 0;
	for (int i = 0; i < this->cards.size(); i++) {
		if (this->cards[i].getType() != NONE) {
			if (realCardCounter == index) {
				return i;
			}
			realCardCounter++;
		}
	}
	return 0;
}

void Player::addScore(int score)
{
	this->score += score;
}

size_t Player::getNbOfCards()
{
	size_t nbCards = 0;
	for (Card c : this->cards)
	{
		if (c.getType() != NONE) {
			nbCards++;
		}
	}
	return nbCards;
}

void Player::removeCard(int index)
{
	if (index >= 0 && index < this->getNbOfCards()) {
		this->cards[this->getIndexWithNone(index)] = Card(NONE);
	}
}