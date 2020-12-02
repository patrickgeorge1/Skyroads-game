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
	bool isOutOfScreen = true;
	int type = GREEN_PLATFORM;
	int column = 0;

	void movePlatformToColumn();
};

#endif