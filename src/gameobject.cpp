#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "GameObject.hpp"

void GameObject::load(Vector2f p_pos, SDL_Texture* p_tex)
{
	currentFrame.x = 0;
	currentFrame.y = 0;
	currentFrame.w = 100;
	currentFrame.h = 100;
}

void GameObject::update() {
	if(last_update == 0)
	{
		last_update = SDL_GetTicks();
	}
	for (GameObject* child : children)
	{
		child->update();
	}
	int current_time = SDL_GetTicks();
	time_delta = (current_time - last_update) / 1000.0;
	last_update = current_time;
}

void GameObject::clean() {}

void GameObject::render() {}

void GameObject::addChild(GameObject* child) {}

SDL_Texture* GameObject::getTex() { return tex;}
SDL_Rect GameObject::getCurrentFrame() { return currentFrame;}