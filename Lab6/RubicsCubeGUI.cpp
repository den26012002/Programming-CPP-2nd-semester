#include "RubicsCubeGUI.h"
#include "GLFW/glfw3.h"
#include "GLFW/glfw3native.h"
#include"GUIhelp.h"
#include<Windows.h>
#include<gl/GLU.h>
#include<gl/GL.h>
#include"RubicsCubeAlgorithms.h"
#include"ButtonGUI.h"
#include<iostream>

static std::string curAlgorithmStr;

static GLfloat xAngle = 25.0f;
static GLfloat yAngle = 25.0f;
static const GLfloat xBorder = 35.0f;
static const GLfloat yBorder = 35.0f;
static int curMods;
static const int windowWidth = 1000;
static const int windowHeight = 800;

static std::vector<ButtonGUI> buttonsGUI;

static void rotationsCallback(GLFWwindow*, int key, int scancode, int action, int mods);

static void cursorCallback(GLFWwindow* window, double xPos, double yPos);

static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);

static void scrollCallback(GLFWwindow* window, double xoffset, double yoffset);

RubicsCubeGUI& RubicsCubeGUI::Instance(RubicsCube& cube) {
    static RubicsCubeGUI rubicsCubeGUI(cube);
    return rubicsCubeGUI;
}

void RubicsCubeGUI::play() {
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        throw "Something went wrong (RubicsCubeGUI::play())";

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(windowWidth, windowHeight, "Rubik's cube", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        throw "Something went wrong (RubicsCubeGUI::play())";
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    glfwSetKeyCallback(window, rotationsCallback);
    glfwSetCursorPosCallback(window, cursorCallback);
    glfwSetMouseButtonCallback(window, mouseButtonCallback);
    glfwSetScrollCallback(window, scrollCallback);

    buttonsGUI.push_back(ButtonGUI(*this, { -1, 1, 0 }, { 0.5f, 0.1f, 0 }, { 0, 0.75f, 0 }, { 0, 1, 0 }, { 1, 0, 1 }));
    buttonsGUI[0].addOnClickFunction(solveOnClick);
    buttonsGUI.push_back(ButtonGUI(*this, { -1, 0.9f, 0 }, { 0.5f, 0.1f, 0 }, { 0.75f, 0, 0 }, { 1, 0, 0 }, { 1, 0, 1 }));
    buttonsGUI[1].addOnClickFunction(shuffleOnClick);

    glEnable(GL_DEPTH_TEST);
    glLoadIdentity();
    
    glFrustum(-1, 1, -1, 1, 1, 10);
    glTranslatef(0, 0, -4.5f);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glPushMatrix();
        makeAlgorithmStep(curAlgorithmStr);
        glRotatef(xAngle, 1.0f, 0.0f, 0.0f);
        glRotatef(-yAngle, 0.0f, 1.0f, 0.0f);
        drawRubicsCube({ -0.75f, 0.75f, 0.75f }, 0.5f);
        for (int i(0); i < buttonsGUI.size(); ++i) {
            buttonsGUI[i].callback();
            buttonsGUI[i].draw();
        }
        glPopMatrix();
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
        //Sleep(100);
    }

    glfwTerminate();
}

void RubicsCubeGUI::makeAlgorithmStep(std::string(*algorithm)(RubicsCube&)) {
    static std::string(*curAlgorithm)(RubicsCube&) = nullptr;
    static std::string stringAlgorithm = "";
    if (curAlgorithm != algorithm || curAlgorithmStr == "") {
        curAlgorithm = algorithm;
        RubicsCube cubeCopy = cube;
        stringAlgorithm = algorithm(cubeCopy);
    }
    makeAlgorithmStep(stringAlgorithm);
}

void RubicsCubeGUI::makeAlgorithmStep(const std::string& algorithm) {
    //static std::string curAlgorithm = "";
    static int i = 0;
    if (curAlgorithmStr != algorithm) {
        curAlgorithmStr = algorithm;
        i = 0;
    }
    if (i >= algorithm.size()) {
        i = 0;
        curAlgorithmStr = "";
        return;
    }
    if (algorithm[i] != '\'') {
        if (i + 1 < algorithm.size() && algorithm[i + 1] == '\'') {
            makeReversedRotation(algorithm[i]);
        } else {
            makeRotation(algorithm[i]);
        }
    }
    ++i;
}

