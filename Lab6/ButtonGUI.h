#pragma once
#include"Button.h"
#include"GUIhelp.h"
#include"RubicsCubeGUI.h"
#include"RubicsCubeAlgorithms.h"
#include<vector>

typedef Coordinates Sizes;

class ButtonGUI : public Button<ButtonGUI> {
public:
	ButtonGUI(RubicsCubeGUI& _connectedCubeGUI);

	//ButtonGUI(const std::vector<void(*)()>&, const std::vector<void(*)()>&);
	ButtonGUI(RubicsCubeGUI&, const Coordinates&, const Sizes&, const Color& _color, const Color& _onCoverColor, const Color& _onClickColor);

	void setPos(const Coordinates&);

	void setSizes(const Sizes&);

	void setColor(const Color&);

	const Coordinates& getPos() const;

	const Sizes& getSizes() const;

	const Color& getColor() const;

	void draw();

	void callback() override;

	void cursorCallback(int windowWidth, int windowHeight, double xPos, double yPos);

	void mouseButtonCallback(int button, int action, int mods);

private:
	RubicsCubeGUI& connectedCubeGUI;
	Coordinates leftUpAngleCoords;
	Sizes sizes;
	Color color;
	Color mainColor;
	Color onCoverColor;
	Color onClickColor;

	void onCover() override;
	
	void onClick() override;

	//void coverCallback();

	friend void changeColorOnCover(ButtonGUI&);

	friend void changeColorOnClick(ButtonGUI&);

	friend void solveOnClick(ButtonGUI&);
	
	friend void shuffleOnClick(ButtonGUI&);
};

void changeColorOnCover(ButtonGUI&);

void changeColorOnClick(ButtonGUI&);

void solveOnClick(ButtonGUI& cube);

void shuffleOnClick(ButtonGUI& cube);