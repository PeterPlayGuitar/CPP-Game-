#include "SpecialElements.h"

class List 
{
private:
	char max = 1;
	struct Node
	{
		Node* next;
		miniCoor direction;
	};
public:
	char length = 0;
	Node* end = NULL;
	Node* begin = NULL;

	void push(miniCoor dir);
	miniCoor pop();
	bool empty();
};