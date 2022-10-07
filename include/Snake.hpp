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
	
	void moveUp(){direction = checkIfOpposite(Up); };
	void moveDown(){direction = checkIfOpposite(Down);};
	void moveLeft(){direction = checkIfOpposite(Left);};
	void moveRight() { direction = checkIfOpposite(Right); };

	int length = 1;
	Direction direction = None;
	SDL_Rect head;

private:
	Direction checkIfOpposite(Direction dir);
};