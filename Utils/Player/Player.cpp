#include "Player.h"
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

Player::Player()
{
}

Player::~Player()
{
}

void Player::increaseSpeed()
{
	speed += PLAYER_SPEED_STEP;
	speed = MIN(PLAYER_MAX_SPEED, speed);
}

void Player::decreaseSpeed()
{
	speed -= PLAYER_SPEED_STEP;
	speed = MAX(PLAYER_DEFAULT_SPEED, speed);
}

void Player::ajustPlayerHeight()
{

	switch (y_axe_movement_type)
	{
		case PLAYER_IS_TAKING_OFF:
			touchingPlatformID = -1; // in the air, not touching the platforms
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

bool Player::checkForFalling(int lenght, Position3D platPos)
{
	// not touching anything, but on the ground == > stay in a gap
	if (touchingPlatformID == -1 && y_axe_movement_type == PLAYER_ON_THE_GROUND) {
		cout << "here landing" << endl;
		return true;
	}


	// touched something before, check if he is still staying on it
	if (touchingPlatformID != -1) {
		// staying on it

		if ((pos.z <= (platPos.z + (lenght / 2)) && pos.z >= (platPos.z - (lenght / 2))) &&
			(pos.x <= (platPos.x + (PLATFORM_WIDTH / 2)) && pos.x >= (platPos.x - (PLATFORM_WIDTH / 2)))) return false;
		else {
			cout << "here leaving" << endl;
			return true;
		}
	}

	return false;
}
