#pragma once
#include"Polygon.h"
#include"GeometryException.h"

namespace geometry {
	class PolygonRegular : public Polygon {
	public:
		double getSquare() const override;

		PolygonRegular(const PolygonRegular&);
		PolygonRegular(const std::vector<Point>&, int = -1);
		PolygonRegular();

		PolygonRegular& operator=(const PolygonRegular&);
	protected:
		bool addPoint(const Point&);
	private:
		double regularAngle;
	};

	const GeometryException polygonRegularException("regular polygon");
}