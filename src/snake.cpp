#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "Snake.hpp"

Snake::Snake(Vector2f* p_pos, Vector2f* p_size)
{
	RectGameObject::load(*p_pos, *p_size);
}

void Snake::update()
{

	if (rect.x < 0 || rect.y < 0 || rect.x > 640 || rect.y > 480) reset();

	switch(direction)
	{
		case Up: 
			rect.y -= GRID_INC; break;
		case Down: 
			rect.y += GRID_INC; break;
		case Left: 
			rect.x -= GRID_INC; break;
		case RIGHT: 
			rect.x += GRID_INC; break;
		default: 
			break;
	}

}

void Snake::growSnake()
{

}

void Snake::reset()
{
	rect.x = RESET_X;
	rect.y = RESET_Y;
	direction = RIGHT;
}

Direction Snake::checkIfOpposite(Direction dir)
{
	if (dir == Up && this->direction != Down) return dir;
	if (dir == Down && this->direction != Up) return dir;
	if (dir == Left && this->direction != RIGHT) return dir;
	if (dir == RIGHT && this->direction != Left) return dir;
	return this->direction;
}


