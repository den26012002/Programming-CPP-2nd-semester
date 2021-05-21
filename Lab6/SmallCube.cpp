#include"SmallCube.h"
#include<algorithm>

SmallCube::SmallCube() :
	front(sides[0]),
	left(sides[1]),
	back(sides[2]),
	right(sides[3]),
	down(sides[4]),
	up(sides[5])
{
	for (int i(0); i < 6; ++i) {
		float value = (float)i;
		sides[i] = BLACK;
	}
}

SmallCube::SmallCube(const SmallCube& other) : 
	SmallCube::SmallCube()
{
	for (int i(0); i < 6; ++i) {
		sides[i] = other.sides[i];
	}
}

void SmallCube::F() {
	std::swap(up, left);
	std::swap(left, down);
	std::swap(down, right);
}

void SmallCube::L() {
	std::swap(up, back);
	std::swap(back, down);
	std::swap(down, front);
}

void SmallCube::B() {
	for (int i(0); i < 3; ++i) {
		SmallCube::F();
	}
}

void SmallCube::R() {
	for (int i(0); i < 3; ++i) {
		SmallCube::L();
	}
}

void SmallCube::D() {
	std::swap(front, left);
	std::swap(left, back);
	std::swap(back, right);
}

void SmallCube::U() {
	for (int i(0); i < 3; ++i) {
		SmallCube::D();
	}
}

const Color& SmallCube::getFront() const {
	return front;
}

const Color& SmallCube::getLeft() const {
	return left;
}

const Color& SmallCube::getBack() const {
	return back;
}

const Color& SmallCube::getRight() const {
	return right;
}

const Color& SmallCube::getDown() const {
	return down;
}

const Color& SmallCube::getUp() const {
	return up;
}

const Color& SmallCube::getSide(int sideNumb) const {
	return sides[sideNumb];
}

bool SmallCube::hasColor(const Color& color) const {
	for (int i(0); i < 6; ++i) {
		if (sides[i] == color) {
			return true;
		}
	}
	return false;
}

SmallCube& SmallCube::operator=(const SmallCube& other) {
	for (int i(0); i < 6; ++i) {
		sides[i] = other.sides[i];
	}
	return *this;
}