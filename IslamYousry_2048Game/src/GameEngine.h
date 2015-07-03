#ifndef GAMEENGINE_H_
#define GAMEENGINE_H_
#include <iostream>
#include <windows.h>
#include <iomanip>
#include<conio.h>
#include<dos.h>
#include<time.h>
#include "RandomGenerator.h"
#include "EasyGenerator.h"
#include "Player.h"
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
using namespace std;
class GameEngine {
	int size;
	int ** arr;
	int ** colors;
	int score;
	RandomGenerator* generator;
	Player currentPlayer;
public:
	GameEngine(int s = 4, int level = 1, string playerName = "Player");
	void generateTwo();
	void print();
	bool swipeUp();
	bool swipeDown();
	bool swipeLeft();
	bool swipeRight();
	bool gameover();
	void setTextColor(int x);
	virtual ~GameEngine();
};

#endif /* GAMEENGINE_H_ */
