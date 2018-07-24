

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <time.h>
#include <windows.h>
#include <conio.h>



using namespace std;

int map[30][65];

class SnakeAttribute {
public:
	int Sx, Sy;
	char body;
};

class Snake {
public:
	vector<SnakeAttribute> snake;
	void Init() {
		SnakeAttribute tmp[5];
		tmp[0].Sx = 10 + 0;
		tmp[0].Sy = 10 + 0;
		tmp[0].body = '#';
		for (int i = 1; i < 5; i++) {
			tmp[i].Sx = 10 - i;
			tmp[i].Sy = 10;
			tmp[i].body = '*';
		}
		for (int j = 0; j < 5; j++) {
			snake.push_back(tmp[j]);
		}
	}
	void Forward(int x,int y) {
		int t_x;
		snake[0].Sx = 10 + x;
		snake[0].Sy = 10 + y;
		if (map[snake[0].Sy][snake[0].Sx] == 1) {
			exit(1);
		}
		map[snake[0].Sy][snake[0].Sx] = 1;
		for (t_x = 0; t_x < snake.size(); t_x++) {
			map[snake[t_x].Sy][snake[t_x].Sx] = 1;
			WriteChar(snake[t_x].Sx, snake[t_x].Sy, snake[t_x].body);
		}
		map[snake[snake.size() - 1].Sy][snake[snake.size() - 1].Sx] = 0;
		WriteChar(snake[t_x - 1].Sx, snake[t_x - 1].Sy, ' ');
		for (int j = snake.size() - 1; j > 0; j--) {
			snake[j].Sx = snake[j - 1].Sx;
			snake[j].Sy = snake[j - 1].Sy;
		}
	}

};

class Food {
public:
	int FoodX;
	int FoodY;
};

void InitMap() {
	for (int m = 0; m < 31; m++) {
		for (int n = 0; n < 66; n++) {
			if (m == 0 || n == 0 || m == 30 || n == 65) map[m][n] = 1;
			else map[m][n] = 0;
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
	if (map[y][x]  == 1) return 1;
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


void InitSnake(vector<SnakeAttribute> &v) {
	int x = 10, y = 10;
	v[0].body = '#';
	v[1].body = '*';
	v[2].body = '*';
	v[3].body = '*';
	v[4].body = '*';
	v[0].Sx = 10;
	v[0].Sy = 10;
	for (int i = 0; i < 5; i++) {
		v[i].Sy = y;
		v[i].Sx = x - i;
	}
	// 	for (int j = 4; j > 0; j--) {
	// 		v[j].Sx = v[j - 1].Sx;
	// 		v[j].Sy = v[j - 1].Sy;
	// 	}
}

void Forward(vector<SnakeAttribute> &v, int x, int y) {

	int t_x;
	v[0].Sx = 10 + x;
	v[0].Sy = 10 + y;
	if (isEdge(v[0].Sx, v[0].Sy)) {
		exit(1);
	}
	map[v[0].Sy][v[0].Sx] = 1;
	for (t_x = 0; t_x < v.size(); t_x++) {
		map[v[t_x].Sy][v[t_x].Sx] = 1;
		WriteChar(v[t_x].Sx, v[t_x].Sy, v[t_x].body);
	}
	map[v[v.size() - 1].Sy][v[v.size() - 1].Sx] = 0;
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

void FoodPosition(Food &myFood) {
	srand((unsigned)time(NULL));
	myFood.FoodX = rand() % 72 + 1;
	myFood.FoodY = rand() % 36 + 1;
	while (map[myFood.FoodY][myFood.FoodX] == 1) {
		srand((unsigned)time(NULL));
		myFood.FoodX = rand() % 64 + 1;
		myFood.FoodY = rand() % 29 + 1;
	}
	WriteChar(myFood.FoodX, myFood.FoodY, '*');
}

int Eat(vector<SnakeAttribute> &snake, Food &myFood) {

	if (snake[0].Sx == myFood.FoodX && snake[0].Sy == myFood.FoodY) {
		SnakeAttribute newsnake;
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
	for (int m = 0; m < 31; m++) {
		for (int n = 0; n < 66; n++) {
			if (map[m][n] == 1) {
				WriteChar(n, m, '*');
			}
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


int main() {
	int x = 0, y = 0;
	vector<SnakeAttribute> snake(5);
	Food snakefood;
	FullScreen();
	SnakeMap();
	ShowCursor(false);
	InitSnake(snake);
	int direction = 1;
	int n_time = 200;
	bool flat = false;
	FoodPosition(snakefood);
	while (TRUE) {
		if (Eat(snake, snakefood)) {
			FoodPosition(snakefood);
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
