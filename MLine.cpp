#include "MLine.h"
#define WHITE setcolor(15)

MLine::MLine()
{
	int standart = IsStandard();
	switch (standart)
	{
	case 0:
		std::cout << "Enter the data for the line :" << std::endl;
		start = new MPoint();
		to = new MPoint();
		break;
	case 1:
		start = new MPoint(100, 200, "A");
		to = new MPoint(50, 100, "B");
		break;
	case 2:
		start = new MPoint(10, 200, "C");
		to = new MPoint(100, 50, "D");
		break;
	case 3:
		start = new MPoint(500, 400, "E");
		to = new MPoint(200, 100, "F");
		break;
	case 4:
		start = new MPoint(100, 500, "G");
		to = new MPoint(500, 200, "H");
		break;
	}
}

MLine::~MLine()
{
	delete start;
	delete to;

	start = nullptr;
	to = nullptr;
}

int MLine::IsStandard()
{
	char choise;
	int package = 0;

	system("cls");

	std::cout << "Use the standard coordinates package? (y/n)" << std::endl;
	std::cin >> choise;

	while (choise != 'n' && choise != 'y')
	{
		std::cout << "ooohhhh???" << "Try again!";
		std::cin >> choise;
	}

	if (choise == 'y')
	{
		std::cout << "Whitch package? (int)" << std::endl;
		std::cout << "1 : (100, 100) (50, 150) - A, B" << std::endl;
		std::cout << "2 : (10, 40) (100, 200) - C, D" << std::endl;
		std::cout << "3 : (500, 400) (200, 100) - E, F" << std::endl;
		std::cout << "4 : (100, 500) (500, 200) - G, H" << std::endl;

		std::cin >> package;

		while (package > 4)
		{
			std::cout << "O_o???" << "Try again!";
			std::cin >> package;
		}
		system("cls");
		return package;
	}
	system("cls");
	return 0;
}

void MLine::CreateLine()
{
	line(start->x, start->y, to->x, to->y);
	WHITE;
}

void MLine::CreateBresenhamLine(int color)
{
	int deltaX = abs(to->x - start->x);
	int deltaY = abs(to->y - start->y);
	int signX = start->x < to->x ? 1 : -1;
	int signY = start->y < to->y ? 1 : -1;
	int error = deltaX - deltaY;
	putpixel(to->x, to->y, color);

	int x = start->x, y = start->y;

	while (x != to->x || y != to->y)
	{
		putpixel(x, y, color);
		int error2 = error * 2;
		if (error2 > -deltaY)
		{
			error -= deltaY;
			x += signX;
		}
		if (error2 < deltaX)
		{
			error += deltaX;
			y += signY;
		}
	}
}

void MLine::ShowLetters()
{
	char charName[10];
	strcpy(charName, start->name.c_str());
	outtextxy(start->x, start->y, charName);

	strcpy(charName, to->name.c_str());
	outtextxy(to->x, to->y, charName);
}

void MLine::Move(int Xdistance, int Ydistance)
{
	start->x += Xdistance;
	to->x += Xdistance;

	start->y += Ydistance;
	to->y += Ydistance;

	ShowLetters();
}

void MLine::ShowPoints()
{
	std::cout << start->name << " : (" << start->x << " : " << start->y << ")" << std::endl;
	std::cout << to->name << " : (" << to->x << " : " << to->y << ")" << std::endl;
}

void MLine::Rotate(float angle, int x, int y)
{
	start->PointRotate(angle, x, y);
	to->PointRotate(angle, x, y);

	ShowLetters();
}

void MLine::Scale(float scale, int x, int y)
{	
	start->x = x + (int)((start->x - x) * scale);
	to->x = x + (int)((to->x - x) * scale);

	start->y = y + (int)((start->y - y) * scale);
	to->y = y + (int)((to->y - y) * scale);

	ShowLetters();
}
