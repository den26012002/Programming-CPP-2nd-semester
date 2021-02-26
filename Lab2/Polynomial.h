#pragma once
#include<iostream>
#include<vector>

class Polynomial {
public:
	int degree() const;

	Polynomial(const Polynomial&);
	explicit Polynomial(const std::vector<double>);
	Polynomial();

	Polynomial& operator=(const Polynomial&);
	Polynomial& operator+=(const Polynomial&);
	Polynomial& operator-=(const Polynomial&);
	Polynomial& operator*=(const Polynomial&);
	Polynomial& operator/=(double);
	double& operator[](int);
	const double& operator[](int) const;
	friend std::istream& operator>>(std::istream&, Polynomial&);

	~Polynomial() = default;
private:
	std::vector<double> coefficients;
	int size;
};

bool operator==(const Polynomial&, const Polynomial&);

bool operator!=(const Polynomial&, const Polynomial&);

Polynomial operator+(const Polynomial&);

Polynomial operator-(const Polynomial&);

Polynomial operator+(Polynomial, const Polynomial&);

Polynomial operator-(Polynomial, const Polynomial&);

Polynomial operator*(Polynomial, const Polynomial&);

Polynomial operator/(Polynomial, double);

std::ostream& operator<<(std::ostream&, const Polynomial&);

std::istream& operator>>(std::istream&, Polynomial&);