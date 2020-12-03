#ifndef Player_HEADER
#define Player_HEADER

#include "../Position/Position3D.h"
#include "../../Defines.h"

class Player {
public:
	Player();
	~Player();

	Position3D pos = Position3D(0, SPHERE_DEFAULT_HEIGHT, 0);

	bool hasFallen = false;
	float fuel = 10;
	float speed = PLAYER_DEFAULT_SPEED;
	int y_axe_movement_type = PLAYER_ON_THE_GROUND;

	void ajustPlayerHeight();
};

#endif