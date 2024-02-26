#include <iostream>
#include "TerminalBoard.h"
#include "TerminalMainMenu.h"
#include <array>

int main()
{
    Player* p1 = new Player();
    p1->setName("Player 1");
    Player* p2 = new Player();
    p2->setName("Player 2");

    Board* board = new TerminalBoard();
    GameManager* gameManager = new GameManager(board, p1, p2);
    
    MainMenu* mainMenu = new TerminalMainMenu(gameManager);
    mainMenu->setUp();
    mainMenu->processUserInput();

    return 0;
}