#pragma once

class MainMenu
{
public:
	virtual void setUp() = 0;
	virtual void start() = 0;
	virtual void quit() = 0;
	virtual void processUserInput() = 0;
};