#include "SpecialElements.h"
#include "List.h"
#include "Bag.h"

static int timeOfMoving = 6;
static int manSize = 16;
static int manHeight = 20;

class Man
{
private:
	float x = 0;
	float y = 0;
	float z = 0;

	short colvoOfCellsInLine;
	short sizeOfOneCell;

	//about moving
	int counterOfMoving = 0;
public:
	coordinate pos;
	List listOfDirections;
	bool moving = false;
	miniCoor currentDirection;

	//about bag
	Bag* bag;

	Man(short X_came, short Y_came, short x_came, short y_came, int colvoOfCellsInLine_came, int sizeOfRegion_came);
	void addDirection(miniCoor dir);
	void Man::moveManByTimeByDirectionInMovingAnimation();
	void goAct();
	void draw();
};