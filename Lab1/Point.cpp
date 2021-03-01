#include"Point.h"

namespace geometry {
	double Point::getX() const {
		return x;
	}

	double Point::getY() const {
		return y;
	}

	Point::Point(const Point& other) : x(other.x), y(other.y) {}

	Point::Point(double _x, double _y) : x(_x), y(_y) {}

	Point& Point::operator=(const Point& other) {
		if (&other == this) {
			return *this;
		}
		x = other.x;
		y = other.y;
		return *this;
	}

	std::ostream& operator<<(std::ostream& cout, const Point& point) {
		cout << '(' << point.getX() << ';' << point.getY() << ')';
		return cout;
	}
}