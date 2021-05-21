#pragma once
#include<string>
#include<vector>
#include<set>


std::vector<std::string> parseString(const std::string& str, std::set<char> symbols = { ' ', ',', '\t' });

bool deleteSubStr(std::string& str, const std::string& subStr);

std::string& deleteFrontSpaces(std::string& str);

std::string& deleteBackSpaces(std::string& str);

template<typename Type>
void print(const std::vector<Type>& arr, std::string sep = " ", std::string end = "\n");