#pragma once
#include "IProgression.h"

class GeometricProgression : public IProgression {
private:
    double a; 
    double r; 
public:
    GeometricProgression(double a, double r);

    double sum(int n) override;
    void showType() override;
};