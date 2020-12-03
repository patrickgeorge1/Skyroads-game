#include "Platform.h"

Platform::Platform()
{
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

Platform Platform::updatePlatform(Platform lastPlatform)
{

	if (isOutOfScreen) {
		//TODO
	}

	if (pos.z > 1) {
		isOutOfScreen = true;
		return lastPlatform;
	}


	pos.z += PLATFORM_Z_STEP;


	return lastPlatform;
}
