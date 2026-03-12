#pragma once
#include<iostream>
#include<string>


class Matrix {
private:
	int** data;
	int rows;
	int cols;

	void allocateMemory(int r, int c);
	void freeMemory();
	void copyFrom(const Matrix& other);

public:
	Matrix();
	Matrix(int n);
	Matrix(int r, int c);
	Matrix(const Matrix& other);

	~Matrix();

	int getRows() const;
	int getCols() const;
	int getElement(int r, int c) const;

	void setRows(int r);
	void setCols(int c);
	void setElement(int r, int c, int value);

	void resize(int r, int c);

	Matrix& operator=(const Matrix& other);
	Matrix operator-() const; // унарний мінус
	Matrix& operator+=(const Matrix& other);
	Matrix& operator-=(const Matrix& other);
	Matrix& operator*=(const Matrix& other);

	operator std::string() const;

	friend Matrix operator+(const Matrix& a, const Matrix& b);
	friend Matrix operator-(const Matrix& a, const Matrix& b);
	friend Matrix operator*(const Matrix& a, const Matrix& b);

	friend std::istream& operator>>(std::istream& in, Matrix& m);
	friend std::ostream& operator<<(std::ostream& out, const Matrix& m);
};