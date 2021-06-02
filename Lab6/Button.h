#pragma once
#include<vector>

template<typename ButtonType>
class Button {
public:
	Button() :
		isCovered(false),
		isClicked(false)
	{}

	void addOnCoverFunction(void(*func)(ButtonType&)) {
		onCoverFunctions.push_back(func);
	}

	void addOnClickFunction(void(*func)(ButtonType&)) {
		onClickFunctions.push_back(func);
	}

	virtual void callback() = 0;

	virtual ~Button() = default;

protected:
	std::vector<void(*)(ButtonType&)> onCoverFunctions;
	std::vector<void(*)(ButtonType&)> onClickFunctions;
	bool isCovered;
	bool isClicked;

	//virtual void idle() = 0;

	virtual void onCover() = 0;

	virtual void onClick() = 0;
};

/*template<typename ButtonType>
void Button<ButtonType>::callback() {
	if (isCovered) {
		onCover();
	}
	if (isClicked) {
		onClick();
	}
}*/