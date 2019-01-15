#include <iostream>
#include "SpecialElements.h"
#include "Map.h"
#include "Man.h"

static short timeOfRotating = 31;

enum stateOfGame { gameState, bagState };

class Game
{
private:
	Map* map;
	Man* man;

	//about game state
	stateOfGame state = gameState;

	void switchState(stateOfGame);

	//about rotating
	short counterOfRotating = 0;
	bool rotating = false;
	float errorOFDegrees = 0;
	miniCoor directionsOfKeys[4];
	struct twoBits { unsigned char num : 2; } specialNum = { 0 };//num Of What Direction Of Keys We Use With Rotated Land

	float rotatingScreanFunction( );
	void rotatingFunction();
public:
	Game();
	bool thisCoordinateIsFree(coordinate place);
	void goAct();
	void draw();
	void keys(int key);
};