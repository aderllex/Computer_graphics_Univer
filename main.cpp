#include "graphics.h"
#include "MLine.h"
#include "MPolygon.h"
#include "MModel.h"
#include <iostream>
#include <string>

/////////////////////////////////////////////////////////////////////////////////////////////

int Color()
{
	std::cout << "What color to use?" << std::endl;
	std::cout << "1 - BLUE" << std::endl;
	std::cout << "2 - GREEN" << std::endl;
	std::cout << "3 - CYAN" << std::endl;
	std::cout << "4 - RED" << std::endl;
	std::cout << "5 - MAGENTA" << std::endl;
	std::cout << "6 - BROWN" << std::endl;

	int color;
	std::cin >> color;
	while (color > 6 || color < 1)
	{
		std::cout << "Huuhh..." << "Try again" << std::endl;
		std::cin >> color;
	}
	return color;
}

/////////////////////////////////////////////////////////////////////////////////////////////

void Move(MLine* firstLine, MLine* secondLine)
{
	std::string choise;
	int Xdistance, Ydistance;
	std::cout << std::endl << "Which of the lines to move?" << std::endl;
	std::cout << "First (fir)" << std::endl;
	std::cout << "Second (sec)" << std::endl;
	std::cout << "Both (bot)" << std::endl;
	std::cin >> choise;

	std::cout << "How far to move on X (int)" << std::endl;
	std::cin >> Xdistance;

	std::cout << "How far to move on Y (int)" << std::endl;
	std::cin >> Ydistance;

	cleardevice();
	if (choise == "fir")
	{
		firstLine->Move(Xdistance, Ydistance);
		secondLine->ShowLetters();
	}
	else if (choise == "sec")
	{
		firstLine->ShowLetters();
		secondLine->Move(Xdistance, Ydistance);
	}
	else if (choise == "bot")
	{
		firstLine->Move(Xdistance, Ydistance);
		secondLine->Move(Xdistance, Ydistance);
	}
}

void Rotation(MLine* firstLine, MLine* secondLine)
{
	std::string choise;
	float angle;
	int x, y;
	std::cout << std::endl << "Which of the lines to rotate?" << std::endl;
	std::cout << "First (fir)" << std::endl;
	std::cout << "Second (sec)" << std::endl;
	std::cout << "Both (bot)" << std::endl;
	std::cin >> choise;

	std::cout << "Write the point from which the line will rotate? (int)" << std::endl;
	firstLine->ShowPoints();
	secondLine->ShowPoints();
	std::cin >> x >> y;

	std::cout << "Write the angle (30 / -60)" << std::endl;
	std::cin >> angle;

	cleardevice();
	if (choise == "fir")
	{
		firstLine->Rotate(angle, x, y);
		secondLine->ShowLetters();
	}
	else if (choise == "sec")
	{
		firstLine->ShowLetters();
		secondLine->Rotate(angle, x, y);
	}
	else if (choise == "bot")
	{
		firstLine->Rotate(angle, x, y);
		secondLine->Rotate(angle, x, y);
	}
}

void Scale(MLine* firstLine, MLine* secondLine)
{
	std::string choise;
	float size;
	int x, y;
	std::cout << std::endl << "Which of the lines to scale?" << std::endl;
	std::cout << "First (fir)" << std::endl;
	std::cout << "Second (sec)" << std::endl;
	std::cout << "Both (bot)" << std::endl;
	std::cin >> choise;

	std::cout << "Write the point from which the line will scale? (int)" << std::endl;
	firstLine->ShowPoints();
	secondLine->ShowPoints();
	std::cin >> x >> y;

	std::cout << "Write the zoom factor (float (1.1 / 0.9))" << std::endl;
	std::cin >> size;

	cleardevice();
	if (choise == "fir")
	{
		firstLine->Scale(size, x, y);
		secondLine->ShowLetters();
	}
	else if (choise == "sec")
	{
		firstLine->ShowLetters();
		secondLine->Scale(size, x, y);
	}
	else if (choise == "bot")
	{
		firstLine->Scale(size, x, y);
		secondLine->Scale(size, x, y);
	}
}

