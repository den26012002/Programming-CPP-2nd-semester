#pragma once
#include"Point.h"

namespace geometry {
	class Vector2 {
	public:
		double getX() const;
		double getY() const;
		double getLength() const;

		Vector2(const Vector2&);
		explicit Vector2(double = 0, double = 0);
		Vector2(const Point&, const Point&);

		Vector2& operator=(const Vector2&);
		Vector2& operator+=(const Vector2&);
		Vector2& operator-=(const Vector2&);
		double operator*=(const Vector2&);
	private:
		double x;
		double y;
	};

	Vector2 operator+(Vector2, const Vector2&);

	Vector2 operator-(Vector2, const Vector2&);

	double operator*(Vector2, const Vector2&);

	double rotationDirection(const Vector2&, const Vector2&);

	double angle(const Vector2&, const Vector2&);

	bool isParallel(const Vector2&, const Vector2&);
}