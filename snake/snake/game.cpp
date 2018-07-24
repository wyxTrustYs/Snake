#include "game.h"
#include <iostream>
#include <conio.h>
#include "Food.h"
#include "map.h"
#include "Print.h"
#include "Snake.h"

using namespace std;

void start() {
	Snake snake;
	int x = 0, y = 0;

	Food snakefood;
	FullScreen();
	InitMap();
	ShowCursor(false);
	snake.Init();
	int direction = 1;
	int n_time = 200;
	bool flat = false;
	snakefood.FoodPosition();
	while (TRUE) {
		if (snake.Eat(snakefood)) {
			snakefood.FoodPosition();
		}
		Sleep(n_time);
		if (GetKeyState(VK_SPACE) < 0) {
			n_time = 20;
		}
		else
		{
			n_time = 200;
		}

		switch (GetOper())
		{
		case 'w':
			direction = 0;
			break;
		case 's':
			direction = 1;
			break;
		case 'a':
			direction = 2;
			break;
		case 'd':
			direction = 3;
			break;
		case 'p':
			cout << "ÓÎÏ·ÔÝÍ£" << endl;
			getch();
			break;
		default:
			break;
		}
		switch (direction)
		{
		case 0:
			y--;
			snake.Forward(x, y);
			break;
		case 1:
			y++;
			snake.Forward(x, y);
			break;
		case 2:
			x--;
			snake.Forward(x, y);
			break;
		case 3:
			x++;
			snake.Forward(x, y);
			break;
		default:
			break;
		}
	}
}

void EditMap() {

}