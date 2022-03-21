#pragma once
#include"RubicsCube.h"
#include"GUIhelp.h"
#include<string>

static GLfloat xAngle = 25.0f;
static GLfloat yAngle = 25.0f;
static int curMods;
static std::string curAlgorithmStr;
static const GLfloat xBorder = 35.0f;
static const GLfloat yBorder = 35.0f;
static const int windowWidth = 1000;
static const int windowHeight = 800;

class RubicsCubeGUI {
public:
	static RubicsCubeGUI& Instance(RubicsCube&);

	RubicsCubeGUI(const RubicsCubeGUI&) = delete;
	
	RubicsCube& getCube() const;

	void play();
	
	void makeAlgorithmStep(std::string(*)(RubicsCube& cube));
	
	void makeAlgorithmStep(const std::string&);

	RubicsCubeGUI& operator=(const RubicsCubeGUI) = delete;

private:
	RubicsCubeGUI(RubicsCube&);

	RubicsCube& cube;

	void drawRubicsCube(const Coordinates&, GLfloat size);

	void makeRotation(char rotation);

	void makeReversedRotation(char rotation);

	static void rotationsCallback(GLFWwindow*, int key, int scancode, int action, int mods);

	static void cursorCallback(GLFWwindow* window, double xPos, double yPos);

	static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);

	static void scrollCallback(GLFWwindow* window, double xoffset, double yoffset);

	friend class ButtonGUI;
};
