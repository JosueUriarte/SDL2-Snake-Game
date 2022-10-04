#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

#include "RenderWindow.hpp"
#include "Entity.hpp"
#include "Utils.hpp"

//using namespace std;

int main(int argc, char* args[]){
	
	// ERROR CHECKING ------------------------------------------------------
	if(SDL_Init(SDL_INIT_VIDEO) > 0)
		std::cout << "SDL_Init HAS FAILED. SDL_ERROR: " << SDL_GetError() << std::endl;
	if(!(IMG_Init(IMG_INIT_PNG)))
		std::cout << "IMG_Init HAS FAILED. IMG_Init Error: " << SDL_GetError() << std::endl;

	// INITIALIZE GAME WINDOW
	RenderWindow window("GAME v1.0", 1000, 1000);

	// INITIALIZE GAME VARIABLES -------------------------------------------
	bool gameRunning = true;
	SDL_Event event;
	const float deltaTime = 0.01f;
	float accumulator = 0.0f;
	float currentTime = utils::hireTimeInSeconds();

	// INITIALIZE SNAKE VARIABLES ------------------------------------------
	SDL_Texture* circleTexture = window.loadTexture("res/gfx/sircle.png");
	SDL_Rect head{500, 500, 10, 10};
	int dir = 0;
	enum Direction
	{
		DOWN,
		LEFT,
		RIGHT,
		UP
	};

	std::vector<Entity> entitiees = {Entity(Vector2f(), circleTexture),Entity(Vector2f(), circleTexture), Entity(Vector2f(), circleTexture)};

	// MAIN GAME LOOP ------------------------------------------------------
	while(gameRunning)
	{
		// int startTicks = SDL_GetTicks();
		// float newTime = utils::hireTimeInSeconds();
		// float frameTime = newTime - currentTime;

		// currentTime = newTime;
		// accumulator += frameTime;

		// while(accumulator >= deltaTime)
		// {
			while (SDL_PollEvent(&event))
			{
				if(event.type == SDL_QUIT) {gameRunning = false;}
				else if(event.type == SDL_KEYDOWN)
				{
					if(event.key.keysym.sym == SDLK_DOWN)  {dir = DOWN;}
					if(event.key.keysym.sym == SDLK_UP)    {dir = UP;}
					if(event.key.keysym.sym == SDLK_LEFT)  {dir = LEFT;}
					if(event.key.keysym.sym == SDLK_RIGHT) {dir = RIGHT;}
				}
				//accumulator -= deltaTime;
			}

			switch(dir)
			{
				case DOWN:
					head.y += 10; break;
				case UP:
					head.y -= 10; break;
				case LEFT:
					head.x -= 10; break;
				case RIGHT:
					head.x += 10; break;
			}
		//}

		//const float alpha = accumulator/deltaTime;
		// CLEAR WINDOW ----------------------------------------------------------
		window.setWindowRenderColor(0,0,0,225);
		window.clear();
		//for(Entity& e: entitiees) window.render(e);

		// DRAW WINDOW --------------------------------------------------------
		window.setWindowRenderColor(225,225,225,225);
		window.renderRect(head);
		window.display();

		// int frameTicks = SDL_GetTicks() - startTicks;
		// if(frameTicks < 1000 / window.getRefreshRate()) SDL_Delay(1000 / window.getRefreshRate() - frameTicks);
	}

	window.cleanUp();
	SDL_Quit();
	return 0;
}