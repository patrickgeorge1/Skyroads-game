#ifndef Platform_HEADER
#define Platform_HEADER

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../Position/Position3D.h"
#include "../Player/Player.h"
#include "../../Defines.h"

using namespace std;

class Platform {
public:
	Platform();
	Platform(Position3D, bool, int);
	~Platform();

	Position3D pos = Position3D();
	bool isOutOfScreen = true;
	int type = GREEN_PLATFORM;
	int column = 0;
	int lenght = PLATFORM_LENGTH;
	int id = -1;

	void movePlatformToColumn();
	int updatePlatform(Platform, Player);
};

#endif