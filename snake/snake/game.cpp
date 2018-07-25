#include "game.h"
#include "Food.h"
#include "map.h"
#include "Print.h"
#include "SaveAndRead.h"

#include <iostream>
#include <conio.h>
using namespace std;


void FunnyStart(char mapname[], Snake &GSnake) {
	Snake tmpSnake;
	tmpSnake = GSnake;
	int x = 0, y = 0;

	Food snakefood;
	// 	FullScreen();
	// 	InitMap();
	ShowCursor(false);
// 	tmpSnake.Init("player1");
	int direction = 1;
	int n_time = 200;
	int flat = 0;
	int snakescore;
	int FoodSpeed = 10;
	int ForwardDir = 0;
	snakefood.FoodPosition();
	while (TRUE) {
		// 		if (snake.Eat(snakefood)) {
		// 			snakefood.FoodPosition();
		// 		}
		if (tmpSnake.Eat(snakefood)) {
			snakefood.FoodPosition();
			snakescore = tmpSnake.score;
			if (snakescore % 5 == 0 && FoodSpeed >= 0) {
				FoodSpeed = FoodSpeed - 2;
			}
		}

		if (flat >= FoodSpeed) {
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
		{
			int save = 0;
			char SnakeName[20];
			WriteChar(34, 34, "游戏暂停(按p游戏继续)", 0);
			WriteChar(24, 36, "1、退出游戏", 0);
			WriteChar(34, 36, "2、存档并退出", 0);
			cin >> save;
			if (save == 2) {
				WriteChar(35, 34, "请输入存档名：", 0);
				cin >> SnakeName;
				Save(SnakeName, tmpSnake, mapname, '2');
				return;
			}
			getch();
			WriteChar(34, 34, "        ", 0);
			break;
		}
		default:
			break;
		}

		switch (direction)
		{
		case 0:
			y = -1;
			x = 0;
			tmpSnake.Forward(x, y);
			break;
		case 1:
			y = 1;
			x = 0;
			tmpSnake.Forward(x, y);
			break;
		case 2:
			x = -1;
			y = 0;
			tmpSnake.Forward(x, y);
			break;
		case 3:
			x = 1;
			y = 0;
			tmpSnake.Forward(x, y);
			break;
		default:
			break;
		}
	}
	
}

void TraditionStart(char mapname[], Snake &GSnake) {
	Snake tmpSnake;
	tmpSnake = GSnake;
	int x = 0, y = 0;

	Food snakefood;
	// 	FullScreen();
	// 	InitMap();
	ShowCursor(false);
	/*GSnake.Init("player1");*/
	int direction = 1;
	int n_time = 200;
	int ForwardDir = 0;
	snakefood.FoodPosition();
	while (TRUE) {
		if (tmpSnake.Eat(snakefood)) {
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
		{
			int save = 0;
			char SnakeName[20];
			WriteChar(34, 34, "游戏暂停(按p游戏继续)", 0);
			WriteChar(24, 36, "1、退出游戏", 0);
			WriteChar(34, 36, "2、存档并退出", 0);
			cin >> save;
			if (save == 2) {
				WriteChar(34, 34, "请输入存档名：", 0);
				cin >> SnakeName;
				Save(SnakeName, tmpSnake, mapname, '1');
				return;
			}
			WriteChar(34, 34, "        ", 0);
			break;
		}
		default:
			break;
		}
		switch (direction)
		{
		case 0:
			y = -1;
			x = 0;
			tmpSnake.Forward(x, y);
			break;
		case 1:
			y = 1;
			x = 0;
			tmpSnake.Forward(x, y);
			break;
		case 2:
			x = -1;
			y = 0;
			tmpSnake.Forward(x, y);
			break;
		case 3:
			x = 1;
			y = 0;
			tmpSnake.Forward(x, y);
			break;
		default:
			break;
		}
	}
	
}