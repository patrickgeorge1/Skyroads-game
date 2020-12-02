#include "../Position/Position3D.h"

Position3D::Position3D()
{
	x = 0;
	y = 0;
	z = 0;
}

Position3D::Position3D(float xx, float yy)
{
	x = xx;
	y = yy;
	z = 0;
}

Position3D::Position3D(float xx, float yy, float zz)
{
	x = xx;
	y = yy;
	z = zz;
}

Position3D::~Position3D()
{
}
