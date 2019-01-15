#include "stdafx.h"
#include "List.h"

using namespace std;

void List::push(miniCoor dir)
{
	if (length < max)
	{
		Node* tmpEnd = end;

		Node* newNode = new Node;
		newNode->next = NULL;
		newNode->direction = dir;

		end = newNode;
		if (tmpEnd == NULL)
		{
			begin = newNode;
		}
		else
			tmpEnd->next = newNode;

		++length;
	}
}

miniCoor List::pop()
{
	miniCoor dir = { 0,0 };
	if (begin != NULL)
	{
		dir = begin->direction;

		Node* tmp = begin->next;
		delete begin;
		begin = tmp;
		if (begin == NULL)
			end = NULL;
		--length;
	}
	return dir;
}

bool List::empty()
{
	if (begin == NULL)
		return true;
	else
		return false;
}