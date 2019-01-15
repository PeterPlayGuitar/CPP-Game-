#include "iostream"
#include "drawingObjects.h"

using namespace std;

enum itemType { none, wood };

class Item
{
public:
	itemType type;
	short number;

	Item();
	void draw();
};

class Bag
{
private:
public:
	const char maxCells = 10;
	Item** cell;

	Bag();
	void draw();
};
