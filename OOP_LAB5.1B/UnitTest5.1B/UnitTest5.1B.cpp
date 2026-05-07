#include"pch.h"
#include "CppUnitTest.h"
#include <cmath>
#include <stdexcept>
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

class Point {
private:
    double x, y;
public:
    Point() : x(0), y(0) {}
    Point(double x, double y) {
        if (std::abs(x) > 10000 || std::abs(y) > 10000) throw std::invalid_argument("err");
        this->x = x; this->y = y;
    }
    double getX() const { return x; }
    double getY() const { return y; }
    Point& operator ++ () { ++x; ++y; return *this; }
    friend double operator - (const Point& p1, const Point& p2) {
        return std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2));
    }
};

namespace PointTests {
    TEST_CLASS(PointOperationTests) {
public:
    TEST_METHOD(ConstructorTest) {
        Point p(3, 4);
        Assert::AreEqual(3.0, p.getX());
        Assert::AreEqual(4.0, p.getY());
    }
    TEST_METHOD(DistanceTest) {
        Point p1(0, 0), p2(3, 4);
        Assert::AreEqual(5.0, p2 - p1);
    }
    TEST_METHOD(IncrementTest) {
        Point p(1, 1);
        ++p;
        Assert::AreEqual(2.0, p.getX());
    }
    TEST_METHOD(ExceptionTest) {
        Assert::ExpectException<std::invalid_argument>([] { Point p(20000, 0); });
    }
    };
}