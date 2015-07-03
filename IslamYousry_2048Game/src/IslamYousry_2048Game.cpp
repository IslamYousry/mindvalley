#include <iostream>
#include <windows.h>
#include <iomanip>
#include<conio.h>
#include<dos.h>
#include<time.h>
#include "GameEngine.h"
using namespace std;

int main() {

	int win = 0, level;
	string pName;
	cout << "Enter Your Name: ";
	cin >> pName;
	do {
		cout << "Choose Your level\n1-Easy\n2-Med\n3-Hard ";
		cin >> level;
	} while (level != 1 && level != 2 && level != 3);
	system("CLS");
	GameEngine g(4, level, pName);
	g.print();
	int c = 0;
	while (1) {
		g.setTextColor(15);
		c = 0;
		switch ((c = getch())) {
		case KEY_UP:
			win = g.swipeUp();
			break;
		case KEY_DOWN:
			win = g.swipeDown();
			break;
		case KEY_LEFT:
			win = g.swipeLeft();
			break;
		case KEY_RIGHT:
			win = g.swipeRight();
			break;
		default:
			//cout << endl << "null" << endl;  // key left
			break;
		}
		system("CLS");
		g.print();
		if (win) {
			cout << "you Win";
			break;
		} else if (g.gameover()) {
			cout << "Game Over\n";
			break;
		}

	}

	system("pause");
	return 0;
}
