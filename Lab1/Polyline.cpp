#include"Line.h"
#include"Polyline.h"

namespace geometry {
	double Polyline::getPerimeter() const {
		double ans = 0;
		for (int i(0); i < size - 1; ++i) {
			ans += Line(points[i], points[i + 1]).getLenght();
		}
		return ans;
	}

	double Polyline::getSquare() const {
		return 0;
	}

	const Point& Polyline::getPoint(int pointNumb) const {
		if (pointNumb >= size || pointNumb < 0) {
			std::cerr << "Warning: you've tried to access a imaginary point";
			if (pointNumb >= size) {
				std::cerr << " (you've accessed a point with number (size - 1))\n";
			}
			else {
				std::cerr << " (you've accessed a point with number (0))\n";
			}
		}
		pointNumb = std::max(0, pointNumb);
		pointNumb = std::min(size - 1, pointNumb);
		return points[pointNumb];
	}

	int Polyline::getSize() const {
		return size;
	}

	Polyline::Polyline(const Polyline& other) : size(other.size), points(other.points) {}

	Polyline::Polyline(const std::vector<Point>& _points, int n) {
		if (n == -1 || n > _points.size()) {
			n = _points.size();
		}
		size = n;
		points.resize(n);
		for (int i(0); i < n; ++i) {
			points[i] = _points[i];
		}
	}

	Polyline::Polyline() : size(0) {}

	Polyline& Polyline::operator=(const Polyline& other) {
		size = other.size;
		points.resize(size);
		for (int i(0); i < size; ++i) {
			points[i] = other.points[i];
		}
		return *this;
	}

	Polyline::~Polyline() {}

	bool Polyline::addPoint(const Point& point) {
		points.push_back(point);
		++size;
		return true;
	}

	std::ostream& operator<<(std::ostream& cout, const Polyline& polyline) {
		cout << '(';
		for (int i(0); i < polyline.getSize(); ++i) {
			cout << polyline.getPoint(i);
			if (i != polyline.getSize() - 1) {
				cout << ", ";
			}
		}
		cout << ')';
		return cout;
	}
}