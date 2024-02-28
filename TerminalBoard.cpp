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

void TerminalBoard::mainScreen(Deck* cards)
{
	std::string mainScreen = "";
	Card* tempCard = new Card(NONE);
	for (size_t i = 0; i < cards->getNbOfCards(); i++) {
		mainScreen += this->getCardRender(tempCard);
	}
	delete tempCard;
	mainScreen += "\n\n\n";
	for (size_t i = 0; i < cards->getNbOfCards(); i++) {
		mainScreen += this->getCardRender(cards->getCardAt(i));
	}
	std::cout << mainScreen << std::endl;
}

void TerminalBoard::cardSelection(Deck* cards)
{
	std::cout << std::endl << "Select the card to play:" << std::endl;
	for (size_t i = 0; i < cards->getNbOfCards(); i++) {
		std::cout << " " << i << "." << this->getCardRender(cards->getCardAt(i)) << std::endl;
	}
}

int TerminalBoard::processUserInputForCardSelection(Deck* cards)
{
	std::string response;
	std::getline(std::cin, response);
	int cardChosen = std::stoi(response);
	if (cardChosen >= 0 && cardChosen < cards->getNbOfCards()) {
		std::cout 
			<< " Card chosen: " << cardChosen << "." 
			<< this->getCardRender(cards->getCardAt(cardChosen)) << std::endl;
		return cardChosen;
	}
	else {
		std::cout << " Please enter a valid number." << std::endl;
		return this->processUserInputForCardSelection(cards);
	}
}

void TerminalBoard::displayTurnWin(std::string playerName)
{
	std::cout << playerName << " wins this turn!" << std::endl << std::endl;
}

void TerminalBoard::displayTurnLose(std::string playerName)
{
	std::cout << playerName << " loses this turn!" << std::endl << std::endl;
}

void TerminalBoard::displayTurnEquality()
{
	std::cout << "Equality, turn continues..." << std::endl << std::endl;
}
