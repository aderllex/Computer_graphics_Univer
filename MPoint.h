#pragma once
#include <string>
#include <iostream>
#include "graphics.h"

class MPoint
{
public:
	MPoint();
	MPoint(float x, float y, std::string name);
	int PointRotate(float angle, int x, int y);

	float x;
	float y;
	std::string name;
};