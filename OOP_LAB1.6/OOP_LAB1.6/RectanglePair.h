#pragma once
#include<string>

class Rectangle {
public:
	class Pair {
	private:
		double first;
		double second;
	public:
		Pair();
		Pair(double f, double s);

		void setFirst(double value);
		void setSecond(double value);
		double getFirst() const {
			return first;
		}
		double getSecond() const {
			return second;
		}

		bool Init(double f, double s);
		void Read();
		void Display() const;
		std::string toString() const;

		double multiply() const;
	};
private:
	Pair sides;
public:
	Rectangle();
	Rectangle(double a, double b);

	Pair getSides() const {
		return sides;
	}
	bool setSides(double a, double b);
	bool Init(double a, double b);
	void Read();
	void Display() const;
	std::string toString() const;

	double Area() const;
	double Perimeter() const;
};