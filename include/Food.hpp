#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "RectGameObject.hpp"
#include "Math.hpp"

class Food : public RectGameObject
{
public:
	Food(Vector2f* p_pos, Vector2f* p_size);
	void update();

	void findNewPos(); 
	void isColliding();

private:
};