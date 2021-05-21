#include<Windows.h>
#include"pugixml-1.11\src\pugixml.hpp"
#include"TransportInfo.h"
#include<iostream>
#include<string>
#include<vector>

int main() {
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	try {
		TransportInfo info;
		info.getInfo("data.xml");
		std::cout << u8"Маршруты с наибольшим количеством остановок:\n";
		info.printMaxStoppingRoutes(std::cout);
		std::cout << std::endl;
		std::cout << u8"Наиболее длинные маршруты:\n";
		info.printMaxDistRoute(std::cout);
		std::cout << std::endl;
		std::cout << u8"Улица с наибольшим числом остановок:\n";
		info.printMaxStoppingStreet(std::cout);
	} catch (const char* str) {
		std::cerr << str;
	}
	catch (...) {
		std::cerr << "Unknown error";
	}

	return 0;
}