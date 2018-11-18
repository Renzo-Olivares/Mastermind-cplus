/*
 * File:   Gameplay.cpp
 */
#include <iostream>
#include "Gameplay.h"

int Gameplay::init()
{
	//set the difficulty
	setDiff();

	//create cpu object and generate random sequence
	Cpu* relCpu = new Cpu(diff);

	//fill vector with colors from cpu generated random sequence
	for (int i = 0; i < diff; i++) {
		colors.push_back(relCpu->showCol(i));
	}

	std::deque <Color> ::iterator it;

	//ten tries
    for (int i = 0; i < TRIES; i++){
        //10 loops for 10 attempts

		//round i user guesses
		std::cout << std::endl;
		std::cout << "\nAttempt " << i + 1 << " :" << std::endl;
		userAttempt();

		//round i show user full guess
		std::cout << "\nShowing your full guess for attempt " << i + 1 << " :" << std::endl;
		for (it = guess->begin(); it != guess->end(); ++it) {
			it->showBall();
		}

		//does user want to submit this guess to check or fix answer
		std::cout << "\nWould you like to submit your guess or fix it? (0 - submit, 1 - fix): ";
		std::cin >> choice;
		if (choice) {
			std::cout << "\nAttempt " << i + 1 << " :" << std::endl;
			flush();
			userAttempt();
		}
		else {
			int count = 0;
			std::cout << "\nHints: " << std::endl;
			for (it = guess->begin(); it != guess->end(); ++it) {
				gPos = it->getPos() - 1;
				gCol = it->getColor();
				hint(gPos, count, gCol);
				count++;
			}
		}
		check();
		flushVec();
		flush();
		if (isWin) {
				std::cout << "\nYou Win" << std::endl;
				return 0;
		}
    }

	if (!isWin) {
			std::cout << "\nYou Lose" << std::endl;
			return 0;
	}
}

void Gameplay::setDiff()
{
	std::cout << "\nWhat difficulty would you like to play on?" << std::endl;
	std::cout << "Easy 4-Code Length (1)" << std::endl;
	std::cout << "Medium 6-Code Length (2)" << std::endl;
	std::cout << "Hard 8-Code Length (3)" << std::endl;
	std::cout << "Enter your choice: ";
	std::cin >> diff;

	diff -= 1;

	diffSet = static_cast<Gameplay::DIFFI>(diff);

	switch (diffSet) {
	case EASY:
		diff = 4;
		break;
	case MEDIUM:
		diff = 6;
		break;
	case HARD:
		diff = 8;
		break;
	}
}

void Gameplay::setnGuess(std::string guess)
{
	if (guess == "Red" | guess == "red") {
		nGuess = 0;
	}
	else if (guess == "Green" | guess == "green") {
		nGuess = 1;
	}
	else if (guess == "Blue" | guess == "blue") {
		nGuess = 2;
	}
	else if (guess == "Yellow" | guess == "yellow") {
		nGuess = 3;
	}
	else if (guess == "Brown" | guess == "brown") {
		nGuess = 4;
	}
	else if (guess == "Orange" | guess == "orange") {
		nGuess = 5;
	}
	else if (guess == "Black" | guess == "black") {
		nGuess = 6;
	}
	else if (guess == "White" | guess == "white") {
		nGuess = 7;
	}
}

int Gameplay::getDiff()
{
	return diff;
}

void Gameplay::rules()
{
	std::cout << "\nRules of the game: " << std::endl;
	std::cout << "The computer will select a random sequence based on the difficulty you select" << std::endl;
	std::cout << "The sequence is a unique combination of any of these colors: red, blue, green, yellow, brown, white, black, orange" << std::endl;
	std::cout << "The aim of the game is to correctly guess the sequence that the computer has generated within ten tries" << std::endl;
	std::cout << "You will be given hints after every attempt" << std::endl;
	std::cout << "You will be told if your guess is the right color & right position OR right color & wrong position" << std::endl;
	std::cout << "You win the game you guess the correct code sequence" << std::endl;
	std::cout << "You lose the game if you cannot guess the correct sequence within ten attempts" << std::endl;
}

void Gameplay::userAttempt()
{
	for (int k = 0; k < diff; k++) {
		//what is your "k" guess
		std::cout << "Enter guess for position " << k + 1 << ": ";
		std::cin >> sGuess;
		setnGuess(sGuess);
		Color* ptr = nullptr;
		ptr = new Color();
		ptr->setColor(static_cast<Color::COL>(nGuess));
		ptr->setPos((k + 1));
		guess->push_back(*ptr);
	}
}

void Gameplay::hint(int guessPos, int count, std::string guessCol)
{
	std::cout << "\nHint for guess " << count + 1 << " : ";
		if (colorExists(guessCol, guessPos))
			std::cout << "Right color";
}

bool Gameplay::colorExists(std::string guessColor, int guessPos)
{
	for (int i = 0; i < diff; i++) {
		if (guessColor == colors[i]) {
			if (guessPos == i) {
				std::cout << "Correct Position, ";
			}
			else
				std::cout << "Wrong Position, ";
			testbool = 1;
			break;
		}
		else {
			testbool = 0;
		}
	}
	return testbool;
}

void Gameplay::flush()
{
	while (!(guess->empty())) {
		guess->pop_back();
	}
}

void Gameplay::flushVec()
{
	while (!(pGuess.empty())) {
		pGuess.pop_back();
	}
}

bool Gameplay::check()
{
	//fill vector with player guess
	for (int i = 0; i < diff; i++) {
		pGuess.push_back(guess->at(i).getColor());
	}

	if (pGuess == colors) {
		isWin = 1;
	}

	return isWin;
}