#include"transportTypes.h"
#include<string>

RouteType inferRouteType(const std::string& type) {
	if (type == std::string(u8"Автобус")) {
		return RouteType::BUS;
	} else if (type == std::string(u8"Троллейбус")) {
		return RouteType::TROLLEY;
	} else if (type == std::string(u8"Трамвай")) {
		return RouteType::TRAM;
	} else {
		throw "Something went wrong";
	}
}

std::string typeToString(const RouteType& type) {
	switch (type) {
	case RouteType::BUS:
		return u8"Автобус";
	case RouteType::TROLLEY:
		return u8"Троллейбус";
	case RouteType::TRAM:
		return u8"Трамвай";
	default:
		throw "Something went wrong";
	}
}