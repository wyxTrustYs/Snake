#include "map.h"
#include "Print.h"
#include "MyMessage.h"
#include <iostream>
#include <windows.h>
#include <conio.h>

int map[30][65];
using namespace std;
void InitMap() {
	for (int m = 0; m < 30; m++) {
		for (int n = 0; n < 65; n++) {
			if (m == 0 || n == 0 || m == 29 || n == 64) {
				map[m][n] = 1;
				WriteChar(n, m, "█",0);
			}
			else map[m][n] = 0;
		}
	}
	WriteChar(0, 32, "play:",0);
	WriteChar(30, 32, "score:",0);
}

void MapToFile(char name[]) {
	FILE *file = NULL;
	char FilePath[20] = "./map/";
	strcat(FilePath, name);
	if ((file = fopen(FilePath, "wb")) == NULL) {
		cout << "open map fail" << endl;
		exit(0);
	}
	fwrite(map, sizeof(map), 1, file);
	fclose(file);

}

void FileToMap(char name[]) {
	FILE *file = NULL;
	char FilePath[20] = "./map/";
	
	strcat(FilePath, name);
	if ((file = fopen(FilePath, "rb")) == NULL) {
		cout << "open map file fail" << endl;
		exit(0);
	}
	fread(map, sizeof(map), 1, file);
	fclose(file);
}

void NewMap() {
	FullScreen();
	InitMap();
	MapDIY();
}

void MapDIY() {
	WriteChar(66, 15, "1、清除地图", 0);
	WriteChar(66, 16, "2、保存地图", 0);
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	INPUT_RECORD stcRecode = { 0 };
	DWORD dwRead;

	SetConsoleMode(hStdin, ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
	while (1) {
		ReadConsoleInput(hStdin, &stcRecode, 1, &dwRead);
		if (stcRecode.EventType == KEY_EVENT) {
			if (stcRecode.Event.KeyEvent.uChar.AsciiChar == '1')
			{
				system("cls");
				InitMap();
				WriteChar(66, 15, "1、清除地图", 0);
				WriteChar(66, 16, "2、保存地图", 0);
				SetConsoleMode(hStdin, ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
			}
			else if(stcRecode.Event.KeyEvent.uChar.AsciiChar == '2')
			{
				break;
			}

			/*flat = getch();*/
// 			switch (flat)
// 			{
// 			case 49:
// 			{
// 				system("cls"); 
// 				InitMap(); 
// 				WriteChar(66, 15, "1、清除地图", 0);
// 				WriteChar(66, 16, "2、保存地图", 0);
// 				break;
// 			}
// 			case 50:break;
// 			default:
//				break;
// 			}
		}
		if (stcRecode.EventType == MOUSE_EVENT) {
			MouseEventProc(stcRecode.Event.MouseEvent);
		}
	}
}

void LoadMap() {
	system("cls");
	FullScreen();

	for (int m = 0; m < 30; m++) {
		for (int n = 0; n < 65; n++) {
				if (map[m][n] == 1) WriteChar(n, m, "█", 0);
		}
	}
	WriteChar(0, 32, "play:", 0);
	WriteChar(30, 32, "score:", 0);
}

void EditMap() {
	system("cls");
	FullScreen();

	for (int m = 0; m < 30; m++) {
		for (int n = 0; n < 65; n++) {
			if (map[m][n] == 1) WriteChar(n, m, "█");
		}
	}
	WriteChar(0, 32, "play:", 0);
	WriteChar(30, 32, "score:", 0);
	MapDIY();
}