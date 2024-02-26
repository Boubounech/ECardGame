#include "TerminalMainMenu.h"

void TerminalMainMenu::setUp()
{
	std::cout <<
		"Welcome to E-Card game!\n"
		"Check the README for rules if you need them.\n"
		" - Enter 1 to play.\n"
		" - Enter 2 to quit.\n";
}

void TerminalMainMenu::start()
{
	std::cout << "Starting game..." << std::endl;
	MainMenu::start();
}

void TerminalMainMenu::quit()
{
	std::cout << "Good bye!" << std::endl;
}

void TerminalMainMenu::processUserInput()
{
	std::string response;
	std::getline(std::cin, response);
	if (response == "1") {
		start();
	}
	else if (response == "2") {
		quit();
	}
	else {
		this->processUserInput();
	}
}
