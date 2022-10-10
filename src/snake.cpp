#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "Snake.hpp"

Snake::Snake(Vector2f* p_pos, Vector2f* p_size)
{
	RectGameObject::load(*p_pos, *p_size, nullptr);
	snakeTail.push_back(this);
}

void Snake::update()
{

	if (rect.x < 0 || rect.y < 0 || rect.x > 640 || rect.y > 480) reset();

	setPrevPos(this->rect.x, this->rect.y);

	switch(direction)
	{
		case Up: 
			//SDL_Delay(50);
			rect.y -= GRID_INC;
			break;
		case Down: 
			//SDL_Delay(50);
			rect.y += GRID_INC;
			break;
		case Left: 
			//SDL_Delay(50);
			rect.x -= GRID_INC;
			break;
		case RIGHT: 
			//SDL_Delay(50);
			rect.x += GRID_INC; 
			break;
		default: 
			break;
	}

	tailUpdate();

}

void Snake::tailUpdate()
{
	for (Snake* snake_obj : snakeTail)
	{
		if (snake_obj->getSnakeParent() != nullptr)
		{
			snake_obj->setPrevPos(snake_obj->getRect().x, snake_obj->getRect().y);
			snake_obj->setRectX(snake_obj->getSnakeParent()->getPrevPos().x);
			snake_obj->setRectY(snake_obj->getSnakeParent()->getPrevPos().y);
		}
	}
}

void Snake::growSnake()
{
	length += 1;
	Snake* newNode = new Snake(new Vector2f(rect.x, rect.y), new Vector2f(rect.w, rect.h));
	newNode->setSnakeParent(snakeTail.back());
	snakeTail.push_back(newNode);
}

void Snake::render(RenderWindow* window)
{
	SDL_RenderFillRect(window->getRenderer(), &rect);
	for(RectGameObject* snake_obj : snakeTail)
	{
		SDL_RenderFillRect(window->getRenderer(), &snake_obj->getRect());
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