void RubicsCubeGUI::drawRubicsCube(const Coordinates& coords, GLfloat size) {
    for (int x(0); x < 3; ++x) {
        for (int y(0); y < 3; ++y) {
            for (int z(0); z < 3; ++z) {
                Coordinates leftUpFrontAngle = coords;
                if (x == 1) {
                    leftUpFrontAngle.x += size;
                } else if (x == 2) {
                    leftUpFrontAngle.x += 2 * size;
                }
                if (y == 1) {
                    leftUpFrontAngle.y -= size;
                } else if (y == 2) {
                    leftUpFrontAngle.y -= 2 * size;
                }
                if (z == 1) {
                    leftUpFrontAngle.z -= size;
                } else if (z == 2) {
                    leftUpFrontAngle.z -= 2 * size;
                }
                drawSmallCube(cube.getCube(x, y, z), leftUpFrontAngle, size);
            }
        }
    }
}

void RubicsCubeGUI::makeRotation(char rotation) {
    switch (rotation) {
    case 'F':
        cube.F();
        break;
    case 'L':
        cube.L();
        break;
    case 'B':
        cube.B();
        break;
    case 'R':
        cube.R();
        break;
    case 'D':
        cube.D();
        break;
    case 'U':
        cube.U();
        break;
    case 'X':
        cube.X();
        break;
    case 'Y':
        cube.Y();
        break;
    case 'Z':
        cube.Z();
        break;
    default:
        throw "Something went wrong RubicsCubeGUI::makeRotation(char)";
    }
}

void RubicsCubeGUI::makeReversedRotation(char rotation) {
    switch (rotation) {
    case 'F':
        cube.Fr();
        break;
    case 'L':
        cube.Lr();
        break;
    case 'B':
        cube.Br();
        break;
    case 'R':
        cube.Rr();
        break;
    case 'D':
        cube.Dr();
        break;
    case 'U':
        cube.Ur();
        break;
    case 'X':
        cube.Xr();
        break;
    case 'Y':
        cube.Yr();
        break;
    case 'Z':
        cube.Zr();
        break;
    default:
        throw "Something went wrong RubicsCubeGUI::makeReversedRotation(char)";
    }
}

RubicsCubeGUI::RubicsCubeGUI(RubicsCube& _cube) :
    cube(_cube)
{}



static void rotationsCallback(GLFWwindow*, int key, int scancode, int action, int mods) {
    if (action == GLFW_PRESS) {
        switch (key) {
        case GLFW_KEY_F:
            curAlgorithmStr = "F";
            break;
        case GLFW_KEY_L:
            curAlgorithmStr = "L";
            break;
        case GLFW_KEY_B:
            curAlgorithmStr = "B";
            break;
        case GLFW_KEY_R:
            curAlgorithmStr = "R";
            break;
        case GLFW_KEY_D:
            curAlgorithmStr = "D";
            break;
        case GLFW_KEY_U:
            curAlgorithmStr = "U";
            break;
        case GLFW_KEY_X:
            curAlgorithmStr = "X";
            break;
        case GLFW_KEY_Y:
            curAlgorithmStr = "Y";
            break;
        case GLFW_KEY_Z:
            curAlgorithmStr = "Z";
            break;
        default:
            break;
        }
        if (mods & GLFW_MOD_CONTROL) {
            curAlgorithmStr += '\'';
        }
    }
    curMods = mods;
}

static void cursorCallback(GLFWwindow* window, double xPos, double yPos) {
    //std::cout << xPos << ' ' << yPos << '\n';
    for (int i(0); i < buttonsGUI.size(); ++i) {
        buttonsGUI[i].cursorCallback(windowWidth, windowHeight, xPos, yPos);
    }
}

static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
    //std::cout << "Click\n";
    for (int i(0); i < buttonsGUI.size(); ++i) {
        buttonsGUI[i].mouseButtonCallback(button, action, mods);
    }
}

static void scrollCallback(GLFWwindow* window, double xoffset, double yoffset) {
    if (curMods & GLFW_MOD_CONTROL) {
        yAngle += yoffset;
        if (yAngle < -yBorder) {
            yAngle = -yBorder;
        }
        if (yAngle > yBorder) {
            yAngle = yBorder;
        }
    } else {
        xAngle += yoffset;
        if (xAngle < -xBorder) {
            xAngle = -xBorder;
        }
        if (xAngle > xBorder) {
            xAngle = xBorder;
        }
        //for touchpad
        yAngle -= xoffset;
        if (yAngle < -yBorder) {
            yAngle = -yBorder;
        }
        if (yAngle > yBorder) {
            yAngle = yBorder;
        }
    }
    //std::cout << xAngle << ' ' << yAngle << '\n';
   
}