#include "stdafx.h"
#include "drawingObjects.h"

void woodIcon(short x, short z, short y, short xx, short zz, short yy)
{
	//cube()
}

void figure(short x, short y, char number, short width, short height)
{
	glBegin(GL_LINES);

	glColor3f(1.0, 1.0, 1.0);

	int h = height;
	int w = width;

	switch (number)
	{
	case 0:
		glVertex3s(x, y, 0);
		glVertex3s(x + w, y, 0);
		glVertex3s(x + w, y, 0);
		glVertex3s(x + w, y + h, 0);
		glVertex3s(x + w, y + h, 0);
		glVertex3s(x, y + h, 0);
		glVertex3s(x, y + h, 0);
		glVertex3s(x, y, 0);
		glVertex3s(x + w, y + 2 * h / 3, 0);
		glVertex3s(x, y + h / 3, 0);
		break;
	case 1:
		glVertex3s(x, y + h / 2, 0);
		glVertex3s(x + w, y + h, 0);
		glVertex3s(x + w, y + h, 0);
		glVertex3s(x + w, y, 0);
		break;
	case 2:
		glVertex3s(x, y + 3 * h / 4, 0);
		glVertex3s(x, y + h, 0);
		glVertex3s(x, y + h, 0);
		glVertex3s(x + w, y + h, 0);
		glVertex3s(x + w, y + h, 0);
		glVertex3s(x + w, y + h / 2, 0);
		glVertex3s(x + w, y + h / 2, 0);
		glVertex3s(x, y, 0);
		glVertex3s(x, y, 0);
		glVertex3s(x + w, y, 0);
		break;
	case 3:
		glVertex3s(x, y + h, 0);
		glVertex3s(x + w, y + h, 0);
		glVertex3s(x + w, y + h, 0);
		glVertex3s(x + w, y + h / 2, 0);
		glVertex3s(x, y + h / 2, 0);
		glVertex3s(x + w, y + h / 2, 0);
		glVertex3s(x + w, y + h / 2, 0);
		glVertex3s(x + w, y, 0);
		glVertex3s(x, y, 0);
		glVertex3s(x + w, y, 0);
		break;
	case 4:
		glVertex3s(x, y + h / 2, 0);
		glVertex3s(x + w / 2, y + h, 0);
		glVertex3s(x + w, y + h, 0);
		glVertex3s(x + w, y + h / 2, 0);
		glVertex3s(x, y + h / 2, 0);
		glVertex3s(x + w, y + h / 2, 0);
		glVertex3s(x + w, y + h / 2, 0);
		glVertex3s(x + w, y, 0);
		break;
	case 5:
		glVertex3s(x, y + h, 0);
		glVertex3s(x + w, y + h, 0);
		glVertex3s(x, y + h / 2, 0);
		glVertex3s(x, y + h, 0);
		glVertex3s(x, y + h / 2, 0);
		glVertex3s(x + w, y + h / 2, 0);
		glVertex3s(x + w, y + h / 2, 0);
		glVertex3s(x + w, y, 0);
		glVertex3s(x, y, 0);
		glVertex3s(x + w, y, 0);
		break;
	case 6:
		glVertex3s(x, y + h / 2, 0);
		glVertex3s(x + w, y + h, 0);
		glVertex3s(x, y + h / 2, 0);
		glVertex3s(x + w, y + h / 2, 0);
		glVertex3s(x, y, 0);
		glVertex3s(x, y + h / 2, 0);
		glVertex3s(x + w, y + h / 2, 0);
		glVertex3s(x + w, y, 0);
		glVertex3s(x, y, 0);
		glVertex3s(x + w, y, 0);
		break;
	case 7:
		glVertex3s(x, y + h, 0);
		glVertex3s(x + w, y + h, 0);
		glVertex3s(x + w, y + h, 0);
		glVertex3s(x + w, y + h / 2, 0);
		glVertex3s(x, y, 0);
		glVertex3s(x + w, y + h / 2, 0);
		break;
	case 8:
		glVertex3s(x, y + h, 0);
		glVertex3s(x + w, y + h, 0);
		glVertex3s(x, y + h / 2, 0);
		glVertex3s(x, y + h, 0);
		glVertex3s(x + w, y + h, 0);
		glVertex3s(x + w, y + h / 2, 0);
		glVertex3s(x, y + h / 2, 0);
		glVertex3s(x + w, y + h / 2, 0);
		glVertex3s(x, y, 0);
		glVertex3s(x, y + h / 2, 0);
		glVertex3s(x + w, y + h / 2, 0);
		glVertex3s(x + w, y, 0);
		glVertex3s(x, y, 0);
		glVertex3s(x + w, y, 0);
		break;
	case 9:
		glVertex3s(x, y + h, 0);
		glVertex3s(x + w, y + h, 0);
		glVertex3s(x, y + h / 2, 0);
		glVertex3s(x, y + h, 0);
		glVertex3s(x + w, y + h, 0);
		glVertex3s(x + w, y + h / 2, 0);
		glVertex3s(x, y + h / 2, 0);
		glVertex3s(x + w, y + h / 2, 0);
		glVertex3s(x, y, 0);
		glVertex3s(x + w, y + h / 2, 0);
		break;
	}
	glEnd();
}

