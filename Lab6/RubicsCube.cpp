#include"RubicsCube.h"
#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>

RubicsCube::RubicsCube() {
	for (int x(0); x < 3; ++x) {
		for (int y(0); y < 3; ++y) {
			for (int z(0); z < 3; ++z) {
				if (x == 0) {
					cubes[x][y][z].left = RED;
				}
				if (x == 2) {
					cubes[x][y][z].right = ORANGE;
				}
				if (y == 0) {
					cubes[x][y][z].up = YELLOW;
				}
				if (y == 2) {
					cubes[x][y][z].down = WHITE;
				}
				if (z == 0) {
					cubes[x][y][z].front = GREEN;
				}
				if (z == 2) {
					cubes[x][y][z].back = BLUE;
				}
			}
		}
	}
}

void RubicsCube::F() {
	for (int i(0); i < 3; ++i) {
		for (int j(0); j < 3; ++j) {
			cubes[i][j][0].F();
		}
	}

	std::swap(cubes[1][0][0], cubes[0][1][0]);
	std::swap(cubes[0][1][0], cubes[1][2][0]);
	std::swap(cubes[1][2][0], cubes[2][1][0]);

	std::swap(cubes[0][0][0], cubes[0][2][0]);
	std::swap(cubes[0][2][0], cubes[2][2][0]);
	std::swap(cubes[2][2][0], cubes[2][0][0]);
}

void RubicsCube::L() {
	for (int i(0); i < 3; ++i) {
		for (int j(0); j < 3; ++j) {
			cubes[0][i][j].L();
		}
	}

	std::swap(cubes[0][0][1], cubes[0][1][2]);
	std::swap(cubes[0][1][2], cubes[0][2][1]);
	std::swap(cubes[0][2][1], cubes[0][1][0]);

	std::swap(cubes[0][0][0], cubes[0][0][2]);
	std::swap(cubes[0][0][2], cubes[0][2][2]);
	std::swap(cubes[0][2][2], cubes[0][2][0]);
}

void RubicsCube::B() {
	for (int i(0); i < 3; ++i) {
		for (int j(0); j < 3; ++j) {
			cubes[i][j][2].B();
		}
	}

	std::swap(cubes[1][0][2], cubes[2][1][2]);
	std::swap(cubes[2][1][2], cubes[1][2][2]);
	std::swap(cubes[1][2][2], cubes[0][1][2]);

	std::swap(cubes[0][0][2], cubes[2][0][2]);
	std::swap(cubes[2][0][2], cubes[2][2][2]);
	std::swap(cubes[2][2][2], cubes[0][2][2]);
}

void RubicsCube::R() {
	for (int i(0); i < 3; ++i) {
		for (int j(0); j < 3; ++j) {
			cubes[2][i][j].R();
		}
	}

	std::swap(cubes[2][0][1], cubes[2][1][0]);
	std::swap(cubes[2][1][0], cubes[2][2][1]);
	std::swap(cubes[2][2][1], cubes[2][1][2]);

	std::swap(cubes[2][0][0], cubes[2][2][0]);
	std::swap(cubes[2][2][0], cubes[2][2][2]);
	std::swap(cubes[2][2][2], cubes[2][0][2]);
}

void RubicsCube::D() {
	for (int i(0); i < 3; ++i) {
		for (int j(0); j < 3; ++j) {
			cubes[i][2][j].D();
		}
	}

	std::swap(cubes[1][2][0], cubes[0][2][1]);
	std::swap(cubes[0][2][1], cubes[1][2][2]);
	std::swap(cubes[1][2][2], cubes[2][2][1]);

	std::swap(cubes[0][2][0], cubes[0][2][2]);
	std::swap(cubes[0][2][2], cubes[2][2][2]);
	std::swap(cubes[2][2][2], cubes[2][2][0]);
}

