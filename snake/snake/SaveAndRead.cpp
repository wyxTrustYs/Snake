#include "MyMap.h"
#include "Snake.h"
#include "SaveAndRead.h"
#include "MyGame.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

void Save(char name[],Snake &snake,char mapname[],char model,char level,char direction) {
	FILE *file = NULL;
	char SnakeFilePath[20] = "./data/";
	char OtherFilePath[20] = "./data/";
	
	strcat(SnakeFilePath, name);
	strcat(SnakeFilePath, ".data");
	strcat(OtherFilePath, name);
	strcat(OtherFilePath, ".other");
	if ((file = fopen(SnakeFilePath, "wb+")) == NULL) {
		cout << "open file fail" << endl;
		exit(0);
	}
	// fwrite(&snake, sizeof(Snake), 1, file);
	int size = snake.snake.size();
	fwrite(&snake.score, sizeof(int), 1, file);
	fwrite(&size, sizeof(int), 1, file);
	fwrite(&snake.snake[0], sizeof(SnakeAttribute), snake.snake.size(), file);
	fclose(file);
	if ((file = fopen(OtherFilePath, "wb+")) == NULL) {
		cout << "open file fail" << endl;
		exit(0);
	}
	
	fputs(mapname, file);
	fputc(model, file);
	fputc(level,file);
	fputc(direction, file);
	fclose(file);
}

char* ReadingSave(char name[],Snake &snake) {
	FILE *file = NULL;
	char SnakeFilePath[20] = "./data/";
	char OtherFilePath[20] = "./data/";
	char dataname[20];
	
	memset(dataname, 0, 20 * sizeof(char));
	snake.snake.clear();
	snake.score = 0;
	strcat(SnakeFilePath, name);
	strcat(SnakeFilePath, ".data");
	strcat(OtherFilePath, name);
	strcat(OtherFilePath, ".other");
	if ((file = fopen(SnakeFilePath, "rb")) == NULL) {
		cout << "open data file fail" << endl;
		exit(0);
	}
	//fread(&snake, sizeof(Snake), 1, file);
	int size = 0;
	SnakeAttribute sa = { 0 };
	fread(&snake.score, sizeof(int), 1, file);
	fread(&size, sizeof(int), 1, file);
	for (int i = 0; i < size; ++i)
	{
		if (fread(&sa, sizeof(SnakeAttribute), 1, file) == 1)
			snake.snake.push_back(sa);
	}
	fclose(file);

	if ((file = fopen(OtherFilePath, "rb")) == NULL) {
		cout << "open data file fail" << endl;
		exit(0);
	}
	fgets(dataname,20,file);
	
	fclose(file);
	return dataname;
}