#include<thread>
#include<GLFW/glfw3.h>
#include<Windows.h>
#include<iostream>
#include<conio.h>
#include"SmallCube.h"
#include"RubicsCube.h"
#include"RubicsCubeGUI.h"
#include"RubicsCubeAlgorithms.h"

int main(int argc, char* argv[])
{
    try {
        RubicsCube cube;
        if (argc == 2) {
            cube.loadConfig(argv[1]);
        }
        srand(time(NULL));
        RubicsCubeGUI& cubeGUI = RubicsCubeGUI::Instance(cube);
        cubeGUI.play();
        
    } catch (char str) {
        std::cerr << str;
    } catch (const char* err) {
        std::cerr << err;
    } catch (...) {
        std::cerr << "Unknown error";
    }
    
    return 0;
}