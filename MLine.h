#pragma once
#include "graphics.h"
#include "MPoint.h"
#include <string>
#include <iostream>
#include <cmath>
#include <math.h>

class MLine
{
public:
	MLine();
	~MLine();
	void CreateLine();
	void CreateBresenhamLine(int color);
	void Move(int Xdistance, int Ydistance);
	void Scale(float size, int x, int y);
	void Rotate(float corner, int x, int y);
	void ShowLetters();
	void ShowPoints();
	MPoint *start;
	MPoint *to;

private:
	int IsStandard();
};