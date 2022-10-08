#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Food.hpp"

Food::Food(Vector2f* p_pos, Vector2f* p_size)
{
	RectGameObject::load(*p_pos, *p_size);
}

void Food::update()
{

}

void Food::findNewPos()
{

}

void Food::isColliding()
{

}