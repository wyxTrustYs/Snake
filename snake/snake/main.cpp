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
		WriteChar(30, 5, "̰������Ϸ");
		WriteChar(20, 10, "1����ʼ��Ϸ");
		WriteChar(30, 10, "2���༭��ͼ");
		WriteChar(40, 10, "3�������ͼ");
		WriteChar(50, 10, "4����ȡ�浵\n");

		cin >> option;

		switch (option)
		{
		case 1:
			system("cls");
			WriteChar(20, 10, "1����ͳ�淨");
			WriteChar(28, 10, "2��Ȥζ�淨\n");

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
			//			cout << "1���޸ĵ�ͼ\n2���½���ͼ\n" << endl;
			system("cls");
			WriteChar(20, 10, "1���޸ĵ�ͼ");
			WriteChar(28, 10, "2���½���ͼ\n");
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
				//				cout << "�������ͼ����" << endl;
				system("cls");
				WriteChar(20, 10, "�������ͼ����");
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
			cout << "��ѡ����Ҫ�򿪵ĵ�ͼ" << endl;
			cin >> name;
			system("cls");
			WriteChar(20, 10, "1����ͳ�淨");
			WriteChar(28, 10, "2��Ȥζ�淨\n");
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