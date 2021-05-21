#pragma once
#include"pugixml-1.11\src\pugixml.hpp"
#include"transportTypes.h"
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<math.h>

typedef std::vector<Coordinates> Stoppings;
typedef std::map<std::string, Stoppings> Routes;
typedef std::map<std::string, int> Location;

class TransportInfo {
public:
	void getInfo(const std::string& filename);

	void printMaxStoppingRoutes(std::ostream& cout) const;

	void printMaxDistRoute(std::ostream& cout) const;

	void printMaxStoppingStreet(std::ostream& cout);

private:
	std::map<LocationType, Location> locationsStoppingCnt;
	std::map<LocationType, std::pair<std::string, int>> maxStoppingLocations;
	std::map<RouteType, Routes> routes;
	std::map<RouteType, std::pair<std::string, int>> maxStoppingRoutes;

	double findDist(const Stoppings& route) const;

	double findDist(const Coordinates& pos1, const Coordinates& pos2) const;

	double getParallelDist(double parallel, double angleDist) const;
	
	double getMeridianDist(double angleDist) const;
};
