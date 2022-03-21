#pragma once
#include<vector>

template<typename ButtonType>
class Button {
public:
	Button() :
		isCovered(false),
		isClicked(false),
		wasActionOnClick(false),
		isActive(true)
	{}

	bool active() {
		return isActive;
	}

	void setActive(bool state) {
		isActive = state;
	}

	void addOnCoverFunction(void(*func)(ButtonType&)) {
		onCoverFunctions.push_back(func);
	}

	void addOnClickFunction(void(*func)(ButtonType&)) {
		onClickFunctions.push_back(func);
	}

	void addIdleFunction(void(*func)(ButtonType&)) {
		idleFunctions.push_back(func);
	}

	void callback() {
		if (isActive) {
			if (isClicked) {
				if (!wasActionOnClick) {
					onClick();
					wasActionOnClick = true;
				}
			} else if (isCovered) {
				onCover();
			} else {
				idle();
			}
		} else {
			idle();
		}
	};

protected:
	std::vector<void(*)(ButtonType&)> onCoverFunctions;
	std::vector<void(*)(ButtonType&)> onClickFunctions;
	std::vector<void(*)(ButtonType&)> idleFunctions;
	bool isCovered;
	bool isClicked;
	bool wasActionOnClick;
	bool isActive;

	void idle() {
		for (int i(0); i < idleFunctions.size(); ++i) {
			idleFunctions[i](*(static_cast<ButtonType*>(this)));
		}
	}

	void onCover() {
		for (int i(0); i < onCoverFunctions.size(); ++i) {
			onCoverFunctions[i](*(static_cast<ButtonType*>(this)));
		}
	}

	void onClick() {
		for (int i(0); i < onClickFunctions.size(); ++i) {
			onClickFunctions[i](*(static_cast<ButtonType*>(this)));
		}
	};
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