#pragma once
#include <string>
#include <iostream>
#include "graphics.h"

class M3dPoint
{
public:
	M3dPoint();
	void Point3dRotate(int angle, int x, int y, int z, int plane);
	friend bool operator==(M3dPoint& point1, M3dPoint& point2);

	float x, y, z;
};

