#include<iostream>
#include"Rectangle.h"

bool Rectangle::Init(double a, double b) {
	return sides.Init(a, b);
}

void Rectangle::Read() {
	std::cout << "Entering sides of rectangle:" << std::endl;
	sides.Read();
}

void Rectangle::Display() const {
	std::cout << "Rectangle [" << sides.toString() << "]" << std::endl;
}

std::string Rectangle::toString() const {
	return "Rectangle with sides: " + sides.toString();
}

double Rectangle::Perimetr() const {
	return 2 * (sides.getFirst() + sides.getSecond());
}

double Rectangle::Area() const {
	return sides.multiply();
}