#include "MyGame.h"
#include "Food.h"
#include "MyMap.h"
#include "Print.h"
#include "SaveAndRead.h"

#include <iostream>
#include <conio.h>
using namespace std;
int speed ;
char level;
int direction = 1;
char SetSpeed() {
	cout << "请选择游戏难度" << endl;
	cout << "1、简单 2、普通 3、困难 4、退出" << endl;
	cin >> level;
	switch (level)
	{
	case '1':
		speed = 200;
		break;
	case '2':
		speed = 140;
		break;
	case '3':
		speed = 80;
		break;
	default:
		break;
	}
	return level;
}
void SetSpeed(char mylevel) {
	level = mylevel;
	switch (level)
	{
	case '1':
		speed = 200;
		break;
	case '2':
		speed = 140;
		break;
	case '3':
		speed = 80;
		break;
	default:
		return;
	}
}

void SetDirection(char direct) {
	direction = direct - 48;
}
void FunnyStart(char mapname[], Snake &GSnake) {
	Snake tmpSnake;
	tmpSnake = GSnake;
	int x = 0, y = 0;
	
	Food snakefood;
	// 	FullScreen();
	// 	InitMap();
	ShowCursor(false);
// 	tmpSnake.Init("player1");
	
	int flat = 0;
	int snakescore;
	int FoodSpeed = 10;
	int ForwardDir = 0;
	snakefood.FoodPosition();

	int n_time = speed;
	while (TRUE) {
		
		if (tmpSnake.Eat(snakefood)) {
			snakefood.FoodPosition();
			snakescore = tmpSnake.score;
			if (snakescore % 5 == 0 && FoodSpeed >= 0) {
				FoodSpeed = FoodSpeed / 2;
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
			n_time = speed;
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
			HANDLE houtstd = GetStdHandle(STD_OUTPUT_HANDLE);
			WriteChar(27, 34, "游戏暂停(按p游戏继续)", 0);
			WriteChar(24, 36, "1、退出游戏", 0);
			WriteChar(34, 36, "2、存档并退出", 0);
			SetConsoleCursorPosition(houtstd, { 48,37 });
			cin >> save;
			if (save == 2) {
				WriteChar(27, 34, "请输入存档名：       ", 0);
				WriteChar(24, 36, "          ", 0);
				WriteChar(34, 36, "             ", 0);
				SetConsoleCursorPosition(houtstd, { 70,34 });
				cin >> SnakeName;
				char tmpdir = direction + 48;
				Save(SnakeName, tmpSnake, mapname, '2',level,tmpdir);
				return;
			}
			else if (save == 1) return;
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
	int ForwardDir = 0;
	snakefood.FoodPosition();
	int n_time = speed;
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
			n_time = speed;
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
			HANDLE houtstd = GetStdHandle(STD_OUTPUT_HANDLE);
			WriteChar(27, 34, "游戏暂停(按p游戏继续)", 0);
			WriteChar(24, 36, "1、退出游戏", 0);
			WriteChar(34, 36, "2、存档并退出", 0);
			SetConsoleCursorPosition(houtstd, { 48,37 });
			cin >> save;
			if (save == 2) {
				WriteChar(27, 34, "请输入存档名：       ", 0);
				WriteChar(24, 36, "          ", 0);
				WriteChar(34, 36, "             ", 0);
				SetConsoleCursorPosition(houtstd, { 70,34 });
				cin >> SnakeName;
				char tmpdir = direction + 48;
				Save(SnakeName, tmpSnake, mapname, '1',level,tmpdir);
				return;
			}
			else if (save == 1) return;
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