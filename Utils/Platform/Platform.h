#ifndef Platform_HEADER
#define Platform_HEADER

#include "../Position/Position3D.h"
#include "../../Defines.h"

class Platform {
public:
	Platform();
	Platform(Position3D, bool, int);
	~Platform();

	Position3D pos = Position3D();
	bool isOutOfScreen = false;
	int type = GREEN_PLATFORM;
};

#endif