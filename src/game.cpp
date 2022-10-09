#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "Game.hpp"
#include "Food.hpp"
#include "RenderWindow.hpp"
#include "Math.hpp"

Game::Game(const char* title, int res_w, int res_h)
{
	// ERROR CHECKING ------------------------------------------------------
	if(SDL_Init(SDL_INIT_VIDEO) > 0)
		std::cout << "SDL_Init HAS FAILED. SDL_ERROR: " << SDL_GetError() << std::endl;
	if(!(IMG_Init(IMG_INIT_PNG)))
		std::cout << "IMG_Init HAS FAILED. IMG_Init Error: " << SDL_GetError() << std::endl;

	// INITIALIZE GAME WINDOW ----------------------------------------------
	window = new RenderWindow(title, res_w, res_h);

	// INITIALIZE GAME OBJECTS ---------------------------------------------
	snake = new Snake(new Vector2f(300, 300), new Vector2f(10, 10));
	apple = new Food(new Vector2f(10, 0), new Vector2f(10, 10));

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
			else if (event.key.keysym.sym == SDLK_r) { snake->reset(); }
		}
	}
}

void Game::update()
{
	// Snake Movement Update
	snake->update();

	// Snake Collision Update
	if (snake->isColliding(apple))
	{
		apple->findNewPos();
		snake->growSnake();
	}

}

void Game::render()
{
	// CLEAR WINDOW ----------------------------------------------------------
	window->setWindowRenderColor(0,0,0,0);
	window->clear();	

	// RENDER GAME -------------------------------------------
	window->setWindowRenderColor(225,225,225,225);
	snake->render(window);
	
	window->setWindowRenderColor(225, 0, 0, 0);
	apple->render(window);

	window->display();
	//SDL_Delay(15);
}

void Game::clean(){ window->cleanUp(); }