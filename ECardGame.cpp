#include <iostream>
#include "TerminalBoard.h"
#include "TerminalMainMenu.h"
#include <array>

int main()
{
    Player* p1 = new Player();
    Player* p2 = new Player();

    Board* board = new TerminalBoard();
    GameManager* gameManager = new GameManager(board, p1, p2);
    
    MainMenu* mainMenu = new TerminalMainMenu(gameManager);
    mainMenu->setUp();
    mainMenu->processUserInput();

    return 0;
}