#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "Snake.hpp"

Snake::Snake(Vector2f* p_pos, Vector2f* p_size)
{
	RectGameObject::load(*p_pos, *p_size);
	sdq.push_front(this->rect);
}

void Snake::update()
{

	if (rect.x < 0 || rect.y < 0 || rect.x > 640 || rect.y > 480) reset();

	switch(direction)
	{
		case Up: 
			SDL_Delay(50);rect.y -= GRID_INC; break;
		case Down: 
			SDL_Delay(50);rect.y += GRID_INC; break;
		case Left: 
			SDL_Delay(50);rect.x -= GRID_INC; break;
		case RIGHT: 
			SDL_Delay(50);rect.x += GRID_INC; break;
		default: 
			break;
	}

}

void Snake::growSnake()
{
	/*length += 10;
	sdq.push_front(rect);

	while (sdq.size() > length)
		sdq.pop_back();*/
}

void Snake::render(RenderWindow* window)
{
	for(SDL_Rect dq_rect : sdq)
	{
		SDL_RenderFillRect(window->getRenderer(), &rect);
	}
	
}

void Snake::reset()
{
	length = 1;
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


