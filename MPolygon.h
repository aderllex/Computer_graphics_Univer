#pragma once
#include "graphics.h"
#include "MPoint.h"
#include <vector>

class MPolygon
{
public:
	MPolygon(int color);
	~MPolygon();

	void MovePolygon();
	void RotatePolygon();
	void ScalePolygon();

	static int GetKey();

private:
	MPoint Set2DCursor();
	void ShowPolygon();
	void Filling();

	std::vector<MPoint> points;
	int countOfPoints;
	int color;
};