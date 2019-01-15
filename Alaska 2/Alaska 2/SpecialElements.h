#pragma once
#include "cmath"

static const short colvoOfRegionsInLine = 15;
static const short colvoOfCellsInLine = 20;
static const int sizeOfRegion = 400;
static const short sizeOfCell = sizeOfRegion / colvoOfCellsInLine;

class miniCoor
{
public:
	short x, y;
};

class coordinate
{
public:
	short X, Y, x, y;

	bool inMap();
	coordinate operator+ (miniCoor b);
};

float ran();
double doubleRan();