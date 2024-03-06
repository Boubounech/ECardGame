#include "ClientPlayer.h"

void ClientPlayer::connect()
{
	this->socket->openConnection();
}

void ClientPlayer::listenToServer()
{
	char message[10] = "ERR";
	this->socket->receiveData(message, 10);
	std::string query = message;

	if (query.find("GIV") != std::string::npos) {
		std::array<Card, 5> cards = std::array<Card, 5> {
			Card(NONE), Card(NONE), Card(NONE), Card(NONE), Card(NONE)
		};
		for (size_t i = 0; i < cards.size(); i++) {
			cards[i] = Card::createFromIdentifier(query[4+i]);
		}
		this->deck = new Deck(cards);
		this->giveCards(this->deck);
	}
	else if (query.find("REM") != std::string::npos) {
		this->removeCard(query[4] - '0');
	}
	else if (query.find("PLA") != std::string::npos) {
		int cardChosen = this->getChosenCard();
		char response[10] = "YED ";
		response[4] = cardChosen + '0';
		this->socket->sendData(response, 10);
	}
	else if (query.find("VIC") != std::string::npos) {
		this->displayVictory();
	}
	else if (query.find("DEF") != std::string::npos) {
		this->displayDefeat();
	}
}