void RunLines()
{
	std::string choise;

	MLine firstLine;
	MLine secondLine;
	int firstColor;
	int secondColor;

	std::cout << "What method should I use to draw the lines?" << std::endl;
	std::cout << "Standard (sta)" << std::endl;
	std::cout << "Bresenham (bre)" << std::endl;
	std::cin >> choise;
	system("cls");

	if (choise == "sta")
	{
		firstColor = Color();
		setcolor(firstColor);
		firstLine.CreateLine();

		secondColor = Color();
		setcolor(secondColor);
		secondLine.CreateLine();
		system("cls");
	}
	else if (choise == "bre")
	{
		firstColor = Color();
		firstLine.CreateBresenhamLine(firstColor);
		secondColor = Color();
		secondLine.CreateBresenhamLine(secondColor);
		system("cls");
	}

	while (true)
	{
		system("cls");
		std::cout << "What will be the instructions?" << std::endl;
		std::cout << "Finish the program (fin)" << std::endl;
		std::cout << "Move (mov)" << std::endl;
		std::cout << "Rotate (rot)" << std::endl;
		std::cout << "Scale (sca)" << std::endl;

		std::cin >> choise;
		
		if (choise == "fin")
			break;
		else if (choise == "mov")
		{
			Move(&firstLine, &secondLine);
			setcolor(firstColor);
			firstLine.CreateLine();
			setcolor(secondColor);
			secondLine.CreateLine();
			std::cout << "Moved!" << std::endl;
		}
		else if (choise == "rot")
		{
			Rotation(&firstLine, &secondLine);
			setcolor(firstColor);
			firstLine.CreateLine();
			setcolor(secondColor);
			secondLine.CreateLine();
			std::cout << "Rotated!" << std::endl;
		}
		else if (choise == "sca")
		{
			Scale(&firstLine, &secondLine);
			setcolor(firstColor);
			firstLine.CreateLine();
			setcolor(secondColor);
			secondLine.CreateLine();
			std::cout << "Scailed!" << std::endl;
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////

void RunPolygon()
{
	MPolygon polygon(Color());
	int key;

	while (true)
	{
		system("cls");
		std::cout << "Select mode :" << std::endl;
		std::cout << "Finish the program (Esc)" << std::endl;
		std::cout << "Move mode (G)" << std::endl;
		std::cout << "Rotate mode (R)" << std::endl;
		std::cout << "Scale mode (S)" << std::endl;

		key = MPolygon::GetKey();

		if (key == 27)
			break;

		std::cout << key << std::endl;

		if (key == 103 || key == 71)
		{
			system("cls");
			std::cout << "Move mode" << std::endl;
			std::cout << "Move the polygon with the mouse!" << std::endl;
			polygon.MovePolygon();
		}
		else if (key == 82 || key == 114)
		{
			system("cls");
			polygon.RotatePolygon();
		}
		else if (key == 83 || key == 115)
		{
			system("cls");
			std::cout << "Scale mode" << std::endl;
			std::cout << "Scale the polygon with the mouse!" << std::endl;
			polygon.ScalePolygon();
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////

void RunModel()
{
	MModel model;
	// MModel model(true);
	int key;

	while (true)
	{
		system("cls");
		std::cout << "Select mode :" << std::endl;
		std::cout << "Finish the program (Esc)" << std::endl;
		std::cout << "Move mode (G)" << std::endl;
		std::cout << "Rotate mode (R)" << std::endl;
		std::cout << "Scale mode (S)" << std::endl;

		key = MPolygon::GetKey();

		if (key == 27)
			break;

		std::cout << key << std::endl;

		if (key == 103 || key == 71)
		{
			system("cls");
			std::cout << "Move mode" << std::endl;
			model.MoveModel();
		}
		else if (key == 82 || key == 114)
		{
			system("cls");
			model.RotateModel();
		}
		else if (key == 83 || key == 115)
		{
			system("cls");
			std::cout << "Scale mode" << std::endl;
			model.ScaleModel();
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	initwindow(700, 700);

	RunModel();
	// RunPolygon();
	// RunLines();

	return 0;
}