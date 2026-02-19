#include "Circle.h"
#include <cmath>

using namespace std;

const double PI = 3.141592653589793;

// Конструктори
Circle::Circle() : x(0), y(0), R(1) {}

Circle::Circle(double xVal, double yVal, double rVal)
{
    Init(xVal, yVal, rVal);
}

double Circle::GetX() const { return x; }
double Circle::GetY() const { return y; }
double Circle::GetR() const { return R; }

void Circle::SetX(double value)
{
    x = value;
}

void Circle::SetY(double value)
{
    y = value;
}

void Circle::SetR(double value)
{
    if (value <= 0)
    {
        cout << "Error!" << endl;
        exit(1);
    }
    R = value;
}

// Init
void Circle::Init(double xVal, double yVal, double rVal)
{
    SetX(xVal);
    SetY(yVal);
    SetR(rVal);
}

// Read
void Circle::Read()
{
    double xVal, yVal, rVal;
    cout << "enter x: ";
    cin >> xVal;
    cout << "enter y: ";
    cin >> yVal;
    cout << "enter R: ";
    cin >> rVal;

    Init(xVal, yVal, rVal);
}

// Display
void Circle::Display() const
{
    cout << "Centr: (" << x << ", " << y << ")" << endl;
    cout << "Radius: " << R << endl;
    cout << "Area: " << Area() << endl;
    cout << "Lenth: " << Circumference() << endl;
}

double Circle::Area() const
{
    return PI * R * R;
}

double Circle::Circumference() const
{
    return 2 * PI * R;
}

Circle makeCircle(double x, double y, double R)
{
    if (R <= 0)
    {
        cout << "Помилка! Радіус повинен бути > 0." << endl;
        exit(1);
    }

    return Circle(x, y, R);
}
