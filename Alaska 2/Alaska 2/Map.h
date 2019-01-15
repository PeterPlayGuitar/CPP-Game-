#include "iostream"
#include "SpecialElements.h"
#include "Region.h"

using namespace std;

class Map
{
private:
	int colvoOfRegionsInLine;
	int colvoOfCellsInLine;
public:
	Region*** region;


	Map(int colvoOfRegionsInLine_came, int colvoOfCellsInLine_came, int sizeOfRegion_came);
	void treePlantingUpSimulation();
	void draw(short X, short Y);
};