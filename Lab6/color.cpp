#include"color.h"

bool operator==(const Color& color1, const Color& color2) {
	return ((color1.r == color2.r) && (color1.g == color2.g) && (color1.b == color2.b));
}

bool operator!=(const Color& color1, const Color& color2) {
	return !(color1 == color2);
}

Color findColorByLetter(char letter) {
	switch (letter) {
	case '0':
		return BLACK;
	case 'R':
		return RED;
	case 'G':
		return GREEN;
	case 'B':
		return BLUE;
	case 'Y':
		return YELLOW;
	case 'O':
		return ORANGE;
	case 'W':
		return WHITE;
	default:
		//throw "Something went wrong (findColorByNumb): " + letter;
		throw letter;
	}
}

char findLetterByColor(const Color& color) {
	if (color == BLACK) {
		return '0';
	} else if (color == RED) {
		return 'R';
	} else if (color == GREEN) {
		return 'G';
	} else if (color == BLUE) {
		return 'B';
	} else if (color == YELLOW) {
		return 'Y';
	} else if (color == ORANGE) {
		return 'O';
	} else if (color == WHITE) {
		return 'W';
	} else {
		throw "Something went wrong (findNumbByColor)";
	}
}