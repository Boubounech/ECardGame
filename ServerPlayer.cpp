#include "ServerPlayer.h"

void ServerPlayer::awaitConnection()
{
	this->socket->acceptConnection();
}

int ServerPlayer::getChosenCard()
{
	char message[10] = "PLA";
	this->socket->sendData(message, 10);
	this->socket->receiveData(message, 10);
	int valueChosen = message[4] - '0'; // message[4] is 'n' in 'YED n'
	return valueChosen;
}

void ServerPlayer::displayVictory()
{
	char message[10] = "VIC";
	this->socket->sendData(message, 10);
}

void ServerPlayer::displayDefeat()
{
	char message[10] = "DEF";
	this->socket->sendData(message, 10);
}

void ServerPlayer::displayEquality()
{
	char message[10] = "EQU";
	this->socket->sendData(message, 10);
}

void ServerPlayer::giveCards(Deck* deck)
{
	Player::giveCards(deck);
	char message[10] = "GIV ";
	for (size_t i = 0; i < deck->getNbOfCards(); i++) {
		message[i + 4] = deck->getCardAt(i)->getCardIdentifier();
	}
	this->socket->sendData(message, 10);
}

void ServerPlayer::removeCard(int index)
{
	Player::removeCard(index);
	char message[10];
	sprintf_s(message, "REM %d", index);
	this->socket->sendData(message, 10);
}
