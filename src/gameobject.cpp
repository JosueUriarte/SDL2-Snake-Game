#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "GameObject.hpp"

GameObject::GameObject(Vector2f p_pos, SDL_Texture* p_tex)
:pos(p_pos), tex(p_tex)
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

SDL_Texture* Entity::getTex() { return tex;}
SDL_Rect Entity::getCurrentFrame() { return currentFrame;}