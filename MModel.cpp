#include "MModel.h"
#define WHITE setcolor(15)
#define BLUE setcolor(1)
#define GREEN setcolor(2)
#define CYAN setcolor(3)
#define RED setcolor(4)
#define MAGENTA setcolor(5)

MModel::MModel()
{
	std::vector<M3dPoint> points(4);
	points[0].x = 100;
	points[0].y = 100;
	points[0].z = 100;

	points[1].x = 300;
	points[1].y = 100;
	points[1].z = 100;

	points[2].x = 200;
	points[2].y = 300;
	points[2].z = 100;

	points[3].x = 200;
	points[3].y = 200;
	points[3].z = 300;

	this->points = points;

	ShowModel();

	center.x = 200;
	center.y = 200;
	center.z = 200;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////

void MModel::ShowModel()
{
	FillModel();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////

void MModel::FillModel()
{
	ShowXY();
	ShowXZ();
	ShowYZ();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////

void MModel::ShowXY()
{
	for (int i = 1; i < 3; ++i)
	{
		line(points[i - 1].x, points[i - 1].y, points[i].x, points[i].y);
		line(points[i - 1].x, points[i - 1].y, points[3].x, points[3].y);
	}
	line(points[0].x, points[0].y, points[3 - 1].x, points[3 - 1].y);
	line(points[3 - 1].x, points[3 - 1].y, points[3].x, points[3].y);
}

void MModel::ShowXZ()
{
	for (int i = 1; i < 3; ++i)
	{
		line(points[i - 1].x + 400, points[i - 1].z, points[i].x + 400, points[i].z);
		line(points[i - 1].x + 400, points[i - 1].z, points[3].x + 400, points[3].z);
	}
	line(points[0].x + 400, points[0].z, points[3 - 1].x + 400, points[3 - 1].z);
	line(points[3 - 1].x + 400, points[3 - 1].z, points[3].x + 400, points[3].z);
}

void MModel::ShowYZ()
{
	for (int i = 1; i < 3; ++i)
	{
		line(points[i - 1].y, points[i - 1].z + 400, points[i].y, points[i].z + 400);
		line(points[i - 1].y, points[i - 1].z + 400, points[3].y, points[3].z + 400);
	}
	line(points[0].y, points[0].z + 400, points[3 - 1].y, points[3 - 1].z + 400);
	line(points[3 - 1].y, points[3 - 1].z + 400, points[3].y, points[3].z + 400);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////

void MModel::MoveModel(std::string movement)
{
	if (movement == "inside")
	{
		std::cout << "inside" << std::endl;
		for (int i = 0; i < points.size(); ++i)
			points[i].z += 10;
		center.z += 10;
	}
	else if (movement == "outside")
	{
		std::cout << "outside" << std::endl;
		for (int i = 0; i < points.size(); ++i)
			points[i].z -= 10;
		center.z -= 10;
	}
	else if (movement == "up")
	{
		std::cout << "up" << std::endl;
		for (int i = 0; i < points.size(); ++i)
			points[i].y -= 10;
		center.y -= 10;
	}
	else if (movement == "down")
	{
		std::cout << "down" << std::endl;
		for (int i = 0; i < points.size(); ++i)
			points[i].y += 10;
		center.y += 10;
	}
	else if (movement == "left")
	{
		std::cout << "left" << std::endl;
		for (int i = 0; i < points.size(); ++i)
			points[i].x -= 10;
		center.x -= 10;
	}
	else if (movement == "right")
	{
		std::cout << "right" << std::endl;
		for (int i = 0; i < points.size(); ++i)
			points[i].x += 10;
		center.x += 10;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////

void MModel::RotateModel(bool IsClockwise)
{
	if (IsClockwise)
	{
		for (int i = 0; i < 4; ++i)
			points[i].Point3dRotate(10, center.x, center.y, center.z, planeRotate);
	}
	else
	{
		for (int i = 0; i < 4; ++i)
			points[i].Point3dRotate(-10, center.x, center.y, center.z, planeRotate);
	}
}

void MModel::SetPlaneRotate(int plane)
{
	planeRotate = plane;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////

void MModel::ScaleModel(bool IsIncrease)
{
	if (IsIncrease)
	{
		for (int i = 0; i < points.size(); ++i)
		{
			points[i].x = center.x + (points[i].x - center.x) * 0.9;
			points[i].y = center.y + (points[i].y - center.y) * 0.9;
			points[i].z = center.z + (points[i].z - center.z) * 0.9;
		}
	}
	else
	{
		for (int i = 0; i < points.size(); ++i)
		{
			points[i].x = center.x + (points[i].x - center.x) * 1.1;
			points[i].y = center.y + (points[i].y - center.y) * 1.1;
			points[i].z = center.z + (points[i].z - center.z) * 1.1;
		}
	}
}
