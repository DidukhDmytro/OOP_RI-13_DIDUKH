#pragma once
#include "IProgression.h"

class ArithmeticProgression : public IProgression {
private:
    double a; 
    double d; 
public:
    ArithmeticProgression(double a, double d);

    double sum(int n) override;
    void showType() override;
};