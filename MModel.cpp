#include "MModel.h"
#define WHITE setcolor(15)
#define BLUE setcolor(1)
#define GREEN setcolor(2)
#define CYAN setcolor(3)
#define RED setcolor(4)
#define MAGENTA setcolor(5)

#define LABANUMBER 5

int MModel::laba = LABANUMBER;

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

	center.x = 200;
	center.y = 200;
	center.z = 200;

	ShowModel();
}

MModel::MModel(bool IsFiveLaba)
{
	std::vector<M3dPoint> points(4);
	points[0].x = 200;
	points[0].y = 200;
	points[0].z = 150;

	points[1].x = 400;
	points[1].y = 200;
	points[1].z = 100;

	points[2].x = 300;
	points[2].y = 400;
	points[2].z = 200;

	points[3].x = 300;
	points[3].y = 300;
	points[3].z = 400;

	this->points = points;

	center.x = 300;
	center.y = 300;
	center.z = 300;

	ShowModel();
}

std::vector<Face> MModel::FacesCalculating()
{
	std::vector<Face> faces(4);

	faces[0].first = points[0];
	faces[0].second = points[1];
	faces[0].third = points[3];

	faces[1].first = points[1];
	faces[1].second = points[2];
	faces[1].third = points[3];

	faces[2].first = points[2];
	faces[2].second = points[0];
	faces[2].third = points[3];

	faces[3].first = points[0];
	faces[3].second = points[1];
	faces[3].third = points[2];

	return faces;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////

void MModel::ShowModel()
{
	if (MModel::laba == 4)
	{
		line(400, 0, 400, 800);
		line(0, 400, 800, 400);

		ShowXY();
		ShowXZ();
		ShowYZ();
	}
	else if (MModel::laba == 5)
	{
		FillModel();
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////

void MModel::FillModel()
{
	std::vector<M3dPoint> massivForZFunction = SortPointsForZFunction(points);
	faces = FacesCalculating();

	for (int i = 0; i < massivForZFunction.size(); ++i)
		std::cout << massivForZFunction[i].z << std::endl;

	for (int i = 0; i < faces.size(); ++i)
		faces[i].priority = SetFacePriority(faces[i], massivForZFunction);

	int count = 1;
	while (count < 5)
	{
		for (int i = 0; i < faces.size(); ++i)
		{
			if (faces[i].priority == count)
			{
				FillFace(faces[i], count);
				break;
			}
		}
		count++;
	}
}

int MModel::SetFacePriority(Face face, std::vector<M3dPoint> massivForZFunction)
{
	if (face.first == massivForZFunction[0] && face.second == massivForZFunction[1] && face.third == massivForZFunction[2])
		return 1;
	if (face.first == massivForZFunction[0] && face.third == massivForZFunction[1] && face.second == massivForZFunction[2])
		return 1;
	if (face.second == massivForZFunction[0] && face.first == massivForZFunction[1] && face.third == massivForZFunction[2])
		return 1;
	if (face.second == massivForZFunction[0] && face.third == massivForZFunction[1] && face.first == massivForZFunction[2])
		return 1;
	if (face.third == massivForZFunction[0] && face.second == massivForZFunction[1] && face.first == massivForZFunction[2])
		return 1;
	if (face.third == massivForZFunction[0] && face.first == massivForZFunction[1] && face.second == massivForZFunction[2])
		return 1;

	if (face.first == massivForZFunction[0] && face.second == massivForZFunction[1] && face.third == massivForZFunction[3])
		return 2;
	if (face.first == massivForZFunction[0] && face.third == massivForZFunction[1] && face.second == massivForZFunction[3])
		return 2;
	if (face.second == massivForZFunction[0] && face.first == massivForZFunction[1] && face.third == massivForZFunction[3])
		return 2;
	if (face.second == massivForZFunction[0] && face.third == massivForZFunction[1] && face.first == massivForZFunction[3])
		return 2;
	if (face.third == massivForZFunction[0] && face.second == massivForZFunction[1] && face.first == massivForZFunction[3])
		return 2;
	if (face.third == massivForZFunction[0] && face.first == massivForZFunction[1] && face.second == massivForZFunction[3])
		return 2;

	if (face.first == massivForZFunction[0] && face.second == massivForZFunction[2] && face.third == massivForZFunction[3])
		return 3;
	if (face.first == massivForZFunction[0] && face.third == massivForZFunction[2] && face.second == massivForZFunction[3])
		return 3;
	if (face.second == massivForZFunction[0] && face.first == massivForZFunction[2] && face.third == massivForZFunction[3])
		return 3;
	if (face.second == massivForZFunction[0] && face.third == massivForZFunction[2] && face.first == massivForZFunction[3])
		return 3;
	if (face.third == massivForZFunction[0] && face.second == massivForZFunction[2] && face.first == massivForZFunction[3])
		return 3;
	if (face.third == massivForZFunction[0] && face.first == massivForZFunction[2] && face.second == massivForZFunction[3])
		return 3;

	if (face.first == massivForZFunction[1] && face.second == massivForZFunction[2] && face.third == massivForZFunction[3])
		return 4;
	if (face.first == massivForZFunction[1] && face.third == massivForZFunction[2] && face.second == massivForZFunction[3])
		return 4;
	if (face.second == massivForZFunction[1] && face.first == massivForZFunction[2] && face.third == massivForZFunction[3])
		return 4;
	if (face.second == massivForZFunction[1] && face.third == massivForZFunction[2] && face.first == massivForZFunction[3])
		return 4;
	if (face.third == massivForZFunction[1] && face.second == massivForZFunction[2] && face.first == massivForZFunction[3])
		return 4;
	if (face.third == massivForZFunction[1] && face.first == massivForZFunction[2] && face.second == massivForZFunction[3])
		return 4;
}

void MModel::FillFace(Face face, int color)
{
	setfillstyle(1, color);;

	std::vector<int>intPoints;

	intPoints.push_back(face.first.x);
	intPoints.push_back(face.first.y);
	intPoints.push_back(face.second.x);
	intPoints.push_back(face.second.y);
	intPoints.push_back(face.third.x);
	intPoints.push_back(face.third.y);

	fillpoly(3, intPoints.data());
}

std::vector<M3dPoint> MModel::SortPointsForZFunction(std::vector<M3dPoint> inputMassivPoints)
{
	std::vector<M3dPoint> massivForZFunction(4);
	float MaxZ = 0, MinZ = 800;

	for (int i = 0; i < inputMassivPoints.size(); ++i)
	{
		if (inputMassivPoints[i].z > MaxZ)
			MaxZ = inputMassivPoints[i].z;
		if(inputMassivPoints[i].z < MinZ)
			MinZ = inputMassivPoints[i].z;
	}

	for (int i = 0; i < inputMassivPoints.size(); ++i)
	{
		if (inputMassivPoints[i].z == MaxZ)
			massivForZFunction[3] = inputMassivPoints[i];
		if(inputMassivPoints[i].z == MinZ)
			massivForZFunction[0] = inputMassivPoints[i];
	}

	int counter = 1;
	for (int i = 0; i < inputMassivPoints.size(); ++i)
	{
		if (inputMassivPoints[i].z == massivForZFunction[3].z || inputMassivPoints[i].z == massivForZFunction[0].z)
			continue;
		else
		{
			massivForZFunction[counter] = inputMassivPoints[i];
			counter++;
		}
	}

	if (massivForZFunction[1].z > massivForZFunction[2].z)
	{
		M3dPoint Plug;

		Plug = massivForZFunction[2];
		massivForZFunction[2] = massivForZFunction[1];
		massivForZFunction[1] = Plug;
	}
		
	return massivForZFunction;
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
