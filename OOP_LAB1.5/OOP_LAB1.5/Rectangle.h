#pragma once
#include"Pair.h"

class Rectangle {
private:
	Pair sides;
public:
	Pair getSides() const {
		return sides;
	}
	Pair setSides(Pair value) {
		sides = value;
	}

	bool Init(double a, double b);
	void Read();
	void Display() const;
	std::string toString() const;

	double Area() const;
	double Perimetr() const;
};