#pragma once

class Progression {
protected:
    double a;
    double d;

public:
    Progression(double a, double d);

    virtual double sum(int n) = 0;
    virtual void showType() = 0;

    virtual ~Progression();
};