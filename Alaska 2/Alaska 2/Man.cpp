#include "stdafx.h"
#include <iostream>
#include "glut.h"
#include "Man.h"
#include "drawingObjects.h"

using namespace std;

Man::Man(short X_came, short Y_came, short x_came, short y_came, int colvoOfCellsInLine_came, int sizeOfRegion_came)
{
	pos.X = X_came;
	pos.Y = Y_came;
	pos.x = x_came;
	pos.y = y_came;
	colvoOfCellsInLine = colvoOfCellsInLine_came;
	sizeOfOneCell = sizeOfRegion_came / colvoOfCellsInLine;
	x = pos.x * sizeOfOneCell;
	y = pos.y * sizeOfOneCell;

	bag = new Bag();
}

void Man::addDirection(miniCoor dir)
{
	listOfDirections.push(dir);
}
void Man::moveManByTimeByDirectionInMovingAnimation()
{
	float speed;

	float k = 4 * sizeOfOneCell / (float)timeOfMoving / (float)timeOfMoving;
	if (counterOfMoving <= timeOfMoving / 2)
	{
		speed = k*counterOfMoving;
		z += speed*0.8;
	}
	else
	{
		speed = k*(-counterOfMoving + timeOfMoving);
		z -= speed*0.8;
	}

	x += currentDirection.x*speed;
	y += currentDirection.y*speed;
}

void Man::goAct()
{
	//moving
	if (moving)
	{
		moveManByTimeByDirectionInMovingAnimation();

		++counterOfMoving;
		if (counterOfMoving > timeOfMoving)
		{
			moving = false;
			counterOfMoving = 0;

			x = pos.x * sizeOfOneCell;
			y = pos.y * sizeOfOneCell;
			z = 0;

			//cout << "X: " << pos.X << " Y: " << pos.Y << " x: " << pos.x << " y: " << pos.y << '\n';
		}
	}
}

void Man::draw()
{
	short centering_constant = (sizeOfOneCell - manSize) / 2;

	cube(x + centering_constant, z, y + centering_constant, manSize, manHeight, manSize, color({ (float)0.02, (float)0.02, (float)0.5 }));
}