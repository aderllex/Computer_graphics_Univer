#pragma once
#include "graphics.h"
#include "M3dPoint.h"
#include <vector>
#include <string>

struct Face
{
	M3dPoint first;
	M3dPoint second;
	M3dPoint third;
	int priority;
};

typedef struct Face Face;

class MModel
{
public:
	MModel();
	MModel(bool IsFiveLaba);

	void MoveModel(std::string movement);
	void RotateModel(bool IsClockwise);
	void ScaleModel(bool IsIncrease);
	void ShowModel();
	void SetPlaneRotate(int plane);

	static int laba;

private:
	void FillModel();
	std::vector<Face> FacesCalculating();
	std::vector<M3dPoint> SortPointsForZFunction(std::vector<M3dPoint> massivForZFunction);
	int SetFacePriority(Face face, std::vector<M3dPoint> massivForZFunction);
	void FillFace(Face face, int color);

	void ShowXY();
	void ShowXZ();
	void ShowYZ();

	int planeRotate = 1;
	std::vector<M3dPoint> points;
	M3dPoint center;

	std::vector<Face> faces;
};

