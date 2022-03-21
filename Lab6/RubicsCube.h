#pragma once
#include"SmallCube.h"
#include<string>

class RubicsCube {
public:
	RubicsCube();

	void F();
	void L();
	void B();
	void R();
	void D();
	void U();
	void X();
	void Y();
	void Z();

	//reversed (with prime)
	void Fr();
	void Lr();
	void Br();
	void Rr();
	void Dr();
	void Ur();
	void Xr();
	void Yr();
	void Zr();

	bool isSolved() const;
	bool isUnsolvable() const;

	const SmallCube& getCube(short x, short y, short z) const;

	const Color& getFrontColor() const;
	const Color& getLeftColor() const;
	const Color& getBackColor() const;
	const Color& getRightColor() const;
	const Color& getDownColor() const;
	const Color& getUpColor() const;
	const Color& getSideColor(int sideNumb);

	void loadConfig(const std::string& fileName);
	void saveConfig(const std::string& fileName) const;
	void logConfig() const;

	RubicsCube& operator=(const RubicsCube&);
private:
	SmallCube cubes[3][3][3]; //1 - x coordinate, 2 - y, 3 - z (from left-upper corner of the screen)
	bool solvable;

	void saveConfig(std::ostream&) const;

	void reverseTurn(void(RubicsCube::*)());
};

