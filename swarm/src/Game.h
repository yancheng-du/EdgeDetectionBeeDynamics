#ifndef Game_hpp
#define Game_hpp

#include "SDL.h"
#include <stdio.h>
#include <iostream>
#include "const.h"
#include "Swarm.h"

class Game
{
public:
	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void handleEvents();
	void update();
	void render();
	void clean();

	bool running() { return isRunning; };
private:

	bool isRunning;

	SDL_Rect r;
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Texture* texture;

	Swarm* bee_swarm;
};

#endif
