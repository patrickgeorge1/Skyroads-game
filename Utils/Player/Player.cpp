#include "Player.h"
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

Player::Player()
{
}

Player::~Player()
{
}

void Player::ajustPlayerHeight()
{

	switch (y_axe_movement_type)
	{
		case PLAYER_IS_TAKING_OFF:
			pos.y = MIN(pos.y + PLAYER_JUMP_STEP, PLAYER_MAX_HEIGHT);
			if (pos.y == PLAYER_MAX_HEIGHT) y_axe_movement_type = PLAYER_IS_LANDING;
			break;
		case PLAYER_IS_LANDING:
			pos.y = MAX(pos.y - PLAYER_JUMP_STEP, SPHERE_DEFAULT_HEIGHT);
			if (pos.y == SPHERE_DEFAULT_HEIGHT) y_axe_movement_type = PLAYER_ON_THE_GROUND;
			break;
		default:
			break;
	}
}
