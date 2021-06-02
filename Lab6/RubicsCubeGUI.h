#pragma once
#include"RubicsCube.h"
#include"GUIhelp.h"
#include<string>

class RubicsCubeGUI {
public:
	static RubicsCubeGUI& Instance(RubicsCube&);

	RubicsCubeGUI(const RubicsCubeGUI&) = delete;

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

	friend class ButtonGUI;
};

//void keyCallback(GLFWwindow*, int key, int scancode, int action, int mods);