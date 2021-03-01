#include<math.h>
#include"common.h"
#include"Vector2.h"

namespace geometry {
	double Vector2::getX() const {
		return x;
	}

	double Vector2::getY() const {
		return y;
	}

	double Vector2::getLength() const {
		return std::sqrt(x * x + y * y);
	}

	Vector2::Vector2(const Vector2& other) : x(other.x), y(other.y) {}

	Vector2::Vector2(double _x, double _y) : x(_x), y(_y) {}

	Vector2::Vector2(const Point& start, const Point& end) : x(end.getX() - start.getX()), y(end.getY() - start.getY()) {}

	Vector2& Vector2::operator=(const Vector2& other) {
		x = other.x;
		y = other.y;
		return *this;
	}

	Vector2& Vector2::operator+=(const Vector2& other) {
		x += other.x;
		y += other.y;
		return *this;
	}

	Vector2& Vector2::operator-=(const Vector2& other) {
		x -= other.x;
		y -= other.y;
		return *this;
	}

	double Vector2::operator*=(const Vector2& other) {
		return (x * other.x + y * other.y);
	}

	Vector2 operator+(Vector2 vect1, const Vector2& vect2) {
		return vect1 += vect2;
	}

	Vector2 operator-(Vector2 vect1, const Vector2& vect2) {
		return vect1 -= vect2;
	}

	double operator*(Vector2 vect1, const Vector2& vect2) {
		return vect1 *= vect2;
	}

	double rotationDirection(const Vector2& vect1, const Vector2& vect2) {
		return vect1.getX() * vect2.getY() - vect1.getY() * vect2.getX();
	}

	double angle(const Vector2& vect1, const Vector2& vect2) {
		return std::acos((vect1 * vect2) / (vect1.getLength() * vect2.getLength()));
	}

	bool isParallel(const Vector2& vect1, const Vector2& vect2) {
		return (isEquals(angle(vect1, vect2), 0) || isEquals(angle(vect1, vect2), std::acos(-1)));
	}
}