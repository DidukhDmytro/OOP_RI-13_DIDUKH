#include"Matrix.h"
#include<iostream>
#include<sstream>
#include<stdexcept>

void Matrix::allocateMemory(int r, int c) {
	if (r <= 0 || c <= 0) {
		rows = 0;
		cols = 0;
		data = nullptr;
		return;
	}

	rows = r;
	cols = c;

	data = new int* [rows];
	for (int i = 0; i < rows; i++){
		data[i] = new int[cols];
		for ( int j = 0; j < cols; j++){
			data[i][j] = 0;
		}
	}
}

void Matrix::freeMemory() {
	if (data != nullptr) {
		for (int i = 0; i < rows; i++) {
			delete[] data[i];
		}
		delete[] data;
	}

	data = nullptr;
	rows = 0;
	cols = 0;
}

void Matrix::copyFrom(const Matrix& other) {
	allocateMemory(other.rows, other.cols);

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			data[i][j] = other.data[i][j];
		}
	}
}

Matrix::Matrix() {
	data = nullptr;
	rows = 0;
	cols = 0;
}

Matrix::Matrix(int n) {
	data = nullptr;
	rows = 0;
	cols = 0;

	if (n > 0) {
		allocateMemory(n, n);
	}
}

Matrix::Matrix(int r, int c) {
	data = nullptr;
	rows = 0;
	cols = 0;

	if (r > 0 && c > 0) {
		allocateMemory(r, c);
	}
}

Matrix::Matrix(const Matrix& other) {
	data = nullptr;
	rows = 0;
	cols = 0;

	copyFrom(other);
}

Matrix::~Matrix() {
	freeMemory();
}

int Matrix::getRows() const{
	return rows;
}

int Matrix::getCols() const{
	return cols;
}

int Matrix::getElement(int r, int c)const {
	if (r < 0 || r >= rows || c < 0 || c >= cols) {
		throw std::out_of_range("Index out of range");
	}

	return data[r][c];
}

void Matrix::setRows(int r){
	if (r > 0)
		resize(r, cols == 0 ? 1 : cols);
}

void Matrix::setCols(int c){
	if (c > 0)
		resize(rows == 0 ? 1 : rows, c);
}

void Matrix::setElement(int r, int c, int value){
	if (r < 0 || r >= rows || c < 0 || c >= cols)
		throw std::out_of_range("Index out of range");

	data[r][c] = value;
}

void Matrix::resize(int r, int c) {
	if (r <= 0 || c <= 0) {
		return;
	}
	
	Matrix temp(r, c);

	int minRows = (rows < r) ? rows : r;
	int minCols = (cols < c) ? cols : c;

	for (int i = 0; i < minRows; i++) {
		for (int j = 0; j < minCols; j++) {
			temp.data[i][j] = data[i][j];
		}
	}
	*this = temp;
}

Matrix& Matrix::operator=(const Matrix& other) {
	if (this != &other) {
		freeMemory();
		copyFrom(other);
	}
	return *this;
}

Matrix Matrix::operator-() const {
	Matrix result(rows, cols);

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			result.data[i][j] = -data[i][j];
		}
	}
	return result;
}


Matrix& Matrix::operator+=(const Matrix& other) {
	if (rows != other.rows || cols != other.cols)
		throw std::invalid_argument("Matrix must have same dimensions to be added");

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			data[i][j] += other.data[i][j];
		}
	}
	return *this;
}

Matrix& Matrix::operator-=(const Matrix& other) {
	if (rows != other.rows || cols != other.cols)
		throw std::invalid_argument("Matrix must have same dimensions to be substracted");

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			data[i][j] -= other.data[i][j];
		}
	}
	return *this;
}

Matrix& Matrix::operator*=(const Matrix& other) {
	*this = (*this) * other;
	return *this;
}

Matrix::operator std::string() const {
	std::ostringstream sout;

	sout << "Matrix (" << rows << "x" << cols << "):\n";
	for (int i = 0; i < rows; i++){
		for (int j = 0; j < cols; j++){
			sout << data[i][j] << "\t";
		}
		sout << "\n";
	}

	return sout.str();
}

Matrix operator+(const Matrix& a, const Matrix& b) {
	if (a.rows != b.rows || a.cols != b.cols) {
		throw std::invalid_argument("Matrix must have same dimension to be added");
	}

	Matrix result(a.rows, a.cols);

	for (int i = 0; i < a.rows; i++) {
		for (int j = 0; j < a.cols; j++) {
			result.data[i][j] = a.data[i][j] + b.data[i][j];
		}
	}
	return result;
}

Matrix operator-(const Matrix& a, const Matrix& b) {
	if (a.rows != b.rows || a.cols != b.cols) {
		throw std::invalid_argument("Matrix must have same dimension to be substracted");
	}

	Matrix result(a.rows, a.cols);

	for (int i = 0; i < a.rows; i++) {
		for (int j = 0; j < a.cols; j++) {
			result.data[i][j] = a.data[i][j] - b.data[i][j];
		}
	}
	return result;
}

Matrix operator*(const Matrix& a, const Matrix& b) {
	if (a.cols != b.rows) {
		throw std::invalid_argument("Wrong dimension to be multiplied");
	}

	Matrix result(a.rows, a.cols);

	for (int i = 0; i < a.rows; i++) {
		for (int j = 0; j < b.cols; j++) {
			result.data[i][j] = 0;
			for (int k = 0; k < a.cols; k++) {
				result.data[i][j] += a.data[i][k] * b.data[k][j];
			}
		}
	}
	return result;
}

std::istream& operator>>(std::istream& in, Matrix& m) {
	int r, c;

	std::cout << "Enter a number of rows: "; in >> r;
	std::cout << "Enter a number of cols: "; in >> c;

	if (r <= 0 || c <= 0) {
		throw std::invalid_argument("Rows and cols must be positive");
	}

	m.resize(r, c);

	std::cout << "Enter matrix elements: \n";
	for (int i = 0; i < m.rows; i++) {
		for (int j = 0; j < m.cols; j++) {
			std::cout << "[" << i << "][" << j << "] = "; in >> m.data[i][j];
		}
	}
	return in;
}

std::ostream& operator<<(std::ostream& out, const Matrix& m) {
	out << "Matrix (" << m.rows << "x" << m.cols << "):\n";
	for (int i = 0; i < m.rows; i++) {
		for (int j = 0; j < m.cols; j++) {
			out << m.data[i][j] << "\t";
		}
		out << "\n";
	}
	return out;
}