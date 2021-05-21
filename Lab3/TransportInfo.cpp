#include"TransportInfo.h"
#include"stringHelp.h"
#include"pugixml-1.11\src\pugixml.hpp"
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<math.h>

static const double INF = 1e9;

void TransportInfo::getInfo(const std::string& filename) {
	pugi::xml_document doc;
	pugi::xml_parse_result res = doc.load_file(filename.c_str());
	if (!res) {
		throw "Something went wrong";
	}
	int cnt = 0;
	for (pugi::xml_node station : doc.child("dataset").children("transport_station")) {
		RouteType routeType = inferRouteType(std::string(station.child_value("type_of_vehicle")));
		std::string routesString = station.child_value("routes");
		std::vector<std::string> routeNumbs = parseString(station.child_value("routes"), { ' ', ',', '.' });
		std::vector<std::string> coordinatesString = parseString(station.child_value("coordinates"));
		Coordinates coordinates = { std::atof(coordinatesString[0].c_str()), std::atof(coordinatesString[1].c_str()) };
		for (auto routeNumb : routeNumbs) {
			routes[routeType][routeNumb].push_back(coordinates);
			if (!maxStoppingRoutes.count(routeType)) {
				maxStoppingRoutes[routeType] = { "0", 0 };
			}
			if (routes[routeType][routeNumb].size() > maxStoppingRoutes[routeType].second) {
				maxStoppingRoutes[routeType].first = routeNumb;
				maxStoppingRoutes[routeType].second = routes[routeType][routeNumb].size();
			}
		}
		std::vector<std::string> locationsString = parseString(station.child_value("location"), { ',' });
		for (auto location : locationsString) {
			location = " " + location;
			LocationType locationType = LocationType::OTHER;
			int typePos;
			if (deleteSubStr(location, u8" ул.") || deleteSubStr(location, u8" улица")) {
				locationType = LocationType::STREET;
				deleteBackSpaces(deleteFrontSpaces(location));
				if (!locationsStoppingCnt[locationType].count(location)) {
					locationsStoppingCnt[locationType][location] = 0;
				}
				++locationsStoppingCnt[locationType][location];
				if (!maxStoppingLocations.count(locationType)) {
					maxStoppingLocations[locationType] = { "0", 0 };
				}
				if (locationsStoppingCnt[locationType][location] > maxStoppingLocations[locationType].second) {
					maxStoppingLocations[locationType].first = location;
					maxStoppingLocations[locationType].second = locationsStoppingCnt[locationType][location];
				}
			}
		}
	}
}

void TransportInfo::printMaxStoppingRoutes(std::ostream& cout) const {
	for (auto route : maxStoppingRoutes) {
		cout << typeToString(route.first) << ": " << route.second.first << '\n';
	}
}

void TransportInfo::printMaxDistRoute(std::ostream& cout) const {
	for (auto route : routes) {
		double maxDist = 0;
		std::string maxDistRoute = "";
		for (auto stopping : route.second) {
			int routeDist = findDist(stopping.second);
			if (routeDist > maxDist) {
				maxDist = routeDist;
				maxDistRoute = stopping.first;
			}
		}
		cout << typeToString(route.first) << ": " << maxDistRoute << '\n';
	}

}

void TransportInfo::printMaxStoppingStreet(std::ostream& cout) {
	cout << maxStoppingLocations[LocationType::STREET].first << u8" улица: " << maxStoppingLocations[LocationType::STREET].second << '\n';
}

double TransportInfo::findDist(const Stoppings& route) const {
	std::vector<bool> isVisited(route.size(), false);
	int left = rand() % route.size();
	int right = -1;
	isVisited[left] = true;
	double ansDist = 0.0;
	for (int i(0); i < route.size() - 1; ++i) {
		double distToNext = INF;
		int nextStopping = -1;
		bool isNextRight = true;
		for (int j(0); j < route.size(); ++j) {
			if (isVisited[j]) {
				continue;
			}
			if (findDist(route[left], route[j]) < distToNext) {
				distToNext = findDist(route[left], route[j]);
				nextStopping = j;
				isNextRight = (right == -1);
			}
			if ((right != -1 && findDist(route[right], route[j]) < distToNext)) {
				distToNext = findDist(route[right], route[j]);
				nextStopping = j;
				isNextRight = true;
			}
		}
		ansDist += distToNext;
		isVisited[nextStopping] = true;
		if (isNextRight) {
			right = nextStopping;
		} else {
			left = nextStopping;
		}
	}
	return ansDist;
}

double TransportInfo::findDist(const Coordinates& pos1, const Coordinates& pos2) const {
	double parallelDist = getParallelDist((pos1.N + pos2.N) / 2.0, std::abs(pos1.E - pos2.E));
	double meridianDist = getMeridianDist(std::abs(pos1.N - pos2.N));
	return std::sqrt(std::pow(parallelDist, 2.0) + std::pow(meridianDist, 2.0));
}

double TransportInfo::getParallelDist(double parallel, double angleDist) const {
	return (angleDist / 180.0) * 6378137.0 * std::cos(parallel / 180.0);
}

double TransportInfo::getMeridianDist(double angleDist) const {
	return (angleDist / 180.0) * 20004274.0;
}
