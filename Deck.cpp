#include "Deck.h"


Card* Deck::getCardAt(int index)
{
	return &this->cards[this->getIndexWithNone(index)];
}

int Deck::getIndexWithNone(int index)
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

size_t Deck::getNbOfCards()
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

void Deck::removeCard(int index)
{
	if (index >= 0 && index < this->getNbOfCards()) {
		this->cards[this->getIndexWithNone(index)] = Card(NONE);
	}
}