void cube(short x, short z, short y, short xx, short zz, short yy, color col)
{
	glBegin(GL_QUADS);

	//a
	glColor3f(col.r, col.g, col.b);
	glVertex3s(x, z, y + yy);
	glVertex3s(x + xx, z, y + yy);
	glVertex3s(x + xx, z + zz, y + yy);
	glVertex3s(x, z + zz, y + yy);

	//b
	glColor3f(col.r*0.6, col.g*0.6, col.b*0.6);
	glVertex3s(x + xx, z, y);
	glVertex3s(x + xx, z, y + yy);
	glVertex3s(x + xx, z + zz, y + yy);
	glVertex3s(x + xx, z + zz, y);

	//-b
	glVertex3s(x, z, y);
	glVertex3s(x, z, y + yy);
	glVertex3s(x, z + zz, y + yy);
	glVertex3s(x, z + zz, y);

	//-a
	glColor3f(col.r*0.4, col.g*0.4, col.b*0.4);
	glVertex3s(x, z, y);
	glVertex3s(x + xx, z, y);
	glVertex3s(x + xx, z + zz, y);
	glVertex3s(x, z + zz, y);

	//c
	glColor3f(col.r*0.8, col.g*0.8, col.b*0.8);
	glVertex3s(x, z + zz, y + yy);
	glVertex3s(x, z + zz, y);
	glVertex3s(x + xx, z + zz, y);
	glVertex3s(x + xx, z + zz, y + yy);

	glEnd();
}

void coordinateLines()
{
	glBegin(GL_LINES);

	glColor3f(1.0, 0.0, 0.0);

	glVertex3s(0, 0, 0);
	glVertex3s(100, 0, 0);

	glColor3f(0.0, 1.0, 0.0);

	glVertex3s(0, 0, 0);
	glVertex3s(0, 100, 0);

	glColor3f(0.0, 0.0, 1.0);

	glVertex3s(0, 0, 0);
	glVertex3s(0, 0, 100);

	glEnd();
}

/*
***1
glVertex3s(x, y + h, 0);
glVertex3s(x + w, y + h, 0);
***2
glVertex3s(x, y + h / 2, 0);
glVertex3s(x, y + h, 0);
***3
glVertex3s(x, y + h / 2, 0);
glVertex3s(x + w, y + h, 0);
***4
glVertex3s(x + w, y + h, 0);
glVertex3s(x + w, y + h / 2, 0);
***5
glVertex3s(x, y + h/2, 0);
glVertex3s(x + w, y + h/2, 0);
***6
glVertex3s(x, y , 0);
glVertex3s(x, y + h/2, 0);
***7
glVertex3s(x, y, 0);
glVertex3s(x + w, y + h/2, 0);
***8
glVertex3s(x + w, y + h/2, 0);
glVertex3s(x + w, y, 0);
***9
glVertex3s(x, y , 0);
glVertex3s(x + w, y, 0);

*/