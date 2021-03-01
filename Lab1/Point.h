#pragma once
#include<iostream>

namespace geometry {
	class Point {
	public:
		double getX() const;
		double getY() const;
		//double getCoordinate(int coordNumb) const;

		Point(const Point&);
		explicit Point(double = 0, double = 0);

		Point& operator=(const Point&);
	private:
		double x;
		double y;
	};

	std::ostream& operator<<(std::ostream&, const Point&);
}