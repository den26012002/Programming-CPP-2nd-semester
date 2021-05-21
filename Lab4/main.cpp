#include<iostream>
//#include<algorithm>
#include<vector>
#include<map>
#include"mystl.h"

struct Point {
	int x, y;
};

bool cmp(const Point& p1, const Point& p2) {
	return ((p1.x * p1.x) + (p1.y * p1.y) < (p2.x * p2.x) + (p2.y * p2.y));
}

bool f(int a, int b) {
	return a < b;
}

bool palindrome(int a, int b) {
	return (a == b);
}

class F {
public:
	bool operator()(int a) {
		return std::rand() % 2;
	}
};

template<typename Type>
std::ostream& operator<<(std::ostream& cout, std::vector<Type> arr) {
	for (int i(0); i < arr.size(); ++i) {
		cout << arr[i] << ' ';
	}
	return cout;
}

int main() {
	std::vector<Point> arr(10);
	for (int i(0); i < 10; ++i) {
		arr[i] = {i, i};
	}
	arr[0] = { 10, 10 };
	F func;
	//std::cout << arr;
	std::cout << is_sorted(arr.begin(), arr.end(), cmp) << '\n';


	return 0;
}
