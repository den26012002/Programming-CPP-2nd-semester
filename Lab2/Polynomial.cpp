#include<string>
#include<algorithm>
#include"Polynomial.h"

int Polynomial::degree() const {
	return std::max(size - 1, 0);
}

Polynomial::Polynomial(const Polynomial& other) : coefficients(other.coefficients), size(other.size) {}

Polynomial::Polynomial(const std::vector<double> _coefficients) : coefficients(_coefficients), size(_coefficients.size()) {
	while (size > 0 && _coefficients[size - 1] == 0) {
		--size;
	}
}

Polynomial::Polynomial() : size(0) {}

Polynomial& Polynomial::operator=(const Polynomial& other) {
	if (this == &other) {
		return *this;
	}
	size = other.size;
	coefficients.resize(other.size);
	for (int i(0); i < other.size; ++i) {
		coefficients[i] = other.coefficients[i];
	}
	return *this;
}

Polynomial& Polynomial::operator+=(const Polynomial& other) {
	if (other.size > size) {
		size = other.size;
		coefficients.resize(other.size);
	}
	for (int i(0); i < other.size; ++i) {
		coefficients[i] += other.coefficients[i];
	}
	return *this;
}

Polynomial& Polynomial::operator-=(const Polynomial& other) {
	return (*this += -other);
}

Polynomial& Polynomial::operator*=(const Polynomial& other) {
	Polynomial ans;
	ans.size = size + other.size - 1;
	ans.coefficients.resize(ans.size);
	for (int i(0); i < size; ++i) {
		for (int j(0); j < other.size; ++j) {
			ans.coefficients[i + j] += coefficients[i] * other.coefficients[j];
		}
	}
	return (*this = ans);
}

Polynomial& Polynomial::operator/=(double divisor) {
	for (int i(0); i < size; ++i) {
		coefficients[i] /= divisor;
	}
	return *this;
}

double& Polynomial::operator[](int index) {
	if (index > size || index < 0) {
		throw "";
	}
	return coefficients[index];
}

const double& Polynomial::operator[](int index) const {
	if (index > size || index < 0) {
		throw "";
	}
	return coefficients[index];
}

bool operator==(const Polynomial& polynom1, const Polynomial& polynom2) {
	if (polynom1.degree() != polynom2.degree()) {
		return false;
	}
	for (int i(0); i < polynom1.degree(); ++i) {
		if (polynom1[i] != polynom2[i]) {
			return false;
		}
	}
	return true;
}

bool operator!=(const Polynomial& polynom1, const Polynomial& polynom2) {
	return !(polynom1 == polynom2);
}

Polynomial operator+(const Polynomial& polynom) {
	return polynom;
}

Polynomial operator-(const Polynomial& polynom) {
	Polynomial ans(polynom);
	for (int i(0); i < polynom.degree() + 1; ++i) {
		ans[i] *= -1;
	}
	return ans;
}

Polynomial operator+(Polynomial polynom1, const Polynomial& polynom2) {
	return (polynom1 += polynom2);
}

Polynomial operator-(Polynomial polynom1, const Polynomial& polynom2) {
	return (polynom1 -= polynom2);
}

Polynomial operator*(Polynomial polynom1, const Polynomial& polynom2) {
	return (polynom1 *= polynom2);
}

Polynomial operator/(Polynomial polynom, double divisor) {
	return (polynom /= divisor);
}

std::ostream& operator<<(std::ostream& cout, const Polynomial& polynom) {
	for (int i(polynom.degree()); i >= 0; --i) {
		if (i != polynom.degree()) {
			if (polynom[i] > 0) {
				cout << '+';
			}
		}
		if (polynom[i] < 0) {
			cout << '-';
		}
		if (polynom[i] != 0 || polynom.degree() == 0) {
			if (std::abs(polynom[i]) != 1 || i == 0) {
				cout << std::abs(polynom[i]);
			}
			if (i != 0) {
				cout << 'x';
				if (i > 1) {
					cout << '^' << i;
				}
			}
		}
	}
	return cout;
}

std::istream& operator>>(std::istream& cin, Polynomial& polynom) {
	polynom.coefficients.clear();
	polynom.size = 0;
	std::string polynomStr;
	std::getline(cin, polynomStr);
	std::string copyPolynomStr;
	for (int i(0); i < polynomStr.size(); ++i) {
		if (polynomStr[i] != ' ' && polynomStr[i] != '\t') {
			copyPolynomStr += polynomStr[i];
		}
	}
	polynomStr = copyPolynomStr;

	for (int i(0); i < polynomStr.size();) {
		bool wasNumb = false;
		bool isNegative = false;
		int coefficientNow = 0;
		while (i < polynomStr.size() && polynomStr[i] != 'x' && !(polynomStr[i] >= '0' && polynomStr[i] <= '9')) {
			if (polynomStr[i] == '-') {
				isNegative = !isNegative;
			} else if (polynomStr[i] == '+') {}
			else {
				throw "Input error";
			}
			++i;
		}
		while (i < polynomStr.size() && (polynomStr[i] >= '0' && polynomStr[i] <= '9')) {
			wasNumb = true;
			coefficientNow *= 10;
			coefficientNow += polynomStr[i] - '0';
			++i;
		}
		if (i < polynomStr.size() && polynomStr[i] == '*') {
			++i;
			if (i >= polynomStr.size() || polynomStr[i] != 'x') {
				throw "Input error";
			}
		}
		if (i < polynomStr.size() && polynomStr[i] != 'x') {
			throw "Input error";
		}
		int degree = 0;
		if (i < polynomStr.size() && polynomStr[i] == 'x') {
			if (!wasNumb) {
				coefficientNow = 1;
			}
			if (isNegative) {
				coefficientNow *= -1;
			}
			++i;
			if (i < polynomStr.size() && polynomStr[i] == '^') {
				++i;
			}
			while (i < polynomStr.size() && (polynomStr[i] >= '0' && polynomStr[i] <= '9')) {
				degree *= 10;
				degree += polynomStr[i] - '0';
				++i;
			}
			if (degree == 0) {
				degree = 1;
			}
		}
		if (degree >= polynom.degree()) {
			polynom.coefficients.resize(degree + 1);
			polynom.size = degree + 1;
		}
		polynom[degree] += coefficientNow;
	}
	while (polynom.size > 0 && polynom.coefficients[polynom.size - 1] == 0) {
		--polynom.size;
	}
	return cin;
}