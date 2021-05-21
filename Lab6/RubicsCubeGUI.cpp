#include "RubicsCubeGUI.h"
#include "GLFW/glfw3.h"
#include"GUIhelp.h"
#include<Windows.h>

void RubicsCubeGUI::play() {
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        throw "Something went wrong (RubicsCubeGUI::play())";

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(1000, 800, "Rubik's cube", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        throw "Something went wrong (RubicsCubeGUI::play())";
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glEnable(GL_DEPTH_TEST);
    glLoadIdentity();
    glFrustum(-1, 1, -1, 1, 1, 10);
    glTranslatef(0, 0, -1);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        /*glTranslatef(0, 0, -0.01f);
        glPushMatrix();
        glRotatef(10, 0, 1, 0);
        glBegin(GL_QUADS);
            glColor3f(1.0f, 1.0f, 1.0f);
		    glVertex3f(-0.5f, 0.5f, 0.0f);
		    glVertex3f(-0.5f, -0.5f, 0.0f);
		    glVertex3f(0.5f, -0.5f, 0.0f);
		    glVertex3f(0.5f, 0.5f, 0.0f);

			glColor3f(0.0f, 1.0f, 0.0f);
			glVertex3f(-0.5f, 0.5f, -10.0f);
			glVertex3f(-0.5f, -0.5f, -10.0f);
			glVertex3f(0.5f, -0.5f, -10.0f);
			glVertex3f(0.5f, 0.5f, -10.0f);
        glEnd();
        glPopMatrix();*/
        glTranslatef(0, 0, -0.01f);
        glPushMatrix();
        glRotatef(-45.0f, 0.5f, 1.0f, 0.0f);
        //drawSmallCube(cube.getCube(0, 0, 0), { 0.5f, -0.5f, 0.0f }, 0.5f);
        //drawSmallCube(cube.getCube(1, 0, 0), { 1.0f, -0.5f, 0.0f }, 0.5f);
        for (int x(0); x < 3; ++x) {
            for (int y(0); y < 3; ++y) {
                for (int z(0); z < 3; ++z) {
                    Coordinates leftUpFrontAngle;
                    if (x == 0) {
                        leftUpFrontAngle.x = 0.5f;
                    } else if (x == 1) {
                        leftUpFrontAngle.x = 1.0f;
                    } else if (x == 2) {
                        leftUpFrontAngle.x = 1.5f;
                    }
                    if (y == 0) {
                        leftUpFrontAngle.y = 0.5f;
                    } else if (y == 1) {
                        leftUpFrontAngle.y = 0.0f;
                    } else if (y == 2) {
                        leftUpFrontAngle.y = -0.5f;
                    }
                    if (z == 0) {
                        leftUpFrontAngle.z = 1.0f;
                    } else if (z == 1) {
                        leftUpFrontAngle.z = 0.5f;
                    } else if (z == 2) {
                        leftUpFrontAngle.z = 0.0f;
                    }
                    drawSmallCube(cube.getCube(x, y, z), leftUpFrontAngle, 0.5f);
                }
            }
        }
        glPopMatrix();
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
        Sleep(10);
    }

    glfwTerminate();
}