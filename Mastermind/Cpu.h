#ifndef CPU_H
#define CPU_H

#include "Color.h"
#include <deque>
#include <random>
#include <algorithm>

class Cpu {
private:
	std::deque <Color> *ranSeq = new std::deque <Color>;
	std::vector <int> *ranNum = new std::vector <int>;
	bool isUnique = 0;
public:
	Cpu(int n) {
		genSeq(n);
	}
	~Cpu() {
		delete ranSeq;
		delete ranNum;
		ranSeq = nullptr;
		ranNum = nullptr;
	}
	void genSeq(int);
	void showGuess();
	std::string showCol(int);
	int showPos(int);
	void setUnique();
	void flushVect();
};

#endif