#include "Button.h"
//////
//////Button::Button() :
//////	isCovered(false)
//////{}
//////
//////void Button::addOnCoverFunction(void(*func)(Button&)) {
//////	onCoverFunctions.push_back(func);
//////}
//////
//////void Button::addOnClickFunction(void(*func)(Button&)) {
//////	onClickFunctions.push_back(func);
//////}
//////
//////void Button::onCover() {
//////	for (int i(0); i < onCoverFunctions.size(); ++i) {
//////		onCoverFunctions[i]();
//////	}
//////}
//////
//////void Button::onClick() {
//////	for (int i(0); i < onClickFunctions.size(); ++i) {
//////		onClickFunctions[i]();
//////	}
//////}