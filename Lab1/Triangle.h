#pragma once
#include"PolylineClosed.h"

namespace geometry {
	class Triangle : public PolylineClosed {
	public:
		double getSquare() const override;

		Triangle(const Triangle&);
		Triangle(const std::vector<Point>&);
		Triangle(const Point&, const Point&, const Point&);
		Triangle() = delete;

		Triangle& operator=(const Triangle&);
	private:
	};
}