#pragma once
#include"Point.h"

namespace geometry {
	class Line {
	public:
		double getLenght() const;
		const Point& getPoint(int) const;

		Line(const Line&);
		Line(Point, Point);

		Line& operator=(const Line&);
	private:
		Point points[2];
	};
}