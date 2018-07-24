#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
using namespace std;

int map[30][65];

void OutputPos(int nx, int ny);

void MouseEventProc(MOUSE_EVENT_RECORD mer);
int MessageLoop();
void WriteChar(int x, int y, const char szStr[], int color);
void InitMap();
void KeyEventProc(KEY_EVENT_RECORD ker);
void FullScreen();

int main() {
	int tmp[30][65];
	FullScreen();
	FILE *file = NULL;
	if ((file = fopen("data", "wb+")) == NULL) {
		cout << "open fail" << endl;
		exit(0);
	}

	InitMap();
	MessageLoop();
	fwrite(map, sizeof(map), 1, file);
	rewind(file);
	fread(tmp, sizeof(tmp), 1, file);

	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 65; j++) {
			if (tmp[i][j] == 0) {
				cout << ' ';
			}
			else
			{
				cout << tmp[i][j] << ' ';
			}
		}
		cout << endl;
	}
	fclose(file);

	getchar();
	return 0;
}

void FullScreen() {
	HWND hwnd = GetForegroundWindow();
	int x = GetSystemMetrics(SM_CXSCREEN) + 300;
	int y = GetSystemMetrics(SM_CYSCREEN) + 300;
	char setting[30];
	sprintf(setting, "mode con:cols=%d lines=%d", x, y);
	system(setting);
}

void WriteChar(int x, int y, const char szStr[], int color = 0)
{

	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { x * 2, y };
	SetConsoleCursorPosition(hOut, pos);
	puts(szStr);
}

void OutputPos(int nX, int nY) {
	map[nY][nX] = 1;
}

void KeyEventProc(KEY_EVENT_RECORD ker) {
	if (ker.bKeyDown) {
		WriteChar(0, 0, "¼üÅÌ°´ÏÂ", 0x50);
	}
	else
	{
		WriteChar(0, 0, "¼üÅÌµ¯Æð", 0x50);
	}
}

void MouseEventProc(MOUSE_EVENT_RECORD mer) {

	if (mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) {
		if (mer.dwEventFlags == MOUSE_MOVED) {
			OutputPos(mer.dwMousePosition.X, mer.dwMousePosition.Y);
		}
	}
		
}

void InitMap() {
	for (int m = 0; m < 31; m++) {
		for (int n = 0; n < 66; n++) {
			if (m == 0 || n == 0 || m == 30 || n == 65) {
				map[m][n] = 1;
				WriteChar(n, m, "*");
			}
			else map[m][n] = 0;
		}
	}
	WriteChar(0, 32, "play:");
	WriteChar(30, 32, "score:");
}

int MessageLoop() {
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	INPUT_RECORD stcRecode = { 0 };
	DWORD dwRead;
	SetConsoleMode(hStdin, ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
	while (1) {
		ReadConsoleInput(hStdin, &stcRecode, 1, &dwRead);
		if (stcRecode.EventType == KEY_EVENT)  return 1;
		else if (stcRecode.EventType == MOUSE_EVENT) {
			MouseEventProc(stcRecode.Event.MouseEvent);
		}
	}
}