#include "stdafx.h"
#include "glut.h"
#include <iostream>
#include <ctime>
#include "Game.h"

using namespace std;

void processNormalKeys(int key, int x, int y);
void TimerFunction(int value);
void Display();
void Initialize();
void makingGlut();

int FPS = 60;
int width = 0.7 * 1366;//800;
int height = 0.7 * 768;// width / sqrt(2);

Game* game;

int main(int argc, char **argv)
{

	srand(time(0));

	game = new Game;

	glutInit(&argc, argv);
	makingGlut();

	return 0;
}

void makingGlut()
{
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(width, height);
	glutInitWindowPosition(200, 100);
	glutCreateWindow("Alaska");

	Initialize();

	glutDisplayFunc(Display);

	glutSpecialUpFunc(processNormalKeys);
	glutTimerFunc(1000 / FPS, TimerFunction, 1);

	glutMainLoop();
}

void Initialize()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-width / 2, width / 2, -height / 2, height / 2, -1600, 1600);

	gluLookAt(1.0, 0, 1.0, 0, -1, 0, 0.0, 1.0, 0.0);

	glTranslatef(200, 0, 200);
	glRotated(15, 0, 1, 0);
	glTranslatef(-200, 0, -200);

	glTranslatef(0, 240, 0);
}

void Display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	game->draw();

	glutSwapBuffers();
}

void TimerFunction(int value)
{
	game->goAct();
	glutPostRedisplay();
	glutTimerFunc(1000 / (float)FPS, TimerFunction, 1);
}

void processNormalKeys(int key, int x, int y)
{
	game->keys(key);
}