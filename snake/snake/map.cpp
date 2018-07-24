#include "map.h"
#include "Print.h"
#include <iostream>
int map[30][65];
using namespace std;
void InitMap() {
	for (int m = 0; m < 31; m++) {
		for (int n = 0; n < 66; n++) {
			if (m == 0 || n == 0 || m == 30 || n == 65) {
				map[m][n] = 1;
				WriteChar(n, m, '*');
			}
			else map[m][n] = 0;
		}
	}
	WriteChar(0, 32, "play:");
	WriteChar(30, 32, "score:");
}
void MapToFile(char name[]) {
	FILE *file = NULL;
	if ((file = fopen(name, "w")) == NULL) {
		cout << "open map fail" << endl;
		exit(0);
	}
	fwrite(map, sizeof(map), 1, file);

	fclose(file);

}

void FileToMap(char name[]) {
	FILE *file = NULL;
	if ((file = fopen(name, "r")) == NULL) {
		cout << "open map file fail" << endl;
		exit(0);
	}
	fread(map, sizeof(map), 1, file);
	fclose(file);
}
