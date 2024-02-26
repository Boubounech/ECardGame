#include "TerminalBoard.h"

std::map<CardType, char> TerminalBoard::cardRenderMap = {
	{ CITIZEN, 'C' },
	{ KING, 'K' },
	{ SLAVE, 'S' }
};

std::string TerminalBoard::getCardRender(Card* card)
{
	char value = this->cardRenderMap.at(card->getType());
	std::string cardRender = " |";
	cardRender += value;
	cardRender += "| ";
	return cardRender;
}

void TerminalBoard::mainScreen(Player* p1, Player* p2)
{
	std::string mainScreen = "";
	for (size_t i = 0; i < 5; i++) {
		mainScreen += this->getCardRender(p1->getCardAt(i));
	}
	mainScreen += "\n\n\n";
	for (size_t i = 0; i < 5; i++) {
		mainScreen += this->getCardRender(p2->getCardAt(i));
	}
	std::cout << mainScreen << std::endl;
}

void TerminalBoard::cardSelection()
{
	std::cout << "" << std::endl;
}