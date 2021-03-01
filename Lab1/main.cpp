#include<iostream>
#include<vector>
#include<string>
#include"Point.h"
#include"PolylineClosed.h"
#include"Triangle.h"
#include"Polygon.h"
#include"PolygonRegular.h"
#include"Trapezium.h"

int main() {
	try {
		using namespace geometry;
		std::vector<Point> points(10);
		points[0] = Point(0, 0);
		points[1] = Point(0, 25);
		points[2] = Point(25, 25);
		points[3] = Point(25, 0);
		points[4] = Point(100, 10);
		PolygonRegular polygonRegular(points, 4);
		Polygon polygon(points, 3);
		Polyline polyline(points, 3);
		std::vector<Point> trapeziumPoints(4);
		trapeziumPoints[0] = Point(0, 0);
		trapeziumPoints[1] = Point(10, 0);
		trapeziumPoints[2] = Point(9, 10);
		trapeziumPoints[3] = Point(0, 10);
		Trapezium trapezium(trapeziumPoints);
		PolylineClosed polylineClosed(points, 5);
		Triangle triangle(trapeziumPoints);
		Polyline* ptr[7];
		ptr[0] = &polygonRegular;
		ptr[1] = &polygon;
		ptr[2] = &polyline;
		ptr[3] = &trapezium;
		ptr[4] = &polygonRegular;
		ptr[5] = &polylineClosed;
		ptr[6] = &triangle;
		for (int i(0); i < 7; ++i) {
			std::cout << ptr[i]->getPerimeter() << ' ' << ptr[i]->getSquare() << '\n';
		}
	} catch (geometry::GeometryException& error) {
		std::cerr << error.what();
	} catch (std::exception& error) {
		std::cerr << error.what();
	}



	return 0;
}