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
	int score = 0;
	vector<SnakeAttribute> snake;
	void Init();
	void Forward(int x, int y);
	int Eat(Food &myFood);
};