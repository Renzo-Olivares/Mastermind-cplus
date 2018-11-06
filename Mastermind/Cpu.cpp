#include "Cpu.h"

void Cpu::genSeq(int sz)
{
	std::random_device rd;
	std::mt19937 mt(rd());    // The random number generator using a non-deterministic random device
	std::uniform_int_distribution<int> dist(0, 7);    // The distribution that gives us random numbers in [0,99]

	for (int i = 0; i < sz; i++) {
		Color* ptr = nullptr;
		ptr = new Color();
		ptr->setColor(static_cast<Color::COL>(dist(mt)));
		ptr->setPos(i);
		ranSeq->push_back(*ptr);
	}
}

void Cpu::showGuess()
{
	std::deque <Color> ::iterator it;
	for (it = ranSeq->begin(); it != ranSeq->end(); ++it) {
		it->showBall();
	}
}

std::string Cpu::showCol(int n)
{
	return ranSeq->at(n).getColor();
}

int Cpu::showPos(int n)
{
	return ranSeq->at(n).getPos();
}