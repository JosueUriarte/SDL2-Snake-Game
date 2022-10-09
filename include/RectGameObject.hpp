#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>
#include <deque>

#include <RenderWindow.hpp>
#include <Math.hpp>

class RectGameObject
{
public:
	//RectGameObject();
	void load(Vector2f p_pos, Vector2f p_size);
	virtual void render(RenderWindow* window);
	void clean();

	bool isColliding(RectGameObject* obj);
	virtual void addChild(RectGameObject child);
	RectGameObject* parent = nullptr;
	//std::deque<RectGameObject> children;

	SDL_Rect getRect() { return rect; }

protected:
	SDL_Rect rect;
	bool is_colliding = false;
	int last_update = 0;
	double time_delta = 0;
};