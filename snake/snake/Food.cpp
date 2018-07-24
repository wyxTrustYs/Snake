#include "Food.h"
#include "map.h"
#include "Print.h"

#include <iostream>
#include <time.h>

using namespace std;

void Food::FoodPosition() {
	srand((unsigned)time(NULL));
	FoodPos.X = rand() % 64 + 1;
	FoodPos.Y = rand() % 29 + 1;
	while (map[FoodPos.Y][FoodPos.X] == 1) {
		srand((unsigned)time(NULL));
		FoodPos.X = rand() % 64 + 1;
		FoodPos.Y = rand() % 29 + 1;
	}
	WriteChar(FoodPos.X, FoodPos.Y, '*',0);
}

void Food::FoodPositionMove() {

	srand((unsigned)time(NULL));
	int direction;
	direction = rand() % 4;
	WriteChar(FoodPos.X, FoodPos.Y, ' ', 0);
	switch (direction)
	{
	case 0:
		if(map[FoodPos.Y][FoodPos.X+1] != 1) FoodPos.X++;
		else if (map[FoodPos.Y + 1][FoodPos.X] != 1) FoodPos.Y++;
		else if (map[FoodPos.Y - 1][FoodPos.X] != 1) FoodPos.Y--;
		else if (map[FoodPos.Y][FoodPos.X - 1] != 1)FoodPos.X--;
		break;
	case 1:
		if (map[FoodPos.Y][FoodPos.X - 1] != 1) FoodPos.X--;
		else if (map[FoodPos.Y + 1][FoodPos.X] != 1) FoodPos.Y++;
		else if (map[FoodPos.Y - 1][FoodPos.X] != 1) FoodPos.Y--;
		else if (map[FoodPos.Y][FoodPos.X + 1] != 1) FoodPos.X++;
		break;
	case 2:
		if (map[FoodPos.Y+1][FoodPos.X] != 1) FoodPos.Y++;
		else if (map[FoodPos.Y][FoodPos.X - 1] != 1)FoodPos.X--;
		else if (map[FoodPos.Y][FoodPos.X + 1] != 1) FoodPos.X++;
		else if (map[FoodPos.Y - 1][FoodPos.X] != 1) FoodPos.Y--;
		break;
	case 3:
		if (map[FoodPos.Y-1][FoodPos.X] != 1) FoodPos.Y--;
		else if (map[FoodPos.Y][FoodPos.X - 1] != 1)FoodPos.X--;
		else if (map[FoodPos.Y][FoodPos.X + 1] != 1) FoodPos.X++;
		else if (map[FoodPos.Y + 1][FoodPos.X] != 1) FoodPos.Y++;
		break;
	default:
		break;
	}
	WriteChar(FoodPos.X, FoodPos.Y, '*',0);
}