#include <iostream>
#include "TerminalMainMenu.h"

int main()
{
    MainMenu* mainMenu = new TerminalMainMenu();
    mainMenu->setUp();
    mainMenu->processUserInput();

    return 0;
}