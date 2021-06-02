#pragma once
#include"GLFW/glfw3.h"

struct Color {
	GLfloat r;
	GLfloat g;
	GLfloat b;
};

bool operator==(const Color&, const Color&);
bool operator!=(const Color&, const Color&);

const Color BLACK = { 0.0f, 0.0f, 0.0f };
const Color RED = { 1.0f, 0.0f, 0.0f };
const Color GREEN = { 0.0f, 1.0f, 0.0f };
const Color BLUE = { 0.0f, 0.0f, 1.0f };
const Color YELLOW = { 1.0f, 1.0f, 0.0f };
const Color ORANGE = { 1.0f, 0.64f, 0.0f };
const Color WHITE = { 1.0f, 1.0f, 1.0f };

Color findColorByLetter(char letter);

char findLetterByColor(const Color& color);