#include "Color.h"
#include <iostream>

void Color::setPos(int n)
{
	position = n;
}

void Color::setColor(COL ranColor)
{
	switch (ranColor) {
	case RED:
		color = "Red";
		break;
	case GREEN:
		color = "Green";
		break;
	case BLUE:
		color = "Blue";
		break;
	case YELLOW:
		color = "Yellow";
		break;
	case BROWN:
		color = "Brown";
		break;
	case ORANGE:
		color = "Orange";
		break;
	case BLACK:
		color = "Black";
		break;
	case WHITE:
		color = "White";
		break;
	}
}

std::string Color::getColor()
{
	return color;
}

void Color::showBall()
{
	std::cout << "Guess for position " << position << ": " << color << std::endl;
}

int Color::getPos()
{
	return position;
}