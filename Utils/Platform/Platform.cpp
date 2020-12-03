#include "Platform.h"

Platform::Platform()
{
	srand((unsigned int)time(NULL));
}

Platform::Platform(Position3D pos, bool isOut, int type)
{
	this->pos = pos;
	this->isOutOfScreen = isOut;
	this->type = type;
}

Platform::~Platform()
{
}

void Platform::movePlatformToColumn()
{
	pos.x = (-1) * column * PLATFORM_WIDTH + (PLATFORM_WIDTH / 2);
}

int Platform::updatePlatform(Platform lastPlatform, Player &player)
{
	// add
	if (isOutOfScreen) {
		isOutOfScreen = false;
		lenght = rand() % (PLATFORM_MAX_LENGTH - PLATFORM_LENGTH + 1) + PLATFORM_LENGTH;
		pos.z = (-1) * ((-1) * lastPlatform.pos.z + (lastPlatform.lenght / 2) + GAP_BETWEEN_PLATFORMS_SIZE + (lenght / 2));
		type = rand() % 4;
		// don t want to create red platform too often
		if (type == RED_PLATFORM) {
			if (!player.LastRedCountIsOver()) {
				type = rand() % 3;
			}
			else {
				player.startLastRedCount();
			}
		}
		isTouched = false;

		//cout << "col " << column << " last platform was " << lastPlatform.id << " [zCenter=" << lastPlatform.pos.z << " , lenght= " << lastPlatform.lenght << "]"
		//	<< "  ----> new last is " << id << " [zCenter=" << pos.z << " , lenght= " << lenght << "]" << endl;


		return id;
	}

	if (pos.z > 10) {
		isOutOfScreen = true;
		return lastPlatform.id;
	}

	pos.z += player.speed + player.penalty_speed;
	return lastPlatform.id;
}

void Platform::checkForCollision(Player& player)
{
	if (player.y_axe_movement_type == PLAYER_ON_THE_GROUND &&
		(player.pos.z <= (pos.z + (lenght / 2)) && player.pos.z >= (pos.z - (lenght / 2))) &&
		(player.pos.x <= (pos.x + (PLATFORM_WIDTH / 2)) && player.pos.x >= (pos.x - (PLATFORM_WIDTH / 2)))) {
		player.touchingPlatformID = id;
		
		if (!isTouched) {
			switch (type)
			{
				case ORANGE_PLATFORM:
					player.startPenalty();
					break;
				case YELLOW_PLATFORM:
					player.deductFuelPenalty();
					break;
				case GREEN_PLATFORM:
					player.receiveFuelBonus();
					break;
				case RED_PLATFORM:
					player.gameOver = true;
					break;
			}
		}

		isTouched = true;
	}
}



