#include <iostream>
#include "game.h"
#include "map.h"
using namespace std;

int main() {
	cout << "贪吃蛇游戏" << endl;
	int option;
	char name[10];
	int num;
	while (true) {
		system("cls");
		printf("1、开始游戏\n2、编辑地图\n3、载入地图\n");
		cin >> option;
		switch (option)
		{
		case 1:
			printf("1、传统玩法\n2、趣味玩法\n");
			
			cin >> num;
			FileToMap("init.map");
			LoadMap();
			switch (num)
			{
			case 1:
				TraditionStart();
				break;
			case 2:
				FunnyStart();
				break;
			default:
				break;
			}
			
			break;
		case 2:
			cout << "1、修改地图\n2、新建地图\n" << endl;
			
			cin >> num;
			switch (num)
			{
			case 1:
				system("dir .\\map");
				cin >> name;
				FileToMap(name);
				EditMap();
				MapToFile(name);
				break;
			case 2:
				cout << "请输入地图名称" << endl;
				cin >> name;
				NewMap();
				MapToFile(name);
				break;
			default:
				break;
			}
			
			break;
		case 3:
			
			system("dir .\\map");
			cin >> name;
			FileToMap(name);
			LoadMap();
			system("pause");
			break;
		default:
			break;
		}
		
		
	}
	return 0;
}