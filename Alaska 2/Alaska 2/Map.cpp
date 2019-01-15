#include "stdafx.h"
#include "Map.h"

Map::Map(int colvoOfRegionsInLine_came, int colvoOfCellsInLine_came, int sizeOfRegion_came)
{
	colvoOfRegionsInLine = colvoOfRegionsInLine_came;
	colvoOfCellsInLine = colvoOfCellsInLine_came;

	region = new Region**[colvoOfRegionsInLine];
	for (int i = 0; i < colvoOfRegionsInLine; i++)
		region[i] = new Region*[colvoOfRegionsInLine];
	for (int i = 0; i < colvoOfRegionsInLine; i++)
		for (int j = 0; j < colvoOfRegionsInLine; j++)
			region[i][j] = new Region(i, j, colvoOfCellsInLine_came, sizeOfRegion_came);

	treePlantingUpSimulation();
}

void Map::treePlantingUpSimulation()
{
	int counterOfTrees = 0;
	int colvoOfCells = colvoOfRegionsInLine*colvoOfRegionsInLine*colvoOfCellsInLine*colvoOfCellsInLine;
	float procentsOfTrees = 0.15;
	int errorTime = 340;

	for (int step = 0; counterOfTrees < colvoOfCells*procentsOfTrees; step++)
	{
		counterOfTrees = 0;

		for (int X = 0; X < colvoOfRegionsInLine; X++)
			for (int Y = 0; Y < colvoOfRegionsInLine; Y++)
				for (int x = 0; x < colvoOfCellsInLine; x++)
					for (int y = 0; y < colvoOfCellsInLine; y++)
						if(doubleRan()<1.0/ colvoOfCells)
							region[X][Y]->tree[x][y]->exist = true;

		//grow simulation

		for (int X = 0; X < colvoOfRegionsInLine; X++)
			for (int Y = 0; Y < colvoOfRegionsInLine; Y++)
				for (int x = 0; x < colvoOfCellsInLine; x++)
					for (int y = 0; y < colvoOfCellsInLine; y++)
					{
						if (region[X][Y]->tree[x][y]->exist)
						{
							++counterOfTrees;
							if (region[X][Y]->tree[x][y]->age >= 10)
							{
								if (ran() < 0.4)
								{
									float diameter = 3.5;
									short dx = diameter * cosf(ran()*3.14);
									short dy = diameter * cosf(ran()*3.14);
									coordinate tmpCoor = { X,Y,x,y };
									tmpCoor = tmpCoor + miniCoor({ dx,dy });

									if (tmpCoor.inMap())
										region[tmpCoor.X][tmpCoor.Y]->tree[tmpCoor.x][tmpCoor.y]->exist = true;
								}
							}
							if (region[X][Y]->tree[x][y]->age >= 12)
								if (ran() < 0.25)
									region[X][Y]->tree[x][y]->die();
							region[X][Y]->tree[x][y]->age += 1;
						}
					}
		if (step >= errorTime)
			break;
	}

	// outputting of map
	/*coordinate a = { 0,0,0,0 };
	if (!region[0][0]->tree[0][0]->exist)
		cout << ". ";
	else
		cout << "$ ";
	while (true)
	{
		a = a + miniCoor({ 1,0 });
		if (a.X >= colvoOfRegionsInLine)
		{
			a.X = 0; a.x = 0;
			a = a + miniCoor({ 0,1 });
			cout << '\n';
		}
		if (a.Y >= colvoOfRegionsInLine)
			break;

		if (!region[a.X][a.Y]->tree[a.x][a.y]->exist)
			cout << ". ";
		else
			cout << "$ ";
	}*/
}

void Map::draw(short X, short Y)
{
	//miniMap
	glBegin(GL_LINES);
	glColor3f(0, 0, 1);
	for (int i = 0; i < colvoOfRegionsInLine + 1; i++)
	{
		glVertex3f(i * 10, 0, 3 * sizeOfRegion / 2);
		glVertex3f(i * 10, 0, 3 * sizeOfRegion / 2 + 10 * colvoOfRegionsInLine);
		glVertex3f(0, 0, i * 10 + 3 * sizeOfRegion / 2);
		glVertex3f(10 * colvoOfRegionsInLine, 0, i * 10 + 3 * sizeOfRegion / 2);
	}
	glEnd();
	glBegin(GL_QUADS);
	glColor3b(83, 188, 244);
	glVertex3f(X * 10, 0, Y * 10 + 3 * sizeOfRegion / 2);
	glVertex3f(X * 10 + 10, 0, Y * 10 + 3 * sizeOfRegion / 2);
	glVertex3f(X * 10 + 10, 0, Y * 10 + 3 * sizeOfRegion / 2 + 10);
	glVertex3f(X * 10, 0, Y * 10 + 3 * sizeOfRegion / 2 + 10);
	glEnd();

	region[X][Y]->draw();
}