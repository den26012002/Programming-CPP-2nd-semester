#include"transportTypes.h"
#include<string>

RouteType inferRouteType(const std::string& type) {
	if (type == std::string(u8"�������")) {
		return RouteType::BUS;
	} else if (type == std::string(u8"����������")) {
		return RouteType::TROLLEY;
	} else if (type == std::string(u8"�������")) {
		return RouteType::TRAM;
	} else {
		throw "Something went wrong";
	}
}

std::string typeToString(const RouteType& type) {
	switch (type) {
	case RouteType::BUS:
		return u8"�������";
	case RouteType::TROLLEY:
		return u8"����������";
	case RouteType::TRAM:
		return u8"�������";
	default:
		throw "Something went wrong";
	}
}