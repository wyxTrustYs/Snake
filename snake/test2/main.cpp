#include <iostream>
#include <stdlib.h>
#include <vector>
#include <time.h>
#include <windows.h>
#include <conio.h>

//#define  KEY_DOWN(key) GetAsyncKeyState(key) == (SHORT)0x8001?1:0
using namespace std;

int map[37][73];

class Snake {
public:
	int Sx, Sy;
	char body;
};
class Food {
public:
	int FoodX;
	int FoodY;
};

void InitMap() {
	for (int m = 0; m < 38; m++) {
		for (int n = 0; n < 74; n++) {
			if (m == 0 || n == 0 || m == 37 || n == 73) {
				map[m][n] = 1;
			}
			else
			{
				map[m][n] = 0;
			}
		}
	}
}

void WriteChar(int x, int y, const char szStr, int color = 0)
{

	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { x * 2, y };
	SetConsoleCursorPosition(hOut, pos);
	putchar(szStr);
}

int isEdge(int x, int y) {
	if (x == 0 || x == 73 || y == 0 || y == 37) return 1;
	return 0;
}

void ShowCursor(bool isShow) {
	HANDLE hOutStd = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 1;
	cci.bVisible = isShow;
	SetConsoleCursorInfo(hOutStd, &cci);
}

void FullScreen() {
	HWND hwnd = GetForegroundWindow();

	int x = GetSystemMetrics(SM_CXSCREEN) + 300;
	int y = GetSystemMetrics(SM_CYSCREEN) + 300;
	char setting[30];
	sprintf(setting, "mode con:cols=%d lines=%d", x, y);
	system(setting);
}


void InitSnake(vector<Snake> &v) {
	int x = 10, y = 10;
	v[0].body = '#';
	v[1].body = '*';
	v[2].body = '*';
	v[3].body = '*';
	v[4].body = '*';
	v[0].Sx = 10;
	v[0].Sy = 10;
	for (int i = 1; i < 4; i++) {
		v[i].Sy = y;
		v[i].Sx = x - i;
	}
	for (int j = 4; j > 0; j--) {
		v[j].Sx = v[j - 1].Sx;
		v[j].Sy = v[j - 1].Sy;
	}
}

void Forward(vector<Snake> &v, int x, int y) {

	int t_x;
	v[0].Sx = 10 + x;
	v[0].Sy = 10 + y;
	if (isEdge(v[0].Sx, v[0].Sy)) {
		exit(1);
	}
	for (t_x = 0; t_x < v.size(); t_x++) {
		WriteChar(v[t_x].Sx, v[t_x].Sy, v[t_x].body);
	}
	WriteChar(v[t_x - 1].Sx, v[t_x - 1].Sy, ' ');
	for (int j = v.size() - 1; j > 0; j--) {
		v[j].Sx = v[j - 1].Sx;
		v[j].Sy = v[j - 1].Sy;
	}
}

int GetOper() {
	if (_kbhit()) {
		return getch();
	}
	return 0;
}

void FoodPosition(Food &myFood,vector<Snake> &snake) {
	int SnakePosition[37][73];
	for (int i = 0; i < 37; i++) {
		memset(SnakePosition[i], 0, 73 * sizeof(int));
	}
	vector<Snake>::iterator iter = snake.begin();
	for (; iter != snake.end(); iter++) {
		SnakePosition[iter->Sy][iter->Sx] = 1;
	}
	srand((unsigned)time(NULL));
	myFood.FoodX = rand() % 72+1;
	myFood.FoodY = rand() % 36+1;
	while (SnakePosition[myFood.FoodY][myFood.FoodX] == 1 ){
		srand((unsigned)time(NULL));
		myFood.FoodX = rand() % 72 + 1;
		myFood.FoodY = rand() % 36 + 1;
	}
  	WriteChar(myFood.FoodX, myFood.FoodY, '*');
}

int Eat(vector<Snake> &snake, Food &myFood) {
	
	if (snake[0].Sx == myFood.FoodX && snake[0].Sy == myFood.FoodY) {
		Snake newsnake;
		newsnake.Sx = myFood.FoodX;
		newsnake.Sy = myFood.FoodY;
		newsnake.body = '*';
		snake.push_back(newsnake);
		return 1;
	}
	return 0;
}

void SnakeMap() {

	int i = 0;
	InitMap();
	for (int m = 0; m < 38; m++) {
		for (int n = 0; n < 74; n++) {
			if (map[m][n] == 1) {
				WriteChar(n, m, '*');
			}
		}
	}


// 	while (i < 73) {
// 		WriteChar(i, 0, '*');
// 		WriteChar(i, 37, '*');
// 		if (i > 36) {
// 			i++;
// 			continue;
// 		}
// 		WriteChar(0, i, '*');
// 		WriteChar(72, i, '*');
// 
// 		i++;
// 	}
}

int main() {
	int x = 0, y = 0;
	Snake tmpSnake;
	vector<Snake> snake(5);
	Food snakefood;
	FullScreen();
	SnakeMap();
	ShowCursor(false);
	InitSnake(snake);
	int direction = 1;
	int n_time = 200;
	bool flat = false;
	FoodPosition(snakefood,snake);
	while (TRUE) {
		if (Eat(snake, snakefood)) {
			FoodPosition(snakefood,snake);
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
			Forward(snake, x, y);
			break;
		case 1:
			y++;
			Forward(snake, x, y);
			break;
		case 2:
			x--;
			Forward(snake, x, y);
			break;
		case 3:
			x++;
			Forward(snake, x, y);
			break;
		default:
			break;
		}
	}

	return 0;
}
