#include "stdafx.h"
#include "SpecialElements.h"

bool coordinate::inMap()
{
	if (X < 0 || Y < 0 || X >= colvoOfRegionsInLine || Y >= colvoOfRegionsInLine)
		return false;
	return true;
}

coordinate coordinate::operator+(miniCoor b)
{
	coordinate tmp = { X,Y,x,y };
	tmp.x += b.x;
	tmp.y += b.y;
	while (tmp.x < 0)
	{
		--tmp.X;
		tmp.x += colvoOfCellsInLine;
	}
	while (tmp.x >= colvoOfCellsInLine)
	{
		++tmp.X;
		tmp.x -= colvoOfCellsInLine;
	}
	while (tmp.y < 0)
	{
		--tmp.Y;
		tmp.y += colvoOfCellsInLine;
	}
	while (tmp.y >= colvoOfCellsInLine)
	{
		++tmp.Y;
		tmp.y -= colvoOfCellsInLine;
	}
	return tmp;
}

float ran()
{
	return (float)(rand()) / RAND_MAX;
}
double doubleRan()
{
	return (double)(rand()) / RAND_MAX;
}