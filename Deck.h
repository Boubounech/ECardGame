#pragma once
#include "Card.h"
#include <array>

class Deck
{
private:
	std::array<Card, 5> cards;

	int getIndexWithNone(int index);

public:
	Deck() {
		this->cards = std::array<Card, 5> {
			Card(NONE), Card(NONE), Card(NONE), Card(NONE), Card(NONE)
		};
	}
	Deck(std::array<Card, 5>& cards) { this->cards = cards; }
	Card* getCardAt(int index);
	size_t getNbOfCards();
	void removeCard(int index);
};