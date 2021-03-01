#pragma once
#include"PolylineClosed.h"
#include"GeometryException.h"

namespace geometry {
	class Polygon : public PolylineClosed {
	public:
		double getSquare() const override;

		Polygon(const Polygon&);
		Polygon(const std::vector<Point>&, int = -1);
		Polygon();

		Polygon& operator=(const Polygon&);
	protected:
		bool addPoint(const Point&);
	private:
	};

	const GeometryException polygonException("polygon");
}