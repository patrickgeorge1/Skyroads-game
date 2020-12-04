#include "Player.h"
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))
#define ABS(x)  (x<0)?-x:x
#define SGN(x)  (x<0)?-1:1

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
	if (penaltyIsOver()) endPenalty();

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

	fuel -= PLAYER_FUEL_LOSS_STEP;
	if (fuel < 0) {
		fuel = 0;
		gameOver = true;
	}
}

bool Player::checkForFalling(int lenght, Position3D platPos)
{
	// not touching anything, but on the ground == > stay in a gap
	if (touchingPlatformID == -1 && y_axe_movement_type == PLAYER_ON_THE_GROUND) {
		gameOver = true;
		return true;
	}


	// touched something before, check if he is still staying on it
	if (touchingPlatformID != -1) {
		// staying on it

		if ((pos.z <= (platPos.z + (lenght / 2)) && pos.z >= (platPos.z - (lenght / 2))) &&
			(pos.x <= (platPos.x + (PLATFORM_WIDTH / 2)) && pos.x >= (platPos.x - (PLATFORM_WIDTH / 2)))) return false;
		else {
			gameOver = true;
			return true;
		}
	}

	return false;
}

void Player::startPenalty()
{
	penalty_begin = clock();
	penalty_speed = PLAYER_PENALTY_SPEED;
}

bool Player::penaltyIsOver()
{
	penalty_end = clock();
	return (difftime(penalty_end, penalty_begin) >= PLAYER_PENALTY_DURATION);
}

void Player::endPenalty()
{
	penalty_speed = 0;
}

void Player::deductFuelPenalty()
{
	fuel -= PLAYER_FUEL_PENALTY;
	if (fuel < 0) {
		fuel = 0;
		gameOver = true;
	}

}

void Player::receiveFuelBonus()
{
	fuel += PLAYER_FUEL_BONUS;
	if (fuel > PLAYER_MAX_FUEL) fuel = PLAYER_MAX_FUEL;
}

void Player::startLastRedCount()
{
	last_red_begin = clock();
}

bool Player::LastRedCountIsOver()
{
	last_red_end = clock();
	if (difftime(last_red_end, last_red_begin) >= INTERVAL_BETWEEN_RED_PLATFORMS) return true;
	return false;
}

void Player::startGameOverAnimation()
{
	pos.y -= GAME_OVER_FALLING_STEP;
	pos.x = cos(pos.y * 2);
}

bool Player::gameOverAnimationFinished()
{
	return pos.y < GAME_OVER_DEPTH;
}

void Player::startNoiseAnimation()
{
	noise_begin = clock();

}

bool Player::endNoiseAnimation()
{
	noise_end = clock();
	return (difftime(noise_end, noise_begin) >= NOISE_ANIMATION_DURATION);
}
