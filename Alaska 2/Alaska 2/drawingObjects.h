#pragma once
#include "glut.h"
#include "iostream"

using namespace std;

struct color
{
	float r, g, b;
};

void cube(short x, short z, short y, short xx, short zz, short yy, color col);
void figure(short x, short y, char number, short, short);
void coordinateLines();

void woodIcon(short x, short z, short y, short xx, short zz, short yy);