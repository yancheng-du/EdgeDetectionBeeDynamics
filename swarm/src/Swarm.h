#include "SDL.h"
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include "const.h"

class Bee {
public:
	Bee();
	~Bee();

	void bee_init();
	void bee_update();
	SDL_Point get_pos() {
		return pos;
	}

private:
	float x, y;
	float v_x, v_y;
	SDL_Point pos;
};




class Swarm
{

public:
	Swarm();
	~Swarm();

	void swarm_init();
	void swarm_update();
	void swarm_clear();
	SDL_Point* get_points() {
		return points;
	}

private:
	int bee_num;
	Bee* bees_ptr;
	SDL_Point* points;

};
