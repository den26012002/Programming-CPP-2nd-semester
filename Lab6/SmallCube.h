#pragma once
#include"color.h"

class SmallCube {
public:
	SmallCube();
	SmallCube(const SmallCube&);

	void F();
	void L();
	void B();
	void R();
	void D();
	void U();

	const Color& getFront() const;
	const Color& getLeft() const;
	const Color& getBack() const;
	const Color& getRight() const;
	const Color& getDown() const;
	const Color& getUp() const;
	const Color& getSide(int sideNumb) const;

	bool hasColor(const Color&) const;

	SmallCube& operator=(const SmallCube&);
private:
	Color sides[6]; //0-front, 1-left, 2-back, 3-right, 4-down, 5-up
	Color& front;
	Color& left;
	Color& back;
	Color& right;
	Color& down;
	Color& up;

	friend class RubicsCube;
};

