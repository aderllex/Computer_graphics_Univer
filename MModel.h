#pragma once
#include "graphics.h"
#include "M3dPoint.h"
#include <vector>
#include <string>

class MModel
{
public:
	MModel();

	void MoveModel(std::string movement);
	void RotateModel(bool IsClockwise);
	void ScaleModel(bool IsIncrease);
	void ShowModel();
	void SetPlaneRotate(int plane);

private:
	void FillModel();
	void ShowXY();
	void ShowXZ();
	void ShowYZ();

	int planeRotate = 1;
	std::vector<M3dPoint> points;
	M3dPoint center;
};

