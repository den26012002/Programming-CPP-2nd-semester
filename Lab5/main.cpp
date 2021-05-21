#include<iostream>
#include<algorithm>
#include<vector>
#include<deque>
#include"RingBuffer.h"
#include"RingBufferException.h"

struct Point {
	int x, y;
};

std::ostream& operator<<(std::ostream& cout, const Point& p) {
	std::cout << '(' << p.x << ';' << p.y << ')';
	return cout;
}

bool cmp(const Point& p1, const Point& p2) {
	return ((p1.x * p1.x) + (p1.y * p1.y) < (p2.x * p2.x) + (p2.y * p2.y));
}

int main() {
	try {
		RingBuffer<Point> buffer(10);
		for (int i(0); i < 15; ++i) {
			buffer.push_back({ rand(), rand() });
		}
		RingBuffer<Point> buffer1 = buffer;
		//buffer1 = buffer;
		buffer1.front() = { 10, 20 };
		for (auto i : buffer1) {
			std::cout << i << ' ';
		}
		std::cout << '\n';
		std::sort(buffer.begin(), buffer.end(), cmp);
		for (auto i : buffer) {
			std::cout << i << ' ';
		}
	} catch (RingBufferException& err) {
		std::cerr << err.what();
	}
	
	return 0;
}