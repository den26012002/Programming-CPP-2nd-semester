#include<math.h>
#include"Vector2.h"
#include"common.h"
#include"PolygonRegular.h"

namespace geometry {
	double PolygonRegular::getSquare() const {
		return getSize() * std::pow(Vector2(getPoint(0), getPoint(1)).getLength(), 2) / (4 * std::tan(std::acos(-1) / getSize()));
	}

	PolygonRegular::PolygonRegular(const PolygonRegular& other) : Polygon::Polygon(other), regularAngle(other.regularAngle) {}

	PolygonRegular::PolygonRegular(const std::vector<Point>& _points, int n) {
		if (n == -1 || n > _points.size()) {
			n = _points.size();
		}
		if (n == 0) {
			regularAngle = 0;
		}
		else {
			regularAngle = std::acos(-1) * (n - 2) / n;
		}
		for (int i(0); i < n; ++i) {
			if (!addPoint(_points[i])) {
				//throw "You've tried to create a non-regular polygon";
				throw polygonRegularException;
			}
		}
	}

	PolygonRegular::PolygonRegular() : Polygon::Polygon(), regularAngle(0) {}

	PolygonRegular& PolygonRegular::operator=(const PolygonRegular& other) {
		Polygon::operator=(other);
		return *this;
	}

	bool PolygonRegular::addPoint(const Point& point) {
		if (getSize() < 2) {
			return Polyline::addPoint(point);
		}
		else {
			Vector2 ba(getPoint(getSize() - 1), getPoint(getSize() - 2));
			Vector2 bc(getPoint(getSize() - 1), point);
			if (isEquals(angle(ba, bc), regularAngle) &&
				isEquals(ba.getLength(), bc.getLength())) {

				return Polygon::addPoint(point);
			}
			else {
				return false;
			}
		}
	}
}