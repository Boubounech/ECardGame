#pragma once
#include <iostream>
#include <sstream>
#include "MainMenu.h"

class TerminalMainMenu : public MainMenu
{
public:
	TerminalMainMenu(GameManager* gm) : MainMenu(gm) {};
	void setUp() override;
	void start() override;
	void quit() override;
	void processUserInput() override;
};