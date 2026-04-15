#pragma once
#include "Progression.h"

class ArithmeticProgression : public Progression {
public:
    ArithmeticProgression(double a, double d);

    double sum(int n) override;
    void showType() override;
};