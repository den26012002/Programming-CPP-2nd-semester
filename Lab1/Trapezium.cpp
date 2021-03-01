#include"Vector2.h"
#include"Trapezium.h"

namespace geometry {
	Trapezium::Trapezium(const Trapezium& other) : Polygon::Polygon(other) {}

	Trapezium::Trapezium(const std::vector<Point>& _points) {
		Vector2 ab(_points[0], _points[1]);
		Vector2 bc(_points[1], _points[2]);
		Vector2 cd(_points[2], _points[3]);
		Vector2 da(_points[0], _points[3]);
		if ((isParallel(ab, cd) && !isParallel(bc, da)) ||
			(!isParallel(ab, cd) && isParallel(bc, da))) {

			for (int i(0); i < 4; ++i) {
				if (!addPoint(_points[i])) {
					//throw "You've tried to create a non-polygon";
					throw polygonException;
				}
			}
		}
		else {
			//throw "You've tried to create a non-trapezium";
			throw trapeziumException;
		}
	}

	Trapezium::Trapezium(const Point& p1, const Point& p2, const Point& p3, const Point& p4)
		: Trapezium::Trapezium(std::vector<Point>({ p1, p2, p3, p4 })) {}

	//Trapezium::Trapezium() : Polygon::Polygon() {}

	Trapezium& Trapezium::operator=(const Trapezium& other) {
		Polygon::operator=(other);
		return *this;
	}
}