#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <deque>

#include <RectGameObject.hpp>
#include <RenderWindow.hpp>
#include <Math.hpp>

enum SnakeVariables {RESET_X = 300, 
					RESET_Y = 300,
					GRID_INC = 10};
enum Direction {Up,Down,Left,RIGHT,None };

class Snake : public RectGameObject
{
public:
	Snake(Vector2f* p_pos, Vector2f* p_size);
	void update();
	void render(RenderWindow* window);
	
	void moveUp(){direction = checkIfOpposite(Up); };
	void moveDown(){direction = checkIfOpposite(Down);};
	void moveLeft(){direction = checkIfOpposite(Left);};
	void moveRight() { direction = checkIfOpposite(RIGHT);};

	int getLength() { return length; };
	void growSnake();
	void reset();

	Direction direction = RIGHT;
	
private:
	int length = 1;
	std::deque<SDL_Rect> sdq;
	Direction checkIfOpposite(Direction dir);
};