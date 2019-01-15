#include "stdafx.h"
#include "Bag.h"

Item::Item()
{
	number = 0;
	type = none;
}

void Item::draw()
{

}

Bag::Bag()
{
	cell = new Item*[maxCells];
	for (int i = 0; i < maxCells; i++)
	{
		cell[i] = new Item();
	}
}

void Bag::draw()
{
	figure(10, 10, 4, 5, 10);
	for (int i = 0; i < maxCells; i++)
		cell[i]->draw();
}