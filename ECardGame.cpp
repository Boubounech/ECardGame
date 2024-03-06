#include <iostream>
#include "TerminalBoard.h"
#include "TerminalMainMenu.h"
#include <array>

int main()
{
    Board* boardP1 = new TerminalBoard();
    Board* boardP2 = new TerminalBoard();
    Player* p1 = new Player(boardP1);
    //p1->setName("Player 1");
    Player* p2 = new Player(boardP2);
    p2->setName("Player 2");

    GameManager* gameManager = new GameManager();
    gameManager->addPlayer(p1);
    gameManager->addPlayer(p2);
    gameManager->setNumberOfTurns(1);
    
    MainMenu* mainMenu = new TerminalMainMenu(gameManager);
    mainMenu->setUp();
    mainMenu->processUserInput();

    delete mainMenu;
    delete gameManager;
    delete p2;
    delete p1;
    delete boardP2;
    delete boardP1;

    return 0;
}