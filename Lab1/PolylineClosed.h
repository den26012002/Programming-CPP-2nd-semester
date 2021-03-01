#pragma once
#include"Polyline.h"

namespace geometry {
	class PolylineClosed : public Polyline {
	public:
		double getPerimeter() const override;

		PolylineClosed(const PolylineClosed&);
		PolylineClosed(const std::vector<Point>&, int = -1);
		PolylineClosed();

		PolylineClosed& operator=(const PolylineClosed&);
	private:
	};

	std::ostream& operator<<(std::ostream&, const PolylineClosed&);
}