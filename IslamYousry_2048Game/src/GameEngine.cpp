#include "GameEngine.h"

GameEngine::GameEngine(int s, int level, string playerName) {
	currentPlayer.setPlayerName(playerName);
	score = 0;
	size = s;
	arr = new int*[size];
	colors = new int*[size];
	for (int i = 0; i < size; ++i) {
		arr[i] = new int[size];
		colors[i] = new int[size];
		for (int j = 0; j < size; ++j) {
			colors[i][j] = 15;
			arr[i][j] = 0;
		}
	}
	if (level == 1)
		generator = new EasyGenerator;
	else if (level == 2) {
		cout << "Will be done in version 2, Now we will select Easy mode";
		generator = new EasyGenerator;
	} else if (level == 3) {
		cout << "Will be done in version 3, Now we will select Easy mode";
		generator = new EasyGenerator;
	}
	generateTwo();
}

void GameEngine::generateTwo() {
	generator->generate(arr, colors, size);
}

void GameEngine::print() {
	cout << currentPlayer.getPlayerName()<< ", Use arrows to swipe and reach 2048 ...\n\n";
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			setTextColor(colors[i][j]);
			if (arr[i][j] == 0)
				cout << "[ " << setw(4) << " " << " ]";
			else {
				cout << "[ " << setw(4) << arr[i][j] << " ]";
			}
		}
		cout << endl;
	}
	setTextColor(15);
	cout << "\nScore = " << score << endl;
}

void GameEngine::setTextColor(int x) {
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	FlushConsoleInputBuffer(hConsole);
	SetConsoleTextAttribute(hConsole, x);
}

bool GameEngine::swipeDown() {
	int Win = 0;
	for (int j = 0; j < size; j++) {
		int stop = size - 1;
		colors[0][j] = 15;
		for (int i = size - 1; i >= 1; --i) {
			colors[i][j] = 15;
			for (int k = i; k <= stop; ++k) {

				if (arr[k][j] == arr[k - 1][j] && arr[k][j] != 0) {
					arr[k][j] += arr[k - 1][j];
					if (arr[k][j] == 2048)
						Win = 1;
					score += arr[k][j];
					arr[k - 1][j] = 0;
					colors[k][j] = 10; // New Green
					stop = k - 1;
					break;
				}
				if (arr[k][j] == 0) {
					arr[k][j] = arr[k - 1][j];
					arr[k - 1][j] = 0;
				}
			}
		}
	}
	if (Win == 1)
		return 1;
	generateTwo();
	return 0;
}
bool GameEngine::swipeUp() {
	int Win = 0;
	for (int j = 0; j < size; j++) {
		int stop = 1;
		colors[0][j] = 15;
		for (int i = 1; i <= size - 1; ++i) {
			colors[i][j] = 15;
			for (int k = i; k >= stop; --k) {

				if (arr[k - 1][j] == arr[k][j] && arr[k][j] != 0) {
					arr[k - 1][j] += arr[k][j];
					if (arr[k - 1][j] == 2048)
						Win = 1;
					score += arr[k - 1][j];
					arr[k][j] = 0;
					colors[k - 1][j] = 10; // New Green
					stop = k + 1;
					break;
				}
				if (arr[k - 1][j] == 0) {
					arr[k - 1][j] = arr[k][j];
					arr[k][j] = 0;
				}
			}
		}
	}
	if (Win == 1)
		return 1;
	generateTwo();
	return 0;
}
bool GameEngine::swipeRight() {
	int Win = 0;
	for (int i = 0; i < size; i++) {
		int stop = size - 1;
		colors[i][0] = 15;
		for (int j = size - 1; j >= 1; --j) {
			colors[i][j] = 15;
			for (int k = j; k <= stop; ++k) {
				if (arr[i][k] == arr[i][k - 1] && arr[i][k] != 0) {
					arr[i][k] += arr[i][k - 1];
					if (arr[i][k] == 2048)
						Win = 1;
					score += arr[i][k];
					arr[i][k - 1] = 0;
					colors[i][k] = 10; // New Green
					stop = k - 1;
					break;
				}
				if (arr[i][k] == 0) {
					arr[i][k] = arr[i][k - 1];
					arr[i][k - 1] = 0;
				}
			}
		}
	}
	if (Win == 1)
		return 1;
	generateTwo();
	return 0;
}
bool GameEngine::swipeLeft() { // move,calculate then generate new 2 in
	int Win = 0;
	for (int i = 0; i < size; i++) {
		int stop = 1;
		colors[i][0] = 15;
		for (int j = 1; j < size; ++j) {
			colors[i][j] = 15;
			for (int k = j; k >= stop; --k) {
				if (arr[i][k - 1] == arr[i][k] && arr[i][k] != 0) {
					arr[i][k - 1] += arr[i][k];
					if (arr[i][k - 1] == 2048)
						Win = 1;
					score += arr[i][k - 1];
					arr[i][k] = 0;
					colors[i][k - 1] = 10; // new Green
					stop = k + 1;
					break;
				}
				if (arr[i][k - 1] == 0) {
					arr[i][k - 1] = arr[i][k];
					arr[i][k] = 0;
				}
			}
		}
	}
	if (Win == 1)
		return 1;
	generateTwo();
	return 0;
}

bool GameEngine::gameover() {
	int check[4][2] = { { -1, 0 }, { 0, -1 }, { 0, 1 }, { 1, 0 } };
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			for (int k = 0; k < 4; ++k) {
				if (i + check[k][0] >= 0 && i + check[k][0] < size && j
						+ check[k][1] >= 0 && j + check[k][1] < size) {
					if (arr[i][j] == arr[i + check[k][0]][j + check[k][1]])
						return false;
				}

			}
		}
	}
	return true;
}
GameEngine::~GameEngine() {
	currentPlayer.setPlayerScore(score);
	//	currentPlayer.save(); // to implemented in version 2
	for (int i = 0; i < size; ++i) {
		delete[] arr[i];
	}
	delete[] arr;
}

