#include "MPoint.h"
#define RADIANS(x) x*3.1415926535 / 180

MPoint::MPoint()
{
	std::cout << "Enter the name of a point : (string)" << std::endl;
	std::cin >> this->name;

	std::cout << "Enter the X coordinate '" << this->name << "' point : (int)" << std::endl;
	std::cin >> this->x;

	std::cout << "Enter the Y coordinate '" << this->name << "' point : (int)" << std::endl;
	std::cin >> this->y;
	
	char charName[10];
	strcpy(charName, this->name.c_str());
	outtextxy(x, y, charName);

	system("cls");
}

MPoint::MPoint(float x, float y, std::string name)
{
	this->x = x;
	this->y = y;
	this->name = name;

	char charName[10];
	strcpy(charName, this->name.c_str());
	outtextxy(this->x, this->y, charName);

	system("cls");
}

int MPoint::PointRotate(float angle, int x, int y)
{
	float radius = sqrt(pow(x - this->x, 2) + pow(y - this->y, 2));

	if (radius == 0)
		return 0;
	if (angle == 0)
		return 0;

	float Sin = sin(RADIANS(angle));
	float Cos = cos(RADIANS(angle));

	this->x -= x;
	this->y -= y;

	float deltaX = (this->x * Cos) - (this->y * Sin);
	float deltaY = (this->x * Sin) + (this->y * Cos);

	this->x = deltaX + x;
	this->y = deltaY + y;

}