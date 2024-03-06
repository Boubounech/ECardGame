#pragma once
#include <string>
#include "Player.h"
#include "Board.h"
#include "Socket/TcpClientSocket.hpp"

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
class ClientPlayer : public Player
{
private:
	TcpClientSocket* socket;
	Deck* deck;

public:
	ClientPlayer(char* ip, int port, Board* board) : Player(board) {
		deck = NULL;
		socket = new TcpClientSocket(ip, port);
	}
	~ClientPlayer()
	{
		socket->closeConnection();
		delete socket;
		if (deck != NULL)
			delete deck;
	}

	void connect();
	bool isConnected() { return this->socket->isConnected(); }
	void listenToServer();
};