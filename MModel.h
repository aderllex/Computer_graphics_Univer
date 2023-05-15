#pragma once
#include "graphics.h"
#include "M3dPoint.h"
#include <vector>

class MModel
{
public:
	MModel();
	MModel(bool isPiramid);

	void MoveModel();
	void RotateModel();
	void ScaleModel();
};

