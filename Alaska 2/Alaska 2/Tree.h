#include "glut.h"
#include "SpecialElements.h"

class Tree
{
private:
public:
	miniCoor pos;
	char age = 0;
	float exist = false;

	Tree(miniCoor pos_came);
	void die();
	void drawIfExist();
};