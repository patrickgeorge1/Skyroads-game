#ifndef Player_HEADER
#define Player_HEADER

#include <iostream>
#include "../Position/Position3D.h"
#include "../../Defines.h"
#include <ctime>

using namespace std;

class Player {
public:
	Player();
	~Player();

	Position3D pos = Position3D(0, SPHERE_DEFAULT_HEIGHT, 0);

	bool hasFallen = false;
	float fuel = PLAYER_MAX_FUEL;
	float speed = PLAYER_DEFAULT_SPEED;
	int y_axe_movement_type = PLAYER_ON_THE_GROUND;
	int touchingPlatformID = -1;
	float penalty_speed = 0;
	bool gameOver = false;

	clock_t penalty_begin;
	clock_t penalty_end;
	clock_t last_red_begin;
	clock_t last_red_end;
	clock_t noise_begin;
	clock_t noise_end;

	void increaseSpeed();
	void decreaseSpeed();
	void ajustPlayerHeight();
	bool checkForFalling(int, Position3D);
	void startPenalty();
	bool penaltyIsOver();
	void endPenalty();
	void deductFuelPenalty();
	void receiveFuelBonus();

	void startLastRedCount();
	bool LastRedCountIsOver();

	void startGameOverAnimation();
	bool gameOverAnimationFinished();

	void startNoiseAnimation();
	bool endNoiseAnimation();

};

#endif