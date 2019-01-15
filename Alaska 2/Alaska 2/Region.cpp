#include "stdafx.h"
#include "Region.h"
#include "glut.h"
#include "drawingObjects.h"

Region::Region(short x, short y, int colvoOfCellsInLine_came, int sizeOfRegion_came)
{
	pos.x = x;
	pos.y = y;

	colvoOfCellsInLine = colvoOfCellsInLine_came;
	sizeOfRegion = sizeOfRegion_came;

	tree = new Tree**[colvoOfCellsInLine];
	for (int i = 0; i < colvoOfCellsInLine; i++)
	{
		tree[i] = new Tree*[colvoOfCellsInLine];
		for (int j = 0; j < colvoOfCellsInLine; j++)
			tree[i][j] = new Tree(miniCoor({ (short)i, (short)j }));
	}
}


void Region::draw()
{
	// drawing trees
	for (int x = 0; x < colvoOfCellsInLine; x++)
		for (int y = 0; y < colvoOfCellsInLine; y++)
			tree[x][y]->drawIfExist();

	//сетка
	/*glBegin(GL_LINES);
	glColor3f(0.5, 1, 0.5);
	for (int i = 0; i < colvoOfCellsInLine; i++)
	{
		glVertex3f(i*sizeOfRegion / colvoOfCellsInLine, 0.3, 0);
		glVertex3f(i*sizeOfRegion / colvoOfCellsInLine, 0.3, sizeOfRegion);
		glVertex3f(0, 0.3, i*sizeOfRegion / colvoOfCellsInLine);
		glVertex3f(sizeOfRegion, 0.3, i*sizeOfRegion / colvoOfCellsInLine);
	}
	glEnd();*/

	//land
	color rgb0 = { (float)0, (float) 0.5, (float)0 };
	color rgb1 = { (float)0, (float) 0.7, (float)0 };
	color rgb2 = { (float)0, (float) 0.6, (float)0 };
	color rgb3 = { (float)0, (float) 0.4, (float)0 };

	//c
	glBegin(GL_POLYGON);
	glColor3f(rgb0.r, rgb0.g, rgb0.b);
	glVertex3f(0, 0, 0);
	glColor3f(rgb1.r, rgb1.g, rgb1.b);
	glVertex3f(0, 0, sizeOfRegion);
	glColor3f(rgb2.r, rgb2.g, rgb2.b);
	glVertex3f(sizeOfRegion, 0, sizeOfRegion);
	glColor3f(rgb3.r, rgb3.g, rgb3.b);
	glVertex3f(sizeOfRegion, 0, 0);
	glEnd();

	rgb0 = { (float)0.68, (float) 0.45, (float)0.1 };
	rgb1 = { (float)0.3, (float) 0.1, (float)0 };

	glBegin(GL_POLYGON);
	glColor3f(rgb0.r*0.4, rgb0.g*0.4, rgb0.b*0.4);
	glVertex3f(0, 0, 0);
	glVertex3f(sizeOfRegion, 0, 0);
	glColor3f(rgb1.r*0.4, rgb1.g*0.4, rgb1.b*0.4);
	glVertex3f(sizeOfRegion, -80, 0);
	glVertex3f(0, -80, 0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(rgb0.r*0.6, rgb0.g*0.6, rgb0.b*0.6);
	glVertex3f(sizeOfRegion, 0, 0);
	glVertex3f(sizeOfRegion, 0, sizeOfRegion);
	glColor3f(rgb1.r*0.6, rgb1.g*0.6, rgb1.b*0.6);
	glVertex3f(sizeOfRegion, -80, sizeOfRegion);
	glVertex3f(sizeOfRegion, -80, 0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(rgb0.r*0.6, rgb0.g*0.6, rgb0.b*0.6);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 0, sizeOfRegion);
	glColor3f(rgb1.r*0.6, rgb1.g*0.6, rgb1.b*0.6);
	glVertex3f(0, -80, sizeOfRegion);
	glVertex3f(0, -80, 0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(rgb0.r, rgb0.g, rgb0.b);
	glVertex3f(0, 0, sizeOfRegion);
	glVertex3f(sizeOfRegion, 0, sizeOfRegion);
	glColor3f(rgb1.r, rgb1.g, rgb1.b);
	glVertex3f(sizeOfRegion, -80, sizeOfRegion);
	glVertex3f(0, -80, sizeOfRegion);
	glEnd();
}