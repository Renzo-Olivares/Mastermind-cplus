#ifndef CPU_H
#define CPU_H

#include "Color.h"
#include <deque>
#include <random>
#include <cstdlib>
#include <ctime>

class Cpu {
private:
	std::deque <Color> *ranSeq = new std::deque <Color>;
	//bool isUnique = 0;
public:
	Cpu(int n) {
		genSeq(n);
		srand(static_cast<unsigned int>(time(0)));
	}
	~Cpu() {
		delete ranSeq;
		ranSeq = nullptr;
	}
	void genSeq(int);
	void showGuess();
	std::string showCol(int);
	int showPos(int);
	//void setUnique();
	//bool getisUnique();
};

#endif