#include "Game.h"


Game::Game()
{
	init();
	while (!gl.shouldCloseWindow())
	{
		update();
		render();
	}
}

Game::~Game()
{
	clean();
}

void Game::run()
{
}

void Game::update()
{
}

void Game::render()
{
	
}

void Game::init()
{
	gl.SetupOpengl(1000,1000);

	
}

void Game::clean()
{
}
