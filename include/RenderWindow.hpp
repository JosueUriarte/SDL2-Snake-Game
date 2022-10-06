#pragma once // Used to just copy once to other classes
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class RenderWindow
{
public:
	RenderWindow(const char* p_title, int p_w, int p_h);
	SDL_Texture* loadTexture(const char* p_filePath); 

	int getRefreshRate();

	void cleanUp();
	void clear();
	//void render(Entity& p_entity);
	void renderRect(SDL_Rect& head);
	void setWindowRenderColor(int c1, int c2, int c3, int c4);
	void display();
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
};