#include "EasyGenerator.h"

void EasyGenerator::generate(int** arr, int ** colors, int size) {
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			if (arr[i][j] == 0) {
				colors[i][j] = 9;
				arr[i][j] = 2;
				return;
			}
		}
	}
}
