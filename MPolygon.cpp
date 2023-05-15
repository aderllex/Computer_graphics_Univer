#include "MPolygon.h"
#define WHITE setcolor(15)
#define ALLPOINTS (int i = 0; i < countOfPoints; ++i)

MPolygon::MPolygon(int color)
{
	std::cout << "Enter the number of polygon points" << std::endl;
	std::cin >> countOfPoints;

	std::cout << "Click on the window!" << std::endl;
	int x, y;
	for ALLPOINTS
	{
		while (!ismouseclick(WM_LBUTTONDOWN))
			delay(50);

		getmouseclick(WM_LBUTTONDOWN, x, y);

		points.push_back(MPoint(x, y, std::to_string(i + 1)));
	}

	this->color = color;
	ShowPolygon();
}

MPolygon::~MPolygon()
{

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////

void MPolygon::ShowPolygon()
{
	setfillstyle(1, color);

	/*for(int i = 1; i < countOfPoints; ++i)
		line(points[i - 1].x, points[i - 1].y, points[i].x, points[i].y);
	line(points[countOfPoints - 1].x, points[countOfPoints - 1].y, points[0].x, points[0].y);*/

	std::vector<int>intPoints;
	for (int i = 0; i < countOfPoints; ++i)
	{
		intPoints.push_back(points[i].x);
		intPoints.push_back(points[i].y);
	}
	fillpoly(countOfPoints, intPoints.data());

	WHITE;
}

MPoint MPolygon::Set2DCursor()
{
	std::cout << "Select 2d cursor" << std::endl;
	std::cout << "Click on the window!" << std::endl;
	int x, y;

	while (!ismouseclick(WM_LBUTTONDOWN))
		delay(50);

	getmouseclick(WM_LBUTTONDOWN, x, y);

	return MPoint(x, y, "Cursor");
}

int MPolygon::GetKey()
{
	int key = getch();
	if (key == 0) 
		key = getch();
	return key;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////

void MPolygon::MovePolygon()
{
	int key = 0, deltaX = 0, deltaY = 0;
	int startX, startY;

	clearmouseclick(WM_LBUTTONDOWN);
	clearmouseclick(WM_LBUTTONUP);

	while (!ismouseclick(WM_LBUTTONDOWN))
		delay(50);

	getmouseclick(WM_LBUTTONDOWN, startX, startY);

	std::cout << "start - " << startX << "   " << startY << std::endl;

	while (true)
	{
		clearmouseclick(WM_LBUTTONUP);
		delay(50);

		if (ismouseclick(WM_LBUTTONUP))
			break;

		POINT pnt;
		GetCursorPos(&pnt);

		deltaX = startX - pnt.x + 8;
		deltaY = startY - pnt.y + 31;
		
		std::cout << " : " << deltaX << "   " << deltaY << std::endl;

		cleardevice();
		
		for ALLPOINTS
		{
			points[i].x -= deltaX;
			points[i].y -= deltaY;

			char charName[10];
			strcpy(charName, std::to_string(i + 1).c_str());
			outtextxy(points[i].x, points[i].y, charName);
		}

		startX = pnt.x - 8;
		startY = pnt.y - 31;

		ShowPolygon();
	}
}

void MPolygon::RotatePolygon()
{
	MPoint Cursor = Set2DCursor();

	std::cout << Cursor.x << ' ' << Cursor.y << ' ' << Cursor.name << std::endl;

	std::cout << "Rotate mode" << std::endl;
	std::cout << "Rotate the polygon with 'A' and 'D'!" << std::endl;
	std::cout << "Click Enter to finish rotate" << std::endl;

	char charName[10];
	strcpy(charName, Cursor.name.c_str());
	outtextxy(Cursor.x, Cursor.y, charName);

	int key = 0;
	float angle = 0;
	while (true)
	{
		delay(50);
		key = MPolygon::GetKey();
		if (key == 97 || key == 65)
			angle -= 30;
		else if (key == 100 || key == 68)
			angle += 30;
		else if (key == 13 || key == 27)
			break;
		else
			continue;

		cleardevice();
		for ALLPOINTS
		{
			points[i].PointRotate(angle, Cursor.x, Cursor.y);

			strcpy(charName, points[i].name.c_str());
			outtextxy(points[i].x, points[i].y, charName);
		}
		angle = 0;

		strcpy(charName, Cursor.name.c_str());
		outtextxy(Cursor.x, Cursor.y, charName);
		ShowPolygon();
	}

	cleardevice();
	for ALLPOINTS
	{
		strcpy(charName, points[i].name.c_str());
		outtextxy(points[i].x, points[i].y, charName);
	}
	ShowPolygon();
}

void MPolygon::ScalePolygon()
{
	MPoint Cursor = Set2DCursor();

	int key = 0;
	float deltaX = 0, deltaY = 0;
	int startX, startY;
	float scale = 1;

	clearmouseclick(WM_LBUTTONDOWN);
	clearmouseclick(WM_LBUTTONUP);

	while (!ismouseclick(WM_LBUTTONDOWN))
		delay(50);

	getmouseclick(WM_LBUTTONDOWN, startX, startY);

	std::cout << "start - " << startX << "   " << startY << std::endl;

	while (true)
	{
		clearmouseclick(WM_LBUTTONUP);
		delay(100);

		if (ismouseclick(WM_LBUTTONUP))
			break;

		POINT pnt;
		GetCursorPos(&pnt);

		deltaX = float(startX - pnt.x + 8) / 1.5;
		deltaY = float(startY - pnt.y + 31) / 1.5;

		float radius = sqrt(pow(Cursor.x - startX, 2) + pow(Cursor.y - startY, 2));
		float newRadius = sqrt(pow(Cursor.x - startX + deltaX, 2) + pow(Cursor.y - startY + deltaY, 2));
		scale = newRadius / radius;
		
		std::cout << "R : " << radius << std::endl;
		std::cout << "N : " << newRadius << std::endl;
		std::cout << "scale - " << scale << std::endl;

		cleardevice();

		char charName[10];

		for ALLPOINTS
		{
			points[i].x = Cursor.x + ((points[i].x - Cursor.x) * scale);
			points[i].y = Cursor.y + ((points[i].y - Cursor.y) * scale);

			strcpy(charName, std::to_string(i + 1).c_str());
			outtextxy(points[i].x, points[i].y, charName);
		}
		
		strcpy(charName, Cursor.name.c_str());
		outtextxy(Cursor.x, Cursor.y, charName);

		startX = pnt.x - 8;
		startY = pnt.y - 31;

		ShowPolygon();
	}

	cleardevice();
	for ALLPOINTS
	{
		char charName[10];
		strcpy(charName, points[i].name.c_str());
		outtextxy(points[i].x, points[i].y, charName);
	}
	ShowPolygon();
}