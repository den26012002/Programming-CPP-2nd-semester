#pragma once
#include<string>

enum class LocationType {
	STREET,
	OTHER
};

enum class RouteType {
	BUS,
	TROLLEY,
	TRAM
};

RouteType inferRouteType(const std::string& type);

std::string typeToString(const RouteType& type);

struct Coordinates {
	double N;
	double E;
};