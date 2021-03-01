#pragma once
#include"Polygon.h"
#include"GeometryException.h"

namespace geometry {
	class Trapezium : public Polygon {
	public:
		Trapezium(const Trapezium&);
		Trapezium(const std::vector<Point>&);
		Trapezium(const Point&, const Point&, const Point&, const Point&);
		Trapezium() = delete;

		Trapezium& operator=(const Trapezium&);
	private:
	};

	const GeometryException trapeziumException("trapezium");
}