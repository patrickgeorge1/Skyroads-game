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
