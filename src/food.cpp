#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdlib.h>

#include "Food.hpp"
#include "Snake.hpp"

Food::Food(Vector2f* p_pos, Vector2f* p_size)
{
	RectGameObject::load(*p_pos, *p_size, this);
	findNewPos();
}

void Food::findNewPos()
{
	srand(time(0));
	int new_x, new_y, multiple;

	new_x = rand() % 640 + 1;
	new_x = new_x + 10 / 2;
	new_x -= new_x % 10;

	new_y = rand() % 480 + 1;
	new_y = new_y + 10 / 2;
	new_y -= new_y % 10;

	RectGameObject::rect.x = new_x;
	RectGameObject::rect.y = new_y;
}