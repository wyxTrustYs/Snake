#include "Snake.h"
#include "map.h"
#include "Print.h"
//#include "Food.h"
#include <iostream>
#include <sstream>
using namespace std;

void Snake::Init() {
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

void Snake::Forward(int x, int y) {
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

int Snake::Eat(Food &myFood) {
//	stringstream ss;
	char c[8];
	memset(c, 0, 8 * sizeof(char));
	if (snake[0].Sx == myFood.FoodPos.X && snake[0].Sy == myFood.FoodPos.Y) {
		SnakeAttribute newsnake;
		newsnake.Sx = myFood.FoodPos.X;
		newsnake.Sy = myFood.FoodPos.Y;
		newsnake.body = '*';
		snake.push_back(newsnake);
		score++;
		sprintf(c, "%5d", score);
		WriteChar(34, 32, c);
		return 1;
	}
	return 0;
}