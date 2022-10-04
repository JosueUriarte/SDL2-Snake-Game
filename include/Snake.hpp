#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include <Math.hpp>

class Snake
{
public:
	Snake();
	void Draw(SDL_Renderer renderer);
	void moveUp();
	int length;
	// Vector2f& getPos() { return pos;}
	// SDL_Texture* getTex();
	// SDL_Rect getCurrentFrame();
private:
	// Vector2f pos;
	// SDL_Rect currentFrame;
	// SDL_Texture* tex;
};