#pragma once
#include<vector>
#include"Point.h"

namespace geometry {
	class Polyline {
	public:
		virtual double getPerimeter() const;
		virtual double getSquare() const;
		const Point& getPoint(int) const;
		int getSize() const;

		Polyline(const Polyline&);
		Polyline(const std::vector<Point>&, int = -1);
		Polyline();

		Polyline& operator=(const Polyline&);

		virtual ~Polyline();
	protected:
		bool addPoint(const Point&);
	private:
		std::vector<Point> points;
		int size;
	};

	std::ostream& operator<<(std::ostream&, const Polyline&);
}