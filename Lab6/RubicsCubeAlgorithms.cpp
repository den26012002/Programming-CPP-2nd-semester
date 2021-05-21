#include"RubicsCubeAlgorithms.h"
#include<vector>
#include<time.h>
#include<conio.h>

std::string randomShuffle(RubicsCube& cube) {
	std::string shuffleSequence = "";
	//srand(time(NULL));
	for (int i(0); i < rand() % 1000 + 100; ++i) {
		switch (rand() % 6) {
		case 0:
			cube.F();
			shuffleSequence += 'F';
			break;
		case 1:
			cube.L();
			shuffleSequence += 'L';
			break;
		case 2:
			cube.B();
			shuffleSequence += 'B';
			break;
		case 3:
			cube.R();
			shuffleSequence += 'R';
			break;
		case 4:
			cube.D();
			shuffleSequence += 'D';
			break;
		case 5:
			cube.U();
			shuffleSequence += 'U';
			break;
		default:
			break;
		}
	}
	return shuffleSequence;
}

std::string rTrigger(RubicsCube& cube) {
	cube.R();
	cube.U();
	cube.Rr();
	cube.Ur();
	return "RUR'U'";
}

std::string rTriggerWithFront(RubicsCube& cube) {
	std::string moveSequence = "";
	cube.F();
	moveSequence += 'F';
	moveSequence += rTrigger(cube);
	cube.Fr();
	moveSequence += "F\'";
	return moveSequence;
}

std::string lTrigger(RubicsCube& cube) {
	cube.Lr();
	cube.Ur();
	cube.L();
	cube.U();
	return "L'U'LU";
}

std::string moveUpFrontToLeft(RubicsCube& cube) {
	std::string moveSequence = "";
	cube.Ur();
	moveSequence += "U\'";
	moveSequence += lTrigger(cube);
	cube.Yr();
	moveSequence += "Y\'";
	moveSequence += rTrigger(cube);
	return moveSequence;
}

std::string moveUpFrontToRight(RubicsCube& cube) {
	std::string moveSequence = "";
	cube.U();
	moveSequence += 'U';
	moveSequence += rTrigger(cube);
	cube.Y();
	moveSequence += 'Y';
	moveSequence += lTrigger(cube);
	return moveSequence;
}

std::string removeUpColor(RubicsCube& cube, short x, short z, const Color& color) {
	std::string moveSequence = "";
	while (cube.getCube(x, 0, z).getUp() == color) {
		cube.U();
		moveSequence += 'U';
	}
	return moveSequence;
}

std::string swapUpSides(RubicsCube& cube) {
	cube.R();
	cube.U();
	cube.Rr();
	cube.U();
	cube.R();
	cube.U();
	cube.U();
	cube.Rr();
	return "RUR\'URUUR\'";
}

std::string swapUpAngles(RubicsCube& cube) {
	cube.R();
	cube.Ur();
	cube.Lr();
	cube.U();
	cube.Rr();
	cube.Ur();
	cube.L();
	cube.U();
	return "RU\'L\'UR\'U\'LU";
}

