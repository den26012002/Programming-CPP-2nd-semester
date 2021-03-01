#include<math.h>
#include<algorithm>
#include"Line.h"

namespace geometry {
	double Line::getLenght() const {
		return sqrt(pow(points[0].getX() - points[1].getX(), 2) + pow(points[0].getY() - points[1].getY(), 2));
	}

	const Point& Line::getPoint(int pointNumb) const {
		pointNumb = std::max(0, pointNumb);
		pointNumb = std::min(1, pointNumb);
		return points[pointNumb];
	}

	Line::Line(const Line& other) {
		for (int i = 0; i < 2; i++) {
			points[i] = other.points[i];
		}
	}

	Line::Line(Point p0, Point p1) {
		points[0] = p0;
		points[1] = p1;
	}

	Line& Line::operator=(const Line& other) {
		if (&other == this) {
			return *this;
		}
		for (int i = 0; i < 2; i++) {
			points[i] = other.points[i];
		}
		return *this;
	}
}