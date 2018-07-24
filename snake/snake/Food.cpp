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
	WriteChar(FoodPos.X, FoodPos.Y, '*');
}