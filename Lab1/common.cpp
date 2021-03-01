#include<algorithm>
#include"common.h"

namespace geometry {
	double getPerimeter(const Polyline& polyline) {
		return polyline.getPerimeter();
	}

	double getSquare(const Polyline& polyline) {
		return polyline.getSquare();
	}
}

bool isEquals(double a, double b) {
	double exp = 1e-5;
	return (std::abs(a - b) <= exp);
}