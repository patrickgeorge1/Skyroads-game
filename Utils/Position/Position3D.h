#ifndef Position3D_HEADER
#define Position3D_HEADER

class Position3D {
public:
	Position3D();
	Position3D(float, float);
	Position3D(float, float, float);
	~Position3D();

	float x;
	float y;
	float z;
};

#endif