#pragma once
#include <iostream>
#include <string>
#include <sstream>

class Point {
private:
    double x;
    double y;

public:
    Point();                               
    Point(double x, double y);             
    Point(const Point& other);            

    void setX(double value);
    void setY(double value);
    double getX() const { return x; }
    double getY() const { return y; }

    bool Init(double x, double y);
    void Read();
    void Display() const;
    std::string toString() const;

    void moveX(double delta);
    void moveY(double delta);
    static double distance(const Point& p1, const Point& p2);

    Point& operator = (const Point& other);
    operator std::string() const;         

    Point& operator ++ ();                 
    Point operator ++ (int);               
    Point& operator -- ();                 
    Point operator -- (int);               

    friend std::ostream& operator << (std::ostream& out, const Point& p);
    friend std::istream& operator >> (std::istream& in, Point& p);
    friend double operator - (const Point& p1, const Point& p2); 
};