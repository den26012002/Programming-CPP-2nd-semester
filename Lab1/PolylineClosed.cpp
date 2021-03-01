#include"Line.h"
#include"PolylineClosed.h"

namespace geometry {
	double PolylineClosed::getPerimeter() const {
		double ans = 0;
		for (int i(0); i < getSize(); ++i) {
			ans += Line(getPoint(i), getPoint((i + 1) % getSize())).getLenght();
		}
		return ans;
	}

	PolylineClosed::PolylineClosed(const PolylineClosed& other) : Polyline::Polyline(other) {}

	PolylineClosed::PolylineClosed(const std::vector<Point>& _points, int n) : Polyline::Polyline(_points, n) {}

	PolylineClosed::PolylineClosed() : Polyline::Polyline() {}

	PolylineClosed& PolylineClosed::operator=(const PolylineClosed& other) {
		Polyline::operator=(other);
		return *this;
	}

	std::ostream& operator<<(std::ostream& cout, const PolylineClosed& polylineClosed) {
		cout << (Polyline)polylineClosed;
		return cout;
	}
}