#pragma once

#include "glInterface.h"
#include "../Renderer.h"

class Game
{
	public:
	Game();
	~Game();
	void run();
	void update();
	void render();
	void init();
	void clean();

	void quit(){ isRunning =false;}

private:
	Renderer renderer;
	glInterface gl;

	bool isRunning = false;

};