std::string beginnerLevelSolveAlgorithm(RubicsCube& cube) {
	std::string solveSequence = "";
	const Color& downColor = cube.getDownColor();
	//flower
	{
		for (int i(0); i < 3; ++i) {
			std::vector<std::pair<short, short>> coordXZ = { {0, 0}, {0, 2}, {2, 2}, {2, 0} };
			for (int i(0); i < 8; ++i) {
				if (cube.getCube(coordXZ[i / 2].first, 1, coordXZ[i / 2].second).getSide((((i + 1) / 2) % 4)) == downColor) {
					switch (i) {
					case 0:
						solveSequence += removeUpColor(cube, 0, 1, downColor);
						cube.Lr();
						solveSequence += "L\'";
						break;
					case 1:
						solveSequence += removeUpColor(cube, 1, 0, downColor);
						cube.F();
						solveSequence += 'F';
						break;
					case 2:
						solveSequence += removeUpColor(cube, 1, 2, downColor);
						cube.Br();
						solveSequence += "B\'";
						break;
					case 3:
						solveSequence += removeUpColor(cube, 0, 1, downColor);
						cube.L();
						solveSequence += 'L';
						break;
					case 4:
						solveSequence += removeUpColor(cube, 2, 1, downColor);
						cube.Rr();
						solveSequence += "R\'";
						break;
					case 5:
						solveSequence += removeUpColor(cube, 1, 2, downColor);
						cube.B();
						solveSequence += 'B';
						break;
					case 6:
						solveSequence += removeUpColor(cube, 1, 0, downColor);
						cube.Fr();
						solveSequence += "F\'";
						break;
					case 7:
						solveSequence += removeUpColor(cube, 2, 1, downColor);
						cube.R();
						solveSequence += 'R';
						break;
					}
				}
			}
			coordXZ = { {1, 0}, {0, 1}, {1, 2}, {2, 1} };
			for (int i(0); i < 4; ++i) {
				for (int j(0); j < 2; ++j) {
					if (cube.getCube(coordXZ[i].first, 2, coordXZ[i].second).getSide(j ? i : 4) == downColor) {
						switch (i * 2 + j) {
						case 0:
							solveSequence += removeUpColor(cube, 1, 0, downColor);
							cube.F();
							solveSequence += 'F';
							solveSequence += removeUpColor(cube, 0, 1, downColor);
							cube.Lr();
							solveSequence += "L\'";
							break;
						case 1:
							solveSequence += removeUpColor(cube, 1, 0, downColor);
							cube.F();
							cube.F();
							solveSequence += "FF";
							break;
						case 2:
							solveSequence += removeUpColor(cube, 0, 1, downColor);
							cube.Lr();
							solveSequence += "L'";
							solveSequence += removeUpColor(cube, 1, 0, downColor);
							cube.F();
							solveSequence += 'F';
							break;
						case 3:
							solveSequence += removeUpColor(cube, 0, 1, downColor);
							cube.L();
							cube.L();
							solveSequence += "LL";
							break;
						case 4:
							solveSequence += removeUpColor(cube, 1, 2, downColor);
							cube.Br();
							solveSequence += "B\'";
							solveSequence += removeUpColor(cube, 0, 1, downColor);
							cube.L();
							solveSequence += 'L';
							break;
						case 5:
							solveSequence += removeUpColor(cube, 1, 2, downColor);
							cube.B();
							cube.B();
							solveSequence += "BB";
							break;
						case 6:
							solveSequence += removeUpColor(cube, 2, 1, downColor);
							cube.Rr();
							solveSequence += "R\'";
							solveSequence += removeUpColor(cube, 1, 2, downColor);
							cube.B();
							solveSequence += "B";
							break;
						case 7:
							solveSequence += removeUpColor(cube, 2, 1, downColor);
							cube.R();
							cube.R();
							solveSequence += "RR";
							break;
						}
					}
				}
			}
			for (int i(0); i < 4; ++i) {
				if (cube.getCube(coordXZ[i].first, 0, coordXZ[i].second).getSide(i) == downColor) {
					switch (i) {
					case 0:
						cube.Fr();
						solveSequence += "F\'";
						solveSequence += removeUpColor(cube, 0, 1, downColor);
						cube.Lr();
						solveSequence += "L\'";
						break;
					case 1:
						cube.L();
						solveSequence += 'L';
						solveSequence += removeUpColor(cube, 1, 0, downColor);
						cube.F();
						solveSequence += 'F';
						break;
					case 2:
						cube.B();
						solveSequence += 'B';
						solveSequence += removeUpColor(cube, 0, 1, downColor);
						cube.L();
						solveSequence += 'L';
						break;
					case 3:
						cube.R();
						solveSequence += 'R';
						solveSequence += removeUpColor(cube, 1, 2, downColor);
						cube.B();
						solveSequence += 'B';
						break;
					}
				}
			}
		}
	}

	//cross
	{
		for (int i(0); i < 4; ++i) {
			if (cube.getCube(1, 0, 0).getFront() == cube.getFrontColor() &&
				cube.getCube(1, 0, 0).getUp() == downColor) {
				cube.F();
				cube.F();
				solveSequence += "FF";
			}
			if (cube.getCube(0, 0, 1).getLeft() == cube.getLeftColor() &&
				cube.getCube(0, 0, 1).getUp() == downColor) {
				cube.L();
				cube.L();
				solveSequence += "LL";
			}
			if (cube.getCube(1, 0, 2).getBack() == cube.getBackColor() &&
				cube.getCube(1, 0, 2).getUp() == downColor) {
				cube.B();
				cube.B();
				solveSequence += "BB";
			}
			if (cube.getCube(2, 0, 1).getRight() == cube.getRightColor() &&
				cube.getCube(2, 0, 1).getUp() == downColor) {
				cube.R();
				cube.R();
				solveSequence += "RR";
			}
			cube.U();
			solveSequence += 'U';
		}
	}

	//down layer
	{
		for (int i(0); i < 16; ++i) {
			if (cube.getCube(2, 2, 0).getDown() == cube.getDownColor() &&
				cube.getCube(2, 2, 0).getFront() == cube.getFrontColor() &&
				cube.getCube(2, 2, 0).getRight() == cube.getRightColor()) {
				cube.Y();
				solveSequence += 'Y';
				continue;
			}
			if (cube.getCube(2, 2, 0).hasColor(cube.getDownColor())) {
				solveSequence += rTrigger(cube);
			}
			for (int i(0); i < 4; ++i) {
				if (cube.getCube(2, 0, 0).hasColor(cube.getDownColor()) &&
					cube.getCube(2, 0, 0).hasColor(cube.getFrontColor()) &&
					cube.getCube(2, 0, 0).hasColor(cube.getRightColor()))
				{
					while (!(cube.getCube(2, 2, 0).getDown() == cube.getDownColor())) {
						solveSequence += rTrigger(cube);
					}
					break;
				}
				cube.U();
				solveSequence += 'U';
			}
			cube.Y();
			solveSequence += 'Y';
		}
	}

	//middle layer
	{
		for (int k(0); k < 8; ++k) {
			for (int i(0); i < 4; ++i) {
				for (int j(0); j < 4; ++j) {
					if (cube.getCube(1, 0, 0).getFront() == cube.getFrontColor() &&
						cube.getCube(1, 0, 0).getUp() != cube.getUpColor())
					{
						for (int m(0); m < 2; ++m) {
							if (cube.getCube(1, 0, 0).getUp() == cube.getLeftColor()) {
								solveSequence += moveUpFrontToLeft(cube);
							}
							if (cube.getCube(1, 0, 0).getUp() == cube.getRightColor()) {
								solveSequence += moveUpFrontToRight(cube);
							}
						}
					}
					cube.U();
					solveSequence += 'U';
				}

				cube.Y();
				solveSequence += 'Y';
			}
			for (int i(0); i < 4; ++i) {
				if (cube.getCube(2, 1, 0).getFront() != cube.getFrontColor() ||
					cube.getCube(2, 1, 0).getRight() != cube.getRightColor())
				{
					solveSequence += moveUpFrontToRight(cube);
					break;
				}
				cube.Y();
				solveSequence += 'Y';
			}
		}
	}

	//up cross
	{
		const Color& upColor = cube.getUpColor();
		if (cube.getCube(1, 0, 0).getUp() != upColor &&
			cube.getCube(0, 0, 1).getUp() != upColor &&
			cube.getCube(1, 0, 2).getUp() != upColor &&
			cube.getCube(2, 0, 1).getUp() != upColor)
		{
			solveSequence += rTriggerWithFront(cube);
		}
		if (cube.getCube(1, 0, 0).getUp() != upColor ||
			cube.getCube(0, 0, 1).getUp() != upColor ||
			cube.getCube(1, 0, 2).getUp() != upColor ||
			cube.getCube(2, 0, 1).getUp() != upColor) 
		{
			while (true) {
				if (cube.getCube(0, 0, 1).getUp() == upColor) {
					if (cube.getCube(1, 0, 2).getUp() == upColor) {
						solveSequence += rTriggerWithFront(cube);
						solveSequence += rTriggerWithFront(cube);
						break;
					}
					if (cube.getCube(2, 0, 1).getUp() == upColor) {
						solveSequence += rTriggerWithFront(cube);
						break;
					}
				}
				cube.U();
				solveSequence += 'U';
			}
		}
	}
	
	//up correct cross
	{
		bool correctCross = false;
		for (int i(0); (i < 8) && !correctCross; ++i) {
			cube.U();
			solveSequence += 'U';
			if (cube.getCube(1, 0, 0).getFront() == cube.getFrontColor() &&
				cube.getCube(0, 0, 1).getLeft() == cube.getLeftColor() &&
				cube.getCube(1, 0, 2).getBack() == cube.getBackColor() &&
				cube.getCube(2, 0, 1).getRight() == cube.getRightColor())
			{
				break;
			}
			for (int j(0); j < 8; ++j) {
				cube.Y();
				solveSequence += 'Y';
				if (cube.getCube(1, 0, 2).getBack() == cube.getBackColor()) {
					if (cube.getCube(2, 0, 1).getRight() == cube.getRightColor()) {
						solveSequence += swapUpSides(cube);
						cube.U();
						solveSequence += 'U';
						correctCross = true;
						break;
					}
					if (cube.getCube(1, 0, 0).getFront() == cube.getFrontColor()) {
						solveSequence += swapUpSides(cube);
						continue;
					}
				}
			}
		}
	}

	//up correct angles
	{
		const Color& frontColor = cube.getFrontColor();
		const Color& leftColor = cube.getLeftColor();
		const Color& backColor = cube.getBackColor();
		const Color& rightColor = cube.getRightColor();
		for (int k(0); k < 2; ++k) {
			for (int i(0); i < 4; ++i) {
				if (cube.getCube(0, 0, 0).hasColor(frontColor) && cube.getCube(0, 0, 0).hasColor(leftColor)) {
					break;
				}
				cube.Y();
				solveSequence += 'U';
			}
			if (cube.getCube(0, 0, 0).hasColor(frontColor) && cube.getCube(0, 0, 0).hasColor(leftColor)) {
				while (!cube.getCube(0, 0, 2).hasColor(leftColor)) {
					solveSequence += swapUpAngles(cube);
				}
			} else {
				solveSequence += swapUpAngles(cube);
			}
		}
	}

	//final
	{
		cube.X();
		cube.X();
		solveSequence += "XX";
		bool solved = true;
		for (int i(0); i < 4; ++i) {
			if (cube.getCube(2, 2, 0).hasColor(downColor) && cube.getCube(2, 2, 0).getDown() != downColor) {
				solved = false;
				break;
			}
			cube.Y();
			solveSequence += 'Y';
		}
		if (!solved) {
			for (int i(0); i < 4; ++i) {
				while (cube.getCube(2, 2, 0).getDown() != downColor) {
					solveSequence += rTrigger(cube);
				}
				cube.D();
				solveSequence += 'D';
			}
			while (cube.getCube(2, 2, 0).getFront() != cube.getFrontColor()) {
				cube.D();
				solveSequence += 'D';
			}
		}
	}

	return solveSequence;
}