#pragma once
#include<string>

class Pair {
private:
	double first;
	double second;
public:
	double getFirst() const {
		return first;
	}
	double getSecond() const {
		return second;
	}

	void setFirst(double value);
	void setSecond(double value);

	bool Init(double f, double s);
	void Read();
	void Display() const;
	std::string toString() const;

	double multiply() const;
};