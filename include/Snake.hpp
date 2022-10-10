#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>

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
	void moveRight() {direction = checkIfOpposite(RIGHT);};


	Vector2f getPrevPos() { return prevPos; }
	void setPrevPos(float pos_x, float pos_y) { prevPos.x = pos_x; prevPos.y = pos_y; }
	int getLength() { return length; };

	Snake* getSnakeParent() { return snakeParent; }
	void setSnakeParent(Snake* child) { snakeParent = child; }

	void growSnake();
	void reset();

	Direction direction = RIGHT;
	
private:
	void tailUpdate();
	int length = 2;
	Vector2f prevPos;
	Snake* snakeParent = nullptr;
	std::vector<Snake*> snakeTail;
	Direction checkIfOpposite(Direction dir);
};