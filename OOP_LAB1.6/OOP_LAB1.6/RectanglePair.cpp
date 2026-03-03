#include<iostream>
#include<sstream>
#include<string>
#include"RectanglePair.h"

Rectangle::Pair::Pair() : first(1), second(1){}
Rectangle::Pair::Pair(double f, double s) {
    Rectangle::Pair::Init(f, s);
}   

void Rectangle::Pair::setFirst(double value) {
	if (value > 0)
	{
		this->first = value;
	}
}

void Rectangle::Pair::setSecond(double value) {
	if (value > 0)
	{
		this->second = value;
	}
}

bool Rectangle::Pair::Init(double f, double s) {
	if (f > 0 && s > 0)
	{
		this->first = f;
		this->second = s;
		return true;
	}
	return false;
}

void Rectangle::Pair::Read() {
	double f, s;
	std::cout << "Enter first number: "; std::cin >> f;
	std::cout << "Enter second number: "; std::cin >> s;
	Init(f, s);
}

void Rectangle::Pair::Display() const {
	std::cout << "First = " << first << " Second = " << second << std::endl;
}

std::string Rectangle::Pair::toString() const {
	std::stringstream ss;
	ss << "(" << first << ", " << second << ")";
	return ss.str();
}

double Rectangle::Pair::multiply() const {
	return first * second;
}

Rectangle::Rectangle(): sides(1, 1) {}
Rectangle::Rectangle(double a, double b) {
	Init(a, b);
}

bool Rectangle::setSides(double a, double b) {
	return sides.Init(a, b);
}

bool Rectangle::Init(double a, double b) {
	return sides.Init(a, b);
}

void Rectangle::Read() {
	sides.Read();
}

void Rectangle::Display() const {
	std::cout << "Rectangle sides: ";
	sides.Display();
	std::cout << "Perimeter = " << Perimeter() << std::endl;
	std::cout << "Area = " << Area() << std::endl;
}

std::string Rectangle::toString() const {
	std::stringstream ss;
	ss << "Rectangle sides: " << sides.toString()
		<< " P=" << Perimeter()
		<< " S=" << Area();
	return ss.str();
}
double Rectangle::Area() const {
	return sides.multiply();
}

double Rectangle::Perimeter() const {
	return 2 * (sides.getFirst() + sides.getSecond());
}