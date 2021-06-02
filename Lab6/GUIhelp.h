#pragma once
#include"GLFW/glfw3.h"
#include"SmallCube.h"
#include"RubicsCube.h"
//#include"ButtonGUI.h"
#include<vector>

struct Coordinates {
	GLfloat x;
	GLfloat y;
	GLfloat z;
};

void drawQuads(const std::vector<Coordinates>&, const Color&);

void drawSmallCube(const SmallCube&, const Coordinates&, GLfloat size);

//void drawRubicsCube(const RubicsCube&, const Coordinates&, GLfloat size);