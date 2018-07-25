#ifndef Snake_H
#define Snake_H


#include <vector>
#include "Food.h"
using namespace std;

class SnakeAttribute {
public:
	int Sx, Sy;
	char body;
};

class Snake {
public:
	int score;
	//string name;
	vector<SnakeAttribute> snake;
	void Init(string name);
	void Forward(int x, int y);
	int Eat(Food &myFood);
};

#endif