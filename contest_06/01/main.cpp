#include <cmath>

class Shape {
public:
	virtual double getPerimeter() {
		return 0;
	}
};

class Rectangle : public Shape {
protected:
	int length;
	int width;
public:
	Rectangle(int a, int b) : length(a), width(b) {}

	double getPerimeter() override {
		return 2 * (length + width);
	}
};

class Circle : public Shape {
protected:
	int radius;
public:
	Circle(int r) : radius(r) {}

	double getPerimeter() override {
		return 2 * M_PI * radius;
	}
};

class Triangle : public Shape {
protected:
	int side1;
	int side2;
	int side3;
public:
	Triangle(int a, int b, int c) : side1(a), side2(b), side3(c) {}

	double getPerimeter() override {
		if (side1 + side2 > side3 && side1 + side3 > side2 && side2 + side3 > side1) {
			return side1 + side2 + side3;
		}
		else {
			return 0;
		}
	}
};
