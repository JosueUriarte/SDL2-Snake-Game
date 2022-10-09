#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "RectGameObject.hpp"

//RectGameObject::RectGameObject() {}

void RectGameObject::load(Vector2f p_pos, Vector2f p_size)
{
	rect.x = p_pos.x;
	rect.y = p_pos.y;
	rect.w = p_size.x;
	rect.h = p_size.y;
}

void RectGameObject::clean(){}

void RectGameObject::render(RenderWindow* window)
{
	SDL_RenderFillRect(window->getRenderer(), &rect);

	//if (!children.empty())
	//{
	//	for (RectGameObject obj : children)
	//	{
	//		SDL_RenderFillRect(window->getRenderer(), &obj.getRect());
	//	}
	//}
	
}

bool RectGameObject::isColliding(RectGameObject* obj)
{
	if (obj->getRect().x == this->getRect().x && obj->getRect().y == this->getRect().y)
	{
		is_colliding = true;
		return true;
	}
	else {
		is_colliding = false;
		return false;
	}
}

void RectGameObject::addChild(RectGameObject child)
{
	//children.push_back(child);
}