#include "M3dPoint.h"
#define RADIANS(x) x*3.1415926535 / 180

M3dPoint::M3dPoint()
{
}

void M3dPoint::Point3dRotate(int angle, int x, int y, int z, int plane)
{
	float Sin = sin(RADIANS(angle));
	float Cos = cos(RADIANS(angle));

	if (plane == 1)
	{
		float radius = sqrt(pow(x - this->x, 2) + pow(x - this->y, 2));

		this->x -= x;
		this->y -= y;

		float deltaX = (this->x * Cos) - (this->y * Sin);
		float deltaY = (this->x * Sin) + (this->y * Cos);

		this->x = deltaX + x;
		this->y = deltaY + y;
	}

	if (plane == 2)
	{
		float radius = sqrt(pow(x - this->x, 2) + pow(z - this->z, 2));

		this->x -= x;
		this->z -= z;

		float deltaX = (this->x * Cos) - (this->z * Sin);
		float deltaZ = (this->x * Sin) + (this->z * Cos);

		this->x = deltaX + x;
		this->z = deltaZ + z;
	}

	if (plane == 3)
	{
		float radius = sqrt(pow(y - this->y, 2) + pow(z - this->z, 2));

		this->y -= y;
		this->z -= z;

		float deltaY = (this->y * Cos) - (this->z * Sin);
		float deltaZ = (this->y * Sin) + (this->z * Cos);

		this->y = deltaY + y;
		this->z = deltaZ + z;
	}
}
