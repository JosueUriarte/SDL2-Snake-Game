#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "Snake.hpp"

Snake::Snake(int p_x, int p_y, int w, int h)
{
	// SNAKE(POSITION.X, POSITION.Y, WIDTH, HEIGHT)
	head.x = p_x;
	head.y = p_y;
	head.w = w;
	head.h = h;
}

void Snake::update()
{
	switch(direction)
	{
		case Up: 
			head.y -= 10; break;
		case Down: 
			head.y += 10; break;
		case Left: 
			head.x -= 10; break;
		case Right: 
			head.x += 10; break;
		default: 
			break;
	}
}

void Snake::Draw(RenderWindow* window)
{
	window->renderRect(head);
}