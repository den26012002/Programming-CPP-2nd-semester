#pragma once
#include"RubicsCube.h"

class RubicsCubeGUI {
public:
	RubicsCubeGUI(RubicsCube& _cube) :
		cube(_cube)
	{
		
	}

	void play();

private:
	RubicsCube& cube;
};

