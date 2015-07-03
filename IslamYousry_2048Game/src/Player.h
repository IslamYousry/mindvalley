#ifndef PLAYER_H_
#define PLAYER_H_
#include <string>
using namespace std;
class Player {
	string name;
	int currentScore;
	int maxScore;
public:
	Player();
	Player(string n);
	void setPlayerName(string n);
	string getPlayerName();
	void setPlayerScore(int s);
	int getPlayerScore();
	//	void save();  // to be implemented in version 2
	//	void retrieve();  to be implemented in version 2
};

#endif /* PLAYER_H_ */
