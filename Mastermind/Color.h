#ifndef COLOR_H
#define COLOR_H

#include <string>

class Color {
	private:
		std::string color = "";
		int position = 0;
	public:
		Color() {};
		~Color() {};
		enum COL { RED, GREEN, BLUE, YELLOW, BROWN, ORANGE, BLACK, WHITE };
		COL ballCol;
		void setColor(COL);
		void setPos(int);
		void showBall();
		int getPos();
		std::string getColor();
};
#endif
