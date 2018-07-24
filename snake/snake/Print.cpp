#include "Print.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;


void WriteChar(int x, int y, const char szStr, int color)
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { x * 2, y };
	SetConsoleCursorPosition(hOut, pos);
	putchar(szStr);
}

void WriteChar(int x, int y, const char szStr[], int color) {
	{
		HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD pos = { x * 2, y };
		SetConsoleCursorPosition(hOut, pos);
		puts(szStr);
	}
}
void WriteChar(int x, int y, const char szStr[]) {
	{
		HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD pos = { x*2 , y };
		SetConsoleCursorPosition(hOut, pos);
		cout << szStr;
	}
}

void ShowCursor(bool isShow) {
	HANDLE hOutStd = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 1;
	cci.bVisible = isShow;
	SetConsoleCursorInfo(hOutStd, &cci);
}
void FullScreen() {
	HWND hwnd = GetForegroundWindow();
	int x = GetSystemMetrics(SM_CXSCREEN) + 300;
	int y = GetSystemMetrics(SM_CYSCREEN) + 300;
	char setting[30];
	sprintf(setting, "mode con:cols=%d lines=%d", x, y);
	system(setting);
}
int GetOper() {
	if (_kbhit()) {
		return getch();
	}
	return 0;
}