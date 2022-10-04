#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "Game.hpp"
#include "RenderWindow.hpp"

Game::Game()
{
	// ERROR CHECKING ------------------------------------------------------
	if(SDL_Init(SDL_INIT_VIDEO) > 0)
		std::cout << "SDL_Init HAS FAILED. SDL_ERROR: " << SDL_GetError() << std::endl;
	if(!(IMG_Init(IMG_INIT_PNG)))
		std::cout << "IMG_Init HAS FAILED. IMG_Init Error: " << SDL_GetError() << std::endl;

	// INITIALIZE GAME WINDOW ----------------------------------------------
	window = new RenderWindow("SDL2 Snake", 640, 480);

	// INITIALIZE SNAKE ----------------------------------------------------
	snake = new Snake(300, 300, 10, 10);

	// START GAME LOOP -----------------------------------------------------
	is_running = true;
}

void Game::handleEvents()
{
	SDL_Event event;
	if(SDL_PollEvent(&event))
	{
		if(event.type == SDL_QUIT) {is_running = false;}

		else if(event.type == SDL_KEYDOWN)
		{
			if(event.key.keysym.sym == SDLK_w)  {snake->moveUp();}
			else if(event.key.keysym.sym == SDLK_a)  {snake->moveLeft();}
			else if(event.key.keysym.sym == SDLK_s)  {snake->moveDown();}
			else if(event.key.keysym.sym == SDLK_d)	{snake->moveRight();}
		}
	}
}

void Game::update()
{
	snake->update();
}

void Game::render()
{
	// CLEAR WINDOW ----------------------------------------------------------
	window->setWindowRenderColor(0,0,0,0);
	window->clear();	

	// RENDER GAME -------------------------------------------
	window->setWindowRenderColor(225,225,225,225);
	window->renderRect(snake->head);
	window->display();
	SDL_Delay(20);
}

void Game::clean()
{
	window->cleanUp();
}