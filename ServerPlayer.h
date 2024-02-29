#pragma once
#include "Player.h"
#include "EmptyBoard.h"
#include "Socket/TcpServerSocket.hpp"

/*
* Turn results:
* VIC
* DEF
* EQU
* 
* Player input:
* PLA	--> YED n
* 
* Managing cards:
* GIV c1c2c3c4c5
* REM n
*/

class ServerPlayer : public Player
{
private:
	Board* board;
	TcpServerSocket* socket;

public:
	static const size_t PORT = 56893;

	ServerPlayer(char* ip) : Player(board) {
		board = new EmptyBoard();
		socket = new TcpServerSocket(ip, PORT);
	}
	~ServerPlayer() {
		this->socket->closeConnection();
		delete board;
		delete socket;
	}

	void awaitConnection();

	int getChosenCard() override;
	void displayVictory() override;
	void displayDefeat() override;
	void displayEquality() override;

	void giveCards(Deck* deck) override;
	void removeCard(int index) override;
};