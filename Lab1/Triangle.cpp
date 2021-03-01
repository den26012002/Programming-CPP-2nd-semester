#include<math.h>
#include"Line.h" 
#include"Triangle.h"

namespace geometry {
	double Triangle::getSquare() const {
		double sides[3];
		double p = 0;
		for (int i(0); i < 3; ++i) {
			sides[i] = Line(getPoint(i), getPoint((i + 1) % 3)).getLenght();
			p += sides[i];
		}
		p /= 2;
		int ans = p;
		for (int i(0); i < 3; ++i) {
			ans *= (p - sides[i]);
		}
		return std::sqrt(ans);
	}

	Triangle::Triangle(const Triangle& other) : PolylineClosed::PolylineClosed(other) {}

	Triangle::Triangle(const std::vector<Point>& _points) : PolylineClosed::PolylineClosed(_points, 3) {}

	Triangle::Triangle(const Point& p1, const Point& p2, const Point& p3) : PolylineClosed::PolylineClosed(std::vector<Point>({ p1, p2, p3 }), 3) {}

	//Triangle::Triangle() : PolylineClosed::PolylineClosed() {}

	Triangle& Triangle::operator=(const Triangle& other) {
		PolylineClosed::operator=(other);
		return *this;
	}
}