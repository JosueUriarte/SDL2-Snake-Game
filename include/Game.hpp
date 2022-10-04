#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "Snake.hpp"
#include "RenderWindow.hpp"

class Game
{
public:
	Game();

	void handleEvents();
	void update();
	void render();
	void clean();

	bool isRunning() {return is_running; }

private:

	RenderWindow* window = nullptr;
	Snake* snake = nullptr;

	bool is_running = false;
};