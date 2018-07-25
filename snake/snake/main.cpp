#include <iostream>
#include "game.h"
#include "map.h"
#include "Print.h"
#include "Snake.h"
#include "SaveAndRead.h"
using namespace std;

int main() {
	int option;
	char name[10];
	int num;
	Snake snake;
	FullScreen();
	while (true) {
		system("cls");
		WriteChar(30, 5, "贪吃蛇游戏");
		WriteChar(20, 10, "1、开始游戏");
		WriteChar(30, 10, "2、编辑地图");
		WriteChar(40, 10, "3、载入地图");
		WriteChar(50, 10, "4、读取存档\n");

		cin >> option;

		switch (option)
		{
		case 1:
			system("cls");
			WriteChar(20, 10, "1、传统玩法");
			WriteChar(28, 10, "2、趣味玩法\n");

			cin >> num;
			FileToMap("init.map");
			LoadMap();
			snake.Init("player1");
			switch (num)
			{
			case 1:
				TraditionStart("init.map",snake);
				break;
			case 2:
				FunnyStart("init.map",snake);
				break;
			default:
				break;
			}

			break;
		case 2:
			//			cout << "1、修改地图\n2、新建地图\n" << endl;
			system("cls");
			WriteChar(20, 10, "1、修改地图");
			WriteChar(28, 10, "2、新建地图\n");
			cin >> num;
			switch (num)
			{
			case 1:
				system("cls");
				system("dir .\\map");
				cin >> name;
				FileToMap(name);
				EditMap();
				MapToFile(name);
				break;
			case 2:
				//				cout << "请输入地图名称" << endl;
				system("cls");
				WriteChar(20, 10, "请输入地图名称");
				cin >> name;
				NewMap();
				MapToFile(name);
				break;
			default:
				break;
			}

			break;
		case 3:
			system("cls");

			system("dir .\\map");
			cout << "请选择你要打开的地图" << endl;
			cin >> name;
			system("cls");
			WriteChar(20, 10, "1、传统玩法");
			WriteChar(28, 10, "2、趣味玩法\n");
			cin >> num;
			FileToMap(name);
			LoadMap();
			snake.Init("player1");
			switch (num)
			{
			case 1:
				TraditionStart(name,snake);
				break;
			case 2:
				FunnyStart(name,snake);
				break;
			default:
				break;
			}
			break;
		case 4:
		{
			char level;
			char *tmpname = NULL;
			system("cls");
			system("dir .\\data");
			cin >> name;
			snake.snake.clear();
			tmpname = ReadingSave(name, snake);
			level = tmpname[strlen(tmpname) - 1];
			tmpname[strlen(tmpname) - 1] = '\0';
			strcpy(name, tmpname);

			system("cls");
			FileToMap(name);
			LoadMap();
			//			SetSnake(snake);
			switch (level)
			{
			case '1':
				TraditionStart(name, snake);
				break;
			case '2':
				FunnyStart(name, snake);
				break;
			default:
				break;
			}
			break;
		}
			
		default:
			break;
		}


	}
	return 0;
}