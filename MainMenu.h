#pragma once
#include "GameManager.h"

class MainMenu
{
private:
	GameManager* gameManager;

public:
	MainMenu(GameManager* gameManager) { this->gameManager = gameManager; }
	virtual void setUp() = 0;
	virtual void start() { this->gameManager->startGame(); };
	virtual void quit() = 0;
	virtual void processUserInput() = 0;
};