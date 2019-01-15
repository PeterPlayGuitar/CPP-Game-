#include "iostream"
#include "SpecialElements.h"
#include "Tree.h"

using namespace std;

class Region
{
private:
	
public:
	miniCoor pos;
	int colvoOfCellsInLine;
	int sizeOfRegion;

	Tree*** tree;

	Region(short x, short y, int colvoOfCellsInLine_came, int sizeOfRegion_came);
	void draw();
};