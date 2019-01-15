#include "stdafx.h"
#include "SpecialElements.h"
#include "Tree.h"
#include "drawingObjects.h"

Tree::Tree(miniCoor pos_came)
{
	pos = pos_came;
}

void Tree::die()
{
	exist = false;
	age = 0;
}

void Tree::drawIfExist()
{
	if (exist)
	{
		if (age > 4)
		{
			short thicknessOFTree = 7 + 5 * age / 12, thicknessOfLeaves = 14 + 5 * age / 9;
			short centering_constant_1 = (sizeOfCell - thicknessOFTree) / 2;
			short centering_constant_2 = (sizeOfCell - thicknessOfLeaves) / 2;
			cube(pos.x * sizeOfCell + centering_constant_1, 0, pos.y* sizeOfCell + centering_constant_1, thicknessOFTree, 20, thicknessOFTree, color({ float(0.45),float(0.29),0 }));
			cube(pos.x * sizeOfCell + centering_constant_2, 20, pos.y* sizeOfCell + centering_constant_2, thicknessOfLeaves, 6 + age, thicknessOfLeaves, color({ (float)0.13,(float)0.43,0 }));
		}
		else
		{
			short thicknessOfLeaves = 10 + 2*age;
			short centering_constant_2 = (sizeOfCell - thicknessOfLeaves) / 2;
			cube(pos.x * sizeOfCell + centering_constant_2, 0, pos.y* sizeOfCell + centering_constant_2, thicknessOfLeaves, thicknessOfLeaves, thicknessOfLeaves, color({ (float)0.1,(float)0.35,0 }));
		}
	}
}
