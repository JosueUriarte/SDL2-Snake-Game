#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "RectGameObject.hpp"

void RectGameObject::load(Vector2f p_pos, Vector2f p_size)
{
	rect.x = p_pos.x;
	rect.y = p_pos.y;
	rect.w = p_size.x;
	rect.h = p_size.y;
}

void RectGameObject::clean() {}

void RectGameObject::render(RenderWindow* window)
{
	SDL_RenderFillRect(window->getRenderer(), &rect);
}

void RectGameObject::addChild(RectGameObject* child) {}