void RubicsCube::U() {
	for (int i(0); i < 3; ++i) {
		for (int j(0); j < 3; ++j) {
			cubes[i][0][j].U();
		}
	}

	std::swap(cubes[1][0][0], cubes[2][0][1]);
	std::swap(cubes[2][0][1], cubes[1][0][2]);
	std::swap(cubes[1][0][2], cubes[0][0][1]);

	std::swap(cubes[0][0][0], cubes[2][0][0]);
	std::swap(cubes[2][0][0], cubes[2][0][2]);
	std::swap(cubes[2][0][2], cubes[0][0][2]);
}

void RubicsCube::X() {
	RubicsCube::R();
	
	for (int i(0); i < 3; ++i) {
		RubicsCube::L();
	}

	for (int i(0); i < 3; ++i) {
		for (int j(0); j < 3; ++j) {
			cubes[1][i][j].R();
		}
	}

	std::swap(cubes[1][0][0], cubes[1][2][0]);
	std::swap(cubes[1][2][0], cubes[1][2][2]);
	std::swap(cubes[1][2][2], cubes[1][0][2]);

	std::swap(cubes[1][1][0], cubes[1][2][1]);
	std::swap(cubes[1][2][1], cubes[1][1][2]);
	std::swap(cubes[1][1][2], cubes[1][0][1]);
}

void RubicsCube::Y() {
	RubicsCube::U();

	for (int i(0); i < 3; ++i) {
		RubicsCube::D();
	}

	for (int i(0); i < 3; ++i) {
		for (int j(0); j < 3; ++j) {
			cubes[i][1][j].U();
		}
	}

	std::swap(cubes[0][1][0], cubes[2][1][0]);
	std::swap(cubes[2][1][0], cubes[2][1][2]);
	std::swap(cubes[2][1][2], cubes[0][1][2]);
	
	std::swap(cubes[1][1][0], cubes[2][1][1]);
	std::swap(cubes[2][1][1], cubes[1][1][2]);
	std::swap(cubes[1][1][2], cubes[0][1][1]);
}

void RubicsCube::Z() {
	RubicsCube::F();

	for (int i(0); i < 3; ++i) {
		RubicsCube::B();
	}

	for (int i(0); i < 3; ++i) {
		for (int j(0); j < 3; ++j) {
			cubes[i][j][1].F();
		}
	}

	std::swap(cubes[0][0][1], cubes[0][2][1]);
	std::swap(cubes[0][2][1], cubes[2][2][1]);
	std::swap(cubes[2][2][1], cubes[2][0][1]);

	std::swap(cubes[1][0][1], cubes[0][1][1]);
	std::swap(cubes[0][1][1], cubes[1][2][1]);
	std::swap(cubes[1][2][1], cubes[2][1][1]);
}

void RubicsCube::Fr() {
	reverseTurn(&RubicsCube::F);
}

void RubicsCube::Lr() {
	reverseTurn(&RubicsCube::L);
}

void RubicsCube::Br() {
	reverseTurn(&RubicsCube::B);
}

void RubicsCube::Rr() {
	reverseTurn(&RubicsCube::R);
}

void RubicsCube::Dr() {
	reverseTurn(&RubicsCube::D);
}

void RubicsCube::Ur() {
	reverseTurn(&RubicsCube::U);
}

void RubicsCube::Xr() {
	reverseTurn(&RubicsCube::X);
}

void RubicsCube::Yr() {
	reverseTurn(&RubicsCube::Y);
}

void RubicsCube::Zr() {
	reverseTurn(&RubicsCube::Z);
}

bool RubicsCube::isSolved() const {
	for (int x(0); x < 3; ++x) {
		for (int y(0); y < 3; ++y) {
			for (int z(0); z < 3; ++z) {
				if (x == 0) {
					if (cubes[x][y][z].getLeft() != getLeftColor()) {
						return false;
					}
				}
				if (x == 2) {
					if (cubes[x][y][z].getRight() != getRightColor()) {
						return false;
					}
				}
				if (y == 0) {
					if (cubes[x][y][z].getUp() != getUpColor()) {
						return false;
					}
				}
				if (y == 2) {
					if (cubes[x][y][z].getDown() != getDownColor()) {
						return false;
					}
				}
				if (z == 0) {
					if (cubes[x][y][z].getFront() != getFrontColor()) {
						return false;
					}
				}
				if (z == 2) {
					if (cubes[x][y][z].getBack() != getBackColor()) {
						return false;
					}
				}
			}
		}
	}
	return true;
}

