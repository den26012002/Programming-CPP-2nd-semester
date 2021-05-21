#include"stringHelp.h"
#include<iostream>

std::vector<std::string> parseString(const std::string& str, std::set<char> symbols) {
	std::vector<std::string> ans(1, "");
	for (int i(0); i < str.size(); ++i) {
		if (symbols.count(str[i]) && ans.size() > 0 && ans.back() != "") {
			ans.push_back("");
		} else {
			ans.back() += str[i];
		}
	}
	return ans;
}

bool deleteSubStr(std::string& str, const std::string& subStr) {
	int subStrPos = str.find(subStr);
	if (subStrPos == std::string::npos) {
		return false;
	}
	std::string resStr = "";
	for (int i(0); i < str.size(); ++i) {
		if (i < subStrPos || i > subStrPos + subStr.size() - 1) {
			resStr += str[i];
		}
	}
	str = resStr;
	return true;
}

std::string& deleteFrontSpaces(std::string& str) {
	int i = 0;
	while (str[i] == ' ') {
		++i;
	}
	str = str.substr(i);
	return str;
}

std::string& deleteBackSpaces(std::string& str) {
	int i = str.size() - 1;
	while (str[i] == ' ') {
		--i;
	}
	str = str.substr(0, i + 1);
	return str;
}

template<typename Type>
void print(const std::vector<Type>& arr, std::string sep, std::string end) {
	for (int i(0); i < arr.size(); ++i) {
		std::cout << arr[i] << sep;
	}
	std::cout << end;
}