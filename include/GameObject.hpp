#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>

#include <Math.hpp>

class GameObject
{
public:
	void load(Vector2f p_pos, SDL_Texture* p_tex);

	virtual void render();
	virtual void update();
	void clean();

	virtual void addChild(GameObject* child);
	GameObject* parent = nullptr;
	std::vector<GameObject*> children;

	Vector2f& position() { return pos;}
	SDL_Texture* getTex();
	SDL_Rect getCurrentFrame();

protected:
	Vector2f pos;
	SDL_Rect currentFrame;
	SDL_Texture* tex;
	int last_update = 0;
	double time_delta;
};