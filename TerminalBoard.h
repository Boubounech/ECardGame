#pragma once
#include "Board.h"
#include <iostream>
#include <map>

class TerminalBoard : public Board
{
private:
	static std::map<CardType, char> cardRenderMap;
	std::string getCardRender(Card* card);

public:
	void mainScreen(Player* p1, Player* p2) override;
	void cardSelection() override;
};