const SmallCube& RubicsCube::getCube(short x, short y, short z) const {
	return cubes[x][y][z];
}

const Color& RubicsCube::getFrontColor() const {
	return cubes[1][1][0].front;
}

const Color& RubicsCube::getLeftColor() const {
	return cubes[0][1][1].left;
}

const Color& RubicsCube::getBackColor() const {
	return cubes[1][1][2].back;
}

const Color& RubicsCube::getRightColor() const {
	return cubes[2][1][1].right;
}

const Color& RubicsCube::getDownColor() const {
	return cubes[1][2][1].down;
}

const Color& RubicsCube::getUpColor() const {
	return cubes[1][0][1].up;
}

const Color& RubicsCube::getSideColor(int sideNumb) {
	//0-front, 1-left, 2-back, 3-right, 4-down, 5-up
	switch (sideNumb) {
	case 0:
		return getFrontColor();
	case 1:
		return getLeftColor();
	case 2:
		return getBackColor();
	case 3:
		return getRightColor();
	case 4:
		return getDownColor();
	case 5:
		return getUpColor();
	default:
		throw "Something went wrong (RubicsCube::getSideColor(int))";
	}
}

void RubicsCube::loadConfig(const std::string& fileName) {
	std::ifstream fin(fileName);
	char side;
	for (int j(0); j < 6; ++j) {
		fin >> side;
		for (int i(0); i < 9; ++i) {
			char color;
			fin >> color;
			switch (side) {
			case 'F':
				cubes[i % 3][i / 3][0].front = findColorByLetter(color);
				break;
			case 'L':
				cubes[0][i / 3][2 - i % 3].left = findColorByLetter(color);
				break;
			case 'B':
				cubes[2 - i % 3][i / 3][2].back = findColorByLetter(color);
				break;
			case 'R':
				cubes[2][i / 3][i % 3].right = findColorByLetter(color);
				break;
			case 'D':
				cubes[i % 3][2][i / 3].down = findColorByLetter(color);
				break;
			case 'U':
				cubes[i % 3][0][2 - i / 3].up = findColorByLetter(color);
				break;
			default:
				throw "Something went wrong (RubicsCube::loadConfig)";
			}
		}
	}
}

void RubicsCube::saveConfig(const std::string& fileName) const {
	std::ofstream fout(fileName);
	saveConfig(fout);
}

void RubicsCube::logConfig() const {
	saveConfig(std::cout);
}

void RubicsCube::saveConfig(std::ostream& cout) const {
	std::vector<char> sides = { 'F', 'L', 'B', 'R', 'D', 'U' };
	for (int j(0); j < 6; ++j) {
		cout << "\'" << sides[j] << "\'" << '\n';
		for (int i(0); i < 9; ++i) {
			switch (sides[j]) {
			case 'F':
				cout << findLetterByColor(cubes[i % 3][i / 3][0].front);
				break;
			case 'L':
				cout << findLetterByColor(cubes[0][i / 3][2 - i % 3].left);
				break;
			case 'B':
				cout << findLetterByColor(cubes[2 - i % 3][i / 3][2].back);
				break;
			case 'R':
				cout << findLetterByColor(cubes[2][i / 3][i % 3].right);
				break;
			case 'D':
				cout << findLetterByColor(cubes[i % 3][2][i / 3].down);
				break;
			case 'U':
				cout << findLetterByColor(cubes[i % 3][0][2 - i / 3].up);
				break;
			default:
				throw "Something went wrong (RubicsCube::saveConfig)";
			}
			if (i % 3 == 2) {
				cout << '\n';
			} else {
				cout << ' ';
			}
		}
	}
}

void RubicsCube::reverseTurn(void (RubicsCube::* turn)()) {
	for (int i(0); i < 3; ++i) {
		(this->*turn)();
	}
}