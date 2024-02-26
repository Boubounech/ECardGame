#include "TerminalBoard.h"

std::map<CardType, char> TerminalBoard::cardRenderMap = {
	{ CITIZEN, 'C' },
	{ KING, 'K' },
	{ SLAVE, 'S' },
	{ NONE, '#'}
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
	for (size_t i = 0; i < p1->getNbOfCards(); i++) {
		mainScreen += this->getCardRender(p1->getCardAt(i));
	}
	mainScreen += "\n\n\n";
	for (size_t i = 0; i < p2->getNbOfCards(); i++) {
		mainScreen += this->getCardRender(p2->getCardAt(i));
	}
	std::cout << mainScreen << std::endl;
}

void TerminalBoard::cardSelection(Player* player)
{
	std::cout << std::endl << "Select the card to play:" << std::endl;
	for (size_t i = 0; i < player->getNbOfCards(); i++) {
		std::cout << " " << i << "." << this->getCardRender(player->getCardAt(i)) << std::endl;
	}
}

int TerminalBoard::processUserInputForCardSelection(Player* player)
{
	std::string response;
	std::getline(std::cin, response);
	int cardChosen = std::stoi(response);
	if (cardChosen >= 0 && cardChosen < 5) {
		std::cout 
			<< "[" << player->getName() << "] "
			<< "Card chosen: " << cardChosen << "." 
			<< this->getCardRender(player->getCardAt(cardChosen)) << std::endl;
		return cardChosen;
	}
	else {
		std::cout << "Please enter a valid number." << std::endl;
		return this->processUserInputForCardSelection(player);
	}
}

void TerminalBoard::displayTurnWin(Player* player)
{
	std::cout << player->getName() << " wins this turn!" << std::endl << std::endl;
}

void TerminalBoard::displayTurnLose(Player* player)
{
	std::cout << player->getName() << " loses this turn!" << std::endl << std::endl;
}

void TerminalBoard::displayTurnEquality()
{
	std::cout << "Equality, turn continues..." << std::endl << std::endl;
}
