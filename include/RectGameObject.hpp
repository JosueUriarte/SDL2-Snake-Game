#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>

#include <RenderWindow.hpp>
#include <Math.hpp>

class RectGameObject
{
public:
	void load(Vector2f p_pos, Vector2f p_size);
	void render(RenderWindow* renderer);
	void clean();

	virtual void addChild(RectGameObject* child);
	RectGameObject* parent = nullptr;
	std::vector<RectGameObject*> children;

	SDL_Rect getRect() { return rect; }

protected:
	SDL_Rect rect;
	int last_update = 0;
	double time_delta = 0;
};