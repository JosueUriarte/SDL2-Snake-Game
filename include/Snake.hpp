#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include <GameObject.hpp>
#include <RenderWindow.hpp>
#include <Math.hpp>

enum Direction {Up,Down,Left,Right,None };

class Snake : public GameObject
{
public:
	Snake(int p_x, int p_y, int w, int h);

	void Draw(RenderWindow* renderer);
	void update();

	void moveUp(){direction = Up;};
	void moveDown(){direction = Down;};
	void moveLeft(){direction = Left;};
	void moveRight(){direction = Right;};

	int length;
	SDL_Rect head;
	Direction direction = None;

private:
};