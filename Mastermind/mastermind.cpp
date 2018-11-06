/*
 * File:   mastermind.cpp
 */

#include <cstdlib>
#include <iostream>

#include "Gameplay.h"

int main() {

	std::cout << "8   8  8" << std::endl;
	std::cout << "8   8  8 eeee e     eeee eeeee eeeeeee eeee   eeeee eeeee" << std::endl;
	std::cout << "8e  8  8 8    8     8  8 8  88 8  8  8 8        8   8  88" << std::endl;
	std::cout << "88  8  8 8eee 8e    8e   8   8 8e 8  8 8eee     8e  8   8" << std::endl;
	std::cout << "88  8  8 88   88    88   8   8 88 8  8 88       88  8   8" << std::endl;
	std::cout << "88ee8ee8 88ee 88eee 88e8 8eee8 88 8  8 88ee     88  8eee8" << std::endl;

	std::cout << "\n8ee8ee8                                                      88" << std::endl;
	std::cout << "8  8  8 eeeee eeeee eeeee eeee eeeee  eeeeeee e  eeeee eeeee 88" << std::endl;
	std::cout << "8e 8  8 8   8 8   #   8   8    8   8  8  8  8 8  8   8 8   8 88" << std::endl;
	std::cout << "88 8  8 8eee8 8eeee   8e  8eee 8eee8e 8e 8  8 8e 8e  8 8e  8 88" << std::endl;
	std::cout << "88 8  8 88  8    88   88  88   88   8 88 8  8 88 88  8 88  8" << std::endl;
	std::cout << "88 8  8 88  8 8ee88   88  88ee 88   8 88 8  8 88 88  8 88ee8 88" << std::endl;

	Gameplay relGame;

    return 0;
}