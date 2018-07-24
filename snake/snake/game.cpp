#include "game.h"
#include <iostream>
#include <conio.h>
#include "Food.h"
#include "map.h"
#include "Print.h"
#include "Snake.h"

using namespace std;

void FunnyStart() {
	Snake snake;
	int x = 0, y = 0;

	Food snakefood;
	// 	FullScreen();
	// 	InitMap();
	ShowCursor(false);
	snake.Init("player1");
	int direction = 1;
	int n_time = 200;
	int flat = 0;
	int ForwardDir = 0;
	snakefood.FoodPosition();
	while (TRUE) {
		// 		if (snake.Eat(snakefood)) {
		// 			snakefood.FoodPosition();
		// 		}
		if (snake.Eat(snakefood)) {
			snakefood.FoodPosition();
		}

		if (flat == 5) {
			snakefood.FoodPositionMove();
			flat = 0;
		}
		else
		{
			flat++;
		}

		Sleep(n_time);
		if (GetKeyState(VK_SPACE) < 0) {
			n_time = 20;
		}
		else
		{
			n_time = 200;
		}
		ForwardDir = direction;
		switch (GetOper())
		{
		case 'w':
			if (ForwardDir != 1) {
				direction = 0;
			}
			break;
		case 's':
			if (ForwardDir != 0) {
				direction = 1;
			}
			break;
		case 'a':
			if (direction != 3) {
				direction = 2;
			}
			break;
		case 'd':
			if (direction != 2) {
				direction = 3;
			}
			break;
		case 'p':
			WriteChar(34, 34, "ÓÎÏ·ÔÝÍ£", 0);
			getch();
			WriteChar(34, 34, "        ", 0);
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

void TraditionStart() {
	Snake snake;
	int x = 0, y = 0;

	Food snakefood;
	// 	FullScreen();
	// 	InitMap();
	ShowCursor(false);
	snake.Init("player1");
	int direction = 1;
	int n_time = 200;
	int ForwardDir = 0;
	snakefood.FoodPosition();
	while (TRUE) {
		if (snake.Eat(snakefood)) {
			snakefood.FoodPosition();
		}
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
		ForwardDir = direction;
		switch (GetOper())
		{
		case 'w':
			if (ForwardDir != 1) {
				direction = 0;
			}
			break;
		case 's':
			if (ForwardDir != 0) {
				direction = 1;
			}
			break;
		case 'a':
			if (direction != 3) {
				direction = 2;
			}
			break;
		case 'd':
			if (direction != 2) {
				direction = 3;
			}
			break;
		case 'p':
			WriteChar(34, 34, "ÓÎÏ·ÔÝÍ£", 0);
			getch();
			WriteChar(34, 34, "        ", 0);
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