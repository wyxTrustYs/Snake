#include <iostream>
#include "game.h"
#include "map.h"
using namespace std;

int main() {
	cout << "̰������Ϸ" << endl;
	int option;
	char name[10];
	int num;
	while (true) {
		system("cls");
		printf("1����ʼ��Ϸ\n2���༭��ͼ\n3�������ͼ\n");
		cin >> option;
		switch (option)
		{
		case 1:
			printf("1����ͳ�淨\n2��Ȥζ�淨\n");
			
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
			cout << "1���޸ĵ�ͼ\n2���½���ͼ\n" << endl;
			
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
				cout << "�������ͼ����" << endl;
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