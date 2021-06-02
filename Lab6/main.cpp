#include<GLFW/glfw3.h>
#include<Windows.h>
#include<iostream>
#include<conio.h>
#include"SmallCube.h"
#include"RubicsCube.h"
#include"RubicsCubeGUI.h"
#include"RubicsCubeAlgorithms.h"

int main(void)
{
   /* GLFWwindow* window;

    // Initialize the library
    if (!glfwInit())
        return -1;

    // Create a windowed mode window and its OpenGL context
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    // Loop until the user closes the window*/
    try {
        /*RubicsCube cube;
        cube.loadConfig("config.txt");
        srand(time(NULL));
        for (int i(0); i < 10000; ++i) {
            std::cout << i;
            beginnerLevelSolveAlgorithm(cube);
            if (!cube.isSolved()) {
                cube.logConfig();
                throw "Error";
            }
            system("cls");
        }*/
        RubicsCube cube;
        RubicsCube anotherCube;
        //cube.loadConfig("config.txt");
        //randomShuffle(cube);
        //std::cout << beginnerLevelSolveAlgorithm(cube);
        srand(time(NULL));
        randomShuffle(cube);
        //std::cout << beginnerLevelSolveAlgorithm(cube) << '\n';
        //cube.logConfig();
        RubicsCubeGUI& cubeGUI = RubicsCubeGUI::Instance(cube);
        cubeGUI.play();
        //cubeGUI.makeAlgorithmStep(beginnerLevelSolveAlgorithm);
        
    } catch (char str) {
        std::cerr << str;
    } catch (const char* err) {
        std::cerr << err;
    }
    
    /*while (!glfwWindowShouldClose(window))
    {
        // Render here
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_QUADS);
        glColor3f(0.0f, 0.75f, 0.0f);
		    glVertex2d(-0.5f, -0.5f);
		    glVertex2d(0.5f, -0.5f);
		    glVertex2d(0.5f, 0.5f);
            glVertex2d(-0.5f, 0.0f);
		glEnd();
        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events 
        glfwPollEvents();
    }

    glfwTerminate();*/
    return 0;
}