#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
using namespace std;

void OutputPos(int nx, int ny);
void KeyEventProc(KEY_EVENT_RECORD ker);
void MouseEventProc(MOUSE_EVENT_RECORD mer);
int MessageLoop();
void WriteChar(int x, int y, const char szStr, int color = 0);
int main() {
	MessageLoop();
	getchar();
	return 0;
}

void WriteChar(int x, int y, const char szStr[], int color = 0)
{

	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { x * 2, y };
	SetConsoleCursorPosition(hOut, pos);
	puts(szStr);
}

void OutputPos(int nX, int nY) {
	char szBuf[100] = { 0 };
	sprintf(szBuf,  "x=%2d,y=%2d ", nX / 2, nY);
	SetConsoleTitleA(szBuf);
	WriteChar(0, 0, szBuf, 0x50);
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
	switch (mer.dwEventFlags)
	{
	case 0:
		if (mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) {
			WriteChar(0, 0, "×ó¼üµ¥»÷", 0x50);
		}
		else if (mer.dwButtonState == RIGHTMOST_BUTTON_PRESSED) {
			WriteChar(0, 0, "ÓÒ¼üµ¥»÷", 0x50);
		}break;
	case DOUBLE_CLICK:
		WriteChar(0, 0, "Ë«»÷", 0x50);
		break;
	case MOUSE_MOVED:
		OutputPos(mer.dwMousePosition.X, mer.dwMousePosition.Y);
		break;
	default:
		break;
	}
}

int MessageLoop() {
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	INPUT_RECORD stcRecode = { 0 };
	DWORD dwRead;
	SetConsoleMode(hStdin, ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
	while (1) {
		ReadConsoleInput(hStdin, &stcRecode, 1, &dwRead);
		if (stcRecode.EventType == KEY_EVENT) {
			KeyEventProc(stcRecode.Event.KeyEvent);
		}
		else if(stcRecode.EventType == MOUSE_EVENT){
			MouseEventProc(stcRecode.Event.MouseEvent);
		}
	}
}