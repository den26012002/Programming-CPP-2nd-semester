#include "ButtonGUI.h"
#include<iostream>
#include<fstream>
#include<thread>

class ButtonGUI;

ButtonGUI::ButtonGUI(RubicsCubeGUI& _connectedCubeGUI) :
	Button::Button(),
	connectedCubeGUI(_connectedCubeGUI),
	leftUpAngleCoords({ 0, 0, 0 }),
	sizes({ 0, 0, 0 }),
	color({ 0, 0, 0 }),
	mainColor({ 0, 0, 0 }),
	onCoverColor({ 0, 0, 0 }),
	onClickColor({ 0, 0, 0 })
{
	addOnCoverFunction(changeColorOnCover);
	addOnClickFunction(changeColorOnClick);
	addIdleFunction(changeColorOnIdle);
}

//ButtonGUI::ButtonGUI(const std::vector<void(*)()>& _onCoverFunctions, const std::vector<void(*)()>& _onClickFunctions) :
//	ButtonGUI::ButtonGUI()
//{
//	onCoverFunctions = _onCoverFunctions;
//	onClickFunctions = _onClickFunctions;
//}

ButtonGUI::ButtonGUI(RubicsCubeGUI& _connectedCubeGUI, const Coordinates& _leftUpAngleCoords, const Sizes& _sizes,
					  const Color& _mainColor, const Color& _onCoverColor, const Color& _onClickColor) :
	Button::Button(), 
	connectedCubeGUI(_connectedCubeGUI),
	leftUpAngleCoords(_leftUpAngleCoords),
	sizes(_sizes),
	color(_mainColor),
	mainColor(_mainColor),
	onCoverColor(_onCoverColor),
	onClickColor(_onClickColor)
{
	addOnCoverFunction(changeColorOnCover);
	addOnClickFunction(changeColorOnClick);
	addIdleFunction(changeColorOnIdle);
}

void ButtonGUI::setPos(const Coordinates& _leftUpAngleCoords) {
	leftUpAngleCoords = _leftUpAngleCoords;
}

void ButtonGUI::setSizes(const Sizes& _sizes) {
	sizes = _sizes;
}

void ButtonGUI::setColor(const Color& _color) {
	color = _color;
}

const Coordinates& ButtonGUI::getPos() const {
	return leftUpAngleCoords;
}

const Sizes& ButtonGUI::getSizes() const {
	return sizes;
}

const Color& ButtonGUI::getColor() const {
	return color;
}

RubicsCubeGUI& ButtonGUI::getConnectedGUI() const {
	return connectedCubeGUI;
}

void ButtonGUI::draw() {
	glPushMatrix();
	glLoadIdentity();
	glBegin(GL_QUADS);
	glColor3f(color.r, color.g, color.b);
	glVertex2f(leftUpAngleCoords.x, leftUpAngleCoords.y);
	glVertex2f(leftUpAngleCoords.x + sizes.x, leftUpAngleCoords.y);
	glVertex2f(leftUpAngleCoords.x + sizes.x, leftUpAngleCoords.y - sizes.y);
	glVertex2f(leftUpAngleCoords.x, leftUpAngleCoords.y - sizes.y);
	glEnd();
	glPopMatrix();
}

//void ButtonGUI::addOnCoverFunction(void(*func)()) {
//	onCoverFunctions.push_back(func);
//}
//
//void ButtonGUI::addOnClickFunction(void(*func)()) {
//	onClickFunctions.push_back(func);
//}

//void ButtonGUI::callback() {
//	if (isActive) {
//		if (isClicked) {
//			if (!wasActionOnClick) {
//				onClick();
//				wasActionOnClick = true;
//			}
//		} else if (isCovered) {
//			onCover();
//		} else {
//			color = mainColor;
//		}
//	} else {
//		idle();
//	}
//}

void ButtonGUI::cursorCallback(int windowWidth, int windowHeight, double xPos, double yPos) {
	xPos = (xPos - (double)windowWidth / 2) / (double)windowWidth * 2;
	yPos = -(yPos - (double)windowHeight / 2) / (double)windowHeight * 2;
	if (leftUpAngleCoords.x <= xPos && xPos <= leftUpAngleCoords.x + sizes.x &&
		leftUpAngleCoords.y >= yPos && yPos >= leftUpAngleCoords.y - sizes.y) {
		isCovered = true;
	} else {
		isCovered = false;
	}
	//std::cout << (isCovered ? "Covered" : "Not covered") << '\n';
	//onCover();
}

void ButtonGUI::mouseButtonCallback(int button, int action, int mods) {
	if (isCovered) {
		if (button == GLFW_MOUSE_BUTTON_LEFT) {
			//ButtonGUI::onClick();
			if (action == GLFW_PRESS) {
				isClicked = true;
			} else if (action == GLFW_RELEASE) {
				isClicked = false;
				wasActionOnClick = false;
			}
		}
	}
}

//void ButtonGUI::onCover() {
//	for (int i(0); i < onCoverFunctions.size(); ++i) {
//		onCoverFunctions[i](*this);
//	}
//}

//void ButtonGUI::onClick() {
//	for (int i(0); i < onClickFunctions.size(); ++i) {
//		onClickFunctions[i](*this);
//	}
//}


//void ButtonGUI::coverCallback() {
//	if (!isCovered) {
//		color = mainColor;
//	} else {
//		ButtonGUI::onCover();
//	}
//}

void changeColorOnCover(ButtonGUI& button) {
	button.setColor(button.onCoverColor);
}

void changeColorOnClick(ButtonGUI& button) {
	button.setColor(button.onClickColor);
}

void changeColorOnIdle(ButtonGUI& button) {
	button.setColor(button.mainColor);
}

void solveOnClick(ButtonGUI& button) {
	try {
		button.connectedCubeGUI.makeAlgorithmStep(beginnerLevelSolveAlgorithm);
	} catch (...) {
		std::cerr << "This configuration is unsolvable, please load another file\n";
	}
}

void shuffleOnClick(ButtonGUI& button) {
	button.connectedCubeGUI.makeAlgorithmStep(randomShuffle);
}

void logOnClick(ButtonGUI& button) {
	button.getConnectedGUI().getCube().logConfig();
}

void saveOnClick(ButtonGUI& button) {
	std::string filename;
	std::cin >> filename;
	button.getConnectedGUI().getCube().saveConfig(filename);
}

void loadOnClick(ButtonGUI& button) {
	std::string filename;
	std::cin >> filename;
	try {
		button.getConnectedGUI().getCube().loadConfig(filename);
	} catch (...) {
		std::cerr << "Error file format or file doesn't exist";
	}
}