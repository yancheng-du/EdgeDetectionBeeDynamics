#include "Game.h"

SDL_Texture* playerTex;
SDL_Rect srcR, destR;
Game::Game() {}
Game::~Game() {}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
	
	int flags = 0;
	if (fullscreen) { flags = SDL_WINDOW_FULLSCREEN; }
	
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "Subsystems Initialized" << std::endl;
		//create window
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		//create renderer
		renderer = SDL_CreateRenderer(window, -1, 0);

		isRunning = true;
		bee_swarm = new Swarm();
		bee_swarm->swarm_init();



	} else {
		isRunning = false;
	}

}

void Game::handleEvents() {
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
		case SDL_QUIT:
			isRunning = false;
			break;
		default:
			break;
	}
}

void Game::update() {
	bee_swarm->swarm_update();
}

void Game::render() {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, playerTex, NULL, NULL);
	SDL_SetRenderDrawColor(renderer, 255, 150, 100, 255);
	SDL_RenderDrawPoints(renderer, bee_swarm->get_points(), BEE_NUM);
	SDL_RenderPresent(renderer);

}

void Game::clean() {
	delete(bee_swarm);
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "game cleaned" << std::endl;
}
