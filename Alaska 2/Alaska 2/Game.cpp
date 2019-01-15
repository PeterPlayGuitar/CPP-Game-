#include "stdafx.h"
#include "glut.h"
#include "Game.h"

using namespace std;

Game::Game()
{
	directionsOfKeys[0] = { 0,-1 };directionsOfKeys[1] = { -1,0 };directionsOfKeys[2] = { 0,1 };directionsOfKeys[3] = { 1,0 };

	man = new Man(colvoOfRegionsInLine / 2, colvoOfRegionsInLine / 2, colvoOfCellsInLine / 2, colvoOfCellsInLine / 2, colvoOfCellsInLine, sizeOfRegion);
	map = new Map(colvoOfRegionsInLine, colvoOfCellsInLine, sizeOfRegion);
}

bool Game::thisCoordinateIsFree(coordinate place)
{
	if (!place.inMap())
		return false;
	if (map->region[place.X][place.Y]->tree[place.x][place.y]->exist)
		return false;

	return true;
}

void Game::goAct()
{
	//about man
	if (!man->listOfDirections.empty() && !man->moving)
	{
		man->currentDirection = man->listOfDirections.pop();

		coordinate futureCoorOFMan = { man->pos.X,man->pos.Y,man->pos.x,man->pos.y };
		futureCoorOFMan = futureCoorOFMan + man->currentDirection;

		if (thisCoordinateIsFree(futureCoorOFMan))
		{
			man->pos = man->pos + man->currentDirection;
			man->moving = true;
		}
	}
	man->goAct();
}
void Game::draw()
{
	if (state == gameState)
	{
		map->draw(man->pos.X, man->pos.Y);
		man->draw();
		if (rotating)
			rotatingFunction();
	}
	else if (state == bagState)
	{
		man->bag->draw();
	}
}

void Game::keys(int key)
{
	// GAME STATE
	if (state == gameState)
		switch (key)
		{
		case(GLUT_KEY_UP):
			man->addDirection(directionsOfKeys[specialNum.num]);
			break;
		case(GLUT_KEY_LEFT):
			man->addDirection(directionsOfKeys[specialNum.num += 1]);
			specialNum.num -= 1;
			break;
		case(GLUT_KEY_DOWN):
			man->addDirection(directionsOfKeys[specialNum.num += 2]);
			specialNum.num -= 2;
			break;
		case(GLUT_KEY_RIGHT):
			man->addDirection(directionsOfKeys[specialNum.num += 3]);
			specialNum.num -= 3;
			break;
		case(GLUT_KEY_F1):
			switchState(bagState);
			break;
		case(GLUT_KEY_F2):
			rotating = true;
			break;
		case(GLUT_KEY_F3):
			break;
		}
	// BAG STATE
	else if (state == bagState)
		switch (key)
		{
		case(GLUT_KEY_F1):
			switchState(gameState);
			break;
		case(GLUT_KEY_F2):
			break;
		}
}

void Game::switchState(stateOfGame newState)
{
	switch (newState)
	{
	case gameState:
		state = gameState;
		glTranslatef(404, 459, 0);
		glRotated(-35, -1, 0, 0);
		glRotated(30, 0, -1, 0);
		break;
	case bagState:
		while (specialNum.num != 0)
		{
			specialNum.num -= 1;
			glTranslatef(200, 0, 200);
			glRotated(90, 0, 1, 0);
			glTranslatef(-200, 0, -200);
		}
		state = bagState;
		glRotated(30, 0, 1, 0);
		glRotated(-35, 1, 0, 0);
		glTranslatef(-404, -459, 0);
		break;
	}
}

void Game::rotatingFunction()
{

	float currentSpeed = rotatingScreanFunction();

	glTranslatef(200, 0, 200);
	glRotated(currentSpeed, 0, 1, 0);
	glTranslatef(-200, 0, -200);

	errorOFDegrees += currentSpeed;

	++counterOfRotating;
	if (counterOfRotating > timeOfRotating)
	{
		rotating = false;
		counterOfRotating = 0;

		specialNum.num--;

		glTranslatef(200, 0, 200);
		glRotated(90.0 - errorOFDegrees, 0, 1, 0);
		glTranslatef(-200, 0, -200);
		errorOFDegrees = 0;
	}

}

float Game::rotatingScreanFunction()
{
	float k = 4.0 * 90.0 / ((float)timeOfRotating * timeOfRotating);
	if (counterOfRotating <= timeOfRotating / 2)
		return k*counterOfRotating;
	return k*(-counterOfRotating + timeOfRotating);
}

//float speedFunction(float time)
//{
//	float speed;
//
//	float k = 4.0 * (тут переменная насколько ты сместишся) / (all_time * all_time);
//
//	if (time <= all_time / 2)
//		speed = k*time;
//	else
//		speed = k*(all_time - time);
//
//	return speed;
//}