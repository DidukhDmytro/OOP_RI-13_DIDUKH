#include"Pair.h"
#include<iostream>
#include<string>

void Pair::setFirst(double value) {
	if (value > 0)
	{
		this->first = value;
	}
	else
	{
		first = 1;
	}
}
void Pair::setSecond(double value) {
	if (value > 0)
	{
		this->second = value;
	}
	else
	{
		second = 1;
	}
}

bool Pair::Init(double f, double s) {
	if (f > 0 && s > 0)
	{
		this->first = f;
		this->second = s;
		return true;
	}
	return false;
}

void Pair::Read() {
	double f, s;
	do
	{
		std::cout << "Enter first number (>0): "; std::cin >> f;
		std::cout << "Enter second number (>0): "; std::cin >> s;
	} while (!Init(f, s));
}

void Pair::Display() const {
	std::cout << toString() << std::endl;
}

std::string Pair::toString() const {
	return "First: " + std::to_string(first) + ", Second: " + std::to_string(second);
}

double Pair::multiply() const {
	return first * second;
}