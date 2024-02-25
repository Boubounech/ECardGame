#include <iostream>
#include <sstream>
#include "MainMenu.h"
#pragma once

class TerminalMainMenu : public MainMenu
{
public:
	void setUp();
	void start();
	void quit();
	void processUserInput();
};