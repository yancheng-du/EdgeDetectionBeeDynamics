
#include "Swarm.h"

Bee::Bee() {}
Bee::~Bee() {}

void Bee::bee_init() {
	x = rand() % WINDOW_WIDTH;
	y = rand() % WINDOW_HEIGHT;
	v_x = (rand() % BEE_VELOCITY - BEE_VELOCITY / 2) / FPS;
	v_y = (rand() % BEE_VELOCITY - BEE_VELOCITY / 2) / FPS;
	pos.x = x;
	pos.y = y;
}

void Bee::bee_update() {
	v_x += (rand() % BEE_ACC - BEE_ACC / 2) / FPS;
	v_y += (rand() % BEE_ACC - BEE_ACC / 2) / FPS;

	if (v_x >= BEE_VELOCITY / FPS ) {
		v_x = BEE_VELOCITY / FPS;
	}
	if (v_x <= -BEE_VELOCITY / FPS) {
		v_x = -BEE_VELOCITY / FPS;
	}
	if (v_y >= BEE_VELOCITY / FPS) {
		v_y = BEE_VELOCITY / FPS;
	}
	if (v_y <= -BEE_VELOCITY / FPS) {
		v_y = -BEE_VELOCITY / FPS;
	}

	if (x + v_x < 0 || x + v_x >= WINDOW_WIDTH) {
		v_x = -v_x;

	}

	if (y + v_y < 0 || y + v_y >= WINDOW_HEIGHT) {
		v_y = -v_y;
	}

	x += v_x ;
	y += v_y ;

	pos.x = x;
	pos.y = y;
}


Swarm::Swarm() {}
Swarm::~Swarm() {}

void Swarm::swarm_init() {
	bee_num = BEE_NUM;
	bees_ptr = new Bee[bee_num];
	points = new SDL_Point[bee_num];
	for (int i = 0; i < bee_num; i++) {
		bees_ptr[i].bee_init();
		points[i] = bees_ptr[i].get_pos();
	}
}

void Swarm::swarm_update() {
	for (int i = 0; i < bee_num; i++) {
		bees_ptr[i].bee_update();
		points[i] = bees_ptr[i].get_pos();
	}
}

void Swarm::swarm_clear() {
	delete(bees_ptr);
	delete(points);

}

