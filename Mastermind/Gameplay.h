#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include <string>
#include <deque>
#include "Color.h"
#include "Cpu.h"

class Gameplay
{
    private:
    const int TRIES = 10;
	int diff = 0;
	int choice = 0;
	std::string sGuess = "";
	int nGuess = 0;
	int gPos = 0;
	int rPos = 0;
	bool testbool = 0;
	bool isWin = 0;
	int select = 0;
	std::string gCol = "";
	std::string rCol = "";
	//bool dupe = 0;
	enum DIFFI { EASY, MEDIUM, HARD };
	DIFFI diffSet;
	std::deque <Color> *guess = new std::deque <Color>;
	std::vector <std::string> colors;
	std::vector <std::string> pGuess;
    public:
    Gameplay(){
		rules();
        init();
    }
    ~Gameplay(){
		delete guess;
		guess = nullptr;
    }
    int init();
	void setDiff();
	//void setDupe();
	int getDiff();
	//bool getDupe();
	void rules();
	void setnGuess(std::string);
	void userAttempt();
	void hint(int, int, std::string);
	bool colorExists(std::string, int);
	void flush();
	void flushVec();
	bool check();
};

#endif