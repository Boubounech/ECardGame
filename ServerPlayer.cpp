#include "ServerPlayer.h"

void ServerPlayer::awaitConnection()
{
	this->socket->acceptConnection();
}

int ServerPlayer::getChosenCard()
{
	return 0;
}

void ServerPlayer::displayVictory()
{
}

void ServerPlayer::displayDefeat()
{
}

void ServerPlayer::displayEquality()
{
}

void ServerPlayer::giveCards(Deck* deck)
{
	char message[10] = "GIV ";
	for (size_t i = 0; i < deck->getNbOfCards(); i++) {
		message[i + 4] = deck->getCardAt(i)->getCardIdentifier();
	}
	this->socket->sendData(message, 10);
}

void ServerPlayer::removeCard(int index)
{
	char message[10];
	sprintf_s(message, "REM %d", index);
	this->socket->sendData(message, 10);
}
