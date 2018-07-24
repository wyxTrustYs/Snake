#include "map.h"
#include <windows.h>
#include "Print.h"

void OutputPos(int nX, int nY,int flat) {
	if (flat == 1) {
		map[nY][nX/2] = 1;
	}
	else if(flat == 0)
	{
		map[nY][nX/2] = 0;
	}
}
void MouseEventProc(MOUSE_EVENT_RECORD mer) {

	if (mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) {
		if (mer.dwEventFlags == MOUSE_MOVED) {
			OutputPos(mer.dwMousePosition.X, mer.dwMousePosition.Y,1);
			WriteChar(mer.dwMousePosition.X/2, mer.dwMousePosition.Y,"¨€");
		}
	}else if (mer.dwButtonState == RIGHTMOST_BUTTON_PRESSED) {
		if (mer.dwEventFlags == MOUSE_MOVED) {
			OutputPos(mer.dwMousePosition.X, mer.dwMousePosition.Y,0);
			WriteChar(mer.dwMousePosition.X / 2, mer.dwMousePosition.Y, " ");
		}
	}

}