#include"Triangle.h"
#include"Vector2.h"
#include"Polygon.h"
#include"GeometryException.h"

namespace geometry {
	double Polygon::getSquare() const {
		double ans = 0;
		for (int i(1); i < getSize() - 1; ++i) {
			ans += Triangle(getPoint(0), getPoint(i), getPoint(i + 1)).getSquare();
		}
		return ans;
	}

	Polygon::Polygon(const Polygon& other) : PolylineClosed::PolylineClosed(other) {}

	Polygon::Polygon(const std::vector<Point>& _points, int n) {
		if (n == -1 || n > _points.size()) {
			n = _points.size();
		}
		for (int i(0); i < n; ++i) {
			if (!addPoint(_points[i])) {
				//throw "You've tried to create non-polygon";
				throw polygonException;
			}
		}
	}

	Polygon::Polygon() : PolylineClosed::PolylineClosed() {}

	Polygon& Polygon::operator=(const Polygon& other) {
		PolylineClosed::operator=(other);
		return *this;
	}

	bool Polygon::addPoint(const Point& point) {
		if (getSize() < 3) {
			PolylineClosed::addPoint(point);
		}
		else {
			Vector2 ab(getPoint(getSize() - 2), getPoint(getSize() - 1));
			Vector2 bc(getPoint(getSize() - 1), point);
			Vector2 cd(point, getPoint(0));
			Vector2 de(getPoint(0), getPoint(1));
			if (rotationDirection(ab, bc) * rotationDirection(bc, cd) > 0 &&
				rotationDirection(bc, cd) * rotationDirection(cd, de) > 0) {

				PolylineClosed::addPoint(point);
			}
			else {
				return false;
			}
		}
	}
}